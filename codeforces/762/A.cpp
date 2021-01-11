#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    int k;
    cin >> n >> k;
    vector<long long> fac;
    for(long long i = 1;i<=sqrt(n);i++){
        if(n % i == 0){
            fac.push_back(i);
            long long sq = sqrt(n);
            if(i != sq || sq*sq != n)
                fac.push_back(n/i);
        }
    }
    sort(fac.begin(),fac.end());
    if(k <= fac.size())
        cout << fac[k-1];
    else
        cout << -1;
}