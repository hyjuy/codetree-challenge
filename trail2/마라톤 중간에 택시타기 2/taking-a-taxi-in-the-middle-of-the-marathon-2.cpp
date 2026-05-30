#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Node{
    int x;
    int y;
};
int n; 
int dist(int idx, vector <Node> *v){
    int sum = 0;

    int pre_x = (*v)[0].x;
    int pre_y = (*v)[0].y;


    for(int i = 1; i < n; i++){
        if(i == idx) continue;

        int dist_x = abs(pre_x - (*v)[i].x);
        int dist_y = abs(pre_y - (*v)[i].y);
        sum += dist_x + dist_y;
        pre_x = (*v)[i].x;
        pre_y = (*v)[i].y;
    }
    return sum;
}
int main() {
    // Please write your code here.
    cin >> n;
    vector <Node> node(n, {0,0});

    for(int i = 0; i < n; i++){
        cin >> node[i].x >> node[i].y;
    }

    int ans = 1000000000;
    for(int i = 1; i < n-1; i++){
        ans = min(ans, dist(i, &node));
    }
    cout << ans;
    return 0;
}