#pragma once

#include <QBrush>
#include <QObject>
#include <QSqlTableModel>

#include "Constants.h"
#include "DAOLib.h"
// Verwenden eigenes QSqlTableModel
class FischeSqlTableModel : public QSqlTableModel {
public:
  explicit FischeSqlTableModel(QObject *parent = nullptr,
                               QSqlDatabase db = QSqlDatabase());
  // Überschriebene Methode um Daten aus einer Tabelle anzuzeigen
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;

  QVariant headerData(int section, Qt::Orientation orientation,
                      int role = Qt::DisplayRole) const override;
  // Setter-Methoden
  void setNachtText(const QStringList &list);
  void setNiederschlagText(const QStringList &list);

private:
  QStringList listNacht;
  QStringList listNiederschlag;
};
