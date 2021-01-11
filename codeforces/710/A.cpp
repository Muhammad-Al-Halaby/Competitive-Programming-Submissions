#include <iostream>

using namespace std;

int main(){
    char c;
    int n,ans=0;
    cin >> c >> n;
    if(c < 'h')ans+=2;
    if(c > 'a')ans+=2;
    if(n < 8)ans+=2;
    if(n > 1)ans+=2;

    if(ans != 8 && c < 'h' && n < 8)ans--;
    else if(ans != 8 && c < 'h' && n > 1)ans--;
    else if(ans != 8 && n < 8 && c > 'a')ans--;
    else if(ans != 8 && n > 1 && c > 'a')ans--;

    cout << ans;
}