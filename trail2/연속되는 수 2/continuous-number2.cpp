#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n; cin >> n;
    vector <int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        int cnt = 1;
        for(int j = i + 1; j < n; j++){
            if(arr[i] == arr[j]) cnt++;
            else break;
        }
        ans = max(cnt, ans);
    }

    cout << ans;
    return 0;
}