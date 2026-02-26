#include <stdlib.h>
#include "./graph.h"

typedef struct Line {
  double m;
  double c;
} Line;

Line naiiveTrick(Point* pts, int numPts, int epochs) {
  // Make a random line
  Line line;
  line.m = 0;
  line.c = 0;

  for (int i = 0; i < epochs; i++) {
    // Select a random point
    Point chosenPoint = pts[rand() % numPts];

    double pred = line.m * chosenPoint.x + line.c;

    // Case 1: Point is above line and right of y-axis
    if (chosenPoint.y > pred && chosenPoint.x > 0) {
      // Rotate line counter-clockwise
      line.m += 0.1;
      // Translate line upwards
      line.c += 0.1;
    }

    // Case 2: Point is above line and left of y-axis
    else if (chosenPoint.y > pred && chosenPoint.x < 0) {
      // Rotate line clockwise
      line.m -= 0.1;
      // Translate line upwards
      line.c += 0.1;
    }

    // Case 3: Point is below line and right of y-axis
    else if (chosenPoint.y < pred && chosenPoint.x > 0) {
      // Rotate line clockwise
      line.m -= 0.1;
      // Translate line downards
      line.c -= 0.1;
    }
    
    // Case 4: Point is below line and left of y-axis
    else if (chosenPoint.y < pred && chosenPoint.x < 0) {
      // Rotate line counter-clockwise
      line.m += 0.1;
      // Translate line downards
      line.c -= 0.1;
    }
  }

  return line;
}
