#include <iostream>

using namespace std;

int n;
int ans = 0;
void BeautifulNum(int curr_num){
    if(curr_num == n){
        ans++;
        return;
    }
    for(int i = 1; i <= 4; i++){
        if(curr_num + i - 1 > n )continue;
        BeautifulNum(curr_num + i);
    }
}
int main(void){
    cin >> n;

    BeautifulNum(0);

    cout << ans;
}