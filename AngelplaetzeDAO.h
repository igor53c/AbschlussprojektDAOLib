#pragma once

#include <QSqlTableModel>
#include <QVector>

#include "Angelplatz.h"
#include "DAOLib.h"

class DAOLIB_EXPORT AngelplaetzeDAO {
public:
  static bool insertAngelplatz(const QString &path, const QString &name,
                               const QString &type, const int fische,
                               const QString &plz, const QString &ort,
                               const QString &land, const QString &info);

  static bool angelplatzExists(const QString &name);

  static int getRowCount();

  static void deleteTable();

  static Angelplatz *readAngelplatz(qint64 key);

  static QVector<Angelplatz *> readAngelplaetze();

  static QSqlTableModel *readAngelplaetzeIntoTableModel();

  static bool updateAngelplatz(const qint64 key, const QString &path,
                               const QString &name, const QString &type,
                               const int fische, const QString &plz,
                               const QString &ort, const QString &land,
                               const QString &info);

  static bool deleteAngelplatz(const qint64 key);

  static bool changeNumberFische(const qint64 key, const int value);

  static int countColumns();

private:
  AngelplaetzeDAO();
};
