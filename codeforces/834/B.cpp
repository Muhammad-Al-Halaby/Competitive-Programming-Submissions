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

int prefix[(int)1e5+5];
int seen[(int)1e5+5];
int fr[(int)1e5+5];

int main(){
    init();
    int n,k,used_guards=0;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i = 0;i<n;i++)
        fr[s[i]]++;
    for(int i = 0;i<n;i++){
        if(!seen[s[i]] && used_guards + 1 > k){
            cout << "YES";
            return 0;
        }
        if(!seen[s[i]]){
            used_guards++;
            seen[s[i]] = 1;
        }
        fr[s[i]]--;
        if(!fr[s[i]])
            used_guards--;
    }
    cout << "NO";
}