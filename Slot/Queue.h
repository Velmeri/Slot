#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Queue
{
	// �������
	int* Wait;
	// ������������ ������ �������
	int MaxQueueLength;
	// ������� ������ �������
	int QueueLength;

public:
	// �����������
	Queue(int m);

	//����������
	~Queue();

	// ���������� ��������
	void Add(int c);

	// ���������� ��������
	//int Extract();
	void Extract();

	// ������� �������
	void Clear();

	// �������� ������������� ��������� � �������
	bool IsEmpty();

	// �������� �� ������������ �������
	bool IsFull();

	// ���������� ��������� � �������
	int GetCount();

	//������������ �������
	void Show();

	int GetNum();
};

void Queue::Show() {
	cout << "\n\t-------------------------------------\n";
	//������������ �������
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
	//�������� �������
	delete[]Wait;
}

Queue::Queue(int m)
{
	//�������� ������
	MaxQueueLength = m;
	//������� �������
	Wait = new int[MaxQueueLength];
	// ���������� ������� �����
	QueueLength = 0;
}

void Queue::Clear()
{
	// ����������� "�������" ������� 
	QueueLength = 0;
}

bool Queue::IsEmpty()
{
	// ����?
	return QueueLength == 0;
}

bool Queue::IsFull()
{
	// �����?
	return QueueLength == MaxQueueLength;
}

int Queue::GetCount()
{
	// ���������� �������������� � ����� ���������
	return QueueLength;
}

void Queue::Add(int c)
{
	// ���� � ������� ���� ��������� �����, �� ����������� ����������
	// �������� � ��������� ����� �������
	if (!IsFull())
		Wait[QueueLength++] = c;
}
//
//int Queue::Extract()
//{
//	// ���� � ������� ���� ��������, �� ���������� ���, 
//	// ������� ����� ������ � �������� �������	
//	if (!IsEmpty()) {
//		//��������� ������
//		int temp = Wait[0];
//
//		//�������� ��� ��������
//		for (int i = 1; i < QueueLength; i++)
//			Wait[i - 1] = Wait[i];
//
//		//��������� ����������
//		QueueLength--;
//
//		//������� ������(�������)
//		return temp;
//	}
//
//	else // ���� � ����� ��������� ���
//		return -1;
//}


void Queue::Extract()
{
	// ���� � ������� ���� ��������, �� ���������� ���, 
	// ������� ����� ������ � �������� �������	
	if (!IsEmpty())
	{
		//��������� ������
		int temp = Wait[0];

		//�������� ��� ��������
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];

		Wait[QueueLength - 1] = temp;
	}

}