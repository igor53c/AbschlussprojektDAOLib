#include "FischeDAO.h"

FischeDAO::FischeDAO() {}

bool FischeDAO::insertFisch(const QString &path, const QString &name,
                            const qint64 angelplatz, const int laenge,
                            const int gewicht, const QDateTime &zeit,
                            const int temperatur, const int windgeschwindigkeit,
                            const int luftdruck, const QString &isNacht,
                            const QString &niederschlag, const QString &info) {
  QString SQL = "INSERT INTO FISCHE ";
  SQL += "(PATH, NAME, ANGELPLATZ, LAENGE, GEWICHT, ZEIT, TEMPERATUR, "
         "WINDGESCHWINDIGKEIT, ";
  SQL += " LUFTDRUCK, IS_NACHT, NIEDERSCHLAG, INFO) VALUES (";
  SQL += DAOLib::dbString(path) + ", ";
  SQL += DAOLib::dbString(name) + ", ";
  SQL += QString::number(angelplatz) + ", ";
  SQL += QString::number(laenge) + ", ";
  SQL += QString::number(gewicht) + ", ";
  SQL += DAOLib::dbString(zeit.toString("yyyy-MM-dd hh:mm:ss")) + ", ";
  SQL += QString::number(temperatur) + ", ";
  SQL += QString::number(windgeschwindigkeit) + ", ";
  SQL += QString::number(luftdruck) + ", ";
  SQL += DAOLib::dbString(isNacht) + ", ";
  SQL += DAOLib::dbString(niederschlag) + ", ";
  SQL += DAOLib::dbString(info) + ")";

  return DAOLib::executeNonQuery(SQL) > 0;
}

int FischeDAO::getRowCount() {

  QString SQL = "SELECT COUNT(*) FROM FISCHE ";

  bool OK;

  QVariant count = DAOLib::executeScalar(SQL, OK);

  return OK ? count.toInt() : 0;
}

void FischeDAO::deleteTable() {
  QString SQL = "TRUNCATE TABLE FISCHE";

  DAOLib::executeNonQuery(SQL);
}

QVector<Fisch *> FischeDAO::readFische() {

  QVector<Fisch *> retValue;

  Fisch *fisch = nullptr;

  QString SQL = "SELECT * FROM FISCHE";

  bool OK;

  QSqlQuery *query = DAOLib::executeQuery(SQL, OK);

  if (!OK) {
    delete query;

    return retValue;
  }

  // Auf den ersten Datensatz setzen (Zugriff mit Primärschlüssel)
  query->first();

  do {
    // Erstellen des Objekts Postleitzahl
    fisch = new Fisch();

    // Setzen der Werte
    fisch->setPrimaryKey(query->value("PRIMARYKEY").toLongLong());
    fisch->setPath(query->value("PATH").toString());
    fisch->setName(query->value("NAME").toString());
    fisch->setAngelplatz(query->value("ANGELPLATZ").toLongLong());
    fisch->setLaenge(query->value("LAENGE").toInt());
    fisch->setGewicht(query->value("GEWICHT").toInt());
    fisch->setZeit(query->value("ZEIT").toDateTime());
    fisch->setTemperatur(query->value("TEMPERATUR").toInt());
    fisch->setWindgeschwindigkeit(query->value("WINDGESCHWINDIGKEIT").toInt());
    fisch->setLuftdruck(query->value("LUFTDRUCK").toInt());
    fisch->setIsNacht(query->value("IS_NACHT").toString());
    fisch->setNiederschlag(query->value("NIEDERSCHLAG").toString());
    fisch->setInfo(query->value("INFO").toString());

    retValue.push_back(fisch);
  } while (query->next());

  // Nachdem alle Daten aus der Query übernommen wurden,
  // das Objekt vom Heap löschen
  delete query;

  return retValue;
}

QSqlTableModel *FischeDAO::readFischeIntoTableModel() {

  QSqlTableModel *tableModel =
      new QSqlTableModel(nullptr, DAOLib::getDatabaseConnection());

  tableModel->setTable("Fische");

  // Änderungen der Tabelle werden nur vom Programm mit submitAll() oder
  // revertAll() durchgeführt
  tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

  // Alle Datensätze der Tabelle in das SqlTableModel einlesen
  tableModel->select();

  return tableModel;
}

