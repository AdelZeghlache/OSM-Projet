#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL2_rotozoom.h>
#include <SDL2/SDL_ttf.h>
#include "calcul.h"
#include "data.h"

#define WIDTH 800
#define HEIGHT 800

void doPause();
int drawLine(SDL_Renderer *renderer,int x1, int y1,int x2, int y2,int width,int r,int g, int b, int a);
int drawRoad(SDL_Renderer *renderer, Way *way, Node *h_nodes, Bounds *m_bds, int draw_width ,int r, int g, int b, int alpha);
int drawMur(SDL_Renderer *renderer,Node * nds,int width,int nbPoints,int r, int g, int b, int a,Node *h_nodes,Bounds *m_bds);
//int writeText(SDL_Renderer *renderer,char *text,int fontWidth,int x, int y,int width,int height,int r,int g,int b,double angle);
