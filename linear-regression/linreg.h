#ifndef LINREG_H
#define LINREG_H

#include "./graph.h"

typedef struct SimpleLine {
  double m;
  double c;
} Line;

SimpleLine naiiveTrick(Point* pts, int numPts, int epochs, double learningRate);

SimpleLine squareTrick(Point* pts, int numPts, int epochs, double learningRate);

SimpleLine absoluteTrick(Point* pts, int numPts, int epochs, double learningRate);

#endif // LINREG_H
