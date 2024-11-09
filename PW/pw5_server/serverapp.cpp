#include "serverapp.h"

ServerApp::ServerApp(CommParams& comPars, int argc, char *argv[]) : QCoreApplication(argc, argv) {
    com = new Communicator(comPars);
    if (com->isReady()) {
        connect(com, &Communicator::recieved, this, &ServerApp::processMsg);
        connect(this, &ServerApp::send, com, &Communicator::send);
    }
    pol = Polynomial();
}

ServerApp::~ServerApp() {
    if (com != nullptr)
        delete com;
}

void ServerApp::processMsg(QByteArray bytes) {
    QJsonDocument msg = QJsonDocument::fromJson(bytes);
    QJsonDocument resp;
    QJsonObject response;
    response["option"] = msg["option"].toInt();
    switch (msg["option"].toInt()) {
    case 1:
    {
        if (!msg["values"].isArray()) return;
        QJsonArray nums = msg["values"].toArray();
        Array roots(nums.size() - 1);
        for (int i = 1; i < nums.size(); i++) {
            roots.setAt(i - 1, number(nums[i].toString().toStdString()));
        }
        pol = Polynomial(number(nums[0].toString().toStdString()), roots);
        response["message"] = QJsonValue("success");
        resp.setObject(response);
        emit send(resp.toJson());
        break;
    }
    case 2:
    {
        if (!msg["values"].isArray()) return;
        QJsonArray vals = msg["values"].toArray();
        int idx = vals[0].toInt();
        QString val = vals[1].toString();
        if (idx == -1) {
            pol.setHigherCoeff(number(val.toStdString()));
        } else {
            pol.setRoot(idx, number(val.toStdString()));
        }
        response["message"] = QJsonValue("success");
        resp.setObject(response);
        emit send(resp.toJson());
        break;
    }
    case 3:
    {
        QString x = msg["x"].toString();
        number result = pol.evaluate(number(x.toStdString()));
        response["message"] = QJsonValue(QString::fromStdString(result.string()));
        resp.setObject(response);
        emit send(resp.toJson());
        break;
    }
    case 4:
    {
        int size = msg["size"].toInt();
        pol.resizeRoots(unsigned(size));
        response["message"] = QJsonValue("success");
        resp.setObject(response);
        emit send(resp.toJson());
        break;
    }
    case 5:
    {
        QString withRoots = QString::fromStdString(pol.StringRepresentWithRoots()), withCfs = QString::fromStdString(pol.StringRepresentWithCoeff());
        response["message"] = QJsonValue(withRoots + "\n" + withCfs);
        resp.setObject(response);
        emit send(resp.toJson());
        break;
    }
    default:
        response["message"] = QJsonValue("unsupported option");
        resp.setObject(response);
        emit send(resp.toJson());
    }
}
