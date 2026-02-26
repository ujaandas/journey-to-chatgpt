#ifndef MV_LINREG_H
#define MV_LINREG_H

#include "./graph.h"

typedef struct Weight {
  double w;
  double x;
} Weight;

typedef struct MVLine {
  Weight* weights;
  double c;
} MVLine;

MVLine naiiveTrick(Point** pts, int numPts, int epochs, double learningRate);

MVLine squareTrick(Point** pts, int numPts, int epochs, double learningRate);

MVLine absoluteTrick(Point** pts, int numPts, int epochs, double learningRate);

#endif // MV_LINREG_H
