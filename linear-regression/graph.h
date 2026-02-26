#ifndef GRAPH_H
#define GRAPH_H

typedef struct SimpleLine SimpleLine;

typedef struct MVLine MVLine;

typedef struct Point {
  double x;
  double y;
} Point;

typedef struct PointSet {
  Point* points;
  int len;
} PointSet;

Point* makePoints(double x[], int xLen, double y[], int yLen);

PointSet* makePointSet(Point* points, int len);

void drawGraph(PointSet* ps);

void drawSimpleLine(PointSet* ps, SimpleLine line);

void drawMVLine(PointSet** ps, int len, MVLine line);

#endif // GRAPH_H
