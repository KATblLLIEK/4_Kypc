#include <iostream>
#include "Node.h"

template<typename T>
class List
{
private:
	
	size_t size;
	Node<T>* head;

	void copyFrom(const List<T>& src);

public:
	List();
	List(const List<T>& other);
	~List();

	List<T>& operator=(const List<T>& other);

	/*
	* удаление первого элемента в списке
	*/
	void pop_front();

	/*
	* добавление элемента в конец списка
	*/
	void push_back(T data);

	/*
	* очистить список
	*/
	void clear();

	/*
	* получить количество елементов в списке
	*/
	int GetSize() const { return size; }

	Node<T>* GetHead() const { return head; }

	/*
	* перегруженный оператор []
	*/
	T operator[](const int index) const;

	/*
	* добавление элемента в начало списка
	*/
	void push_front(T data);

	/*
	* добавление элемента в список по указанному индексу
	*/
	void insert(T data, int index);

	/*
	* удаление элемента в списке по указанному индексу
	*/
	void removeAt(int index);

	/*
	* удаление последнего элемента в списке
	*/
	void pop_back();
};

#include "List.cpp"