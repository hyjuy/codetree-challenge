#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int x, y;
};

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector <Node> node(n);
    for (int i = 0; i < n; i++) {
        cin >> node[i].x >> node[i].y;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {

                int x1 = node[i].x;
                int x2 = node[j].x;
                int x3 = node[k].x;
                int y1 = node[i].y;
                int y2 = node[j].y;
                int y3 = node[k].y;

                bool sameX = (x1 == x2 || x1 == x3 || x2 == x3);
                bool sameY = (y1 == y2 || y1 == y3 || y2 == y3);

                if (sameX && sameY) {
                    int area = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
                    ans = max(ans, abs(area));
                }

            }
        }
    }
    cout << ans;
    return 0;
}