#include "application.h"
#include "communicator.h"

int main(int argc, char *argv[])
{
    CommParams pars{ QHostAddress::LocalHost, QHostAddress::LocalHost, 8081, 8080 };
    Application a(pars, argc, argv);
    return a.exec();
}
