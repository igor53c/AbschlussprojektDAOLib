#include "FischeSqlTableModel.h"

FischeSqlTableModel::FischeSqlTableModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db) {}

QVariant FischeSqlTableModel::data(const QModelIndex &index, int role) const {

  QVariant value = QSqlTableModel::data(index, role);
  // Im Fall der Spalte IS_NACHT wird ein neuer Wert zurückgegeben
  if (role == Qt::DisplayRole && index.column() == Cnt::Fische::F_IS_NACHT)
    // Ersetzen von BIT-Werten aus einer SQL-Tabelle
    // durch ein bestimmtes Wort aus der Liste
    return QVariant(listNacht[!value.toBool()]);
  // Im Fall der Spalte NIEDERSCHLAG wird ein neuer Wert zurückgegeben
  if (role == Qt::DisplayRole && index.column() == Cnt::Fische::F_NIEDERSCHLAG)
    // Ersetzen von INT-Werten aus einer SQL-Tabelle
    // durch ein bestimmtes Wort aus der Liste
    return QVariant(listNiederschlag[value.toInt()]);
  // Der Text in allen Spalten (außer der INFO-Spalte) steht in der Mitte
  if (role == Qt::TextAlignmentRole && index.column() < Cnt::Fische::F_INFO)
    return Qt::AlignCenter;
  // Ändern Sie die Hintergrundfarbe nur für Felder
  if (role == Qt::BackgroundRole)
    return QBrush(StyleBackground::colorBackground());

  return QSqlTableModel::data(index, role);
}

QVariant FischeSqlTableModel::headerData(int section,
                                         Qt::Orientation orientation,
                                         int role) const {
  // Passen Sie die INFO-Spalte horizontal nach links und vertikal zur Mitte an
  if (section == Cnt::Fische::F_INFO && orientation == Qt::Horizontal &&
      role == Qt::TextAlignmentRole)
    return Qt::AlignVCenter;

  return QSqlTableModel::headerData(section, orientation, role);
}

void FischeSqlTableModel::setNachtText(const QStringList &list) {
  listNacht = list;
}

void FischeSqlTableModel::setNiederschlagText(const QStringList &list) {
  listNiederschlag = list;
}
