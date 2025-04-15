#pragma once
#include <iostream>

using namespace std;

/// <summary>
/// Шаблонный класс динамического массива
/// </summary>
/// <typeparam name="T - тип элементов массива"></typeparam>
template <typename T>
class DynArr
{
private:
	size_t Size; // Размер массива (Выделенная память)
	size_t begArr; // Начальный индекс массива
	size_t endArr; // Конечный индекс массива
	T* Array; // Указатель на массив

	/// <summary>
	/// Метод создания массива заполненного 0
	/// </summary>
	/// <param name="mem - выделяемая память"></param>
	/// <param name="len - размер резерва"></param>
	/// <param name="beg - начало массива в резерве"></param>
	void create(size_t mem, size_t len, size_t beg)
	{
		if (mem < 1)
		{
			mem = 1;
		}
		Size = mem;
		begArr = beg;
		endArr = beg + len;
		Array = new T[mem]();
	}
public:

	/// <summary>
	/// Конструктор с параметрами
	/// </summary>
	/// <param name="size - размер массива"></param>
	DynArr(size_t size)
	{
		create(size, size, 0);
	}

	/// <summary>
	/// Конструктор по умолчанию (пустой массив без элементов)
	/// </summary>
	DynArr()
	{
		create(1, 0, 0);
	}

	/// <summary>
	/// Деструктор
	/// </summary>
	~DynArr()
	{
		delete[] Array;
	}

	/// <summary>
	/// Очистка массива
	/// </summary>
	/// <returns>
	/// Очищенный массив с 0 элементом
	/// </returns>
	DynArr<T>& Clear()
	{
		delete[] Array;
		create(1, 0, 0);
		return *this;
	}

	/// <summary>
	/// Очистка массива с заданием размера нового массива
	/// </summary>
	/// <param name="size - размер нового массива"></param>
	void Init(size_t size)
	{
		delete[] Array;
		create(size, size, 0);
		return *this;
	}

	/// <summary>
	/// Получение длины массива
	/// </summary>
	/// <returns>
	/// Длина массива
	/// </returns>
	size_t length()
	{
		return endArr - begArr;
	}

	/// <summary>
	/// Перегрузка оператора [] (для чтения, изменения элемента по индексу)
	/// </summary>
	/// <param name="i - индекс массива"></param>
	/// <returns>
	/// Указатель на элемент
	/// </returns>
	T& operator [] (size_t i)
	{
		if (i >= length())
		{
			i = length() - 1;
		}
		return Array[begArr + i];
	}

	/// <summary>
	/// Вставка элемента в начало
	/// </summary>
	/// <param name="elem - элемент"></param>
	/// <returns>
	/// Указатель на обновленный массив
	/// </returns>
	DynArr<T>& pushFront(T elem)
	{
		if (begArr == 0)
		{
			T* temp = Array;
			create(Size + length() / 2 + 1, length(), begArr + length() / 2 + 1); // увеличиваем резерв памяти (добавляем половину реального размера массива к резерву)
			for (size_t i = 0; i < length(); i++)
			{
				Array[begArr + i] = temp[i];
			}
			delete[] temp;
		}
		begArr--;
		Array[begArr] = elem;
		return *this;
	}

	/// <summary>
	/// Вставка элемента в конец
	/// </summary>
	/// <param name="elem - элемент"></param>
	/// <returns>
	/// Указатель на обновленный массив
	/// </returns>
	DynArr<T>& pushBack(T elem)
	{
		if (endArr == Size)
		{
			T* temp = Array;
			create(Size + length() / 2 + 1, length(), begArr); // увеличиваем резерв памяти (добавляем половину реального размера массива к резерву)
			for (size_t i = begArr; i < endArr; i++)
			{
				Array[i] = temp[i];
			}
			delete[] temp;
		}
		Array[endArr] = elem;
		endArr++;
		return *this;
	}

	/// <summary>
	/// Удаление элемента в начале
	/// </summary>
	/// <returns>
	/// Удаленный элемент
	/// </returns>
	T popFront()
	{
		if (begArr > length())
		{
			T* temp = Array;
			size_t begTemp = begArr;
			create(Size - begArr, length(), 0);
			for (size_t i = 0; i < length(); i++)
			{
				Array[i] = temp[begTemp + i];
			}
			delete[] temp;
		}
		if (length() > 0)
		{
			begArr++;
		}
		return Array[begArr - 1];
	}

	/// <summary>
	/// Удаление элемента в конце
	/// </summary>
	/// <returns>
	/// Удаленный элемент
	/// </returns>
	T popBack()
	{
		if (Size - endArr > length())
		{
			T* temp = Array;
			create(endArr, length(), begArr);
			for (size_t i = begArr; i < endArr; i++)
			{
				Array[i] = temp[i];
			}
			delete[] temp;
		}
		if (length() > 0)
		{
			endArr--;
		}
		return Array[endArr];
	}
};

void test();