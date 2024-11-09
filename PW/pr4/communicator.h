#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H
#include <QObject>
#include <QUdpSocket>

struct CommParams {
    QHostAddress senderHost;
    QHostAddress recieverHost;
    quint32 senderPort;
    quint32 recieverPort;
};

class Communicator : public QUdpSocket
{
    Q_OBJECT
public:
    Communicator(CommParams&, QWidget*);
    bool isReady();
private:
    CommParams par;
    bool readyToRecieve;
signals:
    void recieved(QByteArray);

public slots:
    void send(QByteArray);

private slots:
    void recieve();

};

#endif // COMMUNICATOR_H
