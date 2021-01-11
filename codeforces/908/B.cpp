#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,startx,starty,ans=0;
    cin >> n >> m;
    int dir[] = {0,1,2,3};
    char arr[n][m];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
                cin >> arr[i][j];
                if(arr[i][j] == 'S'){
                    startx=i;
                    starty=j;
                }
        }
    }
    string s;
    cin >> s;
    do{
        int posx=startx;
        int posy=starty;
        int possible=false;

        for(int i = 0;i<s.length();i++){
            if((s[i]-'0')== dir[0])posx--;
            else if((s[i]-'0')== dir[1])posx++;
            else if((s[i]-'0')== dir[2])posy++;
            else if((s[i]-'0')== dir[3])posy--;
            if(posx < 0 || posy < 0){possible=false;break;}
            if(posx == n || posy == m){possible=false;break;}

            if(arr[posx][posy] == '#'){possible=false;break;}
            else if(arr[posx][posy] == 'E'){possible=true;break;}
        }
        if(possible)ans++;
    }while(next_permutation(dir,dir+4));
    cout << ans;
}