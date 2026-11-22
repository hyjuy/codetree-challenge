
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
        cin >> n >> m;

            vector<int> A(1, 0);
                vector<int> B(1, 0);

                    for (int i = 0; i < n; i++) {
                            int t;
                                    char d;
                                            cin >> t >> d;

                                                    for (int j = 0; j < t; j++) {
                                                                int next = A.back() + (d == 'R' ? 1 : -1);
                                                                            A.push_back(next);
                                                                                    }
                                                                                        }

                                                                                            for (int i = 0; i < m; i++) {
                                                                                                    int t;
                                                                                                            char d;
                                                                                                                    cin >> t >> d;

                                                                                                                            for (int j = 0; j < t; j++) {
                                                                                                                                        int next = B.back() + (d == 'R' ? 1 : -1);
                                                                                                                                                    B.push_back(next);
                                                                                                                                                            }
                                                                                                                                                                }

                                                                                                                                                                    int total = max(A.size(), B.size());

                                                                                                                                                                        A.resize(total, A.back());
                                                                                                                                                                            B.resize(total, B.back());

                                                                                                                                                                                int cnt = 0;

                                                                                                                                                                                    for (int i = 1; i < total; i++) {
                                                                                                                                                                                            if (A[i] == B[i] && A[i - 1] != B[i - 1]) {
                                                                                                                                                                                                        cnt++;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                    }

                                                                                                                                                                                                                        cout << cnt << '\n';

                                                                                                                                                                                                                            return 0;
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                            