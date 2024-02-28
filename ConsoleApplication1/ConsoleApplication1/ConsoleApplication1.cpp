#include <iostream>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

//переворот слова задом наперед
string reverse(const string& word) {
    string reversed_word = word;
    reverse(reversed_word.begin(), reversed_word.end());
    return reversed_word;
}

// удаление гласных букв
string removeVowels(const string& word) {
    string result = word;
    string vowels = "AEIOUaeiouАЕЁИОУЫЭЮЯаеёиоуыэюя";
    result.erase(remove_if(result.begin(), result.end(), [&](char c) {
        return vowels.find(c) != string::npos;
        }), result.end());
    return result;
}

//удаление согласных букв
string removeConsonants(const string& word) {
    string result = word;
    string consonants = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyzБВГДЖЗЙКЛМНПРСТФХЦЧШЩбвгджзйклмнпрстфхцчшщ";
    result.erase(remove_if(result.begin(), result.end(), [&](char c) {
        return consonants.find(c) != string::npos;
        }), result.end());
    return result;
}

//Белиберда
string shuffle(const string& word) {
    string shuffled_word = word;
    random_device rd;
    mt19937 g(rd());
    shuffle(shuffled_word.begin(), shuffled_word.end(), g);
    return shuffled_word;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string word;
    cout << "Введите слово: ";
    cin >> word;

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Вывести слово задом наперед.\n";
        cout << "2. Вывести слово без гласных.\n";
        cout << "3. Вывести слово без согласных.\n";
        cout << "4. Рандомно раскидать буквы заданного слова.\n";
        cout << "0. Выйти.\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Слово задом наперед: " << reverse(word) << "\n";
            break;
        case 2:
            cout << "Слово без гласных: " << removeVowels(word) << "\n";
            break;
        case 3:
            cout << "Слово без согласных: " << removeConsonants(word) << "\n";
            break;
        case 4:
            cout << "Рандомно раскиданные буквы: " << shuffle(word) << "\n";
            break;
        case 0:
            cout << "До свидания!\n";
            break;
        default:
            cout << "Некорректный выбор. Попробуйте еще раз.\n";
        }
    } while (choice != 0);

    return 0;
}
