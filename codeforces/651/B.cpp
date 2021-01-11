#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int fr[1005];
int main(){
    int n,ans=0;
    cin >> n;
    set<int> nums;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        fr[x]++;
        nums.insert(x);
    }
    for(int i = 0;i<n;i++){
        int cnt = 0;
        for(auto i : nums){
            if(fr[i]){
                fr[i]--;
                cnt++;
            }
        }
        ans += max(0,cnt-1);
    }
    cout << ans;
}