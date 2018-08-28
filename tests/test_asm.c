// test_asm.c: tests for assemble() in assemble.c
//
// Copyright (c) 2018 Moaz Ashraf
// Licensed under MIT License
// Refer to LICENSE file

#include <stdio.h>
#include <stdlib.h>
#include "../src/asm.h"

void test_assemble(char *);

char *prog;

int main()
{
    prog = "test";

    test_assemble("NOP");

    return 0;
}

int get_statements(char *, Statement *);
int assemble(const Statement *, int, char *);
void print_hexdump(char *, int);

void test_assemble(char *s)
{
    // get statements
    Statement *statements = (Statement *) calloc(MAX_STMNTS, sizeof(Statement));
    int nstmnt = get_statements(s, statements);

    // assemble
    char outbuf[MAX_PROG];
    int outsize = assemble(statements, nstmnt, outbuf);

    // print hex dump of output
    print_hexdump(outbuf, outsize);
}

void print_hexdump(char buf[], int size)
{
    int pc;
    for (int i = 0, pc = 0; i < size; i += 16) {
        printf("%08x ", i);
        for (pc = i; pc < i + 16 && pc < size; pc++) {
            printf("%02x ", buf[i]);
        }
        putchar('\n');
    }
}