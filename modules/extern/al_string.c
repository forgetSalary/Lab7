//#include "al_string.h"
//
////very unsafe
//int _cdecl str_len(const char* str) {//args: dward pointer to str
//    int length;
//    _asm {
////        push ebp;           //prologue
////        mov ebp, esp;       //
//
//        mov edx, [ebp + 8]; //pointer to str
//        mov eax, 0;         //init eax as a counter
//
//        for_begin:          //while next char != 0 loop it
//            cmp[edx], 0;    //if next char == 0, then end loop
//            je end_loop;    //
//
//            inc eax;        //else increment counter
//            add edx, 1;     //and poiner
//
//        jmp for_begin;  //loop it
//
//        end_loop:
//        move length, eax;
//
////        pop ebp;        //epilogue
//    }
//    return length;
//}
//
//void str_cpy(char* dst, const char* src, int size) {
//    for (int i = 0; i < size; i++) {
//        dst[i] = src[i];
//    }
//}
//
//string_t* str_init(int data_size){
//    string_t* string = malloc(sizeof(string_t));
//    string->data = malloc(data_size);
//    string->data_size = data_size;
//
//    return string;
//}
//
//void str_free(string_t* string){
//    free(string->data);
//    free(string);
//}
//
//string_t* str_del(string_t* string) {
//    free(string->data);
//    free(string);
//}
//
//string_t* str_dup(const char* src) {
//    size_t new_length = str_len(src);
//    string_t* new_str = str_init(new_length+1);
//
//    str_cpy(new_str->data, src, new_length + 1);
//    new_str->data_size = new_length + 1;
//    new_str->lenght = new_length;
//}
//
//void str_cat(string_t* _buf1, string_t* _buf2) {
//    size_t new_size = _buf1->lenght + _buf2->lenght;
//    _buf1->data = realloc(_buf1->data,new_size+1);
//    _buf1->data_size += _buf2->lenght;
//    _buf1->lenght = new_size;
//
//    char* end_of_src = (_buf1->data + new_size);
//
//    str_cpy(end_of_src,_buf2->data,_buf2->lenght);
//
//    str_free(_buf2);
//}
//
//string_t* format(string_t* format,...) {
//    char* next_arg = format;
//
//    string_t *result = str_init(1);
//
//    int count;
//
//    int flag;//0 - format;1 - data;
//    for (int i = 0; i < format->lenght; i++) {
//        if (format->data[i] == '%') {
//            switch (format->data[i+1]) {
//                case 'd':
//                    next_arg += sizeof()
//
//
//                    break;
//                case 's':
//                    break;
//                case 'f':
//                    break;
//
//            }
//        }
//    }
//}