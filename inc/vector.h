#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <stdlib.h>
#define INITLEN 2

typedef struct {
    size_t m_size;
    size_t m_capacity;
    int* m_arr;
    int* m_begin;
    int* m_end;
} int_vector;

typedef struct {
    size_t m_size;
    size_t m_capacity;
    double* m_arr;
    double* m_begin;
    double* m_end;
} double_vector;

//Initialization and Delete
//default
int_vector CreateIntVector();
double_vector CreateDoubleVector();
//copy
int_vector CopyIntVector(int_vector* v);
double_vector CopyDoubleVector(double_vector* v);
//move
int_vector MoveIntVector(int_vector* v);
double_vector MoveDoubleVector(double_vector* v);
//delete
void DeleteIntVector(int_vector* v);
void DeleteDoubleVector(double_vector* v);

//Functions
int int_vector_at(int_vector* v, size_t i);
double double_vector_at(double_vector* v, size_t i);

void int_vector_push_back(int_vector* v, int n);
void double_vector_push_back(double_vector* v, double n);

void int_vector_pop_back(int_vector* v);
void double_vector_pop_back(double_vector* v);

void int_vector_resize(int_vector* v, size_t size);
void double_vector_resize(double_vector* v, size_t size);

void int_vector_clear(int_vector* v);
void double_vector_clear(double_vector* v);

void int_vector_insert(int_vector* v, int* iterator, int n);
void double_vector_insert(double_vector* v, double* iterator, double n);

void int_vector_erase(int_vector* v, int* iterator);
void double_vector_erase(double_vector* v, double* iterator);

void int_vector_swap(int_vector* v, int_vector* u);
void double_vector_swap(double_vector* v, double_vector* u);

//Attributes
size_t int_vector_size(int_vector* v);
size_t double_vector_size(double_vector* v);

size_t int_vector_capacity(int_vector* v);
size_t double_vector_capacity(double_vector* v);

int int_vector_empty(int_vector* v);
double double_vector_empty(double_vector* v);

int int_vector_front(int_vector* v);
double double_vector_front(double_vector* v);
int int_vector_back(int_vector* v);
double double_vector_back(double_vector* v);

int* int_vector_begin(int_vector* v);
int* int_vector_end(int_vector* v);
double* double_vector_begin(double_vector* v);
double* double_vector_end(double_vector* v);

#endif