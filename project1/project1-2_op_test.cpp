#include <iostream>
#include <fstream>
using namespace std;


int main() {
    for (int l = 1; l < 16; l++) {
        string address = "../input/input" + to_string(l) + ".txt";
        fstream myFile(address, ios_base::in);

        long n, k;

        myFile >> n >> k;

        int a[n];
        for (long i = 0; i < n; i++) myFile >> a[i];

        long op = 0;

        long i, j, sum, count = 0;

        for (i = 0; i < n; i++) {
            sum = 0;
            for (j = i; j < n; j++) {
                sum += a[j];
                op++;
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
