#include <stdio.h>
#include <stdlib.h>
#include "./graph.h"

Point* makePoints(double x[], int xLen, double y[], int yLen) {
  if (xLen != yLen) {
    printf("xLen neq yLen, truncating to smaller...\n");
  }

  int smallerLen = xLen < yLen ? xLen : yLen;

  Point *pts = malloc(smallerLen * sizeof(Point));

  for (int i = 0; i < smallerLen; i++) {
    pts[i].x = x[i];
    pts[i].y = y[i];
  }

  return pts;
}

void drawGraph(Point points[], int pointLen){
  FILE *gnuplot = popen("gnuplot", "w");

  if (!gnuplot){
    printf("gnuplot not found!\n");
  }

  fprintf(gnuplot, "set terminal kittycairo\n");
  fprintf(gnuplot, "plot '-'\n");

  for (int i = 0; i < pointLen; i++) {
    fprintf(gnuplot, "%g %g\n", points[i].x, points[i].y);
  }

  fprintf(gnuplot, "e\n");
  fflush(gnuplot);
  pclose(gnuplot);
}
