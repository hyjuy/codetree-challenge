#include <iostream>
#include <vector>

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
        int cnt = 0;
        for(int j = i; j < n; j++){
            if((arr[i] >= 0 && arr[j] >= 0) || (arr[i] < 0 && arr[j] < 0)){
                cnt++;
            }
            else if((arr[i] >= 0 && arr[j] < 0) || (arr[i] < 0 && arr[j] >= 0)){
                break;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans;
    return 0;
}