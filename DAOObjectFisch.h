#pragma once

#include <QObject>

class DAOObjectFisch {
public:
  DAOObjectFisch();

  // Abstrakte Getter- und Setter-Methoden
  virtual void setPrimaryKey(const qint64 value) = 0;
  virtual qint64 getPrimaryKey() const = 0;

  virtual void setPath(const QString &value) = 0;
  virtual QString getPath() const = 0;

  virtual void setName(const QString &value) = 0;
  virtual QString getName() const = 0;

  virtual void setAngelplatz(const qint64 value) = 0;
  virtual qint64 getAngelplatz() const = 0;

  virtual void setLaenge(const int value) = 0;
  virtual int getLaenge() const = 0;

  virtual void setGewicht(const int value) = 0;
  virtual int getGewicht() const = 0;

  virtual void setZeit(const QDateTime &value) = 0;
  virtual QDateTime getZeit() const = 0;

  virtual void setTemperatur(const int value) = 0;
  virtual int getTemperatur() const = 0;

  virtual void setWindgeschwindigkeit(const int value) = 0;
  virtual int getWindgeschwindigkeit() const = 0;

  virtual void setLuftdruck(const int value) = 0;
  virtual int getLuftdruck() const = 0;

  virtual void setIsNacht(const QString& value) = 0;
  virtual QString getIsNacht() const = 0;

  virtual void setNiederschlag(const QString &value) = 0;
  virtual QString getNiederschlag() const = 0;

  virtual void setInfo(const QString &value) = 0;
  virtual QString getInfo() const = 0;
};
