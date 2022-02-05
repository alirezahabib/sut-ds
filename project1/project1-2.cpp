#include <iostream>

int main2() {
    long n, k;
    std::cin >> n;
    std::cin >> k;

    int a[n];
    for (long i = 0; i < n; i++) std::cin >> a[i];

    long i, j, sum, count = 0;

    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = i; j < n; j++) {
            sum += a[j];
            if (sum <= k) count++;
        }
    }
    //std::cout << count << std::endl;

    return 0;
}
