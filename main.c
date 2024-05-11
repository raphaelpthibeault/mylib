#include <stdio.h>
#include <str.h>

int main(void) {
    String *foo = init("HELLO, WORLD!");

    printf("'%s'\n", foo->data);
    uninit(foo);

    String *s = init("FOO");
    concat(s, " BAR");
    concat(s, "+BAZ");

    printf("'%s'\n", s->data);
    uninit(s);

    String *a = init("ABC");
    String *b = init("aaa");
    char *c = "CBC";

    bool res = s_equals_c(a, c);
    printf("'%s' == '%s' := %d\n", a->data, c, res);
    res = s_equals_s(a, b);
    printf("'%s' == '%s' := %d\n", a->data, b->data, res);

    uninit(a);
    uninit(b);

    return 0;
}
