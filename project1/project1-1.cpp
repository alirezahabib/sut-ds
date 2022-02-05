#include <iostream>
using namespace std;

int main() {
    long n, k;
    std::cin >> n;
    std::cin >> k;

    int a[n];
    for (long i = 0; i < n; i++) std::cin >> a[i];

    long i, j, m, sum, count = 0;

    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            for (sum = 0, m = i; m <= j; m++) sum += a[m];
            if (sum <= k) count++;
        }
    }
    std::cout << count << std::endl;

    return 0;
}
