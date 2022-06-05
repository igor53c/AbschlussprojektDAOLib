#pragma once

#include <QObject>

#include "DAOLib.h"
#include "DBObjectAngelplatz.h"

class DAOLIB_EXPORT Angelplatz : public DBObjectAngelplatz {
public:
  Angelplatz();

  virtual ~Angelplatz();

  void setPrimaryKey(const qint64 value) override;
  qint64 getPrimaryKey() const override;

  void setPath(const QString &value) override;
  QString getPath() const override;

  void setName(const QString &value) override;
  QString getName() const override;

  void setType(const QString &value) override;
  QString getType() const override;

  void setFische(const int value) override;
  int getFische() const override;

  void setPlz(const QString &value) override;
  QString getPlz() const override;

  void setOrt(const QString &value) override;
  QString getOrt() const override;

  void setLand(const QString &value) override;
  QString getLand() const override;

  void setInfo(const QString &value) override;
  QString getInfo() const override;

private:
  qint64 primaryKey;
  QString path;
  QString name;
  QString type;
  int fische;
  QString plz;
  QString ort;
  QString land;
  QString info;
};
