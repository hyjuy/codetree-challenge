#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
struct node{
    int l, r;
};
vector <node> line;
bool compare(node a, node b){
    if(a.l == b.l) return a.r < b.r;
    return a.l < b.l;
}
void Choose(){

}
int main() {
    // Please write your code here.
    cin >> n;

    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        line.push_back({l,r});
    }

    sort(line.begin(), line.end(), compare);

    int ans = 1;
    int prev = line[n-1].l;

    for(int i = n - 2; i >= 0; i--){
        if(prev <= line[i].r) continue;
        prev = line[i].l;
        ans++;
    }
    cout << ans;
    return 0;
}