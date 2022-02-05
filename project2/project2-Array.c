#include <stdio.h>

int main2() {
    long n;
    scanf("%ld", &n);
    long a[n];

    for (long i = 0; i < n; i++) scanf("%ld", &a[i]);

    long count = 0, len, j = n;
    do {
        len = j;
        j = 1;
        for (long i = 1; i < len; i++) if (a[i - 1] < a[i]) a[j++] = a[i];
        count++;
    } while (j < len);

    printf("%ld\n", count - 1);
    return 0;
}