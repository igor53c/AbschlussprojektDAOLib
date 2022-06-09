#pragma once

#include <QColor>

#include "Constants.h"
#include "DAOLib_global.h"

class DAOLIB_EXPORT StyleBackground {
public:
  // Hintergrundfarbe der Anwendung
  static QColor colorBackground();

  static void setColorIndex(const int col);

  static int getColorIndex();

private:
  StyleBackground();

  static int colorIndex;
};
