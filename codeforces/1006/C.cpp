#include <bits/stdc++.h>

using namespace std;

int freq[(int)1e6];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n;
    cin >> n;
    int arr[n];
    
    for(int i = 0;i<n;i++)
        cin >> arr[i];
    
    long long sum1=0,sum3=0,sum=0,p1=0,p2=n-1;
    
    while(p1 < p2){
        if(!freq[p1]){sum1 += arr[p1];freq[p1]=1;}
        if(!freq[p2]){sum3 += arr[p2];freq[p2]=1;}
        if(sum1 == sum3)sum = max(sum,sum1);
        if(sum1 <= sum3)p1++;
        if(sum3 <= sum1)p2--;
    }
    
    cout << sum;
}