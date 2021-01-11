#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        long long n,sum1,sum2=1;
        double limit;
        cin >> n;
        sum1=(n*(1+n))/2;//10
        limit = log(n)/log(2);//2
        for(int i = 1;i<=limit;i++)sum2+=pow(2,i);
        sum1-=(2*sum2);
        cout << sum1 << endl;
    }
}