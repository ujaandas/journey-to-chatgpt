#include <stdio.h>
#include <stdlib.h>
#include "./graph.h"
#include "./linreg.h"

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

PointSet* makePointSet(Point* points, int len) {
  PointSet *ps = malloc(sizeof(PointSet));

  ps->points = points;
  ps->len = len;

  return ps;
}

void drawGraph(PointSet* ps) {
  FILE *gnuplot = popen("gnuplot", "w");

  if (!gnuplot){
    printf("gnuplot not found!\n");
  }

  fprintf(gnuplot, "set terminal kittycairo\n");
  fprintf(gnuplot, "plot '-'\n");

  for (int i = 0; i < ps->len; i++) {
    fprintf(gnuplot, "%g %g\n", ps->points[i].x, ps->points[i].y);
  }

  fprintf(gnuplot, "e\n");
  fflush(gnuplot);
  pclose(gnuplot);
}

void drawGraphComplex(PointSet** ps, int len) {

}

void drawSimpleLine(PointSet* ps, Line line) {
  FILE *gnuplot = popen("gnuplot", "w");

  if (!gnuplot) {
    printf("gnuplot not found!\n");
    return;
  }

  fprintf(gnuplot, "set terminal kittycairo\n");

  fprintf(gnuplot, "f(x) = %f*x + %f\n", line.m, line.c);

  fprintf(gnuplot, "plot '-' with points title 'Data', "
      "f(x) with lines title 'Regression'\n");

  for (int i = 0; i < ps->len; i++) {
    fprintf(gnuplot, "%g %g\n", ps->points[i].x, ps->points[i].y);
  }

  fprintf(gnuplot, "e\n");
  fflush(gnuplot);
  pclose(gnuplot);
}
