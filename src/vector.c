#include "../inc/vector.h"

int_vector CreateIntVector() {
    int_vector v;
    v.m_arr = (int*)calloc(INITLEN + 1, sizeof(int));
    v.m_begin = v.m_end = v.m_arr;
    v.m_size = 0;
    v.m_capacity = INITLEN;
    return v;
}
double_vector CreatedoubleVector() {
    double_vector v;
    v.m_arr = (double*)calloc(INITLEN + 1, sizeof(double));
    v.m_begin = v.m_end = v.m_arr;
    v.m_size = 0;
    v.m_capacity = INITLEN;
    return v;
}

int_vector CopyIntVector(int_vector* v) {
    int_vector v_copy;
    v_copy.m_arr = (int*)calloc(v->m_capacity + 1, sizeof(int));
    v_copy.m_begin = v_copy.m_arr;
    v_copy.m_size = v->m_size;
    v_copy.m_capacity = v->m_capacity;
    v_copy.m_end = v_copy.m_arr + v_copy.m_size;
    for (int* it1 = v->m_begin, *it2 = v_copy.m_begin; it1 != v->m_end; it1++, it2++) {
        *it2 = *it1;
    }
    return v_copy;
}
double_vector CopyDoubleVector(double_vector* v) {
    double_vector v_copy;
    v_copy.m_arr = (double*)calloc(v->m_capacity + 1, sizeof(double));
    v_copy.m_begin = v_copy.m_arr;
    v_copy.m_size = v->m_size;
    v_copy.m_capacity = v->m_capacity;
    v_copy.m_end = v_copy.m_arr + v_copy.m_size;
    for (double* it1 = v->m_begin, *it2 = v_copy.m_begin; it1 != v->m_end; it1++, it2++) {
        *it2 = *it1;
    }
    return v_copy;
}

int_vector MoveIntVector(int_vector* v) {
    int_vector v_move;
    v_move.m_arr = v->m_arr;
    v_move.m_begin = v->m_begin;
    v_move.m_end = v->m_end;
    v->m_arr = v->m_begin = v->m_end = NULL;
    v_move.m_size = v->m_size;
    v_move.m_capacity = v->m_capacity;
    DeleteIntVector(v);
    return v_move;
}
double_vector MoveDoubleVector(double_vector* v) {
    double_vector v_move;
    v_move.m_arr = v->m_arr;
    v_move.m_begin = v->m_begin;
    v_move.m_end = v->m_end;
    v->m_arr = v->m_begin = v->m_end = NULL;
    v_move.m_size = v->m_size;
    v_move.m_capacity = v->m_capacity;
    DeleteDoubleVector(v);
    return v_move;
}

void DeleteIntVector(int_vector* v) {
    if (v->m_arr != NULL) {
        free(v->m_arr);
        v->m_arr = v->m_begin = v->m_end = NULL;
    }
    v->m_capacity = 0;
    v->m_size = 0;
}
void DeleteDoubleVector(double_vector* v) {
    if (v->m_arr != NULL) {
        free(v->m_arr);
        v->m_arr = v->m_begin = v->m_end = NULL;
    }
    v->m_capacity = 0;
    v->m_size = 0;
}

int int_vector_at(int_vector* v, size_t i) {
    return v->m_arr[i];
}
double double_vector_at(double_vector* v, size_t i) {
    return v->m_arr[i];
}

void int_vector_push_back(int_vector* v, int n) {
    v->m_arr[v->m_size] = n;
    v->m_size++;
    if (v->m_size == v->m_capacity) {
        v->m_arr = (int*)realloc(v->m_arr, (2 * v->m_capacity + 1) * sizeof(int));
        v->m_capacity *= 2;
        v->m_begin = v->m_arr;
    }
    v->m_end = v->m_arr + v->m_size;
}
void double_vector_push_back(double_vector* v, double n) {
    v->m_arr[v->m_size] = n;
    v->m_size++;
    if (v->m_size == v->m_capacity) {
        v->m_arr = (double*)realloc(v->m_arr, (2 * v->m_capacity + 1) * sizeof(double));
        v->m_capacity *= 2;
        v->m_begin = v->m_arr;
    }
    v->m_end = v->m_arr + v->m_size;
}

void int_vector_pop_back(int_vector* v) {
    if (v->m_size == 0) {
        return;
    }
    v->m_arr[v->m_size - 1] = 0;
    v->m_size--;
    v->m_end--;
}
void double_vector_pop_back(double_vector* v) {
    if (v->m_size == 0) {
        return;
    }
    v->m_arr[v->m_size - 1] = 0;
    v->m_size--;
    v->m_end--;
}

