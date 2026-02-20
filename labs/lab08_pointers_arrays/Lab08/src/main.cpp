#include <iostream>
#include <iomanip>
using namespace std;

#define SIZE 10
#define SIZE1 5
#define SIZE2 8
// Lab 08
// TODO: реализуйте решение по заданию в labs/lab08_pointers_arrays/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке
// Упражнение 1: объяснить использование типов/переменных в коде (без ввода).
    // TODO: при необходимости вывести пояснения/результаты.

    // Упражнение 2: найти ошибки в коде (без ввода).
    // TODO: при необходимости вывести пояснения/результаты.

    // Упражнение 3: заполнить массивы (10 элементов) разными способами.
    // TODO: реализуйте 4 варианта заполнения и выведите 10 значений для каждого.

    // Упражнение 4: линейный самоадресуемый список из 10 элементов.
    // TODO: сформируйте список и выведите элементы по порядку.
 int main() {
    cout << "=== Exercise 3.===" << endl;

    cout << "1. Static array, index addressing:" << endl;
    int staticArrIndex[SIZE];
    for (int i = 0; i < SIZE; i++) {
        staticArrIndex[i] = i * i;
    }
    for (int i = 0; i < SIZE; i++) {
        cout << staticArrIndex[i] << " ";
    }

    cout << "\n2. Static array, pointer addressing:" << endl;
    int staticArrPtr[SIZE];
    int* pStatic = staticArrPtr;
    for (int i = 0; i < SIZE; i++) {
        *(pStatic + i) = i * i;
    }
    for (int i = 0; i < SIZE; i++) {
        cout << *(pStatic + i) << " ";
    }

    cout << "\n3. Dynamic array, index addressing:" << endl;
    int* dynArrIndex = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        dynArrIndex[i] = i * i;
    }
    for (int i = 0; i < SIZE; i++) {
        cout << dynArrIndex[i] << " ";
    }
    delete[] dynArrIndex;

    cout << "\n4. Dynamic array, pointer addressing:" << endl;
    int* dynArrPtr = new int[SIZE];
    int* pDyn = dynArrPtr;
    for (int i = 0; i < SIZE; i++) {
        *(pDyn + i) = i * i;
    }
    for (int i = 0; i < SIZE; i++) {
        cout << *(pDyn + i) << " ";
    }
    delete[] dynArrPtr;

    cout << "\n\n=== Combining ordered arrays ===" << endl;

    int* arr1 = new int[SIZE1];
    int* arr2 = new int[SIZE2];
    int* result = new int[SIZE1 + SIZE2];

    for (int i = 0; i < SIZE1; i++) arr1[i] = i * 2;
    for (int i = 0; i < SIZE2; i++) arr2[i] = i * 2 + 1;

    cout << "Array 1: ";
    for (int i = 0; i < SIZE1; i++) cout << arr1[i] << " ";
    cout << "\nArray 2: ";
    for (int i = 0; i < SIZE2; i++) cout << arr2[i] << " ";

    int i = 0, j = 0, k = 0;
    int* pRes = result;

    while (i < SIZE1 && j < SIZE2) {
        if (arr1[i] < arr2[j]) {
            *(pRes + k) = arr1[i];
            i++;
        }
        else {
            *(pRes + k) = *(arr2 + j);
            j++;
        }
        k++;
    }

    while (i < SIZE1) {
        *(pRes + k) = arr1[i];
        i++; k++;
    }
    while (j < SIZE2) {
        *(pRes + k) = *(arr2 + j);
        j++; k++;
    }

    cout << "\nMerge result: ";
    for (int idx = 0; idx < (SIZE1 + SIZE2); idx++) {
        cout << *(result + idx) << " ";
    }

    delete[] arr1;
    delete[] arr2;
    delete[] result;

    cout << "\n\nMemory cleared. The program is completed." << endl;

    //4 упражнение

struct Node {
    int data;
    Node* prev;
    Node* next;
};

    Node* head = nullptr;
    Node* tail = nullptr;
    const int COUNT = 10;

    cout << "\n\n=== Doubly linked list ===" << endl;

    for (int i = 1; i <= COUNT; i++) {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->prev = tail;
        newNode->next = nullptr;

        if (tail != nullptr) {
            tail->next = newNode;
        }
        else {
            head = newNode;
        }

        tail = newNode;
    }

    cout << "--------------------------------------------------------------------------------" << endl;
    cout << setw(5) << "Index" << " | "
        << setw(5) << "Data" << " | "
        << setw(18) << "Element Address" << " | "
        << setw(18) << "Prev Address" << " | "
        << setw(18) << "Next Address" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    Node* current = head;
    int index = 1;

    while (current != nullptr) {
        cout << setw(5) << index << " | "
            << setw(5) << current->data << " | "
            << setw(18) << current << " | "
            << setw(18) << current->prev << " | "
            << setw(18) << current->next << endl;

        current = current->next;
        index++;
    }

    cout << "--------------------------------------------------------------------------------" << endl << endl;

    cout << "=== LIST STRUCTURE ===" << endl;
    cout << "NULL";

    current = head;
    while (current != nullptr) {
        cout << " <- [" << current->data << "] -> ";
        current = current->next;
    }

    cout << "NULL" << endl << endl;

    cout << "=== Forward ===" << endl;
    current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl << endl;

    cout << "=== Backward ===" << endl;
    current = tail;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;

    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    cout << "\nMemory cleared. The program is completed." << endl;

    return 0;
}