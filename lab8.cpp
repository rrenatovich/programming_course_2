#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;

// 1 СПОСОБ
    int arr1[SIZE];

    cout << "Статический массив + индексы: ";
    for (int i = 0; i < SIZE; i++) {
        arr1[i] = i * i;
        cout << arr1[i] << " ";
    }
    cout << endl;

// 2 СПОСОБ
    int arr2[SIZE];

    int* ptr2 = arr2;

    cout << "Статический массив + указатели: ";
    for (int i = 0; i < SIZE; i++) {
        *ptr2 = i * i;  
        cout << *ptr2 << " ";
        ptr2++; 
    }
    ptr2 = arr2;
    cout << endl;

// 3 СПОСОБ
    int* arr3 = new int[SIZE];

    cout << "Динамический массив + индексы: ";
    for (int i = 0; i < SIZE; i++) {
        arr3[i] = i * i;
        cout << arr3[i] << " ";
    }
    delete[] arr3;
    cout << endl;

// 4 СПОСОБ
    int* arr4 = new int[SIZE];

    int* ptr4 = arr4;
    int* begin4 = arr4;

    cout << "Динамический массив + указатели: ";
    for (int i = 0; i < SIZE; i++) {
        *ptr4 = i * i;
        cout << *ptr4 << " ";
        ptr4++;
    }
    
    ptr4 = begin4;
    cout << endl;

    
}