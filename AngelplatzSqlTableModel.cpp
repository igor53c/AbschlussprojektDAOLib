#include "AngelplatzSqlTableModel.h"

AngelplatzSqlTableModel::AngelplatzSqlTableModel(QObject *parent,
                                                 QSqlDatabase db)
    : QSqlTableModel(parent, db) {}

QVariant AngelplatzSqlTableModel::data(const QModelIndex &index,
                                       int role) const {

  // Der Text in allen Spalten (außer der INFO-Spalte) steht in der Mitte
  if (role == Qt::TextAlignmentRole &&
      index.column() < Cnt::Angelplaetze::A_INFO)
    return Qt::AlignCenter;
  // Ändern die Hintergrundfarbe nur für Felder
  if (role == Qt::BackgroundRole)
      return QBrush(DAOLib::colorBackground());

  return QSqlTableModel::data(index, role);
}

QVariant AngelplatzSqlTableModel::headerData(int section,
                                             Qt::Orientation orientation,
                                             int role) const {
  // Passen Sie die INFO-Spalte horizontal nach links und vertikal zur Mitte an
  if (section == Cnt::Angelplaetze::A_INFO && orientation == Qt::Horizontal &&
      role == Qt::TextAlignmentRole)
    return Qt::AlignVCenter;

  return QSqlTableModel::headerData(section, orientation, role);
}
