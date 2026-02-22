#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void demchar() {
    cout << "char" << endl;
    
    // длина
    char str1[] = "hello";
    cout << "1. strlen: " << strlen(str1) << endl;
    
    // копирование
    char str2[20];
    strcpy(str2, str1);
    cout << "2. strcpy: " << str2 << endl;

    // соединение
    strcat(str2, " world");
    cout << "3. strcat: " << str2 << endl;

}


void demstring() {
    cout << "\nstring" << endl;

    //длина
    string s1 = "hello";
    cout << "1. lenght: " << s1.length() << endl;

    //добавление
    s1.append(" world");
    cout << "2. append: " << s1 << endl;

    //извлечение
    string s2 = s1.substr(0,5);
    cout << "3. substr: " << s2 << endl;

}

int main() {
    demchar();
    demstring();
}