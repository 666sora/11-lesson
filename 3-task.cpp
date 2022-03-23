#include <iostream>

std::string findString(std::string s, int pos1, int pos2) {
    std::string string = "";
    pos1 += (pos1 == 0 ? 0 : 1);
    for (int i = pos1; i < pos2; i++) {
        string += s[i];
    }
    return string;
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
        std::string s4 = findString(s, dotPos3, (s.length()));
        /////////////////////////
        correct = (s1.length() > 1 && s1[0] == '0' ? false : correct);
        correct = (s2.length() > 1 && s2[0] == '0' ? false : correct);
        correct = (s3.length() > 1 && s3[0] == '0' ? false : correct);
        correct = (s4.length() > 1 && s4[0] == '0' ? false : correct);
        /////////////////////////
        correct = (s1.length() == 3 && (s1[0] > '2' 
        || (s1[0] == '2' && s1[1] > '5') 
        || (s1[0] == '2' && s1[1] == '5' && s1[2] > '5')) ? false : correct);
        /////////////////////////
        correct = (s2.length() == 3 && (s2[0] > '2' 
        || (s2[0] == '2' && s2[1] > '5') 
        || (s2[0] == '2' && s2[1] == '5' && s2[2] > '5')) ? false : correct);
        /////////////////////////
        correct = (s3.length() == 3 && (s3[0] > '2' 
        || (s3[0] == '2' && s3[1] > '5') 
        || (s3[0] == '2' && s3[1] == '5' && s3[2] > '5')) ? false : correct);
        /////////////////////////
        correct = (s4.length() == 3 && (s4[0] > '2' 
        || (s4[0] == '2' && s4[1] > '5') 
        || (s4[0] == '2' && s4[1] == '5' && s4[2] > '5')) ? false : correct);
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