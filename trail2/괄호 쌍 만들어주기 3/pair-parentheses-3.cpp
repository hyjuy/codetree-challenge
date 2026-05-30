#include <iostream>
#include <string>
using namespace std;

int findChar(string str, int idx){
    int cnt = 0;
    for(int i = idx + 1; i < str.length(); i++){
        if(str[i] == ')') cnt++;
    }
    return cnt;
}
int main() {
    // Please write your code here.
    string input;
    cin >> input;

    int ans = 0;

    for(int i = 0; i < input.length(); i++){
        if(input[i] == '('){
            ans += findChar(input, i);
        }
    }

    cout << ans;

    return 0;
}