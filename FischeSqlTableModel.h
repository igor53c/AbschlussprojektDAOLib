#pragma once

#include <QObject>
#include <QSqlTableModel>

class FischeSqlTableModel : public QSqlTableModel {
public:
  explicit FischeSqlTableModel(QObject *parent = nullptr,
                               QSqlDatabase db = QSqlDatabase());

  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;

  void setNachtText(const QStringList &list);
  void setNiederschlagText(const QStringList &list);

private:
  QStringList listNacht;
  QStringList listNiederschlag;
};
