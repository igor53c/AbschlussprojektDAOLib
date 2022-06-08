#pragma once

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include "Constants.h"
#include "DAOLib_global.h"

class DAOLIB_EXPORT DAOLib {
public:
  // Datenbankanmeldung mit Windows-Authentifizierung
  static bool connectToDatabase(const QString &driver, const QString driverName,
                                const QString &hostName,
                                const QString &databaseName);

  static QString getDatabaseName();

  static QSqlDatabase getDatabaseConnection();

  static void closeConnection();

  static int executeNonQuery(const QString &SQL);

  static QVariant executeScalar(const QString &SQL, bool &OK);

  static QSqlQuery *executeQuery(const QString &SQL, bool &OK);

  static QString dbString(QString value);
  // Hintergrundfarbe der Anwendung
  static QColor colorBackground();

  static void setColor(const int col);

  static int getColor();

private:
  // Privater Konstruktor.
  // Verhindert das Erstellen dieser Klasse.
  // Alle Methoden sind statisch.
  DAOLib();

  static QSqlDatabase dbConn;
  static QString serverName;
  static QString dbName;

  static int color;
};
