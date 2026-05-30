#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    // Please write your code here.
    int n; cin >> n;
    vector <int> home(n + 1,0);
    vector <int> dist(n + 1,0);

    for(int i = 1; i <= n; i++){
        cin >> home[i];
    }

    int ans = 1e9;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i] += abs(j - i) * home[j];
        }
        ans = min(ans,dist[i]);
    }

    cout << ans;

    return 0;
}