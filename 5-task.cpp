#include <iostream>
#include <string>
#include <cmath>
char findElementForX(std::string s1, std::string s2, std::string s3, int x, int y) {
    if (y == 0) {
        return s1[x];
    }
    else if (y == 1) {
        return s2[x];
    }
    else if (y == 2) {
        return s3[x];
    }
    else {
        return -1;
    }
}
char findElementForY(std::string s1, std::string s2, std::string s3, int x, int y) {
    return findElementForX(s1, s2, s3, y, x);
}
int findWinner(std::string s1, std::string s2, std::string s3, char symbol) {
    int counterX = 0, counterY = 0, counterXY = 0, counterYX = 0;
    bool win = false;
    for (int y = 0; y < 3; y++) {
        counterX = 0;
        counterY = 0;
        char element;
        for (int x = 0; x < 3; x++) {
            element =  findElementForX(s1, s2, s3, x, y);
            if (element == symbol) {
                counterX++;
            }
            element = findElementForY(s1, s2, s3, x, y);
            if (element == symbol) {
                counterY++;
            }
        }
        element = findElementForX(s1, s2, s3, y, y);
        if (element == symbol) {
            counterXY++;
        }
        element = findElementForX(s1, s2, s3, abs(y - 2), y);
        if (element == symbol) {
            counterYX++;
        }
        //
        if (counterXY == 3 && !win) {
            win = true;
        }
        else if (counterXY == 3 && win) {
            return -1;
        }
        if (counterYX == 3 && !win) {
            win = true;
        }
        else if (counterYX == 3 && win) {
            return -1;
        }
        if (counterX == 3 && !win) {
            win = true;
        }
        else if (counterX == 3 && win) {
            return -1;
        }
        if (counterY == 3 && !win) {
            win = true; 
        }
        else if (counterY == 3 && win) {
            return -1;
        }
    }
    if (win) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    std::string s1, s2, s3;
    std::cout << "Input strings: " << std::endl;
    std::cin >> s1 >> s2 >> s3;
    bool correct = true;
    int countX = 0, countO = 0;
    for (int y = 0; y < 3 && correct; y++) {
        for (int x = 0; x < 3 && correct; x++) {
            char element = findElementForX(s1, s2, s3, x, y);
            correct = (element != 'O' && element != 'X' && element != '.' ? false : correct);
            countX += (element == 'X' ? 1 : 0);
            countO += (element == 'O' ? 1 : 0);
        }
    }
    if (countX < countO) {
        correct = false;
    }
    int vanya, petya;
    if (correct) {
        vanya = findWinner(s1, s2, s3, 'O');
        petya = findWinner(s1, s2, s3, 'X');
        if (vanya == -1 || petya == -1) {
            correct = false;
        }
        else if (vanya == 1 && petya == 1) {
            correct = false;
        }
        else if ((vanya == 1 && petya == 0) 
                || (vanya == 0 && petya == 1)) {
            if (vanya == 1 && countO >= countX) {
                correct = false;
            }
            else if (petya == 1 && countX > countO) {
                correct = false;
            } 
        }
    }
    if (!correct) {
        std::cout << "Incorrect";
    }
    else if (vanya == 0 && petya == 0) {
        std::cout << "Nobody";
    }
    else if (vanya == 1) {
        std::cout << "Vanya won";
    }
    else if (petya == 1) {
        std::cout << "Petya won";
    }
}

/*
Петя и Вася играли в крестики-нолики и не стёрли результаты своей игры.
Теперь перед вами табличка 3 × 3, которая осталась после их поединка. Вы хотите понять,
выиграл ли кто-то из них или они не доиграли.
На вход программе даётся три строки, кодирующие верхнюю, среднюю и нижнюю
строчки игрового поля. Крестик обозначается символом X (английская заглавная буква X),
нолик — символом O (заглавная латинская буква O), пустая клетка — точкой.
Если ввод некорректен, то есть такая таблица не могла получиться в ходе
настоящей игры, то надо написать в ответ слово Incorrect.
Если таблица корректна и выиграли крестики, то нужно вывести
в ответ слова petya won, если нолики — то vanya won, а иначе
(то есть они не доиграли или сыграли вничью) надо написать Nobody.
*/
