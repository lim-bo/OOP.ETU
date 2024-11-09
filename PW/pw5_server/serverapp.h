#ifndef SERVERAPP_H
#define SERVERAPP_H

#include <QCoreApplication>
#include "communicator.h"
#include <string>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include "polynom.h"
#include "number.h"
#include "array.h"


class ServerApp : public QCoreApplication
{
    Q_OBJECT
    Communicator* com;
    Polynomial pol;
public:
    ServerApp(CommParams& pars, int argc, char *argv[]);
    ~ServerApp();
signals:
    void send(QByteArray);
private slots:
    void processMsg(QByteArray);
};

#endif // SERVERAPP_H
