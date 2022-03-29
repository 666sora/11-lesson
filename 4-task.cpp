#include <iostream>

std::string findPart(std::string s, int part, int dotPos) {
    std::string string = "";
    int start, end;
    if (part == 1) {
        start = 0;
        end = dotPos;
    }
    else if (part == 2) {
        start = dotPos + 1;
        end = s.length();
    }
    for (int i = start; i < end; i++) {
        string += s[i];
    }
    return string;
}

int findDot(std::string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') {
            return i;
        }
    }
    return -1;
}

bool validation(std::string s, bool correct) {
    bool proper = true;
    bool value = false;
    bool point = false;
    bool minus = false;
    for (int i = 0; i < s.length() && proper == true; i++) {
        if (minus == false && s[0] == '-') {
            minus = true;
        }
        else if (s[i] == '-' && i != 0) {
            proper = false;
        }
        if (point == false && s[i] == '.') {
            point = true;
        }
        else if (s[i] == '.') {
            proper = false;
        }
        if ((s[i] > '9' || s[i] < '0') && (s[i] != 45 && s[i] != 46)) {
            proper = false;
        }
        if (s[i] <= '9' && s[i] >= '0') {
            value = true;
        }
    }
    if (proper && value) {
        return true;
    }
    else {
        return correct;
    }
}

int findValuePosForPart1(std::string s) {
    int i = 0;
    while (i < s.length()) {
        if (s[i] == '0' || s[i] == '-') {
            i++;
        }
        else if (s[i] != '0' && s[i] != '-') {
            return i;
        }
    }
}

std::string zeroForPart2(std::string s, int count) {
    for (int i = 0; i < count; i++) {
        s += '0';
    }
    return s;
}

