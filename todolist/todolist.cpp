#include "Functions.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int k;
    cout << setw(78) << "ПРИЛОЖЕНИЕ СПИСОК ДЕЛ" << endl << endl;
    cout << "Сколько дел запланировано? Введите число:";
    while (!(cin >> k) || (cin.peek() != '\n') || k == 0)
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Некорректный ввод, попробуйте заново." << endl;
    }
    Dela* dela = new Dela[k];
    start(dela, k);
    menu(dela, k);
    return 0;
}


