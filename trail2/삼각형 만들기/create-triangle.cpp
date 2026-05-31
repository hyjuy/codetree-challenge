#include <iostream>
#include <vector>

using namespace std;
struct Node {
    int x, y;
};
vector <int> selected;
int n;
int ans = 0;
void choose(int curr, int cnt, vector<Node>&v) {
    if (cnt == 3) {
        int i1 = selected[0];
        int i2 = selected[1];
        int i3 = selected[2];

        int x1 = v[i1].x;
        int x2 = v[i2].x;
        int x3 = v[i3].x;
        int y1 = v[i1].y;
        int y2 = v[i2].y;
        int y3 = v[i3].y;

        if ((x1 == x2 || x1 == x3 || x2 == x3) && (y1 == y2 || y1 == y3 || y2 == y3)) {
            int temp_size = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
            ans = max(abs(temp_size), ans);
        }
        return;
    }
    if (curr == n)return;
    selected.push_back(curr);
    choose(curr + 1, cnt + 1, v);
    selected.pop_back();
    choose(curr + 1, cnt, v);
}
int main() {
    // Please write your code here.
    cin >> n;
    vector <Node> node(n);
    for (int i = 0; i < n; i++) {
        cin >> node[i].x >> node[i].y;
    }
    choose(0, 0, node);
    cout << ans;
    return 0;
}