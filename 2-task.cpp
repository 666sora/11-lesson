#include <iostream>

std::string firstString(std::string s, int firstStringLength) {
    std::string firstString = "";
    for (int i = 0; i < firstStringLength; i++) {
        firstString += s[i];
    }
    return firstString;
}

std::string secondString(std::string s, int startPosSecondString) {
    std::string secondString = "";
    startPosSecondString++;
    for (int i = startPosSecondString; i < s.length(); i++) {
        secondString += s[i];
    }
    return secondString;
}

int main() {
    bool correct = true;
    bool atChar = false;
    std::string dict = "!#$%&'*+-/=?^_`{|}~.";
    std::string s;
    std::cout << "Input email address: ";
    std::cin >> s;
    if (s[0] == '.' || s[s.length() - 1] == '.') correct = false;
    int firstStringLength;
    for (int i = 0; i < s.length() && correct; i++) {
        if (s[i] == '@' && !atChar) {
            atChar = true;
            firstStringLength = i;
        }
        else if (atChar && s[i] == '@') {
            correct = false;
        }
    }
    for (int i = 0; i < s.length() - 1 && correct; i++) {
        if (s[i] == '.' && s[i] == s[i + 1]) {
            correct = false;
        }
    }
    if (correct) {
        if (atChar == false) correct = false;
        std::string s1 = firstString(s, firstStringLength);
        std::string s2 = secondString(s, firstStringLength);
        if (s1.length() < 1 || s1.length() > 64) correct = false;
        if (s2.length() < 1 || s2.length() > 63) correct = false;
        if (s1[s1.length() - 1] == '.') correct = false;
        if (s2[0] == '.') correct = false;
        bool nonDict;
        for (int i = 0; i < s1.length() && correct; i++) {
            nonDict = false;
            for (int j = 0; j < dict.length() && !nonDict; j++) {
                if (s1[i] == dict[j]) {
                    nonDict = true;
                }
            }
            if ((s1[i] < 'A' || s1[i] > 'Z') && (s1[i] < 'a'
                    || s1[i] > 'z') && (s1[i] < '0' || s1[i] > '9') && !nonDict) {
                correct = false;
            }
        }
        for (int i = 0; i < s2.length() && correct; i++) {
            if ((s2[i] < 'A' || s2[i] > 'Z') && (s2[i] < 'a'
                    || s2[i] > 'z') && (s2[i] < '0' || s2[i] > '9')
                    && s2[i] != '-' && s2[i] != '.') {
                correct = false;
            }
        } 
    }
    if (correct) {
        std::cout << "Yes";
    }
    else {
        std::cout << "No";
    }
}

/*
Напишите программу, которая проверяет
корректность email-адреса, введённого пользователем.
Согласно международным требованиям, корректный email-адрес
должен состоять из двух частей, разделённых знаком @.
Первая часть должна иметь длину не менее одного и не более 64 символов,
вторая часть — не менее одного и не более 63 символов.
Из символов допускаются только английские буквы, цифры и знак «-»
(дефис), а также точка. Точка не может быть первым или последним символом,
а кроме того, две точки не могут идти подряд. В первой части (которая предшествует символу @),
кроме вышеперечисленных, разрешены ещё следующие символы:
!#$%&'*+-/=?^_`{|}~
Пользователь вводит строку, задающую email-адрес.
Программа должна вывести слово Yes, если адрес корректен,
а в противном случае — слово No.
*/