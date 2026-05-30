#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n; cin >> n;
    vector <int> cow(n, 0);
    vector <vector<int>> cmp_cow(n);

    for(int i = 0; i < n; i++){
        cin >> cow[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(cow[i] <= cow[j]) cmp_cow[i].push_back(j);
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        int temp = 0;
        for(int j : cmp_cow[i]){
            temp += cmp_cow[j].size();
        }
        ans += temp;
    }
    cout << ans;
    return 0;
}