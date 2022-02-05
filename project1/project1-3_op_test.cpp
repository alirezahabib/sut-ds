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
        long i, p = 0, sum = 0, count = 0;

        for (i = 0; i < n; i++) {
            sum += a[i];
            op++;
            while (sum > k) {
                sum -= a[p++];
                op += 2;
            }
            count += i - p + 1;
            op += 3;
        }

        cout << op << endl;
    }

    return 0;
}
