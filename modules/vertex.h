#ifndef GRAPHMATRIX_VERTEX_H
#define GRAPHMATRIX_VERTEX_H

#endif //GRAPHMATRIX_VERTEX_H

#include "stdarg.h"

#ifndef GRAPHMATRIX_CONSOLECOLORS_H
#include "extern/consoleColors.h"
#endif

typedef struct vertex_s{
    int name;
    char color;
}vertex;

#define get_vrtx_color(pointer) (*((vertex*)pointer)).color
#define get_vrtx_name(pointer) (*((vertex*)pointer)).name


int get_vertex_index(vertex* array,int name, size_t count);

void print_vertex(const char* format, vertex v);