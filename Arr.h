// Автор: Игонин В.Ю.

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
	size_t begArr; // Начальный индекс массива (массив может располагаться не в начале выделенной памяти, таким образом нет необходимости в смещении при вставке в начало)
	size_t endArr; // Конечный индекс массива
	T* Array; // Указатель на массив

	/// <summary>
	/// Метод создания массива заполненного 0
	/// </summary>
	/// <param name="mem - выделяемая память"></param>
	/// <param name="len - размер массива"></param>
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
	/// Конструктор по умолчанию (массив с зарезервированной памятью под 1 элемент)
	/// </summary>
	DynArr()
	{
		create(1, 0, 0);
	}

	/// <summary>
	/// Конструктор копирования
	/// </summary>
	/// <param name="arr - копируемый массив"></param>
	DynArr(const DynArr<T>& arr)
	{
		create(arr.length(), arr.length(), 0);
		copy(arr.Array + arr.begArr, arr.Array + arr.endArr, this->Array);
		//for (size_t i = 0; i < this->length(); i++)
		//{
		//	this->Array[i] = arr.Array[i];
		//}
	}

	/// <summary>
	/// Конструктор перемещения
	/// </summary>
	/// <param name="arr"></param>
	DynArr(DynArr<T>&& arr)
	{
		create(arr.length(), arr.length(), 0);
		copy(arr.Array + arr.begArr, arr.Array + arr.endArr, this->Array);
		arr.Clear();
	}

	/// <summary>
	/// Оператор присваивания перемещением
	/// </summary>
	/// <param name="arr"></param>
	/// <returns></returns>
	DynArr<T>& operator =(DynArr<T>&& arr)
	{
		if (this != &arr)
		{
			return DynArr(arr);
		}
		return *this;
	}

	/// <summary>
	/// Оператор присваивания копированием
	/// </summary>
	/// <param name="arr"></param>
	/// <returns></returns>
	DynArr<T>& operator =(const DynArr<T>& arr)
	{
		return DynArr(arr);
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
	/// Очищенный массив с 0 элементов
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
	DynArr<T>& Init(size_t size)
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
	size_t length() const
	{
		return endArr - begArr;
	}

	/// <summary>
	/// Перегрузка оператора [] (для чтения, изменения элемента по индексу)
	/// Если индекс больше длины массива береться последний элемент
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
			copy(temp, temp + length(), Array + begArr);
			//for (size_t i = 0; i < length(); i++)
			//{
			//	Array[begArr + i] = temp[i];
			//}
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
			copy(temp+begArr, temp + endArr, Array + begArr);
			//for (size_t i = begArr; i < endArr; i++)
			//{
			//	Array[i] = temp[i];
			//}
			delete[] temp;
		}
		Array[endArr] = elem;
		endArr++;
		return *this;
	}

	/// <summary>
	/// Вставка элемента по индексу (вставка в позицию которой нет, будет вставлять в конец если индекс за пределами массива)
	/// </summary>
	/// <param name="elem - элемент"></param>
	/// <param name="ind - индекс"></param>
	/// <returns>
	/// Указатель на массив
	/// </returns>
	DynArr<T>& pushAt(T elem, size_t ind)
	{
		if (ind >= length())
			return pushBack(elem);
		if (ind <= begArr) // вставка в начало массива если введенный индекс меньше или равен начальному индексу массива
			return pushFront(elem);
		if (endArr == Size)
		{
			T* temp = Array;
			create(Size + length() / 2 + 1, length(), begArr); // увеличиваем резерв памяти (добавляем половину реального размера массива к резерву)
			copy(temp + begArr, temp + endArr, Array + begArr);
			delete[] temp;
		}
		T* temp = new T[length()-ind];
		copy(Array+begArr+ind, Array + endArr, temp);
		Array[begArr+ind] = elem;
		copy(temp, temp + length()-ind, Array + begArr + ind+1);
		delete[] temp;
		endArr++;
		return *this;
	}
	
	/// <summary>
	/// Удаление элемента по индексу
	/// </summary>
	/// <param name="ind - индекс"></param>
	/// <returns>
	/// Удаленный элемент
	/// </returns>
	T popAt(size_t ind)
	{
		if (ind >= endArr-1)
			return popBack();
		if (ind <= begArr)
			return popFront();
		if (Size - endArr > length())
		{
			T* temp = Array;
			create(endArr, length(), begArr);
			copy(temp + begArr, temp + endArr, Array + begArr);
			//for (size_t i = begArr; i < endArr; i++)
			//{
			//	Array[i] = temp[i];
			//}
			delete[] temp;
		}
		T* temp = new T[length() - ind-1];
		T elem = Array[begArr + ind];
		copy(Array + begArr + ind+1, Array + endArr, temp);
		copy(temp, temp + length() - ind-1, Array+begArr+ind);
		delete[] temp;
		if (length() > 0)
		{
			endArr--;
		}
		return elem;
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
			//copy(temp + begTemp, temp + length(), Array);
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
			copy(temp + begArr, temp + endArr, Array + begArr);
			//for (size_t i = begArr; i < endArr; i++)
			//{
			//	Array[i] = temp[i];
			//}
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