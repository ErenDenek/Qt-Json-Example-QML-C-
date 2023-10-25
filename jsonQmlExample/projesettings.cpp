#include "projesettings.h"
#include "jsonmanager.h"

ProjeSettings::ProjeSettings()
{
    m_json.addItem("coordinants");
    m_json.setName("example.json");
}

void ProjeSettings::save()
{
    m_json.save();
}

void ProjeSettings::load()
{
    m_x = m_json.read("coordinants", "X");
    m_y = m_json.read("coordinants", "Y");
    m_z = m_json.read("coordinants", "Z");

    emit xChanged();
    emit yChanged();
    emit zChanged();
}

void ProjeSettings::setName(const QString projectName)
{
    m_json.setName(projectName);
}

QString ProjeSettings::getX() const{
    return m_x;
}

void ProjeSettings::setX(const QString &value){
    m_json.write("coordinants", "X", value);
}

QString ProjeSettings::getY() const{
    return m_y;
}

void ProjeSettings::setY(const QString &value){
    m_json.write("coordinants", "Y", value);
}

QString ProjeSettings::getZ() const{
    return m_z;
}

void ProjeSettings::setZ(const QString &value){
    m_json.write("coordinants", "Z", value);
}

