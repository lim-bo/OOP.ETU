#ifndef CORE_APP_H
#define CORE_APP_H

#include <iostream>
#include <windows.h>
#include <locale>

class CoreApp {
    short mainMenu();
    short sortMenu();
    short elemIndex();
    void waitForAction(short);
public:
    CoreApp();
    int exec();
};

#endif // CORE_APP_H
