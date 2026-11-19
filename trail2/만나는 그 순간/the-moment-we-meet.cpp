#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> A(1000001, 0);
    vector<int> B(1000001, 0);

    int timeA = 0;
    int timeB = 0;
    int pos = 0;

    // A 이동 기록
    for (int i = 0; i < n; i++) {
        char dir;
        int t;
        cin >> dir >> t;

        int dx = (dir == 'R') ? 1 : -1;

        for (int j = 0; j < t; j++) {
            pos += dx;
            A[++timeA] = pos;
        }
    }

    // B 이동 기록
    pos = 0;

    for (int i = 0; i < m; i++) {
        char dir;
        int t;
        cin >> dir >> t;

        int dx = (dir == 'R') ? 1 : -1;

        for (int j = 0; j < t; j++) {
            pos += dx;
            B[++timeB] = pos;
        }
    }

    int answer = -1;

    for (int t = 1; t <= min(timeA, timeB); t++) {
        if (A[t] == B[t]) {
            answer = t;
            break;
        }
    }

    cout << answer << '\n';

    return 0;
}