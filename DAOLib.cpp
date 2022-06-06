#include "DAOLib.h"

QSqlDatabase DAOLib::dbConn = QSqlDatabase();
QString DAOLib::serverName = QString();
QString DAOLib::dbName = QString();

DAOLib::DAOLib() {}

bool DAOLib::connectToDatabase(const QString &driver, const QString driverName,
                               const QString &hostName,
                               const QString &databaseName) {
  bool isDBOpen = false;

  QString connectionString = driverName + ";";

  connectionString += "Server=" + hostName + ";";
  connectionString += "Database=" + databaseName + ";";
  connectionString += "Trusted_Connection=Yes;";

  dbConn = QSqlDatabase::addDatabase(driver, databaseName);

  dbConn.setDatabaseName(connectionString);

  isDBOpen = dbConn.open();

  if (!isDBOpen)
    QMessageBox::critical(nullptr, "Datenbankfehler",
                          QString("Fehler beim Zugriff auf die Datenbank: %1")
                              .arg(dbConn.lastError().text()));
  else {
    serverName = hostName;

    dbName = databaseName;
  }

  return isDBOpen;
}

QString DAOLib::getDatabaseName() { return dbName; }

QSqlDatabase DAOLib::getDatabaseConnection() { return dbConn; }

void DAOLib::closeConnection() {

  dbConn.close();

  serverName = QString();

  dbName = QString();
}

int DAOLib::executeNonQuery(const QString &SQL) {

  QSqlQuery query = QSqlQuery(dbConn);

  int retValue = -1;

  if (!query.exec(SQL))
    QMessageBox::critical(nullptr, "Datensätze Importieren",
                          QString("Fehler beim Zugriff aud die Datenbank: %1")
                              .arg(query.lastError().text()));
  else
    retValue = query.numRowsAffected();

  return retValue;
}

QVariant DAOLib::executeScalar(const QString &SQL, bool &OK) {

  OK = false;

  QVariant retValue = 0;

  QSqlQuery query = QSqlQuery(dbConn);

  bool qryValue = query.exec(SQL);

  if (!qryValue) {
    QMessageBox::critical(nullptr, "Datenbankfehler",
                          QString("Fehler beim Zugriff auf die Datenbank: %1")
                              .arg(dbConn.lastError().text()));

    return retValue;
  }

  query.first();

  OK = true;

  return query.value(0);
}

QSqlQuery *DAOLib::executeQuery(const QString &SQL, bool &OK) {

  QSqlQuery *query = new QSqlQuery(dbConn);
  OK = query->exec(SQL);
  return query;
}

QString DAOLib::dbString(QString value) {
  return "'" + value.replace("'", "''") + "'";
}
