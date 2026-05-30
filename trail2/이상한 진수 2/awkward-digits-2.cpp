#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int chageNum(char *input){
    int sum = 0;
    int size = strlen(input) - 1;
    for(int i = size; i >= 0; i--){
        int num = input[i] - '0';
        if(num){
            sum += pow(2, size - i);
        }
    }
    return sum;
}
int main() {
    // Please write your code here.
    char *input = new char[11];
    cin >> input;
    int ans = 0;
    for(int i = 1; i < strlen(input); i++){
        if(input[i] == '0'){
            input[i] = '1';
            ans = max(ans, chageNum(input));
            input[i] = '0';
        }
        else{
            input[i] = '0';
            ans = max(ans, chageNum(input));
            input[i] = '1';
        }
   
    }

    cout << ans;

    return 0;
}