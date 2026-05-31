#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Node{
    int x, y;
};
int main() {
    // Please write your code here.
    int n; cin >> n;
    vector <Node> node(n);
    for(int i = 0; i < n; i++){
        cin >> node[i].x >> node[i].y;
    }
    int ans = 1000000000;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int diff_x = node[i].x - node[j].x;
            int diff_y = node[i].y - node[j].y;
            ans = min(ans, diff_x*diff_x+diff_y*diff_y);
        }
    }
    cout << ans;
    return 0;
}