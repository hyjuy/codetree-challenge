#include <iostream>
#include <vector>
using namespace std;
int n;
vector <int> arr;
int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++) {
        int input; cin >> input;
        arr.push_back(input);
    }


    int ans = 1, cnt = 1;
    int mode = 0;

    for(int i = 1; i < n; i++){
        if(arr[i-1] < arr[i]){
            if(mode = 0 || mode == 2){
                //이전에 감소거나 증감이 없다면 초기화
                mode = 1;
                cnt = 2;
            }
            else{
                mode = 1;
                cnt++;
            }           
        }
        else if(arr[i-1] > arr[i]){
            //감소
            mode = 2;
            cnt = 2;
        }
        else{
            //증감이 없다면 초기화
            mode = 0;
            cnt = 2;
        }
       
        ans = max(ans, cnt);
    }

    

    cout << ans;

    return 0;
}