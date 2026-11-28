#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
        cin >> n >> m;

            vector<int> A = {0};
                vector<int> B = {0};

                    // A의 시간별 위치 기록
                        for (int i = 0; i < n; i++) {
                                int v, t;
                                        cin >> v >> t;

                                                while (t--) {
                                                            A.push_back(A.back() + v);
                                                                    }
                                                                        }

                                                                            // B의 시간별 위치 기록
                                                                                for (int i = 0; i < m; i++) {
                                                                                        int v, t;
                                                                                                cin >> v >> t;

                                                                                                        while (t--) {
                                                                                                                    B.push_back(B.back() + v);
                                                                                                                            }
                                                                                                                                }

                                                                                                                                    int prev = 2;
                                                                                                                                        int cnt = 0;

                                                                                                                                            for (int i = 1; i < A.size(); i++) {
                                                                                                                                                    int cur;

                                                                                                                                                            if (A[i] > B[i])
                                                                                                                                                                        cur = 1;
                                                                                                                                                                                else if (A[i] < B[i])
                                                                                                                                                                                            cur = -1;
                                                                                                                                                                                                    else
                                                                                                                                                                                                                cur = 0;

                                                                                                                                                                                                                        if (prev != cur)
                                                                                                                                                                                                                                    cnt++;

                                                                                                                                                                                                                                            prev = cur;
                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                    cout << cnt;

                                                                                                                                                                                                                                                        return 0;
                                                                                                                                                                                                                                                        }