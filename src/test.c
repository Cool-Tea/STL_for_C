#include <stdio.h>
#include "vector.h"

int main() {

    int_vector v = CreateIntVector();
    for (int i = 1; i <= 20; i++) {
        int_vector_push_back(&v, i);
    }
    int_vector u = CreateIntVector();
    int_vector_push_back(&u, 100);
    int_vector_push_back(&u, 200);
    int_vector_push_back(&u, 300);
    int_vector_push_back(&u, 400);
    int_vector_swap(&v, &u);
    for (int* it = v.m_begin; it != v.m_end; it++) {
        printf("%d ", *it);
    }
    puts("\n--------------------------");
    for (int* it = u.m_begin; it != u.m_end; it++) {
        printf("%d ", *it);
    }

    DeleteIntVector(&v);
    DeleteIntVector(&u);

    return 0;
}