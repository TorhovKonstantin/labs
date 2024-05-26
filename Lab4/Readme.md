# Лабораторная работа №4

Задача 1.

Познакомиться с библиотечными функциями работы со строками:
1) strlen() - определение длины строки
2) strcat() - конкатенация строк
3) strcpy() - копирование строк
4) strcmp() - сравнение строк


Задача 2.

Написать программу которая будет использовать свои варианты следующих функций:
1) определения длины строки (тремя разными способами)
2) копирования строк
3) сравнения строк
4) конкатенации строк

   Функции для определения длины строки:
   
```c++
int lenghtStr1(const char* str) {
    int length = 0;
    while (*str++) length++;
    return length;
}

int lenghtStr2(const char* str) {
    int length = 0;
    for (; str[length] != '\0'; length++);
    return length;
}

int lenghtStr3(const char* str) {
    const char* s = str;
    while (*s) ++s;
    return s - str;
}
```

  Функция копирования строк:
  
```c++
int comparyStr(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}
```

  Функция конкатенации строк:

```c++
  void concatStr(char* dest, const char* src) {
    while (*dest) dest++;
    while ((*dest++ = *src++));
}
```

Код исходной программы: https://github.com/TorhovKonstantin/labs/blob/main/Lab4/lab4.1.cpp

Результаты решения:

![image](https://github.com/TorhovKonstantin/labs/assets/122263721/d8730711-5c3a-442e-85b0-60abdd47a899)

Задача 3.

Переписать функции так, что бы они использовали динамическую память при задании строк:

![image](https://github.com/TorhovKonstantin/labs/assets/122263721/8cb7df6e-f4e3-4b1b-bbd9-d0dfaa255089)

Код исходной программы: https://github.com/TorhovKonstantin/labs/blob/main/Lab4/lab4.2.cpp

Результаты решения:

![image](https://github.com/TorhovKonstantin/labs/assets/122263721/4f4cb1d9-a88f-49b7-98c9-c45ce90a9b73)


Задача 4.

Изменить программу так, что бы вместо malloc() использовалась функция calloc(). В чем сходство и различие этих функций:
Разница между malloc() и calloc() заключается в том:

Что malloc() выделяет память но не инициализирует её. А calloc() выделяет и инициализирует её.

Код исходной программы: https://github.com/TorhovKonstantin/labs/blob/main/Lab4/lab4.3.cpp

Результаты решения:

![image](https://github.com/TorhovKonstantin/labs/assets/122263721/e0f4db79-5559-4e92-8301-06413d24add6)
