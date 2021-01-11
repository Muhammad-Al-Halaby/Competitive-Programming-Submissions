#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI 3.14159265358979323846
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int sol(int x, int y);
int main(){
    init();
    int n, ans = 0;
    cin >> n;
    int arr[n];
    map<int, int> mp;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        mp[arr[i]]++;
        ans += (arr[i] == 0);
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int seq = 2;
            ll x = arr[i], y = arr[j];
            if(i == j || (!x && !y))continue;
            vector<int> v;
            mp[x]--;mp[y]--;
            while(mp[x + y] > 0){
                y += x;
                x = y - x;
                v.push_back(y);
                mp[y]--;
                seq++;
            }
            mp[arr[i]]++;mp[arr[j]]++;
            for(int k = 0;k < v.size();k++)mp[v[k]]++;
            ans = max(ans, seq);
        }
    }
    cout << ans;
}