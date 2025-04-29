// �����: ������ �.�.

#include "Arr.h"
#include <cassert>

/// <summary>
/// ����� ��������� ������� ���������� ������ ������������ ������
/// </summary>
void test()
{
	// ���� ������������ �� ���������
	DynArr<int> arr0;
	assert(arr0.length() == 0);

	// ���� ������������ � �����������
	DynArr<int> arr1(1);
	assert(arr1.length() == 1);
	assert(arr1[0] == 0);

	// ���� ������������ �����������
	DynArr<int> arr_c(5);
	for (size_t i = 0; i < arr_c.length(); i++)
	{
		arr_c[i] = i;
	}
	DynArr<int> arr_r(arr_c);
	//DynArr<int> arr_r = arr_c;
	assert(arr_r.length() == arr_c.length());
	for (size_t i = 0; i < arr_c.length(); i++)
	{
			assert(arr_r[i] == arr_c[i]);
	}

	// ���� ������������ �����������
	DynArr<int> arr_m(5);
	for (size_t i = 0; i < arr_m.length(); i++)
	{
		arr_m[i] = i;
	}
	DynArr<int> arr_rm(move(arr_m));
	assert(arr_rm.length() == 5);
	assert(arr_m.length() == 0);
	for (size_t i = 0; i < arr_rm.length(); i++)
	{
		assert(arr_rm[i] == i);
	}

	// ���� ������� � ������
	DynArr<int> arr3_push(8);
	arr3_push.pushFront(5); // ������ ����������
	assert(arr3_push.length() == 9);
	assert(arr3_push[0] == 5);
	arr3_push.pushFront(6); // ������ �� ����������
	assert(arr3_push.length() == 10);
	assert(arr3_push[0] == 6);

	// ���� ������� � �����
	DynArr<int> arr3_pushb(8);
	arr3_pushb.pushBack(5); // ������ ����������
	assert(arr3_pushb.length() == 9);
	assert(arr3_pushb[8] == 5);
	arr3_pushb.pushBack(6); // �� ������ ����������
	assert(arr3_pushb.length() == 10);
	assert(arr3_pushb[9] == 6);

	// ���� ��������� �������� �� �������
	DynArr<int> arr3_i(3);
	arr3_i[1] = 2;
	assert(arr3_i.length() == 3);
	assert(arr3_i[1] == 2);

	// ���� �������� �������� � �����
	DynArr<int> arr4_popb(8);
	for (size_t i = 0; i < arr4_popb.length(); i++)
	{
		arr4_popb[i] = i;
	}
	assert(arr4_popb.popBack() == 7); // ������ �� ���������
	assert(arr4_popb.length() == 7);
	assert(arr4_popb.popBack() == 6); // ������ �� ���������
	assert(arr4_popb.popBack() == 5); // ������ �� ���������
	assert(arr4_popb.popBack() == 4); // ������ �� ���������
	assert(arr4_popb.popBack() == 3); // ������ �� ���������
	assert(arr4_popb.popBack() == 2); // ������ ������ ���������
	assert(arr4_popb.length() == 2);
	assert(arr4_popb[1] == 1);

	// ���� �������� �������� � ������
	DynArr<int> arr4_popf(5);
	for (size_t i = 0; i < arr4_popf.length(); i++)
	{
		arr4_popf[i] = i;
	}
	assert(arr4_popf.popFront() == 0); // ������ �� ���������
	assert(arr4_popf.length() == 4);
	assert(arr4_popf[0] == 1);
	assert(arr4_popf.popFront() == 1); // ������ �� ���������
	assert(arr4_popf.popFront() == 2); // ������ �� ���������
	assert(arr4_popf.popFront() == 3); // ������ ������ ���������
	assert(arr4_popf.length() == 1);
	assert(arr4_popf[0] == 4);

	// ���� ������� �� �������
	DynArr<int> arr_pushind(8);
	for (size_t i = 0; i < arr_pushind.length(); i++)
	{
		arr_pushind[i] = i;
	}
	arr_pushind.pushAt(99, 1); // ������ ����������
	arr_pushind.pushAt(90, 1); // ������ �� ����������
	arr_pushind.pushAt(70, 0); // � ������
	arr_pushind.pushAt(60, 11); // � �����
	assert(arr_pushind.length() == 12);
	assert(arr_pushind[0] == 70);
	assert(arr_pushind[1] == 0);
	assert(arr_pushind[2] == 90);
	assert(arr_pushind[3] == 99);
	assert(arr_pushind[4] == 1);
	assert(arr_pushind[5] == 2);
	assert(arr_pushind[6] == 3);
	assert(arr_pushind[7] == 4);
	assert(arr_pushind[8] == 5);
	assert(arr_pushind[9] == 6);
	assert(arr_pushind[10] == 7);
	assert(arr_pushind[11] == 60);

	// ���� �������� �� �������
	DynArr<int> arr_popind(8);
	for (size_t i = 0; i < arr_popind.length(); i++)
	{
		arr_popind[i] = i;
	}
	assert(arr_popind.popAt(2) == 2); // ������ �� ���������
	assert(arr_popind.length() == 7);
	assert(arr_popind[2] == 3);
	assert(arr_popind.popAt(0) == 0); // �� ������
	assert(arr_popind.length() == 6);
	assert(arr_popind.popAt(6) == 7); // �� �����
	assert(arr_popind.popAt(2) == 4);
	assert(arr_popind.popAt(2) == 5);
	assert(arr_popind.popAt(2) == 6);
	assert(arr_popind.length() == 2); // ������ ���������


	// ���� ������� �������
	DynArr<int> arr4_clear(4);
	arr4_clear.Clear();
	assert(arr4_clear.length() == 0);

	// ���� ������� ������� � �������� ������� ������ �������
	DynArr<int> arr4_init(4);
	arr4_clear.Init(8);
	assert(arr4_clear.length() == 8);
}