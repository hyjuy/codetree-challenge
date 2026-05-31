#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int x1, x2;
};
int N;
vector <Node> v;
bool cmp(Node a, Node b){
    if(a.x1 == b.x1) return a.x2 < b.x2;
    return a.x1 < b.x1;
}
int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int st, fin;
        cin >> st >> fin;
        v.push_back({st,fin});
    }
    sort(v.begin(), v.end(), cmp);

    // Please write your code here.
    int ans = 0;
    for (int i = 0; i < N; i++){

        int counting[1001] = {0,};

        for(int j = 0; j < N; j++){
            if(i==j)continue;
            for(int k = v[j].x1 + 1; k <= v[j].x2; k++){
                counting[k]++;
            }
        }
        int temp_cnt = 0;

        int pre = 0;
        for(int j = 0; j < 1001; j++){  
            if(counting[j] >= 1){
                temp_cnt++;
            }
            pre = counting[j];
        }
        ans = max(temp_cnt, ans);
    }

    cout << ans;
    return 0;
}