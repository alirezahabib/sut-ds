#include <iostream>
#include <fstream>

using namespace std;


int main11() {
    for (int l = 1; l < 16; l++) {
        string address = "../input/input" + to_string(l) + ".txt";
        fstream myFile(address, ios_base::in);

        long n, k;
        myFile >> n >> k;

        int a[n];
        for (long i = 0; i < n; i++) myFile >> a[i];

        clock_t Start = clock();

        long i, j, m, sum, count = 0;

        for (i = 0; i < n; i++) {
            for (j = i; j < n; j++) {
                for (sum = 0, m = i; m <= j; m++) sum += a[m];
                if (sum <= k) count++;
            }
        }
        clock_t End = clock();
        cout << int((double(End - Start) / double(CLOCKS_PER_SEC)) * 1000000) << endl;

    }

    return 0;
}
