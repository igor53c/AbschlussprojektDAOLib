QT += widgets sql

QT -= gui

TEMPLATE = lib
DEFINES += DAOLIB_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AngelplaetzeDAO.cpp \
    Angelplatz.cpp \
    AngelplatzSqlTableModel.cpp \
    DAOLib.cpp \
    DAOObjectFisch.cpp \
    DBObjectAngelplatz.cpp \
    Fisch.cpp \
    FischeDAO.cpp \
    FischeSqlTableModel.cpp

HEADERS += \
    AngelplaetzeDAO.h \
    Angelplatz.h \
    AngelplatzSqlTableModel.h \
    Constants.h \
    DAOLib_global.h \
    DAOLib.h \
    DAOObjectFisch.h \
    DBObjectAngelplatz.h \
    Fisch.h \
    FischeDAO.h \
    FischeSqlTableModel.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
