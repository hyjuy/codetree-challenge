#include <iostream>
#include <vector>
using namespace std;

int n;
int map[21][21] = {0,};
int bomb_cnt = 0;
vector <pair<int,int>> bomb_pos;
vector <int> bomb_list;
int ans = 0;


int bomb[4][4][2] = {
    {0,},
    {{-2,0},{-1,0},{1,0},{2,0}},
    {{-1,0},{0,1},{1,0},{0,-1}},
    {{-1,-1},{-1,1},{1,1},{1,-1}},
};
int boom(vector <int> bomb_list){
    int temp[21][21] = {0,};
    int temp_ans = 0;

    for(int i = 0; i < bomb_cnt; i++){

        int x = bomb_pos[i].first;
        int y = bomb_pos[i].second;

        temp[x][y] = 1;

        for(int j = 0; j < 4; j++){
            int nx = x + bomb[bomb_list[i]][j][0];
            int ny = y + bomb[bomb_list[i]][j][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
            temp[nx][ny] = 1;
        }
    }

    for(int i  = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(temp[i][j] == 1){             
                temp_ans++;
            }
        }
    }
    return temp_ans;
}
void Choose(int curr_idx){
    if(curr_idx == bomb_cnt){
        int size = boom(bomb_list);
        if( ans < size ) ans = size;
        return;
    }

    for(int i = 1; i <= 3; i++){
        bomb_list.push_back(i);
        Choose(curr_idx + 1);
        bomb_list.pop_back();
    }
}
int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
            if(map[i][j] > 0){
                bomb_cnt++;
                bomb_pos.push_back({i,j});
            }
        }
    }

    Choose(0);
    cout << ans;
    
    return 0;
}