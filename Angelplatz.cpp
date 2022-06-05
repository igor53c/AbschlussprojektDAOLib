#include "Angelplatz.h"

Angelplatz::Angelplatz() {}

Angelplatz::~Angelplatz() {}

void Angelplatz::setPrimaryKey(const qint64 value) { primaryKey = value; }

qint64 Angelplatz::getPrimaryKey() const { return primaryKey; }

void Angelplatz::setPath(const QString &value) { path = value; }

QString Angelplatz::getPath() const { return path; }

void Angelplatz::setName(const QString &value) { name = value; }

QString Angelplatz::getName() const { return name; }

void Angelplatz::setType(const QString &value) { type = value; }

QString Angelplatz::getType() const { return type; }

void Angelplatz::setFische(const int value) { fische = value; }

int Angelplatz::getFische() const { return fische; }

void Angelplatz::setPlz(const QString &value) { plz = value; }

QString Angelplatz::getPlz() const { return plz; }

void Angelplatz::setOrt(const QString &value) { ort = value; }

QString Angelplatz::getOrt() const { return ort; }

void Angelplatz::setLand(const QString &value) { land = value; }

QString Angelplatz::getLand() const { return land; }

void Angelplatz::setInfo(const QString &value) { info = value; }

QString Angelplatz::getInfo() const { return info; }
