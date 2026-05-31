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
    int ans = 40000*40000;

    for(int i = 0; i < n; i++){
        int min_x = 40000;
        int min_y = 40000;
        int max_x = 0;
        int max_y = 0;
        for(int j = 0; j < n; j++){
            if(i == j)continue;
            min_x = min(min_x, node[j].x);
            min_y = min(min_y, node[j].y);
            max_x = max(max_x, node[j].x);
            max_y = max(max_y, node[j].y);         
        }
        int dist_x = max_x - min_x;
        int dist_y = max_y - min_y;

        ans = min(ans, dist_x*dist_y);
    }
    cout << ans;
    return 0;
}