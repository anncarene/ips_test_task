#include "List.h"
#include <iostream>

using namespace DataStructs;

template <typename T>
bool List<T>::isEmpty()
{
	return this->first == nullptr;
}

template <typename T>
void List<T>::addToStart(T value)
{
	Node<T>* elem = new Node<T>(value, this->first);
	this->first = elem;
	this->size++;
}

template <typename T>
void List<T>::addToEnd(T value)
{
	if (this->isEmpty())
	{
		this->first = new Node<T>(value);
		this->size++;
		return;
	}

	Node<T>* plast = this->first;

	while (plast->next != nullptr) plast = plast->next;

	plast->next = new Node<T>(value);
	this->size++;
}

template <typename T>
void List<T>::print()
{
	if (this->isEmpty())
	{
		std::cout << "Список пуст." << std::endl;
		return;
	}

	Node<T>* p = this->first;

	std::cout << "*****" << std::endl;

	while (p)
	{
		std::cout << p->value << std::endl;
		p = p->next;
	}

	std::cout << "*****" << std::endl;
}

template <typename T>
void List<T>::deleteFromStart()
{
	if (this->isEmpty()) return;

	Node<T>* p = this->first;
	this->first = this->first->next;
	delete p;
	this->size--;
}

template <typename T>
void List<T>::deleteFromEnd()
{
	if (this->isEmpty()) return;

	if(this->first->next == nullptr)
	{
		delete this->first;
		this->first = nullptr;
		return;
	}

	Node<T>* pcur = this->first;
	Node<T>* pprev = this->first;
	
	while (pcur->next != nullptr)
	{
		if (pcur != this->first) pprev = pprev->next;
		pcur = pcur->next;
	}

	pprev->next = nullptr;
	delete pcur;
	this->size--;
}

template <typename T>
void List<T>::deleteEquals(const T& value)
{
	if (this->isEmpty()) return;

	Node<T>* pcur = this->first;
	Node<T>* pprev = this->first;

	while (pcur != nullptr)
	{
		if (pcur->value == value && pcur == this->first)
		{
			pcur = pcur->next;
			pprev = pprev->next;
	
			this->deleteFromStart();
		}
		else if (pcur->value != value && pcur == this->first)
		{
			pcur = pcur->next;
		}
		else if (pcur->value == value && pcur != this->first)
		{
			pprev->next = pcur->next;
			delete pcur;
			pcur = pprev->next;
			this->size--;
		}
		else
		{
			pcur = pcur->next;
			pprev = pprev->next;
		}
	}
}

template <typename T>
void List<T>::invert()
{
	if (this->isEmpty() || this->first->next == nullptr) return;

	Node<T>* pcur = this->first;
	int counter = 0;

	while (pcur != nullptr)
	{
		this->addToStart(pcur->value);
		pcur = pcur->next;
		counter++;
	}

	while (counter != 0)
	{
		this->deleteFromEnd();
		counter--;
	}
}

template <typename T>
List<T>::List(const List<T>& someList)
{
	this->size = 0;
	this->first = nullptr;

	Node<T>* pcur = someList.getFirst();

	while (pcur != nullptr)
	{
		this->addToEnd(pcur->value);
		pcur = pcur->next;
	}
}

template <typename T>
bool List<T>::operator== (const List<T>& someList)
{
	Node<T>* p1 = someList.getFirst();
	Node<T>* p2 = this->first;

	if (
		(p1 == nullptr && p2 != nullptr) ||
		(p2 == nullptr && p1 != nullptr)
	) return false;

	while ((p1 != nullptr) && (p2 != nullptr))
	{
		if (p1->value != p2->value) return false;

		if (p1 != nullptr) p1 = p1->next;
		if (p2 != nullptr) p2 = p2->next;
	}

	return true;
}

template <typename T>
bool List<T>::operator!= (const List<T>& someList) 
{	
	return !(*this == someList);
}

template <typename T>
List<T>& List<T>::operator= (const List<T>& someList)
{
	if (*this == someList) return *this;

	while (!this->isEmpty()) this->deleteFromStart();

	Node<T>* pcur = someList.getFirst();

	while (pcur != nullptr)
	{
		this->addToEnd(pcur->value);
		pcur = pcur->next;
	}

	return *this;
}

template <typename T>
void List<T>::swap(List<T>& someList)
{
    Node<T>* p = this->first;
    this->first = someList.first;
    someList.first = p;
}

template <typename T>
List<T>::~List()
{
	while (!this->isEmpty()) this->deleteFromStart();
}
