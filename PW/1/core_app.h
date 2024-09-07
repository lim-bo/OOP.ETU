#ifndef CORE_APP_H
#define CORE_APP_H

#include <iostream>
#include <windows.h>
#include <locale>
#include "array.h"

class CoreApp {
    inline short mainMenu();
    inline void waitForAction();
public:
    CoreApp();
    int exec();
};

#endif // CORE_APP_H
