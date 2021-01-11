#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    int errs[n];
    int first[n-1];
    int second[n-2];
    
    for(int i = 0;i<n;i++)cin >> errs[i];
    for(int i = 0;i<n-1;i++)cin >> first[i];
    for(int i = 0;i<n-2;i++)cin >> second[i];
    
    int f=0,s=0,sum1=0,sum2=0,sum3=0;
    sum1 = accumulate(errs,errs+n,0);
    sum2 = accumulate(first,first+(n-1),0);
    sum3 = accumulate(second,second+(n-2),0);
    f=sum1 - sum2;
    s=(sum1-f)-sum3;
    cout << f << endl << s;
}