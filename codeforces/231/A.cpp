#include <iostream>

using namespace std;

int main()
{
    int n,problems=0;
    cin >> n;

    for(int i = 0;i<n;i++){
        int p,v,t,temp =0;
        cin >> p >> v >> t;
        if(p == 1) temp++;
        if(v == 1) temp++;
        if(t == 1) temp++;
        if(temp >= 2) problems++;
    }

    cout << problems;
    return 0;
}
