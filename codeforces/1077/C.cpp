#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int freq[(int)1e7+1];

vector<int> idx[(int)1e7+1];

int main(){
    init();
    
    int n;
    cin >> n;
    
    int arr[n];
    ll sum = 0;
    
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
        freq[arr[i]]++;
        idx[arr[i]].push_back(i+1);
    }
    
    set<int> ans;
    
    for(int i = 0;i < n;i++){
        ll key = (sum - arr[i]) - arr[i];
        
        if(key > 1e6 || key < 0)continue;
        
        if(freq[key]){
            for(auto x : idx[key])
                if(x != i+1)ans.insert(x);
        }
    }
    
    cout << ans.size() << "\n";
    for(int x : ans)
        cout << x << " ";
}