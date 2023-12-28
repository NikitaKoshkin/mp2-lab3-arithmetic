// ���������� � ���������� ���������� �����
// ���� ������������ ��������: 
// - ������� ��������, 
// - ���������� ��������, 
// - �������� �������� �������� (��� ��������)
// - �������� �� �������, 
// - ��������� ���������� ��������� � �����
// - ������� ����� 
// ��� ������� � ������ ���� ������ �������������� ������ +

#ifndef __TSTACK_H__
#define __TSTACK_H__


#include <iostream>
#include <string>
#include<vector>

using namespace std;


template <class T>
class TStack
{
	T* arr;
	int count;     // ���-�� ��������� � ����� (������� ������ �����) 
	int top;       // ������� ������� �����
	size_t capacity;  // ������ ������� �����
public:
	TStack(size_t size = 10)
	{
		if (size <= 0)
			throw "wrong size in TStack_constructor";
		capacity = size;
		arr = new T[capacity];
		count = 0;
		top = -1;
	}
	//TStack(const TStack& s); � ����� �� ����������� ����������� � ������ ����?
	~TStack();                // ������� �����
	void push(const T& elem);      // ������� ��������
	void pop();               // ���������� (��������) ��������
	T top_stack();            // �������� �������� ��������
	bool empty();             // �������� �� �������
	int size();               // ��������� ���������� ��������� � �����
};


template <class T>
TStack<T>::~TStack()
{
	delete[] arr;
	arr = nullptr;
	count = 0;
	capacity = 0;
}

template <class T>
void TStack<T>::push(const T& elem)
{
	if (size() == capacity)
	{
		int new_size = capacity + 100;
		T* temp = new T[new_size];
		for (int i = 0;i < capacity;i++)
			temp[i] = arr[i];
		delete[] arr;
		arr = temp;
		capacity = new_size;
	}
	top++;
	arr[top] = elem;
	count++;
}

template <class T>
void TStack<T>::pop()
{
	if (!empty())
	{
		top--;
		count--;
	}

	else
		throw "Error empty stack in top";
}

template <class T>
T TStack<T>::top_stack()
{
	if (!empty())
		return arr[top];
	else
		throw "Error empty stack in top";
}

template <class T>
bool TStack<T>::empty()
{
	if (count == 0)
		return true;
	else
		return false;
}

template <class T>
int TStack<T>::size()
{
	return count;
}

#endif