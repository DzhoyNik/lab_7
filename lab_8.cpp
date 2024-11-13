#include<iostream>
#include<fstream>
#include<string>
#include<limits>
#include<algorithm>

using namespace std;

int getCountLetter(char chFind) {
    char ch;
    fstream file("text.txt");
    int findChCounter = 0;

    while (file.get(ch)) {
        if (chFind == ch) {
            ++findChCounter;
        }
    }

    file.clear();
    file.seekg(0, std::ios::beg);

    return findChCounter;
}

int getCountCombination(string combinationFind) {
    string letter;
    fstream file("text.txt");
    int countCombinationFind = 0;

    while (getline(file, letter)) {
        size_t pos = 0;

        while ((pos = letter.find(combinationFind, pos)) != (string::npos)) {
            ++countCombinationFind;
            pos += combinationFind.length();
        }
    }

    file.clear();
    file.seekg(0, ios::beg);

    return countCombinationFind;
}


int main() {
    setlocale(LC_ALL, "RU");

    int choice;

    while (true) {
        cout << "1) Найти кол-во букв" << endl;
        cout << "2) Найти двубуквенные сочетания" << endl;
        cout << "3) Завершить программу" << endl;
        cout << "  Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            char chFind;

            cout << "Введите букву ";
            cin >> chFind;

            cout << getCountLetter(chFind) << endl;

            break;
        }
        case 2: {
            string combinationFind;
            cout << "Введите сочетание букв ";
            cin >> combinationFind;

            cout << getCountCombination(combinationFind) << endl;

            break;
        }
        case 3:
            return 0;
        }
    }
}