#include <iostream>
using namespace std;

int R, C; 
char board[15][15];
int ans = 0;

void findPath(int r, int c, int step){
    if(r == R - 1 && c == C - 1){
        if(step == 3) ans++;
        return;
    }

    if(step == 3)return;

    char cur = board[r][c];

    for(int i = r + 1; i < R; i++){
        for(int j = c + 1; j < C; j++){
            if(cur != board[i][j]){
                findPath(i,j,step+1);
            }
        }
    }
}
int main() {
    // Please write your code here.
    //적어도 한칸 이상 오른쪽, 적어도 한칸 이상 아래쪽
    //시작 -> 1칸 -> 2칸 -> 마지막

    cin >> R >> C;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];
        }
    }
    
     for(int r1 = 1; r1 < R - 1; r1++) {
        for(int c1 = 1; c1 < C - 1; c1++) {

            if(board[0][0] == board[r1][c1]) continue;

            for(int r2 = r1 + 1; r2 < R - 1; r2++) {
                for(int c2 = c1 + 1; c2 < C - 1; c2++) {

                    if(board[r1][c1] == board[r2][c2]) continue;
                    if(board[r2][c2] == board[R - 1][C - 1]) continue;

                    ans++;
                }
            }
        }
    }
    
    cout << ans;
    return 0;
}