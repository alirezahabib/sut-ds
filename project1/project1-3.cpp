#include <iostream>

int main3() {
    long n, k;
    std::cin >> n;
    std::cin >> k;

    int a[n];
    for (long i = 0; i < n; i++) std::cin >> a[i];

    long i, p = 0, sum = 0, count = 0;

    for (i = 0; i < n; i++) {
        sum += a[i];
        while (sum > k) sum -= a[p++];
        count += i - p + 1;
    }
    //std::cout << count << std::endl;

    return 0;
}
