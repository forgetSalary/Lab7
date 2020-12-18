#include "vertex.h"

int get_vertex_index(vertex* array,int name, size_t count){
    for (int i=0; i<count; i++){
        if (array[i].name == name){
            return i;
        }
    }
    return -1;
}

int chrcount(const char* _String,char _Byte){
    int len = strlen(_String);

    int count=0;
    for (int i = 0;i<len;i++){
        if (_String[i]==_Byte){
            count++;
        }
    }

    return count;
}

void print_vertex(const char* format, vertex v){
    char* index = strstr(format,"%v");
    index[1]='d';
    set_color(v.color);
    printf(format,v.name);
    index[1]='v';
    set_color(DEFAULT_CONSOLE_COLOR);
}