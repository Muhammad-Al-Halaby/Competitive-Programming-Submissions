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
#define EPS 1e-7
#define modulo ll (1e9 + 7)


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

int main(){
    init();
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    char c = 'a';
    int ansx = 0;
    while(c <= 'z'){
        int x = 0, sofar = 0;
        for(int i = 0;i < n;i++){
            if(!i && s[i] == c)sofar++;
            else if(s[i] == c){
                if(sofar && s[i-1] == c)sofar++;
                else if(!sofar)sofar++;
                else sofar = 0;
            }
            else sofar = 0;

            if(sofar == k){
                x++;
                sofar = 0;
            }
        }
        ansx = max(ansx,x);
        c++;
    }
    cout << ansx;
}