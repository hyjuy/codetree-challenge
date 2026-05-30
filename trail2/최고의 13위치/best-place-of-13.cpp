#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int n; cin >> n;
    int map[20][20];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 2; j++){
            int cnt = 0;

            for(int k = 0; k < 3; k++){
                if(map[i][j+k] == 1)cnt++;
            }

            ans = max(ans, cnt);
        }
    }

    cout << ans;
    
    return 0;
}