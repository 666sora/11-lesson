#include <iostream>

std::string findString(std::string s, int pos1, int pos2) {
    std::string string = "";
    pos1 += (pos1 == 0 ? 0 : 1);
    for (int i = pos1; i < pos2; i++) {
        string += s[i];
    }
    return string;
}

bool validation(std::string s, bool correct) {
    if (s.length() > 1 && s[0] == '0') {
        return false;
    }
    else if (s.length() == 3 && (s[0] > '2'
        || (s[0] == '2' && s[1] > '5')
        || (s[0] == '2' && s[1] == '5' && s[2] > '5'))) {
        return false;
    }
    else {
        return correct;
    }
}

int main() {
    bool correct = true;
    std::string s;
    std::cout << "Input IP address: ";
    std::cin >> s;
    if ((s[0] < '0' || s[0] > '9') ||
        (s[s.length() - 1] < '0' || s[s.length() - 1] > '9')) {
        correct = false;
    }
    int dotPos1, dotPos2, dotPos3, counter = 1;
    for (int i = 0; i < s.length() - 1 && correct; i++) {
        if ((s[i] < '0' || s[i] > '9') && s[i] != '.') {
            correct = false;
        }
        if (s[i] == '.' && s[i] == s[i + 1]) {
            correct = false;
        }
        if (s[i] == '.' && counter == 1 && correct) {
            dotPos1 = i;
            counter++;
        }
        else if (s[i] == '.' && counter == 2 && correct) {
            dotPos2 = i;
            counter++;
        }
        else if (s[i] == '.' && counter == 3 && correct) {
            dotPos3 = i;
            counter++;
        }
    }
    correct = (counter == 4 ? true : false);
    if (correct) {
        std::string s1 = findString(s, 0, dotPos1);
        std::string s2 = findString(s, dotPos1, dotPos2);
        std::string s3 = findString(s, dotPos2, dotPos3);
        std::string s4 = findString(s, dotPos3, s.length());
        correct = validation(s1, correct);
        correct = validation(s2, correct);
        correct = validation(s3, correct);
        correct = validation(s4, correct);
    }

    if (correct) {
        std::cout << "Yes";
    }
    else {
        std::cout << "No";
    }
}

/*
Проверьте, задаёт ли введённая пользователем строка корректный IP-адрес четвёртой версии (IPv4).
IP-адрес должен представлять из себя четыре числа, разделённые точками
без пробелов, причём каждое число должно быть в диапазоне от 0 до 255 включительно.
Числа не должны содержать ведущих нулей. Других символов в строке,
кроме вышеописанных, присутствовать не должно.
Пользователь вводит строку, задающую ip-адрес.
Программа должна вывести слово Yes, если адрес
корректен, и слово No, если это не так.
*/