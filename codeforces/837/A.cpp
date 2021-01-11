#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    string w;
    vector<int> vols;
    while(cin >> w){
        int len = w.length(),cap=0;
        for(int i = 0;i<len;i++)if(w[i] >= 'A' && w[i] <= 'Z')cap++;
        vols.push_back(cap);
    }
    cout << *max_element(vols.begin(),vols.end());
}