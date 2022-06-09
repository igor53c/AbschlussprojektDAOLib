#pragma once

#include <QBrush>
#include <QObject>
#include <QSqlTableModel>

#include "Constants.h"
#include "StyleBackground.h"
// Verwenden eigenes QSqlTableModel
class AngelplatzSqlTableModel : public QSqlTableModel {
public:
  explicit AngelplatzSqlTableModel(QObject *parent = nullptr,
                                   QSqlDatabase db = QSqlDatabase());
  // Überschriebene Methoden um Daten aus einer Tabelle anzuzeigen
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;

  QVariant headerData(int section, Qt::Orientation orientation,
                      int role = Qt::DisplayRole) const override;
};
