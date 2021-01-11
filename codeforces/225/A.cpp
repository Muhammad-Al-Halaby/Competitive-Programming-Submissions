#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin >> n >> t;
    if(t>3)t=7-t;
    int tops[n];
    for(int i = 0;i<n;i++){
        int s1,s2,s3;
        cin >> s1 >> s2;
        if(s1 > 3)s1=7-s1;
        if(s2 > 3)s2=7-s2;
        s3=6-(s1+s2);
        tops[i]=s3;
    }
    bool ans=1;
    for(int i = 0;i<n;i++){
        if(t!=tops[i] && t!=(7-tops[i]))ans=0;
    }
    if(ans)cout << "YES";
    else cout << "NO";
}