#ifndef STR_H
#define STR_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

typedef struct s_string {
  unsigned int size;
  char data[0]; // data[0] is pretty niftry trick to make the entire structure have variable length
} String;

unsigned int length(char *str) {
    int n;
    char *p;

    for (n = 0, p = str; *p; ++p, ++n);

    return n;
}

void copy(void *dst, const void *src, const unsigned int n) {
    const char *psrc;
    char *pdst;
    unsigned int i;

    for (i = n, psrc = (const char*)src, pdst = (char *)dst; i; ++psrc, ++pdst, --i) {
        *pdst = *psrc;
    }
}

String *init(char *str) {
    unsigned int n, size;
    char *p;
    String *s;

    n = length(str);
    size = (n + 1) + sizeof(struct s_string);
    s = (String*) malloc(size);
    assert(s);

    *s = (String){};
    copy(s->data, str, n);
    s->size = n;

    p = s->data + n;
    *p = 0;

    return s;
}

bool uninit(String *str) {
    free(str);
    return true;
}

bool concat(String* dst, char* src) {
    unsigned int n, curr_size, new_size;
    char *p;
    String *s;

    n = length(src);
    curr_size = dst->size + sizeof(struct s_string);
    new_size = curr_size + n;

    s = (String *)realloc(dst, new_size);

    if (!s)
        return false;

    p = s->data + s->size;
    copy(p, src, n);
    s->size += n;

    p = s->data + s->size;
    *p = 0;

    return true;
}

bool s_equals_c(String *a, char *b) {
    unsigned int n, i;

    n = length(b);
    if (a->size != n) return false;

    for (i = 0; i < n; ++i) {
        if (a->data[i] != b[i])
            return false;
    }

    return true;
}

bool s_equals_s(String *a, String *b) {
    unsigned int i;

    if (a->size != b->size)
        return false;

    for (i = 0; i < a->size; ++i) {
        if (a->data[i] != b->data[i])
            return false;
    }

    return true;
}

#ifdef __cplusplus
};
#endif // __cplusplus

#endif // STR_H
