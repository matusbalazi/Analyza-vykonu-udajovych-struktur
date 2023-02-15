#include "vector.h"
#include "../ds_routines.h"
#include <cstdlib>
#include <cstring>

namespace structures {
	// NOTE: void* -> smernÌk na vöetko - vöeobecn˝ -> neviem ak˝ je veæk˝ -> veækosù udrûiavam v extra atrib˙te	
	Vector::Vector(size_t size) :
		memory_(calloc(size, 1)), // preferujem calloc, aby som tam mal len nuly
		size_(size)
	{
	}

	Vector::Vector(const Vector& other) :
		Vector(other.size_)
	{
		//kopÌrovacÌ konötruktor
		//skopÌruje pam‰ù na inÈ miesto
		memcpy(memory_, other.memory_, other.size_);
	}

	// NOTE: Dom·ce zadanie 1 - "move" sÈmantika pre triedu Vector
	Vector::Vector(Vector&& other)
	{
		this->memory_ = other.memory_;
		this->size_ = other.size_;
		other.memory_ = nullptr;
	}

	Vector::~Vector()
	{
		//deötruktor
		free(memory_); //uvoænÌm pam‰ù
		memory_ = NULL; //poupratujem (optional, but good)
		size_ = 0; //poupratujem (optional, but good)
	}

	Structure* Vector::clone() const
	{
		return new Vector(*this);
	}

	size_t Vector::size() const
	{
		return size_;
	}

	Structure& Vector::operator=(const Structure& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const Vector&>(other);
		}
		return *this;
	}

	Vector& Vector::operator=(const Vector& other)
	{
		if (this != &other) //nikdy nepriraÔujem s·m sebe
		{
			this->size_ = other.size_;
			this->memory_ = realloc(this->memory_, this->size_);
			memcpy(memory_, other.memory_, other.size_);
		}
		return *this;
	}

	// NOTE: Dom·ce zadanie 1 - "move" sÈmantika pre triedu Vector
	Vector& Vector::operator=(Vector&& other)
	{
		this->memory_ = other.memory_;
		other.memory_ = nullptr;
		return *this;
	}

	bool Vector::operator==(const Vector& other) const
	{	//nechcem tam maù ify -> oper·cia navyöe -> takto rovno vatim v˝sledo nieËoho
		return this->size_ == other.size_ && memcmp(this->memory_, other.memory_, this->size_) == 0;
	}

	byte& Vector::operator[](const int index)
	{
		//DSRoutines::rangeCheckExcept(index, this->size_, "Invalid index in Vector");
		//ned· sa pos˙vaÔ lebo je to smernÌk na void, takûe neviem koæko m·
		//poviem smernÌku, nech sa tv·ri ako byte -- pretypujem -- , a potom sa pos˙vaj ?

		// ZAPISUJEM takto
		// return *(reinterpret_cast<byte*>(memory_) + index);
		// ale na to uû m·m metÛdu
		return *this->getBytePointer(index);
	}

	byte Vector::operator[](const int index) const
	{
		//DSRoutines::rangeCheckExcept(index, this->size_, "Invalid index in Vector");
		//ned· sa pos˙vaÔ lebo je to smernÌk na void, takûe neviem koæko m·
		//poviem smernÌku, nech sa tv·ri ako byte -- pretypujem -- , a potom sa pos˙vaj ?

		// ZAPISUJEM takto
		// return *(reinterpret_cast<byte*>(memory_) + index);
		// ale na to uû m·m metÛdu
		return *this->getBytePointer(index);
	}

	byte* Vector::getBytePointer(const int index) const
	{
		//DSRoutines::rangeCheckExcept(index, this->size_, "Invalid index in Vector");
		// nevyhoda void, ze nemozem scitat s indexom, tak reinterpret_cast pretypovanie smernikov
		return (reinterpret_cast<byte*>(memory_) + index); //vr·ti adresu
	}

	byte& Vector::readBytes(const int index, const int count, byte& dest)
	{
		//DSRoutines::rangeCheckExcept(index, size_, "Invalid index in Vector");
		// KeÔ je menöie rovnÈ ako koniec -> porieöim size + 1
		//DSRoutines::rangeCheckExcept(index + count, size_ + 1, "Invalid index in Vector");

		// DOHODA
		memcpy(&dest, getBytePointer(index), count);
		//if (&dest >= getBytePointer(index) && &dest < getBytePointer(index + count))
		//{
		//	memmove(&dest, getBytePointer(index), count);
		//}
		//else
		//{
		//	memcpy(&dest, getBytePointer(index), count);
		//}
		return dest;
	}

	void Vector::copy(const Vector& src, const int srcStartIndex, Vector& dest, const int destStartIndex, const int length)
	{
		if (length > 0)
		{
			//DSRoutines::rangeCheckExcept(srcStartIndex, src.size_, "Invalid index in Vector");
			//DSRoutines::rangeCheckExcept(srcStartIndex + length, src.size_ + 1, "Invalid index in Vector");
			//DSRoutines::rangeCheckExcept(destStartIndex, dest.size_, "Invalid index in Vector");
			//DSRoutines::rangeCheckExcept(destStartIndex + length, dest.size_ + 1, "Invalid index in Vector");

			if (src.memory_ != dest.memory_)
				memcpy(reinterpret_cast<byte*>(dest.memory_) + destStartIndex, reinterpret_cast<byte*>(src.memory_) + srcStartIndex, length);
			else
				memmove(reinterpret_cast<byte*>(dest.memory_) + destStartIndex, reinterpret_cast<byte*>(src.memory_) + srcStartIndex, length);
		}

	}


}
