#ifndef PROJESETTINGS_H
#define PROJESETTINGS_H

#include <QObject>
#include "jsonmanager.h"

class ProjeSettings : public QObject
{
    Q_OBJECT
public:
    ProjeSettings();

    Q_INVOKABLE void save();
    Q_INVOKABLE void load();
    Q_INVOKABLE void setName(const QString projectName);

    Q_INVOKABLE QString getZ() const;
    Q_INVOKABLE QString getY() const;
    Q_INVOKABLE QString getX() const;

public:
    QString m_x, m_y, m_z;

    JsonManager m_json;

public slots:
    void setX(const QString &value);
    void setY(const QString &value);
    void setZ(const QString &value);

signals:
    void xChanged();
    void yChanged();
    void zChanged();
};

#endif // PROJESETTINGS_H
