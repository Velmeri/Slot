#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Queue
{
	// Очередь
	int* Wait;
	// Максимальный размер очереди
	int MaxQueueLength;
	// Текущий размер очереди
	int QueueLength;

public:
	// Конструктор
	Queue(int m);

	//Деструктор
	~Queue();

	// Добавление элемента
	void Add(int c);

	// Извлечение элемента
	//int Extract();
	void Extract();

	// Очистка очереди
	void Clear();

	// Проверка существования элементов в очереди
	bool IsEmpty();

	// Проверка на переполнение очереди
	bool IsFull();

	// Количество элементов в очереди
	int GetCount();

	//демонстрация очереди
	void Show();

	int GetNum();
};

void Queue::Show() {
	cout << "\n\t-------------------------------------\n";
	//демонстрация очереди
	cout << '\t';
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << ' ';
	}
	cout << "\n\t-------------------------------------\n";
}

inline int Queue::GetNum()
{
	int num =  Wait[0];
	this->Extract();
	return num;
}

Queue::~Queue()
{
	//удаление очереди
	delete[]Wait;
}

Queue::Queue(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new int[MaxQueueLength];
	// Изначально очередь пуста
	QueueLength = 0;
}

void Queue::Clear()
{
	// Эффективная "очистка" очереди 
	QueueLength = 0;
}

bool Queue::IsEmpty()
{
	// Пуст?
	return QueueLength == 0;
}

bool Queue::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}

int Queue::GetCount()
{
	// Количество присутствующих в стеке элементов
	return QueueLength;
}

void Queue::Add(int c)
{
	// Если в очереди есть свободное место, то увеличиваем количество
	// значений и вставляем новый элемент
	if (!IsFull())
		Wait[QueueLength++] = c;
}
//
//int Queue::Extract()
//{
//	// Если в очереди есть элементы, то возвращаем тот, 
//	// который вошел первым и сдвигаем очередь	
//	if (!IsEmpty()) {
//		//запомнить первый
//		int temp = Wait[0];
//
//		//сдвинуть все элементы
//		for (int i = 1; i < QueueLength; i++)
//			Wait[i - 1] = Wait[i];
//
//		//уменьшить количество
//		QueueLength--;
//
//		//вернуть первый(нулевой)
//		return temp;
//	}
//
//	else // Если в стеке элементов нет
//		return -1;
//}


void Queue::Extract()
{
	// Если в очереди есть элементы, то возвращаем тот, 
	// который вошел первым и сдвигаем очередь	
	if (!IsEmpty())
	{
		//запомнить первый
		int temp = Wait[0];

		//сдвинуть все элементы
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];

		Wait[QueueLength - 1] = temp;
	}

}