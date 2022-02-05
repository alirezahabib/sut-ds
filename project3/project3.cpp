#include <iostream>
#include <map>
#include <set>

using namespace std;

enum class Direction {
    UP, LEFT
};

int main3() {
    std::set<long> x_set;
    map<long, long> x_to_num;
    map<long, Direction> x_to_dir;

    long n, m;
    cin >> n >> m;

    x_set.insert(n + 1);
    x_to_dir.insert({n + 1, Direction::LEFT});
    x_to_num.insert({n + 1, n + 2});

    x_set.insert(0);
    x_to_dir.insert({0, Direction::UP});
    x_to_num.insert({0, n + 1});


    for (long i = 0; i < m; i++) {
        char dir;
        long x;
        long y;

        cin >> x >> y >> dir;

        Direction direction;
        if (dir == 'U' || dir == 'u') direction = Direction::UP;
        else direction = Direction::LEFT;

        if (x_set.find(x) != x_set.end()) {
            cout << 0 << endl;
            continue;
        }

        x_set.insert(x);
        long upper, lower, num;

        switch (direction) {
            case Direction::UP:
                upper = *x_set.upper_bound(x);

                switch (x_to_dir.at(upper)) {
                    case Direction::UP:
                        num = x_to_num.at(upper) + upper - x;
                        break;
                    case Direction::LEFT:
                        num = upper - x;
                        break;
                }
                break;
            case Direction::LEFT:
                lower = *(--x_set.lower_bound(x));

                switch (x_to_dir.at(lower)) {
                    case Direction::UP:
                        num = x - lower;
                        break;
                    case Direction::LEFT:
                        num = x_to_num.at(lower) + x - lower;
                        break;
                }
                break;
        }

        x_to_dir.insert({x, direction});
        x_to_num.insert({x, num});
        cout << num << endl;
    }

    return 0;
}