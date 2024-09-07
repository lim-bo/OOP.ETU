#include "core_app.h"

CoreApp::CoreApp() {

}

int CoreApp::exec() {
    // Для машины и ос, на которых тестировалось приложение,
    // понадобились такие костыли
    setlocale(LC_ALL, "PL_pl.UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    short ch;
    Array arr;
    while (true) {
        ch = mainMenu();
        switch (ch) {
        // Выход
        case 0:
            return 0;
        // Инициализация массива со значениями
        case 1:
        {
            unsigned size;
            std::cout << "Размер массива: ";
            std::cin >> size;
            arr = Array(size);
            number input;
            for (unsigned i = 0; i < size; i++) {
                std::cin >> input;
                arr.setAt(i, input);
            }
            break;
        }
        // Расчёт ср. значения, ско среднего и вывод
        case 2:
        {
            std::cout << "Среднее значение: " << arr.mean() << std::endl << "СКО среднего: " << arr.standartDeviation() << std::endl;
            break;
        }
        // Сортировка
        case 3:
            std::cout << "1.По возрастанию" << std::endl;
            std::cout << "2.По убыванию" << std::endl << ">";
            short ch;
            std::cin >> ch;
            switch (ch) {
            case 1:
                arr.sort(true);
                break;
            case 2:
                arr.sort(false);
                break;
            default:
                break;
            }
            std::cout << "Успешно"<< std::endl;
            break;
        // Изменение размера массива
        case 4:
        {
            unsigned size;
            std::cout << "Размер массива: ";
            std::cin >> size;
            arr.resize(size);
            break;
        }
        // Изменение выбранного элемента массива
        case 5:
        {
            unsigned ind;
            number value;
            std::cout << "Индекс элемента: ";
            std::cin >> ind;
            std::cout << "Значение: ";
            std::cin >> value;
            //  Обработка выхода за длину массива
            if (!arr.setAt(ind, value)) {
                std::cout << "Выход за длину массива" << std::endl;
            }
            break;
        }
        // Вывод элементов массива
        case 6:
            std::cout << arr;
            break;
        default:
            break;
        }
        waitForAction();
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

void CoreApp::waitForAction() {
    system("pause");
    system("cls");
}
