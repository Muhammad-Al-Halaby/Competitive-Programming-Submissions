#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l;
    double ans = 0;
    cin >> n >> l;
    int lan[n];
    for(int i = 0;i<n;i++)
        cin >> lan[i];
    sort(lan,lan+n);
    
    for(int i = 0;i<n-1;i++)
        ans = max((int)ans, abs(lan[i]-lan[i+1]));
    
    ans /= 2;
    if(max(lan[0],l-lan[n-1]) > ans)
        ans = max(lan[0],l-lan[n-1]);

    printf("%.9f",ans);
}
