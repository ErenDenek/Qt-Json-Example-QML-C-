#include "jsonmanager.h"
#include <QJsonDocument>
#include <QDebug>

JsonManager::JsonManager(QObject *parent) : QObject(parent){

}

JsonManager::~JsonManager()
{
    Close();
}

void JsonManager::setName(const QString projectName){
    m_projectName = projectName;
}

void JsonManager::addItem(const QString itemName)
{
    bool isExist = false;

    for (const ItemObject *item : itemVect) {
        if (item->objName == itemName) {
            qDebug() << "Same Name!!!";
            isExist = true;
            break;
        }
    }

    if(!isExist){
        ItemObject* newItem = new ItemObject;
        newItem->objName = itemName;
        itemVect.append(newItem);
    }
}

void JsonManager::write(const QString itemName, const QString key, const QString value)
{
    for(int i = 0; i < itemVect.length(); i++)
    {
        if(itemVect[i]->objName == itemName)
        {
            itemVect[i]->obj[key] = value;
            break;
        }
    }
}

//void JsonManager::write(const QString itemName, const QString key, const int value)
//{

//}

QString JsonManager::read(const QString itemName, const QString key)
{
    QString retVal = "test";

    QFile readFile(m_projectName);
    readFile.open(QIODevice::ReadOnly);
    QByteArray data = readFile.readAll();

    QJsonDocument readDoc = QJsonDocument::fromJson(data);

    if (!readDoc.isNull())
    {
        QJsonObject readObject = readDoc.object();
        QJsonObject tempObj;

        tempObj = readObject[itemName].toObject();

        retVal =  tempObj[key].toString();
    }

    return retVal;
}

bool JsonManager::save()
{
    Open();

    if(IsOpen())
    {
        for (const ItemObject *item : itemVect) {
            m_mainObject[item->objName] = item->obj;
        }

        QJsonDocument jsonDoc(m_mainObject);

        m_file.resize(0);
        m_file.write(jsonDoc.toJson());

        Close();

        return true;
    }else{
        return false;
    }

    return false;
}

void JsonManager::Open()
{
    if(!IsOpen())
    {
        m_file.setFileName(m_projectName);

        if(m_file.open(QIODevice::ReadWrite)){
            m_IsOpen = true;
        }else{
            m_IsOpen = false;
        }
    }
}

void JsonManager::Close()
{
    if(IsOpen()){
        m_file.close();
        m_IsOpen = false;
    }
}

bool JsonManager::IsOpen()
{
    return m_IsOpen;
}


