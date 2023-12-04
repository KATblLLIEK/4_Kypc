template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::copyFrom(const List<T>& src)
{
	Node<T>* srcHead = src.GetHead();

	if (srcHead == nullptr)
	{
		size = 0;
		head = nullptr;
		return;
	}

	head = new Node<T>(srcHead->data);

	Node<T>* current = head;
	Node<T>* currentOther = srcHead;

	
	while(currentOther->pNext != nullptr)
	{
		Node<T>* newNext = new Node<T>(currentOther->pNext->data);
		current->pNext = newNext;
		current = current->pNext;
		currentOther = currentOther->pNext;
	}

	size = src.GetSize();
}


template<typename T>
List<T>& List<T>::operator=(const List<T>& other)
{
	if (this == &other)
        return *this;
    
	copyFrom(other);

    return *this;
}

template<typename T>
List<T>::List(const List<T>& other) 
{
	copyFrom(other);
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
T List<T>::operator[](const int index) const
{
	int counter = 0;

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
void List<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
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