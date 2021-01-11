#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int m[] = {1,-1};

int main(){
    init();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int l = 0,r=s.length()-1,p=1;
        while(l < r){
            int ok = 0;
            for(int i = 0;i<2;i++){
                for(int j = 0;j<2;j++){
                    if(s[l] + m[i] == s[r]+m[j] && (s[l] + m[i] >= 'a' && s[l] + m[i] <= 'z') && (s[r] + m[j] >= 'a' && s[r] + m[j] <= 'z'))ok=1;
                }
            }
            if(!ok){
                p = 0;
                break;
            }
            else{
                l++;
                r--;
            }
        }
        if(p)
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
    }
}