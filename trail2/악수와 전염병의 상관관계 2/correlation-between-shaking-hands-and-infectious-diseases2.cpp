#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Handshake {
    int t, x, y;
};

bool infected[101];
int cnt[101];

int main() {
    int N, K, P, T;
    cin >> N >> K >> P >> T;

    vector<Handshake> arr(T);

    for (int i = 0; i < T; i++) {
        cin >> arr[i].t >> arr[i].x >> arr[i].y;
    }

    // 시간순으로 정렬
    sort(arr.begin(), arr.end(),
        [](const Handshake& a, const Handshake& b) {
            return a.t < b.t;
        });

    // 최초 감염자 설정
    infected[P] = true;

    for (int i = 0; i < T; i++) {
        int x = arr[i].x;
        int y = arr[i].y;

        // 악수하기 전 감염 상태 저장
        bool ix = infected[x];
        bool iy = infected[y];

        // 기존 감염자의 악수 횟수 증가
        if (ix) cnt[x]++;
        if (iy) cnt[y]++;

        // x가 y를 감염
        if (ix && cnt[x] <= K) {
            infected[y] = true;
        }

        // y가 x를 감염
        if (iy && cnt[y] <= K) {
            infected[x] = true;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << infected[i];
    }

    return 0;
}