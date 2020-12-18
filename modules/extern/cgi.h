#ifndef GRAPHMATRIX_CGI_H
#define GRAPHMATRIX_CGI_H

#endif //GRAPHMATRIX_CGI_H
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define CONTENT_LENGTH  atoi(getenv("CONTENT_LENGTH"))
#define cnt_type(type)  printf("Content-type: %s\n\n",type)

char* post_data(int content_len);