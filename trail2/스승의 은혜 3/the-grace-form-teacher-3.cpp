#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct price{
    int total, p, s;
};
int N;
int budget;
vector <price> student;

bool cmp(price a, price b){
    if(a.total == b.total){
        if(a.p == b.p) return a.s < b.s;
        return a.p < b.p;
    }
    return a.total < b.total;
}
int main() {
    // Please write your code here.
    cin >> N >> budget;

    for(int i = 0; i < N; i++){
        int p, s;
        cin >> p >> s;
        student.push_back({p+s,p,s});
    }
    sort(student.begin(), student.end(), cmp);
    int ans = 0;
    for(int i = 0; i < N; i++){
        student[i].p = student[i].p/2;
        student[i].total = student[i].p + student[i].s;
        int temp_cnt = 0;
        int temp_budget = budget;
        for(int j = 0; j < N; j++){
            temp_budget -= student[j].total;
            if(temp_budget < 0){
                temp_budget += student[j].total;
                continue;
            }  
            temp_cnt++;    
        }
        ans = max(ans, temp_cnt);
        student[i].p = student[i].p*2;
        student[i].total = student[i].p + student[i].s;

    }
    cout << ans;
    return 0;
}