void int_vector_resize(int_vector* v, size_t size) {
    v->m_arr = (int*)realloc(v->m_arr, (size + 1) * sizeof(int));
    v->m_begin = v->m_arr;
    v->m_size = size < v->m_size ? size : v->m_size;
    v->m_end = v->m_arr + v->m_size;
    v->m_capacity = size == 0 ? INITLEN : size;
}
void double_vector_resize(double_vector* v, size_t size) {
    v->m_arr = (double*)realloc(v->m_arr, (size + 1) * sizeof(double));
    v->m_begin = v->m_arr;
    v->m_size - size < v->m_size ? size : v->m_size;
    v->m_end = v->m_arr + v->m_size;
    v->m_capacity = size == 0 ? INITLEN : size;
}

void int_vector_clear(int_vector* v) {
    for (int* it = v->m_begin; it != v->m_end; it++) {
        *it = 0;
    }
    v->m_size = 0;
    v->m_end = v->m_arr;
}
void double_vector_clear(double_vector* v) {
    for (double* it = v->m_begin; it != v->m_begin; it++) {
        *it = 0.0;
    }
    v->m_size = 0;
    v->m_end = v->m_arr;
}

void int_vector_insert(int_vector* v, int* iterator, int n) {
    int_vector_push_back(v, n);
    for (int* it = v->m_end - 1; it != iterator; it--) {
        *it ^= *(it - 1);
        *(it - 1) ^= *it;
        *it ^= *(it - 1);
    }
}
void double_vector_insert(double_vector* v, double* iterator, double n) {
    double_vector_push_back(v, n);
    for (double* it = v->m_end - 1; it != iterator; it--) {
        double tem = *(it - 1);
        *it = *(it - 1);
        *(it - 1) = tem;
    }
}

void int_vector_erase(int_vector* v, int* iterator) {
    v->m_end--;
    v->m_size--;
    for (int* it = iterator; it != v->m_end; it++) {
        *it = *(it + 1);
    }
    v->m_arr[v->m_size] = 0;
}
void double_vector_erase(double_vector* v, double* iterator) {
    v->m_end--;
    v->m_size--;
    for (double* it = iterator; it != v->m_end; it++) {
        *it = *(it + 1);
    }
    v->m_arr[v->m_size] = 0.0;
}

void int_vector_swap(int_vector* v, int_vector* u) {
    int* tem = v->m_arr;
    v->m_arr = u->m_arr;
    u->m_arr = tem;
    v->m_begin = v->m_arr;
    u->m_begin = u->m_arr;
    tem = v->m_end;
    v->m_end = u->m_end;
    u->m_end = tem;
    tem = NULL;

    int t = v->m_size;
    v->m_size = u->m_size;
    u->m_size = t;
    t = v->m_capacity;
    v->m_capacity = u->m_capacity;
    u->m_capacity = t;
}
void double_vector_swap(double_vector* v, double_vector* u) {
    double* tem = v->m_arr;
    v->m_arr = u->m_arr;
    u->m_arr = tem;
    v->m_begin = v->m_arr;
    u->m_begin = u->m_arr;
    tem = v->m_end;
    v->m_end = u->m_end;
    u->m_end = tem;
    tem = NULL;

    double t = v->m_size;
    v->m_size = u->m_size;
    u->m_size = t;
    t = v->m_capacity;
    v->m_capacity = u->m_capacity;
    u->m_capacity = t;
}

size_t int_vector_size(int_vector* v) {
    return v->m_size;
}
size_t double_vector_size(double_vector* v) {
    return v->m_size;
}

size_t int_vector_capacity(int_vector* v) {
    return v->m_capacity;
}
size_t double_vector_capacity(double_vector* v) {
    return v->m_capacity;
}

size_t int_vector_empty(int_vector* v) {
    return v->m_size == 0;
}
size_t double_vector_empty(double_vector* v) {
    return v->m_size == 0;
}

int int_vector_front(int_vector* v) {
    return v->m_arr[0];
}
double double_vector_front(double_vector* v) {
    return v->m_arr[0];
}
int int_vector_back(int_vector* v) {
    return v->m_arr[v->m_size - 1];
}
double double_vector_back(double_vector* v) {
    return v->m_arr[v->m_size - 1];
}

int* int_vector_begin(int_vector* v) {
    return v->m_begin;
}
int* int_vector_end(int_vector* v) {
    return v->m_end;
}
double* double_vector_begin(double_vector* v) {
    return v->m_begin;
}
double* double_vector_end(double_vector* v) {
    return v->m_end;
}
