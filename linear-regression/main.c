#include <stdio.h>
#include "./graph.h"

int main() {
  // Possible number of rooms
  double features[] = {1, 2, 3, 5, 6, 7};

  // House prices
  double labels[] = {155, 197, 244, 356, 407, 448};

  Point* points = makePoints(features, 6, labels, 6);

  drawGraph(points, 6);

  return 0;
}
