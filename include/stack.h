// объ€вление и реализаци€ шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удалени€)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека 
// при вставке в полный стек должна перевыдел€тьс€ пам€ть +

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
	int count;     // кол-во элементов в стеке (текущий размер стека) 
	int top;       // верхний элемент стека
	size_t capacity;  // размер массива стека
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
	//TStack(const TStack& s); а нужен ли конструктор копировани€ в классе стек?
	~TStack();                // очистка стека
	void push(const T& elem);      // вставка элемента
	void pop();               // извлечение (удаление) элемента
	T top_stack();            // просмотр верхнего элемента
	bool empty();             // проверка на пустоту
	int size();               // получение количества элементов в стеке
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