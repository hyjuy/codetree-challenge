#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A, B;

    for (int i = 0; i < N; i++) {
        int v, t;
        cin >> v >> t;

        for (int j = 0; j < t; j++) {
            A.push_back(v);
        }
    }

    for (int i = 0; i < M; i++) {
        int v, t;
        cin >> v >> t;

        for (int j = 0; j < t; j++) {
            B.push_back(v);
        }
    }

    int posA = 0, posB = 0;
    int leader = 0;  // 0: 아직 없음, 1: A, 2: B
    int answer = 0;

    for (int i = 0; i < (int)A.size(); i++) {
        posA += A[i];
        posB += B[i];

        int current = 0;

        if (posA > posB) {
            current = 1;
        }
        else if (posB > posA) {
            current = 2;
        }
        else {
            continue;
        }

        if (leader != 0 && leader != current) {
            answer++;
        }

        leader = current;
    }

    cout << answer << '\n';

    return 0;
}