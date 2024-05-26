#include <iostream>

int lenghtStr1(const char*);
int lenghtStr2(const char*);
int lenghtStr3(const char*);
void copyStr(char*, const char*);
int comparyStr(const char*, const char*);
void concatStr(char*, const char*);

int main() {
    char str1[] = "qwerty";
    char str2[] = "1234567890";
    char str3[100];

    std::cout << "Znachenie str1: " << str1 << std::endl;
    std::cout << "Znachenie str2: " << str2 << std::endl;
    std::cout << "Znachenie str3: " << str3 << std::endl;


    std::cout << "____________________________ " << std::endl;
    std::cout <<  std::endl;
 


    std::cout << "Funkciya lenghtStr1(). Dlina str1=" << lenghtStr1(str1) << ", str2=" << lenghtStr1(str2) << std::endl;
    std::cout << "Funkciya lenghtStr2(). Dlina str1=" << lenghtStr2(str1) << ", str2=" << lenghtStr2(str2) << std::endl;
    std::cout << "Funkciya lenghtStr3(). Dlina str1=" << lenghtStr3(str1) << ", str2=" << lenghtStr3(str2) << std::endl;

    std::cout <<  std::endl;
    copyStr(str3, str1);
    std::cout << "Kopirovanie str1 v str3. str3 = " << str3 << std::endl;

    std::cout <<  std::endl;

    std::cout << "Esli stroki ravny vyvodit 0, inache otricateloe ili polozhitelnoe chislo" << std::endl;
    int result = comparyStr(str1, str2);
    std::cout << "Rezultat sravneniya str1 i str2: " << result << std::endl;
    result = comparyStr(str1, str3);
    std::cout << "Rezultat sravneniya str1 i str3: " << result << std::endl;


    std::cout <<  std::endl;

    concatStr(str1, str2);
    std::cout << "Rezultat konkatenacii strok str1 i str2: " << str1 << std::endl;

    return 0;
}

// Реализация функций
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

void copyStr(char* dest, const char* src) {
    while ((*dest++ = *src++));
}

int comparyStr(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

void concatStr(char* dest, const char* src) {
    while (*dest) dest++;
    while ((*dest++ = *src++));
}