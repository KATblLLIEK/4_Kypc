template<typename T>
struct Node
{
	Node* pNext;
	T data;

	Node<T>(T data, Node* pNext = nullptr) : pNext(pNext), data(data)
	{}
};