#pragma once

#include <QObject>

class DBObjectAngelplatz {
public:
  DBObjectAngelplatz();

  // Abstrakte Getter- und Setter-Methoden
  virtual void setPrimaryKey(const qint64 value) = 0;
  virtual qint64 getPrimaryKey() const = 0;

  virtual void setPath(const QString &value) = 0;
  virtual QString getPath() const = 0;

  virtual void setName(const QString &value) = 0;
  virtual QString getName() const = 0;

  virtual void setType(const QString &value) = 0;
  virtual QString getType() const = 0;

  virtual void setFische(const int value) = 0;
  virtual int getFische() const = 0;

  virtual void setPlz(const QString &value) = 0;
  virtual QString getPlz() const = 0;

  virtual void setOrt(const QString &value) = 0;
  virtual QString getOrt() const = 0;

  virtual void setLand(const QString &value) = 0;
  virtual QString getLand() const = 0;

  virtual void setInfo(const QString &value) = 0;
  virtual QString getInfo() const = 0;
};
