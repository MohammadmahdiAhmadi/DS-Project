#ifndef VECTORCLASS_H
#define VECTORCLASS_H


#include <iostream>
using namespace std;

template<class T>
class vectorClass {

	T* arr;
	int capacity;
	int current;

	void merge(long long int l, long long int m, long long int r);

public:
	vectorClass();
	vectorClass(int size);


	void push(T data);

	void push(T data, int index);

	void pushFront(T data);

	T get(int index);

	void pop();

	void pop(int index);

	bool search(T key);

	int size();

	int getcapacity();

	void print();

	void mergeSort(long long int l, long long int r);


};





template<class T>
vectorClass<T>::vectorClass()
{
	arr = new T[1];
	capacity = 1;
	current = 0;
}

template<class T>
vectorClass<T>::vectorClass(int size)
{
	arr = new T[size];
	capacity = size;
	current = 0;
}

template<class T>
void vectorClass<T>::push(T data)
{
	if (current == capacity) {
		T* temp = new T[2 * capacity];

		for (int i = 0; i < capacity; i++) {
			temp[i] = arr[i];
		}

		delete[] arr;
		capacity *= 2;
		arr = temp;

		temp = nullptr;
		delete[] temp;
	}

	arr[current] = data;
	current++;
}

template<class T>
void vectorClass<T>::push(T data, int index)
{
	if (index == capacity)
		push(data);
	else
		arr[index] = data;
}

template<class T>
void vectorClass<T>::pushFront(T data)
{
	if (current == capacity) {
		T* temp = new T[2 * capacity];

		temp[0] = data;
		for (int i = 0; i < capacity; i++) {
			temp[i + 1] = arr[i];
		}

		delete[] arr;
		capacity *= 2;
		arr = temp;

		temp = nullptr;
		delete[] temp;
	}
	else {
		T* temp = new T[capacity];

		temp[0] = data;
		for (int i = 1; i < capacity; i++) {
			temp[i] = arr[i - 1];
		}

		delete[] arr;
		arr = temp;

		temp = nullptr;
		delete[] temp;
	}

	current++;
}

template<class T>
T vectorClass<T>::get(int index)
{
	if (index < current)
		return arr[index];
}

template<class T>
void vectorClass<T>::pop()
{
	if (current == 0) {
		cout << endl << "This vector is empty. you cant pop!" << endl;
		return;
	}

	current--;

	if (current < capacity / 2) {
		T* temp = new T[capacity / 2];

		for (int i = 0; i < capacity / 2; i++) {
			temp[i] = arr[i];
		}

		delete[] arr;
		capacity /= 2;
		arr = temp;

		temp = nullptr;
		delete[] temp;
	}
}

template<class T>
void vectorClass<T>::pop(int index)
{
	if (current == 0) {
		cout << endl << "This vector is empty. you cant pop!" << endl;
		return;
	}

	for (int i = index; i < current; i++)
	{
		arr[i] = arr[i + 1];
	}
	current--;

	if (current < capacity / 2) {
		T* temp = new T[capacity / 2];

		for (int i = 0; i < capacity / 2; i++) {
			temp[i] = arr[i];
		}

		delete[] arr;
		capacity /= 2;
		arr = temp;

		temp = nullptr;
		delete[] temp;
	}

}

template<class T>
bool vectorClass<T>::search(T key)
{
	for (int i = 0; i < current; i++)
	{
		if (key == arr[i]) {
			return 1;
		}
	}
	return 0;
}

template<class T>
int vectorClass<T>::size()
{
	return current;
}

template<class T>
int vectorClass<T>::getcapacity()
{
	return capacity;
}

template<class T>
void vectorClass<T>::print()
{
	for (int i = 0; i < current; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T>
void vectorClass<T>::mergeSort(long long int l, long long int r)
{
	if (l < r) {

		long long int m = l + (r - l) / 2;

		mergeSort(l, m);
		mergeSort(m + 1, r);

		merge(l, m, r);
	}
}

template<class T>
void vectorClass<T>::merge(long long int l, long long int m, long long int r)
{
	long long int i, j, k;
	long long int n1 = m - l + 1;
	long long int n2 = r - m;

	T* L = new T[n1];
	T* R = new T[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];


	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}


	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}


#endif // VECTORCLASS_H
