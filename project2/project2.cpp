#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> stack;
    int n;
    cin >> n;
    int a[n], kills[n], max_kills = 0, i;

    for (i = 0; i < n; i++) {
        cin >> a[i];
        kills[i] = 0;
    }

    for (i = n - 1; i >= 0; stack.push(i--)) {
        while (!stack.empty() && a[stack.top()] < a[i]) {
            kills[i] = max(kills[i] + 1, kills[stack.top()]);
            max_kills = max(max_kills, kills[i]);
            stack.pop();
        }
    }

    cout << max_kills;
    return 0;
}
