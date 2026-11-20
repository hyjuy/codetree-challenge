
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, K;
        cin >> N >> M >> K;

            vector<int> cnt(N + 1, 0);
                int answer = -1;

                    for (int i = 0; i < M; i++) {
                            int num;
                                    cin >> num;

                                            cnt[num]++;

                                                    if (cnt[num] == K && answer == -1) {
                                                                answer = num;
                                                                        }
                                                                            }

                                                                                cout << answer << '\n';

                                                                                    return 0;
                                                                                    }
                                                                                    