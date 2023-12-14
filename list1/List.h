#include "Node.h"
#include <iostream>

template<typename T>
class List final
{
private:
	size_t size;
	Node<T>* head;
public:
	List();
	List(const List<T>& other);
	~List();
	List(List<T>&& other) noexcept;

	List<T>& operator=(List<T>&& other) noexcept;
	List<T>& operator=(const List<T>& other);

	/*
	* @brief удаление первого элемента в списке
	*/
	void pop_front();

	/*
	* @brief получение первого элемента в списке
	* @return информация об элементе
	*/
	T top() const;

	/*
	* @brief добавление элемента в конец списка
	* @param data  информация об элементе
	*/
	void push_back(T data);

	/*
	* @brief очистить список
	*/
	void clear();

	/*
	* @brief получить количество элементов в списке
	* @return количество элементов в списке
	*/
	size_t GetSize() const { return size; }


	/*
	* @brief перегруженный оператор []
	*/
	const T operator[](const size_t index) const;

	/*
	* @brief перегруженный оператор []
	*/
	T operator[](const size_t index);

	/*
	* @brief добавление элемента в начало списка
	* @param data информация об элементе
	*/
	void push_front(T data);

	/*
	* @brief добавление элемента в список по указанному индексу
	* @param data информация об элементе
	* @param index индекс элемента
	*/
	void insert(T data, size_t index);

	/*
	* @brief удаление элемента в списке по указанному индексу
	* @param index индекс элемента
	*/
	void removeAt(size_t index);

	/*
	* @brief удаление последнего элемента в списке
	*/
	void pop_back();
};

template<typename T>
List<T>::List() : size(0), head{ nullptr } {};

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& other)
{
	if (this == &other)
		return *this;
	List<T> copy(other);
	std::swap(this->head, copy.head);
	std::swap(this->size, copy.size);
	return *this;
}

template<typename T>
List<T>::List(const List<T>& other) : List()
{
	auto temp = other.head;
	while (temp != nullptr)
	{
		this->push_back(temp->data);
		temp = temp->pNext;
	}
	this->size = other.size;
}

template <typename T>
List<T>::List(List&& other) noexcept : head(other->head), size(other->size) {
	other.count = 0;
	other.head = nullptr;
}

template <typename T>
List<T>& List<T>::operator = (List&& other) noexcept {
	std::swap(this->head, other.head);
	std::swap(this->size, other.size);
	return *this;
}

template<typename T>
void List<T>::pop_front()
{
	auto* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		auto* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	size++;
}

template<typename T>
void List<T>::clear()
{
	while (size > 0)
	{
		pop_front();
	}
}

template<typename T>
T List<T>::operator[](const size_t index)
{
	size_t counter = 0;

	auto current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
	return current->data;
}

template<typename T>
const T List<T>::operator[](const size_t index) const
{
	size_t counter = 0;

	auto current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
	return current->data;
}

template<typename T>
void List<T>::push_front(T data)
{
	auto temp = new Node<T>(data, head);
	this->head = temp;
	size++;
}

template<typename T>
void List<T>::insert(T data, size_t index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		auto* previous = this->head;

		for (size_t i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		auto* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		size++;
	}
}

template<typename T>
void List<T>::removeAt(size_t index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		auto* previous = this->head;
		for (size_t i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		auto* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(size - 1);
}

template <typename T>
T List<T>::top() const {
	return this->head->data;
}