#include <iostream>

std::string encrypt_caesar(int n, std::string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if (s[i] + n < 'A') {
                s[i] = ('Z' - ('A' - (s[i] + n))) + 1;
            }
            else if (s[i] + n > 'Z') {
                s[i] = ('A' + ((s[i] + n) - 'Z')) - 1;
            }
            else {
                s[i] += n;
            }
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (s[i] + n < 'a') {
                s[i] = ('z' - ('a' - (s[i] + n))) + 1;
            }
            else if (s[i] + n > 'z') {
                s[i] = ('a' + ((s[i] + n) - 'z')) - 1;
            }
            else {
                s[i] += n;
            }
        }
    }
    return s;
}

std::string decrypt_caesar (int n, std::string s) {
    n = -n;
    return encrypt_caesar(n, s);
}

int main() {
    int n;
    std::string s;
    bool correct;
    do {
        correct = true;
        std::cout << "Input shift: " << std::endl;
        std::cin >> n;
        if (/*std::cin.fail() ||*/ n == 0) {
            correct = false;
            // std::cin.clear();
            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong shift input!" << std::endl;
        }
    } while (!correct);
    do {
        correct = true;
        std::cout << "Input string: " << std::endl;
        std::cin >> s;
        for (int i = 0; i < s.length() && correct; i++) {
            if ((s[i] < 'A' || s[i] > 'Z')
                && (s[i] < 'a' || s[i] > 'z')) {
                correct = false;
                std::cout << "Wrong string input!" << std::endl;
            }
        }
    } while (!correct);
    do {
        correct = true;
        char answer;
        std::cout << "Choice from encrypt or decrypt(e/d)";
        std::cin >> answer;
        if (answer == 'e') {
            std::cout << encrypt_caesar(n, s);
        }
        else if (answer == 'd') {
            std::cout << decrypt_caesar(n, s);
        }
        else {
            std::cout << "Error answer input!" << std::endl;
            correct = false;
        }
    } while (!correct);
    return 0;
}

/*
Что нужно сделать
В древности для шифрования сообщений использовался такой способ:
все буквы в сообщении сдвигались на одно и то же число позиций в алфавите.
Число позиций могло быть как положительным, так и отрицательным и являлось
параметром шифра. Если для сдвига на данное число позиций алфавита не хватает,
то он зацикливается (то есть буква с номером 27 — это снова буква «a», буква
с номером 28 — это «b» и так далее).

Например, слово abracadabra при сдвиге на 10 позиций превратится в klbkmknklbk.
Этот простейший шифр называется шифром Цезаря. Регистр букв (заглавные и строчные) менять не нужно.
Напишите функцию encrypt_caesar от строки и числа, которая возвращает исходную строку, зашифрованную шифром Цезаря с
параметром, равным данному числу. Также напишите функцию decrypt_caesar, выполняющую обратное преобразование.
Считаем, что входные строки состоят лишь из английских букв; если там содержатся и другие символы, то их надо игнорировать.
*/