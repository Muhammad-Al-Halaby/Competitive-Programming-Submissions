#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isPrime(int n){
    for(int i = 2;i*i<=n;i++){
        if(n % i == 0)return 0;
    }
    return 1;
}
int main(){
    int n;
    cin >> n;
    if(n != 1 && n % 2)
        cout << 1;
    else{
        int i;
        for(i = 1;i<=5;i++)
            if(!isPrime(n * i + 1))
                break;
        cout << i;
    }
}