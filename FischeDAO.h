#pragma once

#include <QDateTime>
#include <QSqlTableModel>
#include <QDebug>

#include "DAOLib.h"
#include "Fisch.h"

class DAOLIB_EXPORT FischeDAO {
public:
  static bool insertFisch(const QString &path, const QString &name,
                          const qint64 angelplatz, const int laenge,
                          const int gewicht, const QDateTime &zeit,
                          const int temperatur, const int windgeschwindigkeit,
                          const int luftdruck, const QString &isNacht,
                          const QString &niederschlag, const QString &info);

  static int getRowCount();

  static void deleteTable();

  static Fisch *readFisch(qint64 key);

  static QVector<Fisch *> readFische();

  static QSqlTableModel *readFischeIntoTableModel();

  static bool updateFisch(const qint64 key, const QString &path,
                          const QString &name, const qint64 angelplatz,
                          const int laenge, const int gewicht,
                          const QDateTime &zeit, const int temperatur,
                          const int windgeschwindigkeit, const int luftdruck,
                          const QString &isNacht, const QString &niederschlag,
                          const QString &info);

  static bool deleteFisch(const qint64 key);

  static QStringList readFischarten();

  static QVariant getMinParameter(QString column);
  static QVariant getMaxParameter(QString column);

  static bool deleteFischeInAngelplatz(qint64 key);
  static int countFischeInAngelplatz(qint64 key);

  static int countColumns();

private:
  FischeDAO();
};
