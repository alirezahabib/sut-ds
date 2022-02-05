#include <iostream>
using namespace std;

unsigned max_partition(const string &s) {
    unsigned l = 0, r = s.length() - 1, count = 0, hash2 = 0;
    unsigned long long hash_left = 0, hash_right = 0;
    unsigned long long m = 1;

    while (l < r) {
        hash2 += (unsigned) s[l] - (unsigned) s[r];

        hash_left = hash_left * 26 + (unsigned) s[l++] - 97;
        hash_right = hash_right + ((unsigned) s[r--] - 97) * m;
        m *= 26;

        if (hash2 == 0 and hash_left == hash_right) {
            count += 2;
            hash_left = 0;
            hash_right = 0;
            m = 1;
        }
    }

    if (m != 1 or r == l) count++;
    return count;
}


int main4() {
    unsigned n;

    cin >> n;
    string s;

    for (unsigned i = 0; i < n; i++) {
        cin >> s;
        cout << max_partition(s) << endl;
    }

    return 0;
}