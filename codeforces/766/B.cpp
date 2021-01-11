#include<bits/stdc++.h>
 using namespace std;
int main(){
    int n;
    cin >> n;
    int s[n];
    vector<int> x;
    for(int i = 0;i<n;i++){
        cin >> s[i];
        if(s[i] > 0)x.push_back(s[i]);
    }
    sort(x.begin(),x.begin()+x.size());
    bool f=0;
    for(int i = 0;i<x.size()-2;i++){
        int j = i+1;
        int m = i+2;
        if(m<x.size() && x[i] + x[j]>x[m]){f=1;break;}
        else f=0;
    }
    
    if(f) cout << "YES";
    else cout <<"NO";
}