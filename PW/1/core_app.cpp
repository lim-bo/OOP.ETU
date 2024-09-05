#include "core_app.h"

CoreApp::CoreApp() {

}

int CoreApp::exec() {
    // Для машины и ос, на которой тестировалось приложение,
    // понадобились такие костыли
    setlocale(LC_ALL, "PL_pl.UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    short ch;
    // Array arr;
    while (true) {
        ch = mainMenu();
        switch (ch) {
        // Выход
        case 0:
            return 0;
        // Инициализация массива со значениями
        case 1:
            break;
        // Расчёт ско среднего и вывод
        case 2:
            break;
        // Сортировка
        case 3:
            switch (sortMenu()) {
            default:
                break;
            }
            break;
        // Изменение размера массива
        case 4:
            break;
        // Изменение выбранного элемента массива
        case 5:
        {
            short ind = elemIndex();
            break;
        }
        // Вывод элементов массива
        case 6:
            break;
        default:
            break;
        }
        waitForAction(ch);
    }
}

short CoreApp::mainMenu() {
    std::cout << "1.Заполнение массива значениями" << std::endl;
    std::cout << "2.Расчёт СКО среднего" << std::endl;
    std::cout << "3.Сортировка массива" << std::endl;
    std::cout << "4.Изменить размер массива" << std::endl;
    std::cout << "5.Изменение элемента по индексу" << std::endl;
    std::cout << "6.Вывод элементов массива" << std::endl;
    std::cout << "0.Выход" << std::endl << ">";
    short ch;
    std::cin >> ch;
    return ch;
}

void CoreApp::waitForAction(short debug) {
    std::cout << debug << std::endl;
    system("pause");
    system("clear");
}

short CoreApp::sortMenu() {
    std::cout << "1.По возрастанию" << std::endl;
    std::cout << "2.По убыванию" << std::endl << ">";
    short ch;
    std::cin >> ch;
    return ch;
}

short CoreApp::elemIndex() {
    short ind;
    std::cout << "Индекс элемента >";
    std::cin >> ind;
    return ind;
}
