#include "Arr.h"
#include <cassert>

/// <summary>
/// Тесты различных методов шаблонного класса динамический массив
/// </summary>
void test()
{
	// тест конструктора по умолчанию
	DynArr<int> arr0;
	assert(arr0.length() == 0);

	// тест конструктора с параметрами
	DynArr<int> arr1(1);
	assert(arr1.length() == 1);
	assert(arr1[0] == 0);

	// тест вставки в начало
	DynArr<int> arr3_push(3);
	arr3_push.pushFront(5);
	assert(arr3_push.length() == 4);
	assert(arr3_push[0] == 5);

	// тест вставки в конец
	DynArr<int> arr3_pushb(3);
	arr3_pushb.pushBack(5);
	assert(arr3_pushb.length() == 4);
	assert(arr3_pushb[3] == 5);

	// тест изменения элемента по индексу
	DynArr<int> arr3_i(3);
	arr3_i[1] = 2;
	assert(arr3_i.length() == 3);
	assert(arr3_i[1] == 2);

	// тест удаления элемента в конце
	DynArr<int> arr4_popb(4);
	for (size_t i = 0; i < arr4_popb.length(); i++)
	{
		arr4_popb[i] = i;
	}
	assert(arr4_popb.popBack() == 3);
	assert(arr4_popb.length() == 3);
	assert(arr4_popb[2] == 2);

	// тест удаления элемента в начале
	DynArr<int> arr4_popf(4);
	for (size_t i = 0; i < arr4_popf.length(); i++)
	{
		arr4_popf[i] = i;
	}
	assert(arr4_popf.popFront() == 0);
	assert(arr4_popf.length() == 3);
	assert(arr4_popf[0] == 1);

	// тест очистки массива
	DynArr<int> arr4_clear(4);
	arr4_clear.Clear();
	assert(arr4_clear.length() == 0);

	// тест очистки массива с заданием размера нового массива
	DynArr<int> arr4_init(4);
	arr4_clear.Init(8);
	assert(arr4_clear.length() == 8);
}