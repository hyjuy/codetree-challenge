#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n; cin >> n;
    vector <int> cow(n, 0);
    for(int i = 0; i < n; i++){
        cin >> cow[i];
    }
    vector<long long> dp2(n, 0);
    long long ans = 0;

    for(int j = 0; j < n; j++){
        for(int i = 0; i < j; i++){
            if(cow[i] <= cow[j]){
                dp2[j]++;
            }
        }
    }

    for(int k = 0; k < n; k++){
        for(int j = 0; j < k; j++){
            if(cow[j] <= cow[k]){
                ans += dp2[j];
            }
        }
    }
    cout << ans;
    return 0;
}