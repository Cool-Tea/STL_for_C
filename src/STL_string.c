#include "../inc/STL_string.h"

//Initialization
//create
string CreateString() {
    string str;
    str.m_str = (char*)calloc(INITLEN + 1, sizeof(char));
    str.m_begin = str.m_end = str.m_str;
    str.m_size = 0;
    str.m_capacity = INITLEN;
    return str;
}
//create and set
string CreateAndSetString(const char* c_str) {
    string str;
    str.m_size = strlen(c_str);
    str.m_str = (char*)calloc(str.m_size + INITLEN + 1, sizeof(char));
    strcpy(str.m_str, c_str);
    str.m_capacity = str.m_size + INITLEN;
    str.m_begin = str.m_str;
    str.m_end = str.m_str + str.m_size;
    return str;
}
//copy
string CopyString(const string* str) {
    string str_copy;
    str_copy.m_size = str->m_size;
    str_copy.m_capacity = str->m_capacity;
    str_copy.m_str = (char*)calloc(str_copy.m_capacity + 1, sizeof(char));
    strcpy(str_copy.m_str, str->m_str);
    str_copy.m_begin = str_copy.m_str;
    str_copy.m_end = str_copy.m_str + str_copy.m_size;
    return str_copy;
}
//move
string MoveString(string* str) {
    string str_move;
    str_move.m_size = str->m_size;
    str_move.m_capacity = str->m_capacity;
    str_move.m_str = str->m_str;
    str_move.m_begin = str_move.m_str;
    str_move.m_end = str_move.m_str + str_move.m_size;
    str->m_str = str->m_begin = str->m_end = NULL;
    DeleteString(str);
    return str_move;
}
//delete
void DeleteString(string* str) {
    if (str->m_str != NULL) {
        free(str->m_str);
        str->m_str = str->m_begin = str->m_end = NULL;
    }
    str->m_size = str->m_capacity = 0;
}

//Functions
void string_set(string* str, const char* c_str) {
    string_clear(str);
    if (str->m_size <= strlen(c_str)) {
        str->m_str = (char*)realloc(str->m_str, (strlen(c_str) + INITLEN + 1) * sizeof(char));
    }
    strcpy(str->m_str, c_str);
    str->m_size = strlen(c_str);
    str->m_capacity = str->m_size + INITLEN;
    str->m_begin = str->m_str;
    str->m_end = str->m_str + str->m_size;
}

char string_at(string* str, size_t i) {
    return str->m_str[i];
}

void string_append(string* str_dest, const string* str_src) {
    str_dest->m_size += str_src->m_size;
    if (str_dest->m_capacity <= str_dest->m_size) {
        str_dest->m_str = (char*)realloc(str_dest->m_str,
            (str_dest->m_size + INITLEN + 1) * sizeof(char));
    }
    strcat(str_dest->m_str, str_src->m_str);
    str_dest->m_capacity = str_dest->m_size + INITLEN;
    str_dest->m_end = str_dest->m_str + str_dest->m_size;
}
void string_append_c_str(string* str, const char* c_str) {
    str->m_size += strlen(c_str);
    if (str->m_capacity <= str->m_size) {
        str->m_str = (char*)realloc(str->m_str, (str->m_size + INITLEN + 1) * sizeof(char));
    }
    strcat(str->m_str, c_str);
    str->m_capacity = str->m_size + INITLEN;
    str->m_end = str->m_str + str->m_size;
}

void string_assign(string* str, char c, size_t size) {
    memset(str->m_str, c, size);
    *(str->m_end) = '\0';
}

void string_clear(string* str) {
    memset(str->m_str, '\0', str->m_size);
}

void string_push_back(string* str, char c) {
    str->m_str[str->m_size++] = c;
    if (str->m_size == str->m_capacity) {
        str->m_str = (char*)realloc(str->m_str, (2 * str->m_capacity + 1) * sizeof(char));
        str->m_capacity *= 2;
        str->m_begin = str->m_str;
    }
    str->m_str[str->m_size] = '\0';
    str->m_end = str->m_str + str->m_size;
}
void string_pop_back(string* str) {
    if (str->m_size == 0) {
        return;
    }
    str->m_str[str->m_size - 1] = '\0';
    str->m_size--;
    str->m_end--;
}

void string_insert(string* str, char* iterator, char c) {
    string_push_back(str, c);
    for (char* it = str->m_end - 1; it != iterator; it--) {
        char tem = *it;
        *it = *(it - 1);
        *(it - 1) = tem;
    }
}

void string_erase(string* str, char* iterator) {
    str->m_size--;
    str->m_end--;
    for (char* it = iterator; it != str->m_end; it++) {
        *it = *(it + 1);
    }
    str->m_str[str->m_size] = '\0';
}

char* string_find(string* str, const char* c_str) {

}

void string_replace(string* str, char* iterator1, char* iterator2, const char* c_str) {
    string substr = string_substr(str, iterator2 - str->m_begin + 1, str->m_size - 1);
    memset(iterator1, '\0', str->m_end - iterator1);
    str->m_size = iterator1 - str->m_begin + 1;
    string_append_c_str(str, c_str);
    string_append(str, &substr);
    DeleteString(&substr);
}

void string_resize(string* str, size_t size) {
    str->m_str = realloc(str->m_str, (size + INITLEN + 1) * sizeof(char));
    str->m_size = size < str->m_size ? size : str->m_size;
    str->m_str[str->m_size] = '\0';
    str->m_capacity = size + INITLEN;
    str->m_begin = str->m_str;
    str->m_end = str->m_str + str->m_size;
}

string string_substr(string* str, size_t beg, size_t end) {
    string substr;
    substr.m_size = end - beg + 1;
    substr.m_capacity = substr.m_size + INITLEN;
    substr.m_str = (char*)calloc(substr.m_capacity + 1, sizeof(char));
    for (size_t i = 0; i < substr.m_size; i++) {
        substr.m_str[i] = str->m_str[beg + i];
    }
    substr.m_str[substr.m_size] = '\0';
    substr.m_begin = substr.m_str;
    substr.m_end = substr.m_str + substr.m_size;
    return substr;
}

void string_swap(string* str1, string* str2) {
    char* tem_p = str1->m_str;
    str1->m_str = str2->m_str;
    str2->m_str = tem_p;

    size_t tem = str1->m_size;
    str1->m_size = str2->m_size;
    str2->m_size = tem;
    tem = str1->m_capacity;
    str1->m_capacity = str2->m_capacity;
    str2->m_capacity = tem;

    str1->m_begin = str1->m_str;
    str1->m_end = str1->m_str + str1->m_size;

    str2->m_begin = str2->m_str;
    str2->m_end = str2->m_str + str2->m_size;
}

//Attributes
char string_front(string* str) {
    return str->m_str[0];
}
char string_back(string* str) {
    return str->m_str[str->m_size - 1];
}

char* string_begin(string* str) {
    return str->m_begin;
}
char* string_end(string* str) {
    return str->m_end;
}

size_t string_size(string* str) {
    return str->m_size;
}
size_t string_length(string* str) {
    return str->m_size;
}
size_t string_capacity(string* str) {
    return str->m_capacity;
}

size_t string_empty(string* str) {
    return str->m_size == 0;
}