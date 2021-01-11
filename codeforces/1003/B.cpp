#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

#define loop(a,n) for(int i = a;i<n;i++)
#define NumofDigits(n) ((int)log10(n)+1)
#define CountofNumber(array,n,x)  (upper_bound(array, array+n, x)-lower_bound(array, array+n, x))
#define readline(s) getline(cin,s)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-6


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int prefix[1000];
int main(){
    init();
    int a,b,x;
    cin >> a >> b >> x;
    string s;
    if(a > b){
        s="0";
        a--;
    }else{
        s="1";
        b--;
    }
    while(x){
        if(s[s.size()-1] == '0' && b){
            s+="1";
            b--;
        }
        else if(a){
            s+="0";
            a--;
        }
        x--;
    }
    for(int i = 0;i<s.size();i++){
        cout << s[i];
        if(s[i] == '1' && b){
            for(int j = 0;j<b;j++)
                cout << '1';
            b = 0;
        }
        else if(s[i] == '0' && a){
            for(int j = 0;j<a;j++)
                cout << '0';
            a = 0;
        }
    }
}