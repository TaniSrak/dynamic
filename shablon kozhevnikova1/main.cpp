#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void fill_arr(T arr[], const int length, int left, int rigth)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % (rigth - left) + left;
	} 
}
template <typename T>
void print_arr(T arr[], const int length)
{
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}
//Task1 Увеличение размера массива
template <typename T>
void arr_app(T*& arr, int length, int num) //ссылка на указатель на тип данных Т &*T
{
	if (num <= 0) // 0. проверка и ограничение от лишних действий
		return;
	T* tmp = new T[length + num]{}; //1. выделение памяти под новый массив нужного размера, T = T,
	// в конце {} заполняют доп элементы массива нулями
	for (int i = 0; i < length; i++) // 2. Копирование значений старого массива в новый
	{
		tmp[i] = arr[i];
	}
	delete[] arr; // 3. освобождение памяти выделенной под старый массив
	arr = tmp; // 4. перенаправление указателя на новый массив
}
//Task2 Уменьшение размера массива
template <typename T>
void arr_del(T*& arr, int length, int num)
{
	if (num <= 0)
		return;
	if (num >= length)
	{
		delete[] arr;
		arr = nullptr;
		return;
	}
	T* tmp = new T[length - num];
	for (int i = 0; i < length - num; i++)
	{
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = tmp;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	//Выделение динамической памяти
	
	int* pointer = new int; //обычный указатель указываем как новый(new), и передаем размер памяти int. выделение участка динамической памяти
	// размером в тип int(4бт)

	*pointer = 7; //разыменование* и присваивание значения 7;
	std::cout << "pointer = " << pointer << std::endl;
	std::cout << "*pointer = " << *pointer << std::endl;

	//создадим новые значения и переписываем нашу переменную, освобождение области памяти на которую pointer выделен динамически;
	delete pointer; //освобождение
	pointer = nullptr; //направление

	if (pointer == nullptr)
		pointer = new int;

	*pointer = 15;
	std::cout << "pointer = " << pointer << std::endl;
	std::cout << "*pointer = " << *pointer << std::endl;
	//правило хорошего тона освобождать память pointer в конце программы
	delete pointer;
	pointer = nullptr; //направление
	

	//одномерные динмические массив
	
	std::cout << "Введите длину массива -> ";
	int dsize;
	std::cin >> dsize;
	int* darr = new int[dsize]; //создали указатель динамического массива направленный на участок типа инт (3 ячейки)
	fill_arr(darr, dsize, 1, 10);
	print_arr(darr, dsize);

	delete[] darr; //обнулили массив полностью
	

	//Двумерные динамические массивы
	
	int rows = 5, cols = 4;
	//int* mx = new int[rows][cols]; такой синтаксис не применим
	int** mx = new int* [cols]; // указатель на массив указателей **
	for (int i = 0; i < rows; i++)
	{
		mx[i] = new int[cols]; //становится равен участку динамической памяти колс
	}

	for (int i = 0; i < rows; i++) //обнуляем все ряды массива
	{
		delete[] mx[i];
	}
	delete[] mx;
	

	//Task1 увеличение размера массива
	std::cout << "Введите размер массива -> ";
	int size1;
	std::cin >> size1;

	int* arr1 = new int[size1];
	fill_arr(arr1, size1, 10, 20);
	std::cout << "Изначальный массив:\n";
	print_arr(arr1, size1);

	std::cout << "Введите количество дополнительных элементов массива -> ";
	std::cin >> n;

	arr_app(arr1, size1, n);
	if (n > 0)
		size1 += n;

	std::cout << "Итоговый массив:\n";
	print_arr(arr1, size1);

	delete[] arr1;
	

	//Задача2 Уменьшение размера массива
	std::cout << "Введите размер массива -> ";
	int size2;
	std::cin >> size2;

	int* arr2 = new int[size2];
	fill_arr(arr2, size2, 10, 20);
	std::cout << "Изначальный массив:\n";
	print_arr(arr2, size2);

	std::cout << "Введите количество дополнительных элементов массива -> ";
	std::cin >> n;

	arr_del(arr2, size2, n);
	if (n >= size2)
		size2 = 0;
	else
		if (n > 0)
			size2 -= n;

	std::cout << "Итоговый массив:\n";
	print_arr(arr2, size2);

	delete[] arr2;


	return 0;
}