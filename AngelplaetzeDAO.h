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

  static bool angelplatzExistsWithName(const QString &name, const qint64 key);

  static bool angelplatzExists(const qint64 key);

  static int getRowCount();

  static void deleteTable();

  static Angelplatz *readAngelplatz(const qint64 key);

  static QString readAngelplatzName(const qint64 key);

  static qint64 readAngelplatzKey(const QString &name);

  static QString readAngelplatzPath(const QString &name);

  static QSqlTableModel *
  readAngelplaetzeIntoTableModel(QWidget *parent = nullptr);

  static bool updateAngelplatz(const qint64 key, const QString &path,
                               const QString &name, const QString &type,
                               const int fische, const QString &plz,
                               const QString &ort, const QString &land,
                               const QString &info);

  static bool deleteAngelplatz(const qint64 key);

  static bool changeNumberFische(const QString &name, const int value);

  static int countColumns();

private:
  AngelplaetzeDAO();
};
