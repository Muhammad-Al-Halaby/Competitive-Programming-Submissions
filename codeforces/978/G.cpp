#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int start[N], finish[N], cnt[N], ans[N], finishPreparing[N];

vector<int> exams[N];

int main(){
    init();

    int n, m;   cin >> n >> m;

    for(int s,d,c, i = 0;i < m;i++){
        cin >> s >> d >> c;

        if(c > d - s)  return cout << -1, 0;

        ans[d] = m + 1;

        start[i] = s, finish[i] = d, cnt[i] = c;

        exams[s].push_back(i);
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for(int i = 1;i <= n;i++){
        for(int j = 0;j < exams[i].size();j++){
            int id = exams[i][j];
            pq.push({finish[id], id});
        }

        if(ans[i] != 0) continue;

        if(pq.empty())
            continue;

        pii top = pq.top();
        ans[i] = top.S + 1;
        cnt[top.S]--;

        if(cnt[top.S] == 0){
            pq.pop();
            finishPreparing[top.S] = i;
        }
    }

    if(pq.size())   return cout << -1, 0;

    for(int i = 0;i < m;i++)
        if(finishPreparing[i] > finish[i])  return cout << -1, 0;

    for(int i = 1;i <= n;i++)   cout << ans[i] << " ";
}