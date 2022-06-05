#include "AngelplaetzeDAO.h"

AngelplaetzeDAO::AngelplaetzeDAO() {}

bool AngelplaetzeDAO::insertAngelplatz(const QString &path, const QString &name,
                                       const QString &type, const int fische,
                                       const QString &plz, const QString &ort,
                                       const QString &land,
                                       const QString &info) {
  QString SQL = "INSERT INTO ANGELPLAETZE ";
  SQL += "(PATH, NAME, TYPE, FISCHE, PLZ, ORT, LAND, INFO) ";
  SQL += "VALUES (";
  SQL += DAOLib::dbString(path) + ", ";
  SQL += DAOLib::dbString(name) + ", ";
  SQL += DAOLib::dbString(type) + ", ";
  SQL += QString::number(fische) + ", ";
  SQL += DAOLib::dbString(plz) + ", ";
  SQL += DAOLib::dbString(ort) + ", ";
  SQL += DAOLib::dbString(land) + ", ";
  SQL += DAOLib::dbString(info) + ")";

  return DAOLib::executeNonQuery(SQL) > 0;
}

bool AngelplaetzeDAO::angelplatzExists(const QString &name) {
  QString SQL = "SELECT COUNT(*) FROM ANGELPLAETZE ";
  SQL += "WHERE NAME = " + DAOLib::dbString(name);

  bool OK;

  QVariant count = DAOLib::executeScalar(SQL, OK);

  return OK ? count.toInt() > 0 : false;
}

int AngelplaetzeDAO::getRowCount() {
  QString SQL = "SELECT COUNT(*) FROM ANGELPLAETZE ";

  bool OK;

  QVariant count = DAOLib::executeScalar(SQL, OK);

  return OK ? count.toInt() : 0;
}

void AngelplaetzeDAO::deleteTable() {
  QString SQL = "TRUNCATE TABLE ANGELPLAETZE";

  DAOLib::executeNonQuery(SQL);
}

QSqlTableModel *AngelplaetzeDAO::readAngelplaetzeIntoTableModel() {
  QSqlTableModel *tableModel =
      new QSqlTableModel(nullptr, DAOLib::getDatabaseConnection());
  tableModel->setTable("Angelplaetze");

  // Änderungen der Tabelle werden nur vom Programm mit submitAll() oder
  // revertAll() durchgeführt
  tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

  // Alle Datensätze der Tabelle in das SqlTableModel einlesen
  tableModel->select();

  return tableModel;
}

Angelplatz *AngelplaetzeDAO::readAngelplatz(qint64 key) {
  Angelplatz *angelplatz = nullptr;

  QString SQL =
      "SELECT PRIMARYKEY, PATH, NAME, TYPE, FISCHE, PLZ, ORT, LAND, INFO "
      "FROM ANGELPLAETZE ";
  SQL += "WHERE PRIMARYKEY = " + QString::number(key);

  bool OK;

  QSqlQuery *query = DAOLib::executeQuery(SQL, OK);
  if (!OK) {
    delete query;

    return angelplatz;
  }

  // Auf den ersten Datensatz setzen (Zugriff mit Primärschlüssel)
  query->first();

  // Erstellen des Objekts Postleitzahl
  angelplatz = new Angelplatz();

  // Setzen der Werte
  angelplatz->setPrimaryKey(query->value("PRIMARYKEY").toLongLong());
  angelplatz->setPath(query->value("PATH").toString());
  angelplatz->setName(query->value("NAME").toString());
  angelplatz->setType(query->value("TYPE").toString());
  angelplatz->setFische(query->value("FISCHE").toInt());
  angelplatz->setPlz(query->value("PLZ").toString());
  angelplatz->setOrt(query->value("ORT").toString());
  angelplatz->setLand(query->value("LAND").toString());
  angelplatz->setInfo(query->value("INFO").toString());

  // Nachdem alle Daten aus der Query übernommen wurden,
  // das Objekt vom Heap löschen
  delete query;

  return angelplatz;
}

QVector<Angelplatz *> AngelplaetzeDAO::readAngelplaetze() {
  QVector<Angelplatz *> retValue;

  Angelplatz *angelplatz = nullptr;

  QString SQL = "SELECT * FROM ANGELPLAETZE";

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
    angelplatz = new Angelplatz();

    // Setzen der Werte
    angelplatz->setPrimaryKey(query->value("PRIMARYKEY").toLongLong());
    angelplatz->setPath(query->value("PATH").toString());
    angelplatz->setName(query->value("NAME").toString());
    angelplatz->setType(query->value("TYPE").toString());
    angelplatz->setFische(query->value("FISCHE").toInt());
    angelplatz->setPlz(query->value("PLZ").toString());
    angelplatz->setOrt(query->value("ORT").toString());
    angelplatz->setLand(query->value("LAND").toString());
    angelplatz->setInfo(query->value("INFO").toString());

    retValue.push_back(angelplatz);
  } while (query->next());

  // Nachdem alle Daten aus der Query übernommen wurden,
  // das Objekt vom Heap löschen
  delete query;

  return retValue;
}

bool AngelplaetzeDAO::updateAngelplatz(const qint64 key, const QString &path,
                                       const QString &name, const QString &type,
                                       const int fische, const QString &plz,
                                       const QString &ort, const QString &land,
                                       const QString &info) {
  QString SQL = "UPDATE ANGELPLAETZE ";
  SQL += "SET PATH = " + DAOLib::dbString(path) + ", ";
  SQL += "NAME = " + DAOLib::dbString(name) + ", ";
  SQL += "TYPE = " + DAOLib::dbString(type) + ", ";
  SQL += "FISCHE = " + QString::number(fische) + ", ";
  SQL += "PLZ = " + DAOLib::dbString(plz) + ", ";
  SQL += "ORT = " + DAOLib::dbString(ort) + ", ";
  SQL += "LAND = " + DAOLib::dbString(land) + ", ";
  SQL += "INFO = " + DAOLib::dbString(info);
  SQL += " WHERE PRIMARYKEY = " + QString::number(key);

  return DAOLib::executeNonQuery(SQL) > 0;
}

bool AngelplaetzeDAO::deleteAngelplatz(const qint64 key) {

  QString SQL = "DELETE FROM ANGELPLAETZE ";
  SQL += "WHERE PRIMARYKEY = " + QString::number(key);

  return DAOLib::executeNonQuery(SQL) > 0;
}

bool AngelplaetzeDAO::changeNumberFische(const qint64 key, const int value) {

  QString SQL = "UPDATE ANGELPLAETZE ";
  SQL += "SET FISCHE = FISCHE + " + QString::number(value);
  SQL += " WHERE PRIMARYKEY = " + QString::number(key);

  return DAOLib::executeNonQuery(SQL) > 0;
}
