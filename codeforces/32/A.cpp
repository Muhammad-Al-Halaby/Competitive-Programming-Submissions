#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,m,result=0;
    cin >> n >> m;
    int h[n];
    for(int i = 0;i < n;i++) cin >> h[i];
    sort(h,h+n);
    for(int i = 0;i<n;i++){
        for(int j =i+1;j<n;j++){
            if(h[j] - h[i] <= m) result += 2;
            else break;
        }
    }
    cout << result;
}