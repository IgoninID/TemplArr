#pragma once
#include <iostream>

using namespace std;

template <typename T>
class DynArr
{
private:
	size_t Size;
	size_t begArr;
	size_t endArr;
	T* Array;

	void create(size_t mem, size_t len, size_t beg)
	{
		if (mem < 1)
		{
			mem = 1;
		}
		Size = mem;
		begArr = beg;
		endArr = beg + len;
		Array = new T[mem];
	}
public:

	DynArr(size_t size)
	{
		create(size, size, 0);
	}

	DynArr()
	{
		create(1, 0, 0);
	}

	~DynArr()
	{
		delete[] Array;
	}

	DynArr<T>& Clear()
	{
		delete[] Array;
		create(1, 0, 0);
		return *this;
	}

	void Init(size_t size)
	{
		delete[] Array;
		create(size, size, 0);
		return *this;
	}

	size_t length()
	{
		return endArr - begArr;
	}

	T& operator [] (size_t i)
	{
		if (i >= length())
		{
			i = length() - 1;
		}
		return Array[begArr + i];
	}

	DynArr<T>& pushFront(T elem)
	{
		if (begArr == 0)
		{
			T* temp = Array;
			create(Size + length() / 2 + 1, length(), begArr + length() / 2 + 1);
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

	DynArr<T>& pushBack(T elem)
	{
		if (endArr == Size)
		{
			T* temp = Array;
			create(Size + length() / 2 + 1, length(), begArr);
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