template<typename T>
List<T>::List() : size(0), head(nullptr) {}


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
	Node<T>* temp = other.head;
	while (temp != nullptr) {
		this->push_back(temp->data);
		temp = temp->pNext;
	}
	this->size = other.GetSize();
}


template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
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
		Node<T>* current = this->head;

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
	while (size)
	{
		pop_front();
	}
}


template<typename T>
T List<T>::operator[](const size_t index) const
{
	size_t counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
	return T{};
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
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
		Node<T>* previous = this->head;

		for (size_t i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);
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
		Node<T>* previous = this->head;
		for (size_t i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T>* toDelete = previous->pNext;

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

template<typename T>
List<T>::List(List<T>&& other) noexcept : head(other->head), size(other->size){
	other.size = 0;
	other.head = nullptr;
}

template<typename T>
List<T>& List<T>::operator=(List<T>&& other) noexcept {
	if (this == *other)
		return *this;
	std::swap(this->head, other->head);
	std::swap(this->size, other->size);
}