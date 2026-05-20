#include <iostream>
#include <vector>
using namespace std;
int n, k; 
vector <int> answer;

void PrintAnswer(){
    for(int i = 0; i < answer.size(); i++) cout << answer[i] << " ";
    cout << '\n';
}
void Choose(int curr_num){
    if(curr_num == n){
        PrintAnswer();
        return;
    }
    for(int i = 1; i <= k; i++){
        answer.push_back(i);
        Choose(curr_num + 1);
        answer.pop_back();
    }
    


    return;
}
int main() {
    // Please write your code here.
    cin >> k >> n;
    Choose(0);
    return 0;
}