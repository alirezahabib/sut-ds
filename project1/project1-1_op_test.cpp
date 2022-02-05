#include <iostream>
#include <fstream>
using namespace std;


int main12() {
    for (int l = 1; l < 16; l++) {
        string address = "../input/input" + to_string(l) + ".txt";
        fstream myFile(address, ios_base::in);

        long n, k;
        myFile >> n >> k;

        int a[n];
        for (long i = 0; i < n; i++) myFile >> a[i];

        long op = 0;

        long i, j, m, sum, count = 0;

        for (i = 0; i < n; i++) {
            for (j = i; j < n; j++) {
                for (sum = 0, m = i; m <= j; m++) {
                    sum += a[m];
                    op++;
                }
                if (sum <= k) {
                    count++;
                    op++;
                }
            }
        }
        cout << op << endl;

    }

    return 0;
}
