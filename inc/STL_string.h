#ifndef _STRING_H_
#define _STRING_H_
#include <stdlib.h>
#include <string.h>
#define INITLEN 2

typedef struct {
    size_t m_size;
    size_t m_capacity;
    char* m_str;
    char* m_begin;
    char* m_end;
} string;

//Initialization
//create
string CreateString();
//create and set
string CreateAndSetString(const char* c_str);
//copy
string CopyString(const string* str);
//move
string MoveString(string* str);
//delete
void DeleteString(string* str);

//Functions
void string_set(string* str, const char* c_str);
//void string_getline(string* str);

char string_at(string* str, size_t i);

void string_append(string* str_dest, const string* str_src);
void string_append_c_str(string* str, const char* c_str);

void string_assign(string* str, char c, size_t size);

void string_clear(string* str);

void string_push_back(string* str, char c);
void string_pop_back(string* str);

void string_insert(string* str, char* iterator, char c);

void string_erase(string* str, char* iterator);

char* string_find(string* str, const char* c_str);

void string_replace(string* str, char* iterator1, char* iterator2, const char* c_str);

void string_resize(string* str, size_t size);

string string_substr(string* str, size_t beg, size_t end);

void string_swap(string* str1, string* str2);

//Attributes
char string_front(string* str);
char string_back(string* str);

char* string_begin(string* str);
char* string_end(string* str);

size_t string_size(string* str);
size_t string_length(string* str);
size_t string_capacity(string* str);

size_t string_empty(string* str);

#endif