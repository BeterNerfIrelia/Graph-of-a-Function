#ifndef DRAWFUNCTION_H_INCLUDED
#define DRAWFUNCTION_H_INCLUDED

#include "../../expressionEvaluator/expressionEvaluator/evaluator/evaluator.h"
#include <graphics.h>
#include <winbgim.h>


extern struct variabile var[1000];

extern char funC[512];
extern std::string fun;
extern Queue infixQ;
extern Queue postQ;
extern int graphicWindow;
extern double interval;
extern const unsigned int width;
extern const unsigned int height;
extern const unsigned int xCentru;
extern const unsigned int yCentru;
extern double xOffset;
extern double yOffset;
extern int graphColor;

void getFun();
void getInfixQueue();
void getPostQueue();
void getFunArray();
void makeWindow();
void getInterval();
void getGraphColor(int culaleasa);

void drawAxis();
void drawGraph(double interval);

#endif // DRAWFUNCTION_H_INCLUDED
