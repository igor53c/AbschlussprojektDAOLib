#include "Fisch.h"

Fisch::Fisch() {}

Fisch::~Fisch() {}

void Fisch::setPrimaryKey(const qint64 value) { primaryKey = value; }

qint64 Fisch::getPrimaryKey() const { return primaryKey; }

void Fisch::setPath(const QString &value) { path = value; }

QString Fisch::getPath() const { return path; }

void Fisch::setName(const QString &value) { name = value; }

QString Fisch::getName() const { return name; }

void Fisch::setAngelplatz(const QString &value) { angelplatz = value; }

QString Fisch::getAngelplatz() const { return angelplatz; }

void Fisch::setLaenge(const int value) { laenge = value; }

int Fisch::getLaenge() const { return laenge; }

void Fisch::setGewicht(const int value) { gewicht = value; }

int Fisch::getGewicht() const { return gewicht; }

void Fisch::setZeit(const QDateTime &value) { zeit = value; }

QDateTime Fisch::getZeit() const { return zeit; }

void Fisch::setTemperatur(const int value) { temperatur = value; }

int Fisch::getTemperatur() const { return temperatur; }

void Fisch::setWindgeschwindigkeit(const int value) {
  windgeschwindigkeit = value;
}

int Fisch::getWindgeschwindigkeit() const { return windgeschwindigkeit; }

void Fisch::setLuftdruck(const int value) { luftdruck = value; }

int Fisch::getLuftdruck() const { return luftdruck; }

void Fisch::setIsNacht(const bool value) { isNacht = value; }

bool Fisch::getIsNacht() const { return isNacht; }

void Fisch::setNiederschlag(const int value) { niederschlag = value; }

int Fisch::getNiederschlag() const { return niederschlag; }

void Fisch::setInfo(const QString &value) { info = value; }

QString Fisch::getInfo() const { return info; }
