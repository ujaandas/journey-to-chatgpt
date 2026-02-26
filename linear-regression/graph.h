#ifndef GRAPH_H
#define GRAPH_H

typedef struct Point {
  double x;
  double y;
} Point;

Point* makePoints(double x[], int xLen, double y[], int yLen);

void drawGraph(Point points[]);

#endif // GRAPH_H
