#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,p=0,m=0,pe=0;
    cin >> n;
    int s[n];
    for(int i = 0;i<n;i++){
            cin >> s[i];
            if(s[i]==1)p++;
            else if(s[i]==2)m++;
            else pe++;
    }
    int w = min(min(p,m),pe);
    cout << w << endl;
    for(int i = 0;i<w;i++){
        bool q=0,r=0,e=0;
        for(int k = 0;k<n;k++){
            if(s[k] != 0){
                if(s[k]==1 && !q){cout << k+1 << " ";s[k]=0;q=1;}
                else if(s[k]==2 && !r){cout << k+1 << " ";s[k]=0;r=1;}
                else if(s[k]==3 && !e){cout << k+1 << " ";s[k]=0;e=1;}
                if(q && r && e)break;
            }
        }
        cout << endl;
    }
}