int main() {
    bool correct = false;
    std::string s1, s2;
    while (!correct) {
        std::cout << "Input float numbers: " << std::endl;
        std::cin >> s1 >> s2;
        correct = validation(s1, correct);
        correct = validation(s1, correct);
        if (!correct) std::cout << "Invalid input" << std::endl;
    }
    int dotPos1 = findDot(s1), dotPos2 = findDot(s2);
    std::string s1Part1 = "";
    std::string s1Part2 = "";
    std::string s2Part1 = "";
    std::string s2Part2 = "";
    if (dotPos1 == 0) {
        s1Part1 += '0';
        for (int i = 1; i < s1.length(); i++) {
            s1Part2 += s1[i];
        }
    }
    else if (dotPos1 == -1) {
        s1Part1 = s1;
        s1Part2 += '0';
    }
    else {
        s1Part1 = findPart(s1, 1, dotPos1);
        s1Part2 = findPart(s1, 2, dotPos1);
    }
    ////////////////////
    if (dotPos2 == 0) {
        s2Part1 += '0';
        for (int i = 1; i < s2.length(); i++) {
            s2Part2 += s2[i];
        }
    }
    else if (dotPos2 == -1) {
        s2Part1 = s2;
        s2Part2 += '0';
    }
    else {
        s2Part1 = findPart(s2, 1, dotPos2);
        s2Part2 = findPart(s2, 2, dotPos2);
    }
    // std::cout << std::endl << dotPos1 << std::endl << dotPos2;
    // std::cout << std::endl << "1.1 " << s1Part1 << std::endl << "1.2 " << s1Part2 << std::endl
    //    << "2.1 " << s2Part1 << std::endl << "2.2 " << s2Part2;
    bool less = false, more = false, equal = false;
    if (s1Part1[0] == '-' && s2Part1[0] != '-') {
        less = true;
    }
    else if (s1Part1[0] != '-' && s2Part1[0] == '-') {
        more = true;
    }
    else if (s1Part1[0] != '-' && s2Part1[0] != '-') {
        int end = (s1Part1.length() >= s2Part1.length() ? s2Part1.length() : s1Part1.length());
        bool valueS1 = false, valueS2 = false;
        int i = findValuePosForPart1(s1Part1), j = findValuePosForPart1(s2Part1);
        for (int start = (i >= j ? j : i); start <= end && !more && !less; start++) {
            if (s1Part1[i] > s2Part1[j]) {
                more = true;
            }
            else if (s1Part1[i] < s2Part1[j]) {
                less = true;
            }
            else {
                i++;
                j++;
            }
        }
        equal = (!more && !less ? true : false);
        if (equal) {
            if (s1Part2.length() > s2Part2.length()) {
                s2Part2 = zeroForPart2(s2Part2, s1Part2.length() - s2Part2.length());
            }
            else if (s1Part2.length() < s2Part2.length()) {
                s1Part2 = zeroForPart2(s1Part2, s2Part2.length() - s1Part2.length());
            }
            int end = s1Part2.length();
            for (int k = 0; k < end && !less && !more; k++) {
                if (s1Part2[k] > s2Part2[k]) {
                    more = true;
                }
                else if (s1Part2[k] < s2Part2[k]) {
                    less = true;
                }
            }
        }
        if (less || more) {
            equal = false;
        }
    }
    else if (s1Part1[0] == '-' && s2Part1[0] == '-') {
        if (s1Part1.length() == 1 && s2Part1.length() == 1) {
            equal = true;
        }
        else if (s1Part1[0] == '-' && s1Part1.length() == 1 && s2Part1.length() > 1) {
            bool value = false;
            for (int i = 0; i < s2Part1.length() && !value; i++) {
                if (s2Part1[i] != '0') {
                    value = true;
                }
            }
            if (value) {
                more = true;
            }
            else {
                equal = true;
            }
        }
        else if (s2Part1[0] == '-' && s2Part1.length() == 1 && s1Part1.length() > 1) {
            bool value = false;
            for (int i = 0; i < s1Part1.length() && !value; i++) {
                if (s1Part1[i] != '0') {
                    value = true;
                }
            }
            if (value) {
                less = true;
            }
            else {
                equal = true;
            }
        }
        else if (s1Part1.length() > 1 && s2Part1.length() > 1) {
            int end = (s1Part1.length() >= s2Part1.length() ? s2Part1.length() : s1Part1.length());
            bool valueS1 = false, valueS2 = false;
            int i = findValuePosForPart1(s1Part1), j = findValuePosForPart1(s2Part1);
            for (int start = (i >= j ? j : i); start <= end && !more && !less; start++) {
                if (s1Part1[i] > s2Part1[j]) {
                    less = true;
                }
                else if (s1Part1[i] < s2Part1[j]) {
                    more = true;
                }
                else {
                    i++;
                    j++;
                }
            }
            equal = (!more && !less ? true : false);
        }
        if (equal) {
            if (s1Part2.length() > s2Part2.length()) {
                s2Part2 = zeroForPart2(s2Part2, s1Part2.length() - s2Part2.length());
            }
            else if (s1Part2.length() < s2Part2.length()) {
                s1Part2 = zeroForPart2(s1Part2, s2Part2.length() - s1Part2.length());
            }
            int end = s1Part2.length();
            for (int k = 0; k < end && !less && !more; k++) {
                if (s1Part2[k] > s2Part2[k]) {
                    less = true;
                }
                else if (s1Part2[k] < s2Part2[k]) {
                    more = true;
                }
            }
        }
        if (less || more) {
            equal = false;
        }
    }
    if (less) {
        std::cout << "Less";
    }
    if (more) {
        std::cout << "More";
    }
    if (equal) {
        std::cout << "Equal";
    }
}

/*
Вы продолжаете писать калькулятор, работающий
над вещественными числами повышенной точности.
Вы уже научились проверять корректность записи
вещественных чисел в виде строк, и теперь перед
вами новая цель — научиться сравнивать такие вещественные числа.

Пользователь вводит две строки, задающие вещественные
числа, в том же формате, как было описано в задаче
«Длинное вещественное число». Программа должна проверить
корректность ввода (для этого можно переиспользовать код,
написанный в задаче «Длинное вещественное число»), после чего
вывести слово Less, если первое число строго меньше второго;
слово More, если первое число строго больше второго; и слово
Equal, если введённые числа равны.
*/