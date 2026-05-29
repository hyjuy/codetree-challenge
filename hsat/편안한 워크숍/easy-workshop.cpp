#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node{
    int cost;
    int depth;
    int r;
    int c;
};

struct cmp{
    bool operator()(Node a, Node b){
        return a.cost > b.cost;
    }
};

int N, K;
int map[100][100];
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
int ans = 1000000000;


int main() {
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    const int INF =1e9;
    vector<vector<vector<int>>> dist(K + 1, vector<vector<int>>(N,vector<int>(N,INF)));

    priority_queue<Node, vector<Node>, cmp> pq;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dist[1][i][j] = 0;
            pq.push({0,1,i,j});
        }
    }

    while(!pq.empty()){
        Node cur = pq.top();
        pq.pop();
        if(cur.cost != dist[cur.depth][cur.r][cur.c])continue;

        if(cur.depth == K){
            cout << cur.cost;
            return 0;
        }

        for(int d = 0; d < 4; d++){
            int nr = cur.r + dr[d];
            int nc = cur.c + dc[d];
            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(map[nr][nc] <= map[cur.r][cur.c])continue;

            int diff = map[nr][nc] - map[cur.r][cur.c];
            int nextCost = max(cur.cost, diff);
            int nextDepth = cur.depth + 1;
            if(dist[nextDepth][nr][nc] > nextCost){
                dist[nextDepth][nr][nc] = nextCost;
                pq.push({nextCost,nextDepth, nr, nc});
            }
        }
    }
    cout << -1;
    return 0;
}
