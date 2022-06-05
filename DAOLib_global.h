#pragma once

#include <QtCore/qglobal.h>

#if defined(DAOLIB_LIBRARY)
#define DAOLIB_EXPORT Q_DECL_EXPORT
#else
#define DAOLIB_EXPORT Q_DECL_IMPORT
#endif
