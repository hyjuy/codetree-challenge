#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n; cin >> n;
    int t; cin >> t;
    vector <int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > t){
            cnt++;
        }
        else{
            //초기화
            cnt = 0;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}