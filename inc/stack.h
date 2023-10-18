#ifndef _STACK_H_
#define _STACK_H_
#include <stdlib.h>
#include <string.h>
#define INITLEN 2

typedef struct {
    size_t m_size;
    size_t m_capacity;
    int* m_data;
} int_stack;

typedef struct {
    size_t m_size;
    size_t m_capacity;
    double* m_data;
} double_stack;

typedef struct {
    size_t m_size;
    size_t m_capacity;
    char* m_data;
} char_stack;

//Initialization
//create
int_stack CreateIntStack();
double_stack CreateDoubleStack();
char_stack CreateCharStack();
//copy
int_stack CopyIntStack(int_stack* stack);
double_stack CopyDoubleStack(double_stack* stack);
char_stack CopyCharStack(char_stack* stack);
//move
int_stack MoveIntStack(int_stack* stack);
double_stack MoveDoubleStack(double_stack* stack);
char_stack MoveCharStack(char_stack* stack);
//delete
void DeleteIntStack(int_stack* stack);
void DeleteDoubleStack(double_stack* stack);
void DeleteCharStack(char_stack* stack);

//Functions
void int_stack_push(int_stack* stack, int data);
void double_stack_push(double_stack* stack, double data);
void char_stack_push(char_stack* stack, char data);

void int_stack_pop(int_stack* stack);
void double_stack_pop(double_stack* stack);
void char_stack_pop(char_stack* stack);

void int_stack_swap(int_stack* stack1, int_stack* stack2);
void double_stack_swap(double_stack* stack1, double_stack* stack2);
void char_stack_swap(char_stack* stack1, char_stack* stack2);

//Attributes
int int_stack_top(int_stack* stack);
double double_stack_top(double_stack* stack);
char char_stack_top(char_stack* stack);

int int_stack_empty(int_stack* stack);
int double_stack_empty(double_stack* stack);
int char_stack_empty(char_stack* stack);

size_t int_stack_size(int_stack* stack);
size_t double_stack_size(double_stack* stack);
size_t char_stack_size(char_stack* stack);

#endif