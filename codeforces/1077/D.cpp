#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int freq[(int)1e7+1];
int used[(int)1e7+1];

int main(){
    init();
    int n,k;
    cin >> n >> k;
    set<int> s;
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        s.insert(x);
        freq[x]++;
    }
    priority_queue< pair<int,int> > pq;
    for(auto x : s){
        pq.push(make_pair(freq[x],x));
    }
    
    while(k--){
        int x = pq.top().second;
        pq.pop();
        cout << x << " ";
        used[x]++;
        int newfreq = freq[x] / (used[x] + 1);
        pq.push(make_pair(newfreq,x));
    }
}