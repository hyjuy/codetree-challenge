#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector <pair<int, int>> lines;
vector <pair<int, int>> selected_lines;
int ans = 10000000;

bool Possible(){
    int num1[12] = {0,};
    int num2[12] = {0,};

    for(int i = 1; i <= n; i++){
        num1[i - 1] = num2[i - 1] = i;
    }

    for(int i = 0; i < (int)lines.size(); i++){
        int idx = lines[i].second;
        swap(num1[idx], num1[idx+1]);
    }

    for(int i = 0; i < (int)selected_lines.size(); i++){
        int idx = selected_lines[i].second;
        swap(num2[idx], num2[idx+1]);
    }

    for(int i = 1; i <= n; i++){
        if(num1[i] != num2[i])return false;
    }

    return true;
}
void FindMinLines(int cnt){
    if(cnt == m){
        if(Possible()){
            ans = min(ans, (int)selected_lines.size());         
        }
        return;
    }

    selected_lines.push_back(lines[cnt]);
    FindMinLines(cnt+1);
    selected_lines.pop_back();
    FindMinLines(cnt+1);
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> c >> r;
        lines.push_back({r,c});
    }

    sort(lines.begin(), lines.end());

    FindMinLines(0);

    cout << ans;

    return 0;
}
