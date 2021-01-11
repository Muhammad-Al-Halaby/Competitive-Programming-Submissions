#include<bits/stdc++.h>
using namespace std; 

int main(){
    int n,zero=0,pairs=0;
    cin >> n;
    int arr[n][2];
    int linesxp[1000];
    int linesxn[1000];
    int linesyp[1000];
    int linesyn[1000];
    
    memset(linesxp, 0,1000);
    memset(linesxn, 0,1000);
    memset(linesyp, 0,1000);
    //memset(linesyn, 0,1000);
    for(int i = 0;i<1000;i++)linesyn[i]=0;
    
    for(int i = 0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
        int diff = arr[i][0]-arr[i][1];
        if(diff > 0)linesxp[diff]++;
        else if(diff < 0)linesxn[abs(diff)]++;
        else if(diff == 0)zero++;
        
        if(1000-arr[i][0]-arr[i][1] > 0)linesyp[1000-arr[i][0]-arr[i][1]]++;
        else linesyn[abs(1000-arr[i][0]-arr[i][1])]++;
    }
    
    for(int i = 0;i<1000;i++){
        if(linesxn[i] > 1)pairs+=((linesxn[i]-1)*linesxn[i])/2;
        if(linesxp[i] > 1)pairs+=((linesxp[i]-1)*linesxp[i])/2;
        if(linesyp[i] > 1)pairs+=((linesyp[i]-1)*linesyp[i])/2;
        if(linesyn[i] > 1)pairs+=((linesyn[i]-1)*linesyn[i])/2;
        
    }
    if(zero > 1)pairs+=((zero-1)*zero)/2;
    cout << pairs;
}