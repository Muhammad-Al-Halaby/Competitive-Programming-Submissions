#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    int n,k;
    cin >> n >> k;
    map<int, int> m;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        m[x] = i+1;
    }
    if(m.size() >= k){
        cout << "YES" << endl;
        for(pair<int,int> p : m){
            cout << p.second << " ";
            k--;
            if(!k)break;
        }
        return 0;
    }
    cout << "NO";
}