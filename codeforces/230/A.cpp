#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int fr[(int)1e7];

int main(){
    init();
    int s,n,x,ans;
    cin >> s >> n;
    x = ans = n;
    pair<int,int> arr[n];
    for(int i = 0;i<n;i++)
        cin >> arr[i].second >> arr[i].first;
    sort(arr,arr+n);
    while(x--){
        for(int i = 0;i<n;i++){
            if(s > arr[i].second && !fr[i]){
                fr[i]++;
                s+= arr[i].first;
                ans--;
            }
        }
    }
    if(!ans)
        cout << "YES";
    else
        cout << "NO";
}