#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,good=0;
    vector<int> ns;
    cin >> n;
    for(int i = 0;i<n;i++){
        int counter=0;
        for(int j = 0;j<n;j++){
            int x;
            cin >> x;
            if(x == 0 || x==2 || x==-1)counter++;
        }
        if(counter==n){
            good++;
            ns.push_back(i+1);
        }
    }
    cout << good << endl;
    for(int i = 0;i<ns.size();i++){
        cout << ns[i] << " ";
    }
}