Fisch *FischeDAO::readFisch(qint64 key) {

  Fisch *fisch = nullptr;

  QString SQL = "SELECT PRIMARYKEY, PATH, NAME, ANGELPLATZ, LAENGE, GEWICHT, "
                "ZEIT, TEMPERATUR, WINDGESCHWINDIGKEIT, LUFTDRUCK, IS_NACHT, "
                "NIEDERSCHLAG, INFO FROM FISCHE ";
  SQL += "WHERE PRIMARYKEY = " + QString::number(key);

  bool OK;

  QSqlQuery *query = DAOLib::executeQuery(SQL, OK);

  if (!OK) {
    delete query;

    return fisch;
  }

  // Auf den ersten Datensatz setzen (Zugriff mit Primärschlüssel)
  query->first();

  // Erstellen des Objekts Postleitzahl
  fisch = new Fisch();

  // Setzen der Werte
  fisch->setPrimaryKey(query->value("PRIMARYKEY").toLongLong());
  fisch->setPath(query->value("PATH").toString());
  fisch->setName(query->value("NAME").toString());
  fisch->setAngelplatz(query->value("ANGELPLATZ").toLongLong());
  fisch->setLaenge(query->value("LAENGE").toInt());
  fisch->setGewicht(query->value("GEWICHT").toInt());
  fisch->setZeit(query->value("ZEIT").toDateTime());
  fisch->setTemperatur(query->value("TEMPERATUR").toInt());
  fisch->setWindgeschwindigkeit(query->value("WINDGESCHWINDIGKEIT").toInt());
  fisch->setLuftdruck(query->value("LUFTDRUCK").toInt());
  fisch->setIsNacht(query->value("IS_NACHT").toString());
  fisch->setNiederschlag(query->value("NIEDERSCHLAG").toString());
  fisch->setInfo(query->value("INFO").toString());

  // Nachdem alle Daten aus der Query übernommen wurden,
  // das Objekt vom Heap löschen
  delete query;

  return fisch;
}

bool FischeDAO::updateFisch(const qint64 key, const QString &path,
                            const QString &name, const qint64 angelplatz,
                            const int laenge, const int gewicht,
                            const QDateTime &zeit, const int temperatur,
                            const int windgeschwindigkeit, const int luftdruck,
                            const QString &isNacht, const QString &niederschlag,
                            const QString &info) {

  QString SQL = "UPDATE FISCHE ";
  SQL += "SET PATH = " + DAOLib::dbString(path) + ", ";
  SQL += "NAME = " + DAOLib::dbString(name) + ", ";
  SQL += "ANGELPLATZ = " + QString::number(angelplatz) + ", ";
  SQL += "LAENGE = " + QString::number(laenge) + ", ";
  SQL += "GEWICHT = " + QString::number(gewicht) + ", ";
  SQL +=
      "ZEIT = " + DAOLib::dbString(zeit.toString("yyyy-MM-dd hh:mm:ss")) + ", ";
  SQL += "TEMPERATUR = " + QString::number(temperatur) + ", ";
  SQL += "WINDGESCHWINDIGKEIT = " + QString::number(windgeschwindigkeit) + ", ";
  SQL += "LUFTDRUCK = " + QString::number(luftdruck) + ", ";
  SQL += "IS_NACHT = " + DAOLib::dbString(isNacht) + ", ";
  SQL += "NIEDERSCHLAG = " + DAOLib::dbString(niederschlag) + ", ";
  SQL += "INFO = " + DAOLib::dbString(info);
  SQL += " WHERE PRIMARYKEY = " + QString::number(key);

  return DAOLib::executeNonQuery(SQL) > 0;
}

bool FischeDAO::deleteFisch(const qint64 key) {
  QString SQL = "DELETE FROM FISCHE ";
  SQL += "WHERE PRIMARYKEY = " + QString::number(key);

  return DAOLib::executeNonQuery(SQL) > 0;
}

QStringList FischeDAO::readFischarten() {

  QStringList retValue;

  retValue.push_back("Fischarten");

  if(getRowCount() < 1)
      return retValue;

  QString SQL = "SELECT DISTINCT NAME FROM FISCHE ORDER BY NAME";

  bool OK;

  QSqlQuery *query = DAOLib::executeQuery(SQL, OK);

  if (!OK) {

    delete query;

    return retValue;
  }

  // Auf den ersten Datensatz setzen (Zugriff mit Primärschlüssel)
  query->first();

  do {

    retValue.push_back(query->value("NAME").toString());

  } while (query->next());

  // Nachdem alle Daten aus der Query übernommen wurden,
  // das Objekt vom Heap löschen
  delete query;

  return retValue;
}

QVariant FischeDAO::getMinParameter(QString column) {

  QString SQL = "SELECT MIN(" + column + ") FROM FISCHE";

  bool OK;

  QVariant value = DAOLib::executeScalar(SQL, OK);

  return OK ? value : 0;
}

QVariant FischeDAO::getMaxParameter(QString column) {

  QString SQL = "SELECT MAX(" + column + ") FROM FISCHE";

  bool OK;

  QVariant value = DAOLib::executeScalar(SQL, OK);

  return OK ? value : 0;
}

bool FischeDAO::deleteFischeInAngelplatz(qint64 key) {

  QString SQL = "DELETE FROM FISCHE ";
  SQL += "WHERE ANGELPLATZ = " + QString::number(key);

  return DAOLib::executeNonQuery(SQL) > 0;
}

int FischeDAO::countFischeInAngelplatz(qint64 key) {

  QString SQL = "SELECT COUNT(*) FROM FISCHE ";
  SQL += "WHERE ANGELPLATZ = " + QString::number(key);

  bool OK;

  QVariant count = DAOLib::executeScalar(SQL, OK);

  return OK ? count.toInt() : 0;
}
