#include <iostream>
using namespace std;

int main(){
    int n,ans=0;
    while(cin >> n)ans+=n;
    if(ans != 0 && ans%5==0)cout << ans/5;
    else cout << -1;
}
