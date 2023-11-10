#include <iostream>
#include <sstream>

using namespace std;

/**
 * @brief Метод, возвращающий заполненный пользователем массив.
 * @param size_ размер массива.
 * @return заполненный массив.
 */
int* InputArray(const size_t size_);

/**
 * @brief Вывод массива на консоль.
 * @param array массив.
 * @param size_ размер массива.
 */
string toString(const int* array, const size_t size_);


/**
 * @brief сложение с числом.
 * @param array массив.
 * @param size_ размер массива.
  * @param num слагаемое.
  * @return массив, сложенный с числом.
 */
int* AddToElem(int* array, const size_t size_,int num);

/**
 * @brief ввод и проверка на корректное число элементов массива
 * @param message вывод определённой фразы при выполнении
 * @param size размер массива
 */
size_t GetSize(const std::string& message);

int main()
{


  try{
    size_t Arr_size;

    Arr_size = GetSize("Введите размер массива ");

    size_t size = Arr_size;
    int* NewArray = nullptr;


    NewArray = InputArray(size);

    cout << toString(NewArray, size);


    int num;

    cout<<"Введите слагаемое ";
    cin>>num;

    AddToElem(NewArray,size,num);

    cout << toString(NewArray, size);


    if (NewArray != nullptr)
    {
       delete[] NewArray;
       NewArray = nullptr;
    }

  }
  catch (const std::invalid_argument& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
        return 1;
  }

  return 0;
}

size_t GetSize(const std::string& message)
{
    int size = -1;
    std::cout << message;
    std::cin >> size;

    if (size <= 0)
    {
        throw std::out_of_range("Некоректное значение. Размер массива должен быть больше нуля");
    }
    size_t newSize = static_cast<size_t>(size);

    return newSize;
}

int* InputArray(const size_t size_){

  int* array = new int[size_];

  cout<<"Введите данные в массив\n";

  for (size_t index = 0 ; index < size_; index++){
      cin >> array[index];
    }

  return array;
}

string toString(const int* array, const size_t size_)
{
  std::stringstream buffer{};

  for(size_t index = 0;index < size_ ;index++){
    buffer << array[index] << " ";
  }
  buffer << "\n";

  return buffer.str();  
}

int* AddToElem(int* array, const size_t size_,int num)
{
  for (size_t index = 0; index < size_; index++){
    array[index] = array[index]+num;
  }
  return array;
}