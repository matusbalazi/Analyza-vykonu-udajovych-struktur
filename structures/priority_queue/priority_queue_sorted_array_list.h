#pragma once

#include "priority_queue_list.h"
#include "../list/array_list.h"
#include <stdexcept> 
#include "../heap_monitor.h"

namespace structures
{
	/// <summary> Prioritny front implementovany utriednym ArrayList-om. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v prioritnom fronte. </typepram>
	template<typename T>
	class PriorityQueueSortedArrayList : public PriorityQueueList<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		PriorityQueueSortedArrayList();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Prioritny front implementovany utriednym ArrayList-om, z ktoreho sa prevezmu vlastnosti. </param>
		PriorityQueueSortedArrayList(const PriorityQueueSortedArrayList<T>& other);

		/// <summary> Operacia klonovania. Vytvori a vrati duplikat udajovej struktury. </summary>
		/// <returns> Ukazovatel na klon struktury. </returns>
		Structure* clone() const override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Prioritny front implementovany zoznamom, z ktoreho ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tento prioritny front nachadza po priradeni. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak vstupny parameter nie je prioritny front implementovany utriedenym ArrayList-om. </exception>  
		/// <remarks> Vyuziva typovy operator priradenia. </remarks>
		virtual PriorityQueueList<T>& operator=(const PriorityQueueList<T>& other) override;

		/// <summary> Operator priradenia pre prioritny front implementovany utriedenym ArrayList-om. </summary>
		/// <param name = "other"> Prioritny front implementovany utriedenym ArrayList-om, z ktoreho ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tento prioritny front nachadza po priradeni. </returns>
		virtual PriorityQueueSortedArrayList<T>& operator=(const PriorityQueueSortedArrayList<T>& other);

		/// <summary> Vlozi prvok s danou prioritou do prioritneho frontu implementovaneho utriednym ArrayList-om. </summary>
		/// <param name = "priority"> Priorita vkladaneho prvku. </param>
		/// <param name = "data"> Vkladany prvok. </param>
		void push(const int priority, const T& data) override;

	protected:
		/// <summary> Vrati index v utriedenom ArrayList-e, na ktorom sa nachadza prvok s najvacsou prioritou. </summary>
		/// <returns> Index prvku s najvacsou prioritou. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je zoznam prazdny. </exception>  
		int indexOfPeek() const override;
	};

	template<typename T>
	inline PriorityQueueSortedArrayList<T>::PriorityQueueSortedArrayList() :
		PriorityQueueList<T>(new ArrayList<PriorityQueueItem<T>*>())
	{
	}

	template<typename T>
	inline PriorityQueueSortedArrayList<T>::PriorityQueueSortedArrayList(const PriorityQueueSortedArrayList<T>& other) :
		PriorityQueueSortedArrayList<T>()
	{
		*this = other;
	}

	template<typename T>
	inline Structure* PriorityQueueSortedArrayList<T>::clone() const
	{
		return new PriorityQueueSortedArrayList<T>(*this);
	}

	template<typename T>
	inline PriorityQueueList<T>& PriorityQueueSortedArrayList<T>::operator=(const PriorityQueueList<T>& other)
	{
		return *this = dynamic_cast<const PriorityQueueSortedArrayList<T>&>(other);
	}

	template<typename T>
	inline PriorityQueueSortedArrayList<T>& PriorityQueueSortedArrayList<T>::operator=(const PriorityQueueSortedArrayList<T>& other)
	{
		if (this != &other)
		{
			PriorityQueueList<T>::operator=(other);
		}
		return *this;
	}

	template<typename T>
	inline void PriorityQueueSortedArrayList<T>::push(const int priority, const T& data)
	{
		// 0) ak je zoznam prazdny => add
		// 1) ak je to priorita, ktora je lepsia ako doteraz najlepsia => add
		// 2) ak je to priorita, ktora je horsia ako doteraz najhorsia => insert(0)
		// 3) pomocou cyklu for hladam od zaciatku index prvku, ktory ma ako prvy lepsiu prioritu ako ja
		//		vlozim sa pred neho
		if (this->list_->isEmpty() || priority < this->peekPriority()) {
			this->list_->add(new PriorityQueueItem<T>(priority, data));
		}
		else {
			int index = 0;
			/*while (priority >= (*this->list_)[index]->getPriority()) {
				index++;
			}*/
			for (int i = 0; (*this->list_)[i]->getPriority() > priority; i++) {
				index++;
			}
			this->list_->insert(new PriorityQueueItem<T>(priority, data), index);
		}
	}

	template<typename T>
	inline int PriorityQueueSortedArrayList<T>::indexOfPeek() const
	{
		if (this->list_->isEmpty()) {
			throw std::logic_error("Priority queue sorted array list is empty!");
		}
		return this->list_->size() - 1;
	}
}