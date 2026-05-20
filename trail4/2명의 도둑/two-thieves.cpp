#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pos{
    int r, c;
};

int n, lim, weight;
int map[10][10];

vector <Pos> pos_list;
vector <int> sel_idx;
int ans = 0;
int best_item_score = 0;

bool isOverlap(Pos a, Pos b){
    if(a.r != b.r)return false;
    int a_st = a.c;
    int a_end = a.c + lim - 1;

    int b_st = b.c;
    int b_end = b.c + lim - 1;

    return !(a_end < b_st || b_end < a_st);
}

void ChooseItem(int curr_idx, int arr[], int sum, int score){
    if(curr_idx == lim){
        if(sum <= weight){
            best_item_score = max(best_item_score, score);
        }
        return;
    }

    ChooseItem(curr_idx + 1, arr, sum + arr[curr_idx], score + arr[curr_idx] * arr[curr_idx]);
    ChooseItem(curr_idx + 1, arr, sum, score);
}

int GetBestScore(Pos p){
    int arr[5];

    for(int i =0; i < lim; i++){
        arr[i] = map[p.r][p.c + i];
    }
    best_item_score = 0;
    ChooseItem(0, arr, 0, 0);
    return best_item_score;
}
void ChooseSt(int curr_idx, int st){
    if(curr_idx == 2){
        Pos theif1 = pos_list[sel_idx[0]];
        Pos theif2 = pos_list[sel_idx[1]];

        if(isOverlap(theif1, theif2))return;

        int score1 = GetBestScore(theif1);
        int score2 = GetBestScore(theif2);

        ans = max(ans, score1 + score2);
        return;
    }
    for(int i = st; i < pos_list.size(); i++){
        sel_idx.push_back(i);
        ChooseSt(curr_idx + 1, i + 1);
        sel_idx.pop_back();
    }
}
int main() {
    // Please write your code here.
    cin >> n >> lim >> weight;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <n; j++){
            cin >> map[i][j];
        }

    for(int r = 0; r < n; r++){
        for(int c = 0; c <= n - lim; c++){
            pos_list.push_back({r,c});
        }
    }

    ChooseSt(0,0);
    
    cout << ans;

    
    return 0;
}