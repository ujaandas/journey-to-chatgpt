#ifndef GRAPH_H
#define GRAPH_H

typedef struct Line Line;

typedef struct Point {
  double x;
  double y;
} Point;

Point* makePoints(double x[], int xLen, double y[], int yLen);

void drawGraph(Point points[], int pointLen);

void drawLine(Point points[], int pointLen, Line line);

#endif // GRAPH_H
