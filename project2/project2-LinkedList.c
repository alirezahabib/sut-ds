#include <stdio.h>

struct Node {
    long value;
    struct Node *next;
};

int main3() {
    long n, i;
    scanf("%ld", &n);
    struct Node a[n];

    for (i = 0; i < n; i++) scanf("%ld", &a[i].value);
    for (i = 0; i < n - 1; i++) a[i].next = &a[i + 1];
    a[n - 1].next = 0;

    long count = 0, removed;
    struct Node *current, *hold;
    do {
        removed = 0;
        hold = &a[0];
        current = &a[0];

        while (current->next != 0) {
            if (current->next->value > current->value) {
                hold->next = current->next;
                hold = current->next;
            } else removed++;
            current = current->next;
        }
        hold->next = 0;
        count++;
    } while (removed != 0);

    printf("%ld\n", count - 1);
    return 0;
}