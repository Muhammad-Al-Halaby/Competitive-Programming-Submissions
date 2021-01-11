#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

multiset<int> arr[3001];

int main(){
    init();
    /* Sometimes you win, sometimes you learn */
    int n, m;
    ll ans = LLONG_MAX;
    cin >> n >> m;

    for(int i = 0;i<n;i++){
        int p, c;
        cin >> p >> c;
        arr[p].insert(c);
    }

    for(int i = 0; i <= n + 1;i++){

        multiset<int> rest;
        ll currAns = 0, votes = 0;

        for(int j = 2;j <= m;j++){

            if(!arr[j].empty()){

                int cnt = arr[j].size();

                for(int x : arr[j]){
                    if(cnt >= i){
                        currAns += x;
                        votes++;
                    }
                    else rest.insert(x);

                    cnt--;
                }
            }
        }
        if(votes + arr[1].size() < i){
            int diff = i - (votes + arr[1].size());
            for(int x : rest){
                currAns += x;
                diff--;
                if(!diff)break;
            }
        }
        ans = min(ans, currAns);
    }
    cout << ans;
}