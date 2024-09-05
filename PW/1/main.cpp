#include "core_app.h"
#include "locale"

int main()
{
    setlocale(LC_ALL, "ru");
    CoreApp a;

    return a.exec();
}
