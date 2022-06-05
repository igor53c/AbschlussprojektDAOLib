#pragma once

#include <QDateTime>
#include <QObject>

#include "DAOLib.h"
#include "DAOObjectFisch.h"

class DAOLIB_EXPORT Fisch : public DAOObjectFisch {
public:
  Fisch();

  virtual ~Fisch();

  void setPrimaryKey(const qint64 value) override;
  qint64 getPrimaryKey() const override;

  void setPath(const QString &value) override;
  QString getPath() const override;

  void setName(const QString &value) override;
  QString getName() const override;

  void setAngelplatz(const qint64 value) override;
  qint64 getAngelplatz() const override;

  void setLaenge(const int value) override;
  int getLaenge() const override;

  void setGewicht(const int value) override;
  int getGewicht() const override;

  void setZeit(const QDateTime &value) override;
  QDateTime getZeit() const override;

  void setTemperatur(const int value) override;
  int getTemperatur() const override;

  void setWindgeschwindigkeit(const int value) override;
  int getWindgeschwindigkeit() const override;

  void setLuftdruck(const int value) override;
  int getLuftdruck() const override;

  void setIsNacht(const QString& value) override;
  QString getIsNacht() const override;

  void setNiederschlag(const QString &value) override;
  QString getNiederschlag() const override;

  void setInfo(const QString &value) override;
  QString getInfo() const override;

private:
  qint64 primaryKey;
  QString path;
  QString name;
  qint64 angelplatz;
  int laenge;
  int gewicht;
  QDateTime zeit;
  int temperatur;
  int windgeschwindigkeit;
  int luftdruck;
  QString isNacht;
  QString niederschlag;
  QString info;
};
