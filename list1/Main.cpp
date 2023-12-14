#include "List.h"

int main()
{

	setlocale(LC_ALL, "ru");


	List<int> lst;
	lst.push_front(5);
	lst.push_front(7);
	lst.push_front(101);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		std::cout << lst[i] << std::endl;
	}

	std::cout << std::endl << "pop_back " << std::endl << std::endl;

	lst.pop_back();

	for (int i = 0; i < lst.GetSize(); i++)
	{
		std::cout << lst[i] << std::endl;
	}
	std::cout << std::endl << "= copy" << std::endl << std::endl;

	List<int> lst2;
	lst2 = lst;

	for (int i = 0; i < lst2.GetSize(); i++)
	{
		std::cout << lst2[i] << std::endl;
	}

	std::cout << std::endl << "copy constructor" << std::endl << std::endl;

	List<int> lst3 = lst;

	for (int i = 0; i < lst3.GetSize(); i++)
	{
		std::cout << lst3[i] << std::endl;
	}

	List<int> lst4;
	List<int> lst5 = lst4;

	return 0;
}
