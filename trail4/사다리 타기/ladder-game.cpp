#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int r, c;
};

struct Info{
    int c1, c2;
};

int n, m;
int fir_arr[12] = {0,};
int temp_arr[12] = {0,};

vector<Info> v[16];
vector<Node> list;
vector<int> sel_list;

int ans = 10000000;

void move(int idx, vector<Info> ladder[16], int mode){
    int c = idx;

    // r의 최대 범위가 15라면 15까지 확인
    for(int r = 1; r <= 15; r++){
        for(auto node : ladder[r]){
            if(c == node.c1){
                c = node.c2;
                break;
            }
            else if(c == node.c2){
                c = node.c1;
                break;
            }
        }
    }

    if(mode == 0) {
        fir_arr[c] = idx;
    }
    else {
        temp_arr[c] = idx;
    }
}

void Choose(int curr_idx){
    // 이미 현재 정답보다 많이 골랐다면 더 볼 필요 없음
    if((int)sel_list.size() >= ans) {
        return;
    }

    if(curr_idx == (int)list.size()){
        vector<Info> temp_v[16];

        for(int i = 0; i < (int)sel_list.size(); i++){          
            int r = list[sel_list[i]].r;
            int c = list[sel_list[i]].c;

            temp_v[r].push_back({c, c + 1});
        }

        // temp_arr 초기화
        for(int i = 1; i <= n; i++){
            temp_arr[i] = 0;
        }

        // 선택한 가로줄만으로 사다리 결과 계산
        for(int i = 1; i <= n; i++){
            move(i, temp_v, 1);
        }

        // 원본 사다리 결과와 같은지 비교
        for(int i = 1; i <= n; i++){
            if(temp_arr[i] != fir_arr[i]){
                return;
            }
        }

        if(ans > (int)sel_list.size()){
            ans = sel_list.size();
        }

        return;
    }

    // 현재 가로줄 선택
    sel_list.push_back(curr_idx);
    Choose(curr_idx + 1);
    sel_list.pop_back();

    // 현재 가로줄 미선택
    Choose(curr_idx + 1);
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int r, c;
        cin >> c >> r;

        list.push_back({r, c});
        v[r].push_back({c, c + 1});
    }

    // 원본 사다리 결과 계산
    for(int i = 1; i <= n; i++){
        move(i, v, 0);
    }

    Choose(0);

    cout << ans;

    return 0;
}