#include "StyleBackground.h"

int StyleBackground::colorIndex = 0;

StyleBackground::StyleBackground() {}

QColor StyleBackground::colorBackground() {

  return Cnt::COLOR_BACKGROUND[colorIndex];
}

void StyleBackground::setColorIndex(const int col) { colorIndex = col; }

int StyleBackground::getColorIndex() { return colorIndex; }
