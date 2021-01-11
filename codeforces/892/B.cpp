#include <bits/stdc++.h>
using namespace std;


int main(){
    long long n,ans=0;
    scanf("%I64d",&n);
    long long arr[n];
    for(int i = n-1;i>=0;i--)
        scanf("%I64d",arr+i);
    int c=0;
    for(int i = 0;i<n;i++){
        if(c==0)ans++;
        if(arr[i] >= c){c=arr[i];continue;}
        if(c>0)c--;
    }
    printf("%I64d",ans);

}