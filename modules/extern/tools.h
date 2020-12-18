#ifndef GRAPHMATRIX_TOOLS_H
#define GRAPHMATRIX_TOOLS_H

#endif //GRAPHMATRIX_TOOLS_H

#include <stdbool.h>
#include "limitedQueue.h"
#include "stretchy_buffers.h"
#include "al_string.h"
#include "array.h"


#define HOME_DIR       "C:\\code\\CGraphs 1.1\\"
#define JS_OUTPUT_PATH "C:\\code\\webLearning\\canvasGraph\\assets\\json\\coloredGraph.json"

#define _VALUE_OF(type,pointer)      *((type*)pointer)
#define new(type)                   malloc(sizeof(type))
#define new_const(type,value)       &((type){value})
#define new_block(type,how_much)    malloc(sizeof(type)*how_much)
#define del(ptr)                    free(ptr)

#define _FOR_(index,range)          for(int index=0;index<range;index++)
#define FOR(index,range)            _FOR_(index,range)

#define and &&
#define or ||

int bytescmp(char* _buf1,char* _buf2,size_t size);

void intmove(int* dst, int* src, int size);

int one_or_zero(float chance);

int fst_false(bool* arr,int size);

int positive_or_zero(int max, double chance);

