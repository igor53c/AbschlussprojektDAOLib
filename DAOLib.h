#pragma once

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include "DAOLib_global.h"

class DAOLIB_EXPORT DAOLib {
public:
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

private:
  DAOLib();

  static QSqlDatabase dbConn;
  static QString serverName;
  static QString dbName;
};
