#include "serverapp.h"
#include <QHostAddress>

int main(int argc, char *argv[])
{
    CommParams pars = {QHostAddress::LocalHost, QHostAddress::LocalHost, 8080, 8081};
    ServerApp a(pars, argc, argv);
    return a.exec();
}
