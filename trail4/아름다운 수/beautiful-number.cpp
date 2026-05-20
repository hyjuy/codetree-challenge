#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
vector <int> v;
int ans = 0;
void BeautifulNum(int curr_num){
    if(curr_num == n){
        ans++;
        return;
    }
    for(int i = 1; i <= 4; i++){
        if(curr_num + i - 1 >= n) continue;
        for(int j = 0; j < i; j++){
            v.push_back(i);
        }
        BeautifulNum(curr_num + i);
        for(int j = 0; j < i; j++){
            v.pop_back();
        }
    }
}

int main() {
    // Please write your code here.
    cin >> n;
    BeautifulNum(0);
    cout << ans;
    return 0;
}