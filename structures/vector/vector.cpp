#include "vector.h"
#include "../ds_routines.h"
#include <cstdlib>
#include <cstring>

namespace structures {
	// NOTE: void* -> smern�k na v�etko - v�eobecn� -> neviem ak� je ve�k� -> ve�kos� udr�iavam v extra atrib�te	
	Vector::Vector(size_t size) :
		memory_(calloc(size, 1)), // preferujem calloc, aby som tam mal len nuly
		size_(size)
	{
	}

	Vector::Vector(const Vector& other) :
		Vector(other.size_)
	{
		//kop�rovac� kon�truktor
		//skop�ruje pam� na in� miesto
		memcpy(memory_, other.memory_, other.size_);
	}

	// NOTE: Dom�ce zadanie 1 - "move" s�mantika pre triedu Vector
	Vector::Vector(Vector&& other)
	{
		this->memory_ = other.memory_;
		this->size_ = other.size_;
		other.memory_ = nullptr;
	}

	Vector::~Vector()
	{
		//de�truktor
		free(memory_); //uvo�n�m pam�
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
		if (this != &other) //nikdy neprira�ujem s�m sebe
		{
			this->size_ = other.size_;
			this->memory_ = realloc(this->memory_, this->size_);
			memcpy(memory_, other.memory_, other.size_);
		}
		return *this;
	}

	// NOTE: Dom�ce zadanie 1 - "move" s�mantika pre triedu Vector
	Vector& Vector::operator=(Vector&& other)
	{
		this->memory_ = other.memory_;
		other.memory_ = nullptr;
		return *this;
	}

	bool Vector::operator==(const Vector& other) const
	{	//nechcem tam ma� ify -> oper�cia navy�e -> takto rovno vatim v�sledo nie�oho
		return this->size_ == other.size_ && memcmp(this->memory_, other.memory_, this->size_) == 0;
	}

	byte& Vector::operator[](const int index)
	{
		//DSRoutines::rangeCheckExcept(index, this->size_, "Invalid index in Vector");
		//ned� sa pos�va� lebo je to smern�k na void, tak�e neviem ko�ko m�
		//poviem smern�ku, nech sa tv�ri ako byte -- pretypujem -- , a potom sa pos�vaj ?

		// ZAPISUJEM takto
		// return *(reinterpret_cast<byte*>(memory_) + index);
		// ale na to u� m�m met�du
		return *this->getBytePointer(index);
	}

	byte Vector::operator[](const int index) const
	{
		//DSRoutines::rangeCheckExcept(index, this->size_, "Invalid index in Vector");
		//ned� sa pos�va� lebo je to smern�k na void, tak�e neviem ko�ko m�
		//poviem smern�ku, nech sa tv�ri ako byte -- pretypujem -- , a potom sa pos�vaj ?

		// ZAPISUJEM takto
		// return *(reinterpret_cast<byte*>(memory_) + index);
		// ale na to u� m�m met�du
		return *this->getBytePointer(index);
	}

	byte* Vector::getBytePointer(const int index) const
	{
		//DSRoutines::rangeCheckExcept(index, this->size_, "Invalid index in Vector");
		// nevyhoda void, ze nemozem scitat s indexom, tak reinterpret_cast pretypovanie smernikov
		return (reinterpret_cast<byte*>(memory_) + index); //vr�ti adresu
	}

	byte& Vector::readBytes(const int index, const int count, byte& dest)
	{
		//DSRoutines::rangeCheckExcept(index, size_, "Invalid index in Vector");
		// Ke� je men�ie rovn� ako koniec -> porie�im size + 1
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
