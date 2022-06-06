#include "FischeSqlTableModel.h"

FischeSqlTableModel::FischeSqlTableModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db) {}

QVariant FischeSqlTableModel::data(const QModelIndex &index, int role) const {

  QVariant value = QSqlTableModel::data(index, role);

  if (role == Qt::DisplayRole && index.column() == 10)
    return QVariant(listNacht[!value.toBool()]);

  if (role == Qt::DisplayRole && index.column() == 11)
    return QVariant(listNiederschlag[value.toInt()]);

  return QSqlTableModel::data(index, role);
}

void FischeSqlTableModel::setNachtText(const QStringList &list) {
  listNacht = list;
}

void FischeSqlTableModel::setNiederschlagText(const QStringList &list) {
  listNiederschlag = list;
}
