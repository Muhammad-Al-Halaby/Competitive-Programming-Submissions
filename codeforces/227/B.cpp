#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    long long v=0,p=0;
    cin >> n;
    map<int, int> nums;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        nums[x] = i+1;
    }
    cin >> m;
    for(int i = 0;i<m;i++){
        int x;
        cin >> x;
        v+=nums[x];
        p+=n-nums[x]+1;
    }
    cout << v << " " << p;
}
