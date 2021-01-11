#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n,m;
    cin>> n >> m;
    string s,t;
    cin >> s >> t;

    int star_idx=-1;

    for(int i = 0;i<n;i++)
        if(s[i] == '*')star_idx = i;
    if(star_idx == -1){
        if(s == t)
            cout << "YES";
        else
            cout << "NO";
        return 0;
    }
    bool ans = 1;

    for(int i = 0;i<star_idx;i++){
        if(s[i] != t[i])ans=0;
    }

    for(int j =n-1, i = m-1;j > star_idx;j--,i--){
        if(i < star_idx || t[i] != s[j]){
			ans=0;
			break;
		}
    }

    if(ans)cout << "YES";
    else cout << "NO";
}