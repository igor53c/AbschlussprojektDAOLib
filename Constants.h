#pragma once

#include <QColor>
#include <QString>

namespace Cnt {

enum EditMode { NEW, UPDATE };
// Filterparameter ComboBox
enum Parameter {
  P_PARAMETER,
  P_LAENGE,
  P_GEWICHT,
  P_ZEIT,
  P_TEMPERATUR,
  P_WINDGESCHWINDIGKEIT,
  P_LUFTDRUCK
};
// Spalten der Tabelle ANGELPLAETZE in der Datenbank
enum Angelplaetze {
  A_PRIMARYKEY,
  A_PATH,
  A_NAME,
  A_TYPE,
  A_FISCHE,
  A_PLZ,
  A_ORT,
  A_LAND,
  A_INFO
};
// Spalten der Tabelle FISCHE in der Datenbank
enum Fische {
  F_PRIMARYKEY,
  F_PATH,
  F_NAME,
  F_ANGELPLATZ,
  F_LAENGE,
  F_GEWICHT,
  F_ZEIT,
  F_TEMPERATUR,
  F_WINDGESCHWINDIGKEIT,
  F_LUFTDRUCK,
  F_IS_NACHT,
  F_NIEDERSCHLAG,
  F_INFO
};
// Hintergrundfarbe der Anwendung
enum Color { WHITE, YELLOW, GRAY, GREEN, RED, BLUE };
// Standardwerte Dimensionstabelle
inline constexpr int MAIN_COL_WIDTH = 150;
inline constexpr int MAIN_HEADER_HEIGHT = 50;
inline constexpr int ANGELPLATZ_COL_WIDTH = 100;
inline constexpr int ANGELPLATZ_HEADER_HEIGHT = 50;
// Die Farbe der markierten Zeile in der Tabelle
inline constexpr QColor COLOR_HIGHLIGHT_BLACK = QColor(0, 0, 0);
inline constexpr QColor COLOR_HIGHLIGHT_YELLOW = QColor(200, 200, 0);
inline constexpr QColor COLOR_HIGHLIGHT_GRAY = QColor(100, 100, 100);
inline constexpr QColor COLOR_HIGHLIGHT_GREEN = QColor(34, 177, 76);
inline constexpr QColor COLOR_HIGHLIGHT_RED = QColor(255, 0, 0);
inline constexpr QColor COLOR_HIGHLIGHT_BLUE = QColor(0, 0, 255);
inline constexpr QColor COLOR_WHITE = QColor(255, 255, 255);
inline constexpr QColor COLOR_YELLOW = QColor(255, 255, 210);
inline constexpr QColor COLOR_GRAY = QColor(245, 245, 245);
inline constexpr QColor COLOR_GREEN = QColor(230, 255, 230);
inline constexpr QColor COLOR_RED = QColor(255, 230, 230);
inline constexpr QColor COLOR_BLUE = QColor(230, 230, 255);
inline const QList<QColor> COLOR_BACKGROUND{
    COLOR_WHITE, COLOR_YELLOW, COLOR_GRAY, COLOR_GREEN, COLOR_RED, COLOR_BLUE};
inline const QList<QColor> COLOR_HIGHLIGHT{
    COLOR_HIGHLIGHT_BLACK, COLOR_HIGHLIGHT_YELLOW, COLOR_HIGHLIGHT_GRAY,
    COLOR_HIGHLIGHT_GREEN, COLOR_HIGHLIGHT_RED,    COLOR_HIGHLIGHT_BLUE};
// Spaltennamen in der Fische-Tabellendatenbank
inline const QString PRIMARYKEY = "PRIMARYKEY";
inline const QString PATH = "PATH";
inline const QString NAME = "NAME";
inline const QString ANGELPLATZ = "ANGELPLATZ";
inline const QString LAENGE = "LAENGE";
inline const QString GEWICHT = "GEWICHT";
inline const QString ZEIT = "ZEIT";
inline const QString TEMPERATUR = "TEMPERATUR";
inline const QString WINDGESCHWINDIGKEIT = "WINDGESCHWINDIGKEIT";
inline const QString LUFTDRUCK = "LUFTDRUCK";
inline const QString IS_NACHT = "IS_NACHT";
inline const QString NIEDERSCHLAG = "NIEDERSCHLAG";
inline const QString INFO = "INFO";
// Spaltennamen in der Angelplaetze-Tabellendatenbank
inline const QString TYPE = "TYPE";
inline const QString FISCHE = "FISCHE";
inline const QString PLZ = "PLZ";
inline const QString ORT = "ORT";
inline const QString LAND = "LAND";
// Verbindung zum MS SQL Server
inline const QString DRIVER = "QODBC";
inline const QString DRIVER_NAME = "DRIVER={SQL Server}";
inline const QString SERVER = "localhost\\SQLEXPRESS";
inline const QString DATABASE_NAME = "alfatraining";
// Übersetzerdaten
inline const QString APP_NAME = "Angeltagebuch";
inline const QString SUFFIX = "_";
inline const QString EN = "en";
inline const QString SRB = "hr";
inline const QString QTBASE_ = "qtbase_";
inline const QString QTBASE_DE = "qtbase_de";
// Daten für XML-Datei
inline const QString XML_PATH = "/AppData/Local/";
inline const QString XML = ".xml";
inline const QString SETTINGS = "Settings";
inline const QString LANGUAGE = "Language";
inline const QString COL_MAIN = "ColumnMain%1";
inline const QString COL_ANGELPLATZ = "ColumnAngelplatz%1";
inline const QString BACKGROUND = "Background";

} // namespace Cnt
