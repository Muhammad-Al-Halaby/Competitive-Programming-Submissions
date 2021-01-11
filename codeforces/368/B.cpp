#include<bits/stdc++.h>

using namespace std;

#define OnlineJudge

bool seen[(int)1e5];
int counter[(int)1e5+1];

int main(){
    #ifndef OnlineJudge
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n, q;
    cin >> n >> q;
    int arr[n];
    for(int i = 0;i<n;i++)
        cin >> arr[i];

    for(int i = n-1;i>=0;i--){
        if(seen[arr[i]]){
            counter[i]= counter[i+1];
        }
        else{
            counter[i]= counter[i+1] + 1;
            seen[arr[i]] = 1;
        }
    }

    for(int i = 0;i<q;i++){
        int x;
        cin >> x;
        cout << counter[x-1] << '\n';
    }
}