#include "../inc/stack.h"

//Initialization
//create
int_stack CreateIntStack() {
    int_stack stack;
    stack.m_data = (int*)calloc(INITLEN, sizeof(int));
    stack.m_capacity = INITLEN;
    stack.m_size = 0;
    return stack;
}
double_stack CreateDoubleStack() {
    double_stack stack;
    stack.m_data = (double*)calloc(INITLEN, sizeof(double));
    stack.m_capacity = INITLEN;
    stack.m_size = 0;
    return stack;
}
char_stack CreateCharStack() {
    char_stack stack;
    stack.m_data = (char*)calloc(INITLEN, sizeof(char));
    memset(stack.m_data, '\0', INITLEN);
    stack.m_capacity = INITLEN;
    stack.m_size = 0;
    return stack;
}
//copy
int_stack CopyIntStack(int_stack* stack) {
    int_stack stack_copy;
    stack_copy.m_capacity = stack->m_capacity;
    stack_copy.m_size = stack->m_size;
    stack_copy.m_data = (int*)calloc(stack->m_capacity, sizeof(int));
    for (size_t i = 0; i < stack->m_size; i++) {
        stack_copy.m_data[i] = stack->m_data[i];
    }
    return stack_copy;
}
double_stack CopyDoubleStack(double_stack* stack) {
    double_stack stack_copy;
    stack_copy.m_capacity = stack->m_capacity;
    stack_copy.m_size = stack->m_size;
    stack_copy.m_data = (double*)calloc(stack->m_capacity, sizeof(double));
    for (size_t i = 0; i < stack->m_size; i++) {
        stack_copy.m_data[i] = stack->m_data[i];
    }
    return stack_copy;
}
char_stack CopyCharStack(char_stack* stack) {
    char_stack stack_copy;
    stack_copy.m_capacity = stack->m_capacity;
    stack_copy.m_size = stack->m_size;
    stack_copy.m_data = (char*)calloc(stack->m_capacity, sizeof(char));
    memset(stack_copy.m_data, '\0', stack_copy.m_capacity);
    for (size_t i = 0; i < stack->m_size; i++) {
        stack_copy.m_data[i] = stack->m_data[i];
    }
    return stack_copy;
}
//move
int_stack MoveIntStack(int_stack* stack) {
    int_stack stack_move;
    stack_move.m_size = stack->m_size;
    stack_move.m_capacity = stack->m_capacity;
    stack_move.m_data = stack->m_data;
    stack->m_data = NULL;
    DeleteIntStack(stack);
    return stack_move;
}
double_stack MoveDoubleStack(double_stack* stack) {
    double_stack stack_move;
    stack_move.m_size = stack->m_size;
    stack_move.m_capacity = stack->m_capacity;
    stack_move.m_data = stack->m_data;
    stack->m_data = NULL;
    DeleteDoubleStack(stack);
    return stack_move;
}
char_stack MoveCharStack(char_stack* stack) {
    char_stack stack_move;
    stack_move.m_size = stack->m_size;
    stack_move.m_capacity = stack->m_capacity;
    stack_move.m_data = stack->m_data;
    stack->m_data = NULL;
    DeleteCharStack(stack);
    return stack_move;
}
//delete
void DeleteIntStack(int_stack* stack) {
    if (stack->m_data != NULL) {
        free(stack->m_data);
        stack->m_data = NULL;
    }
    stack->m_capacity = 0;
    stack->m_size = 0;
}
void DeleteDoubleStack(double_stack* stack) {
    if (stack->m_data != NULL) {
        free(stack->m_data);
        stack->m_data = NULL;
    }
    stack->m_capacity = 0;
    stack->m_size = 0;
}
void DeleteCharStack(char_stack* stack) {
    if (stack->m_data != NULL) {
        free(stack->m_data);
        stack->m_data = NULL;
    }
    stack->m_capacity = 0;
    stack->m_size = 0;
}

//Functions
void int_stack_push(int_stack* stack, int data) {
    stack->m_data[stack->m_size] = data;
    stack->m_size++;
    if (stack->m_size == stack->m_capacity) {
        stack->m_data = (int*)realloc(stack->m_data, stack->m_capacity * 2 * sizeof(int));
        stack->m_capacity *= 2;
    }
}
void double_stack_push(double_stack* stack, double data) {
    stack->m_data[stack->m_size] = data;
    stack->m_size++;
    if (stack->m_size == stack->m_capacity) {
        stack->m_data = (double*)realloc(stack->m_data, stack->m_capacity * 2 * sizeof(double));
        stack->m_capacity *= 2;
    }
}
void char_stack_push(char_stack* stack, char data) {
    stack->m_data[stack->m_size] = data;
    stack->m_size++;
    if (stack->m_size == stack->m_capacity) {
        stack->m_data = (char*)realloc(stack->m_data, stack->m_capacity * 2 * sizeof(char));
        stack->m_capacity *= 2;
    }
}

void int_stack_pop(int_stack* stack) {
    if (stack->m_size <= 0) {
        return;
    }
    stack->m_data[stack->m_size - 1] = 0;
    stack->m_size--;
}
void double_stack_pop(double_stack* stack) {
    if (stack->m_size <= 0) {
        return;
    }
    stack->m_data[stack->m_size - 1] = 0;
    stack->m_size--;
}
void char_stack_pop(char_stack* stack) {
    if (stack->m_size <= 0) {
        return;
    }
    stack->m_data[stack->m_size - 1] = '\0';
    stack->m_size--;
}

void int_stack_swap(int_stack* stack1, int_stack* stack2) {
    int* tem_p = stack1->m_data;
    stack1->m_data = stack2->m_data;
    stack2->m_data = tem_p;

    size_t tem = stack1->m_size;
    stack1->m_size = stack2->m_size;
    stack2->m_size = tem;

    tem = stack1->m_capacity;
    stack1->m_capacity = stack2->m_capacity;
    stack2->m_capacity = tem;
}
void double_stack_swap(double_stack* stack1, double_stack* stack2) {
    double* tem_p = stack1->m_data;
    stack1->m_data = stack2->m_data;
    stack2->m_data = tem_p;

    size_t tem = stack1->m_size;
    stack1->m_size = stack2->m_size;
    stack2->m_size = tem;

    tem = stack1->m_capacity;
    stack1->m_capacity = stack2->m_capacity;
    stack2->m_capacity = tem;
}
void char_stack_swap(char_stack* stack1, char_stack* stack2) {
    char* tem_p = stack1->m_data;
    stack1->m_data = stack2->m_data;
    stack2->m_data = tem_p;

    size_t tem = stack1->m_size;
    stack1->m_size = stack2->m_size;
    stack2->m_size = tem;

    tem = stack1->m_capacity;
    stack1->m_capacity = stack2->m_capacity;
    stack2->m_capacity = tem;
}

//Attributes
int int_stack_top(int_stack* stack) {
    return stack->m_data[stack->m_size - 1];
}
double double_stack_top(double_stack* stack) {
    return stack->m_data[stack->m_size - 1];
}
char char_stack_top(char_stack* stack) {
    return stack->m_data[stack->m_size - 1];
}

int int_stack_empty(int_stack* stack) {
    return stack->m_size == 0;
}
int double_stack_empty(double_stack* stack) {
    return stack->m_size == 0;
}
int char_stack_empty(char_stack* stack) {
    return stack->m_size == 0;
}

size_t int_stack_size(int_stack* stack) {
    return stack->m_size;
}
size_t double_stack_size(double_stack* stack) {
    return stack->m_size;
}
size_t char_stack_size(char_stack* stack) {
    return stack->m_size;
}
