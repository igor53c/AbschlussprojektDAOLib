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

bool AngelplaetzeDAO::angelplatzExistsWithName(const QString &name,
                                               const qint64 key) {
  // Ob es einen Angelplatz mit diesem Namen gibt,
  // aber nicht mit dem Primärschlüssel
  QString SQL = "SELECT COUNT(*) FROM ANGELPLAETZE ";
  SQL += "WHERE NAME = " + DAOLib::dbString(name);
  SQL += " AND NOT PRIMARYKEY = " + QString::number(key);

  bool OK;

  QVariant count = DAOLib::executeScalar(SQL, OK);

  return OK ? count.toInt() > 0 : false;
}

bool AngelplaetzeDAO::angelplatzExists(const qint64 key) {

  QString SQL = "SELECT COUNT(*) FROM ANGELPLAETZE ";
  SQL += "WHERE PRIMARYKEY = " + QString::number(key);

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

AngelplatzSqlTableModel *
AngelplaetzeDAO::readAngelplaetzeIntoTableModel(QWidget *parent) {
  // Verwenden eigenes QSqlTableModel
  AngelplatzSqlTableModel *tableModel =
      new AngelplatzSqlTableModel(parent, DAOLib::getDatabaseConnection());

  tableModel->setTable("Angelplaetze");
  // Änderungen der Tabelle werden nur vom Programm mit submitAll() oder
  // revertAll() durchgeführt
  tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
  // Alle Datensätze der Tabelle in das SqlTableModel einlesen
  tableModel->select();

  return tableModel;
}

Angelplatz *AngelplaetzeDAO::readAngelplatz(const qint64 key) {

  Angelplatz *angelplatz = nullptr;

  QString SQL =
      "SELECT PRIMARYKEY, PATH, NAME, TYPE, FISCHE, PLZ, ORT, LAND, INFO ";
  SQL += "FROM ANGELPLAETZE ";
  SQL += "WHERE PRIMARYKEY = " + QString::number(key);

  bool OK;

  QSqlQuery *query = DAOLib::executeQuery(SQL, OK);
  if (!OK) {
    delete query;

    return angelplatz;
  }
  // Auf den ersten Datensatz setzen (Zugriff mit Primärschlüssel)
  query->first();
  // Erstellen des Objekts Angelplatz
  angelplatz = new Angelplatz();
  // Setzen der Werte
  angelplatz->setPrimaryKey(query->value(Cnt::PRIMARYKEY).toLongLong());
  angelplatz->setPath(query->value(Cnt::PATH).toString());
  angelplatz->setName(query->value(Cnt::NAME).toString());
  angelplatz->setType(query->value(Cnt::TYPE).toString());
  angelplatz->setFische(query->value(Cnt::FISCHE).toInt());
  angelplatz->setPlz(query->value(Cnt::PLZ).toString());
  angelplatz->setOrt(query->value(Cnt::ORT).toString());
  angelplatz->setLand(query->value(Cnt::LAND).toString());
  angelplatz->setInfo(query->value(Cnt::INFO).toString());
  // Nachdem alle Daten aus der Query übernommen wurden,
  // das Objekt vom Heap löschen
  delete query;

  return angelplatz;
}

QString AngelplaetzeDAO::readAngelplatzName(const qint64 key) {

  if (key < 1)
    return QString();
  // Nur Werte aus Spalte NAME nehmen
  QString SQL = "SELECT NAME FROM ANGELPLAETZE ";
  SQL += "WHERE PRIMARYKEY = " + QString::number(key);

  bool OK;

  QVariant name = DAOLib::executeScalar(SQL, OK);

  return OK ? name.toString() : QString();
}

qint64 AngelplaetzeDAO::readAngelplatzKey(const QString &name) {
  // Nur Werte aus Spalte PRIMARYKEY nehmen
  QString SQL = "SELECT PRIMARYKEY FROM ANGELPLAETZE ";
  SQL += "WHERE NAME = " + DAOLib::dbString(name);

  bool OK;

  QVariant key = DAOLib::executeScalar(SQL, OK);

  return OK ? key.toLongLong() : 0;
}

QString AngelplaetzeDAO::readAngelplatzPath(const QString &name) {
  // Nur Werte aus Spalte PATH nehmen
  QString SQL = "SELECT PATH FROM ANGELPLAETZE ";
  SQL += "WHERE NAME = " + DAOLib::dbString(name);

  bool OK;

  QVariant path = DAOLib::executeScalar(SQL, OK);

  return OK ? path.toString() : QString();
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

bool AngelplaetzeDAO::changeNumberFische(const QString &name, const int value) {
  // Ändern den Wert in der Spalte FISCHE
  QString SQL = "UPDATE ANGELPLAETZE ";
  SQL += "SET FISCHE = FISCHE + " + QString::number(value);
  SQL += " WHERE NAME = " + DAOLib::dbString(name);

  return DAOLib::executeNonQuery(SQL) > 0;
}

int AngelplaetzeDAO::countColumns() {
  // Die Gesamtzahl der Spalten in der Tabelle ANGELPLAETZE
  QString SQL = "SELECT COUNT (COLUMN_NAME) AS NUMBER FROM ";
  SQL += "INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME='ANGELPLAETZE'";

  bool OK;

  QVariant count = DAOLib::executeScalar(SQL, OK);

  return OK ? count.toInt() : 0;
}
