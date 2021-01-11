#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    if(s.find(0) != s.end()){
        cout << s.size()-1;
    }
    else cout << s.size();
}