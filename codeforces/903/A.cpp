#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        int a=0;
        for(int i = 0;i<34;i++){
            if((x-3*i) >= 0 && !((x-3*i)%7)){a=1;break;}
        }
        if(a)cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}