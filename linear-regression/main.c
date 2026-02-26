#include <stdio.h>
#include "./graph.h"
#include "./linreg.h"

int main() {
  // Possible number of rooms
  double features[] = {1, 2, 3, 5, 6, 7};

  // House prices
  double labels[] = {155, 197, 244, 356, 407, 448};

  Point* points = makePoints(features, 6, labels, 6);

  // Line naiiveLine = naiiveTrick(points, 6, 1000);
  // Line squareLine = squareTrick(points, 6, 1000, 0.001);
  Line absLine = absoluteTrick(points, 6, 10000, 0.01);

  // drawLine(points, 6, naiiveLine);
  // drawLine(points, 6, squareLine);
  drawLine(points, 6, absLine);

  return 0;
}
