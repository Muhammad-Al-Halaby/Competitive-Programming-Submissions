#include <bits/stdc++.h>
#define OnlineJudge
using namespace std;
int main(){
    #ifndef OnlineJudge
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
	#endif
    int n,ans=0,u=1;
    char last;
    cin >> n;
    string s;
    for(int i = 0;i<n;i++){
        char x;
        cin >> x;
        s+=x;
        if(s.length() == 2 && s == "RU" || s == "UR"){
            ans++;
            s="";
        }
        else if(s.length() == 2){
            s = s[0];
            ans++;
        }

    }
    if(!s.empty())ans++;
    cout << ans;
}