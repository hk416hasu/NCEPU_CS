// Intermediate Representation
#include <stdio.h>
#include <assert.h>
#include "ir.h"

#define IRlen 100
int ir[IRlen][4] = {{0}};
int pc = 1; // program counter for IR

#define unknown -1

int getPC() {
    return pc;
}

_Bool backpatch(struct set *s, int M) {
    // if s is an emptySet, do nothing
    if (s == NULL || s->len == 0) {
        return 0;
    }
    int i = 0;
    while (i < s->len) {
        if (s->arr[i] >= IRlen) {
            return 0;
        }
        ir[s->arr[i]][3] = M;
        i++;
    }
    return 1;
}

void genIR(int op, int arg1, int arg2, int res) {
    ir[pc][0] = op;
    ir[pc][1] = arg1;
    ir[pc][2] = arg2;
    ir[pc][3] = res;
    pc++;
    assert(pc < IRlen);
}

void printIR() {
    FILE *fp = fopen("./quad.txt", "w");
    int i = 1;
    for (i = 1; i < pc; i++) {
        fprintf(fp, "%d %d %d %d %d\n",
                i, ir[i][0], ir[i][1], ir[i][2], ir[i][3]);
    }
    fclose(fp);
}
