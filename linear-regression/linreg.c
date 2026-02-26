#include <stdlib.h>
#include "./graph.h"
#include "./linreg.h"

SimpleLine naiiveTrick(Point* pts, int numPts, int epochs, double learningRate) {
  // Make a random line
  SimpleLine line;
  line.m = 0;
  line.c = 0;

  for (int i = 0; i < epochs; i++) {
    // Select a random point
    Point chosenPoint = pts[rand() % numPts];

    double pred = line.m * chosenPoint.x + line.c;

    // Case 1: Point is above line and right of y-axis
    if (chosenPoint.y > pred && chosenPoint.x > 0) {
      // Rotate line counter-clockwise
      line.m += learningRate;
      // Translate line upwards
      line.c += learningRate;
    }

    // Case 2: Point is above line and left of y-axis
    else if (chosenPoint.y > pred && chosenPoint.x < 0) {
      // Rotate line clockwise
      line.m -= learningRate;
      // Translate line upwards
      line.c += learningRate;
    }

    // Case 3: Point is below line and right of y-axis
    else if (chosenPoint.y < pred && chosenPoint.x > 0) {
      // Rotate line clockwise
      line.m -= learningRate;
      // Translate line downards
      line.c -= learningRate;
    }

    // Case 4: Point is below line and left of y-axis
    else if (chosenPoint.y < pred && chosenPoint.x < 0) {
      // Rotate line counter-clockwise
      line.m += learningRate;
      // Translate line downards
      line.c -= learningRate;
    }
  }

  return line;
}

SimpleLine squareTrick(Point* pts, int numPts, int epochs, double learningRate) {
  // Make a random line
  SimpleLine line;
  line.m = 0;
  line.c = 0;

  for (int i = 0; i < epochs; i++) {
    // Select a random point
    Point chosenPoint = pts[rand() % numPts];

    double pred = line.m * chosenPoint.x + line.c;

    // Is our point above or below the line?
    // This 'theta' corresponds to p - p^
    double theta = chosenPoint.y - pred;

    // Since theta's sign is determined by if our point is above/below the line,
    // we can just add theta to the y-intercept
    line.c += theta * learningRate;

    // Theta is positive when the point is above our line, and vice versa
    // r, or 'x' is positive when the point is right of the y-axis, and vice
    // versa
    // Thus, theta * r is positive when the point is above our line, AND right
    // of the y-axis. Conversely, it is negative when the point is below our
    // line, AND left of the y-axis. This lines up with cases 1/4 and 2/3,
    // respectively.
    line.m += (chosenPoint.x * theta) * learningRate;
  }

  return line;
}

SimpleLine absoluteTrick(Point* pts, int numPts, int epochs, double learningRate) {
  // Make a random line
  SimpleLine line;
  line.m = 0;
  line.c = 0;

  for (int i = 0; i < epochs; i++) {
    // Select a random point
    Point chosenPoint = pts[rand() % numPts];

    double pred = line.m * chosenPoint.x + line.c;

    // Positive if our point is above the line, and vice versa
    double theta = chosenPoint.y - pred;

    if (theta > 0) {
      line.m += chosenPoint.x * learningRate;
      line.c += learningRate;
    } else {
      line.m -= chosenPoint.x * learningRate;
      line.c -= learningRate;
    }
  }

  return line;
}
