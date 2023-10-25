#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <QVector>
#include <QPair>
#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

class ItemObject {
public:
    QJsonObject obj;
    QString objName;
};


class JsonManager : public QObject
{
    Q_OBJECT

public:
    explicit JsonManager(QObject *parent = nullptr);
    ~JsonManager();

    void setName(const QString projectName);
    void addItem(const QString itemName);
    void Open();
    void Close();
    bool save();
    bool load();

    void write(const QString itemName, const QString key, const QString value);
    QString read(const QString itemName, const QString key);

private:
    bool IsOpen();

    QString m_projectName = "void.json";
    QJsonObject m_mainObject; //!This variable keeps all json datas
    QFile m_file;

    QVector<ItemObject *> itemVect;

    bool m_IsOpen = false;
};

#endif // JSONMANAGER_H
