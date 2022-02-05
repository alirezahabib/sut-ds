#include <stdio.h>

unsigned groups;
unsigned *rank;
unsigned *parent;
unsigned *xor_relation;

void fill_options(unsigned *options, unsigned n) {
    unsigned const base = 1000000007;
    unsigned const each = 147483634; // = 2^31 % base
    unsigned option = 1;

    for (int i = 0; i < n + 1; ++i) {
        options[i] = option;
        option = (unsigned long) option * each % base;
    }
}

struct Found {
    unsigned id;
    unsigned xor; // xor path to head
};


struct Found find(unsigned id) {
    struct Found ans;
    ans.xor = 0;

    while (id != parent[id]) {
        ans.xor ^= xor_relation[id];
        id = parent[id];
    }

    ans.id = id;
    return ans;
}


void merge(unsigned id1, unsigned id2, unsigned xor) {
    struct Found top1 = find(id1);
    struct Found top2 = find(id2);

    if (top1.id == top2.id) {
        groups *= (top1.xor ^ top2.xor) == xor;
        return;
    }

    xor ^= top1.xor ^ top2.xor;

    if (rank[top1.id] < rank[top2.id]) {
        parent[top1.id] = top2.id;
        xor_relation[top1.id] = xor;
    } else {
        parent[top2.id] = top1.id;
        xor_relation[top2.id] = xor;

        if (rank[top1.id] == rank[top2.id]) ++rank[top1.id];
    }

    --groups;
}


int main() {
    unsigned n, m;
    scanf("%u %u", &n, &m);

    unsigned temp1[n];
    unsigned temp2[n];
    unsigned temp3[n];
    rank = temp1;
    parent = temp2;
    xor_relation = temp3; // xor relation with parent

    unsigned options[n + 1];
    fill_options(options, n);
    options[0] = 0;

    for (unsigned i = 0; i < n; ++i) {
        rank[i] = 0;
        parent[i] = i;
        xor_relation[i] = 0;
    }

    groups = n;

    for (unsigned i = 0; i < m; ++i) {
        unsigned id1, id2, xor;
        scanf("%u %u %u", &id1, &id2, &xor);

        if (groups) merge(id1 - 1, id2 - 1, xor);
        printf("%u\n", options[groups]);
    }

    return 0;
}