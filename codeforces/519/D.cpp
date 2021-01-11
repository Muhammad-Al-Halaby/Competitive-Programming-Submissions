#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int w[26];
    map<pair<int,long long>,int> mp;
    long long pre[(int)1e5+10], ans = 0;
    string s;

    for(int i = 0;i<26;i++)cin >> w[i];
    cin >> s;

    for(int i = 1;i <= s.size();i++){
        int order = s[i-1]-'a';
        pre[i] = pre[i-1] + w[order];
        ans += mp[make_pair(order,pre[i] - w[order])];
        mp[make_pair(order,pre[i])]++;
    }
    cout << ans;
}