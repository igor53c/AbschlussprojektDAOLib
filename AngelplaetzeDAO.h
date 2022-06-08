#pragma once

#include <QSqlTableModel>

#include "Angelplatz.h"
#include "AngelplatzSqlTableModel.h"
#include "DAOLib.h"

class DAOLIB_EXPORT AngelplaetzeDAO {
public:
  static bool insertAngelplatz(const QString &path, const QString &name,
                               const QString &type, const int fische,
                               const QString &plz, const QString &ort,
                               const QString &land, const QString &info);
  // Ob es einen Angelplatz mit diesem Namen gibt,
  // aber nicht mit dem Primärschlüssel
  static bool angelplatzExistsWithName(const QString &name, const qint64 key);

  static bool angelplatzExists(const qint64 key);

  static int getRowCount();

  static void deleteTable();

  static Angelplatz *readAngelplatz(const qint64 key);

  static QString readAngelplatzName(const qint64 key);

  static qint64 readAngelplatzKey(const QString &name);

  static QString readAngelplatzPath(const QString &name);

  static AngelplatzSqlTableModel *
  readAngelplaetzeIntoTableModel(QWidget *parent = nullptr);

  static bool updateAngelplatz(const qint64 key, const QString &path,
                               const QString &name, const QString &type,
                               const int fische, const QString &plz,
                               const QString &ort, const QString &land,
                               const QString &info);

  static bool deleteAngelplatz(const qint64 key);
  // Ändern den Wert in der Spalte FISCHE
  static bool changeNumberFische(const QString &name, const int value);
  // Die Gesamtzahl der Spalten in der Tabelle
  static int countColumns();

private:
  AngelplaetzeDAO();
};
