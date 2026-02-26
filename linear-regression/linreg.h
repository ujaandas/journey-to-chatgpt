#ifndef LINREG_H
#define LINREG_H

#include <stdlib.h>
#include "./graph.h"

typedef struct Line {
  double m;
  double c;
} Line;

Line naiiveTrick(Point* pts, int numPts, int epochs);

#endif // LINREG_H
