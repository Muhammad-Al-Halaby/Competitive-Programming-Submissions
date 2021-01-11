#include <bits/stdc++.h>
#define OnlineJudge
using namespace std;
int main(){
    #ifndef OnlineJudge
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
	#endif
    int n,mx=1;
    cin >> n;
    string s,s1;
    cin >> s;
    for(int i = 0;i<s.length();i++){
        s1+=s[i];
        int f = s.find(s1,i+1);
        if(f != -1 && f == i+1){
            mx = s1.size();
        }
    }
    cout << s.length() - (mx) + 1;
}