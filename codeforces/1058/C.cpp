#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define EPS 1e-9
void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n,ans = 0;
    cin >> n;
    string s;
    cin >> s;
    int segments = 1,base = 0;
    while(segments < n){
        for(int i = 0;i<segments;i++) base += s[i] - '0';
        int newSeg = 0;
        ans = 1;
        for(int i = segments;i < n;i++){
            newSeg += s[i] - '0';
            if(i + 1 < n && s[i+1] == '0')continue;
            if(newSeg == base)newSeg = 0;

            else if(newSeg > base || (newSeg < base && i == n-1)){
                segments++;
                base = 0;
                ans = 0;
                break;
            }


        }
        if(!newSeg && ans){
            return cout << "YES" , 0;
        }
    }
    cout << "NO";
}
