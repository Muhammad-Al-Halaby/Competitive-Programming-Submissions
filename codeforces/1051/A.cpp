#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int fr[200];

int main(){
    init();

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int l,u,d;
        l = u = d = 0;
        for(int i =0 ;i<s.size();i++){
            char c = s[i];
            if(c >= '0' && c <= '9')d++;
            else if(islower(c))l++;
            else u++;
        }

        if(l && u && d){
            cout << s << '\n';continue;
        }
        string rep = "";
        if(!d)rep += '7';
        if(!u)rep += 'U';
        if(!l)rep += 'l';

        if(rep.size() == 1){
            for(int i = 0;i<s.size();i++){
                if(isupper(s[i]) && u > 1){s[i]=rep[0];break;}
                if(islower(s[i]) && l > 1){s[i]=rep[0];break;}
                if(s[i] >= '0' && s[i] <= '9' && d > 1){s[i]=rep[0];break;}
            }
            cout << s << '\n';continue;
            continue;
        }

        s[0] = rep[0];
        s[1] = rep[1];
        cout << s << '\n';continue;
    }
}
