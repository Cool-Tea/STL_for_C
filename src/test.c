#include <stdio.h>
#include "STL_string.h"

int main() {

    string s = CreateAndSetString("hello world!");
    string_append_c_str(&s, "Hello string!");
    string_insert(&s, s.m_begin + 4, 'O');
    string_erase(&s, s.m_begin + 5);
    string_replace(&s, s.m_begin + 6, s.m_begin + 10, "STL");
    for (char* it = s.m_begin; it != s.m_end; it++) {
        printf("%c", *it);
    }
    printf("\n");
    char* re = string_find(&s, "Hello");
    for (size_t i = 0; i < 6; i++, re++) {
        printf("%c", *re);
    }
    DeleteString(&s);

    return 0;
}