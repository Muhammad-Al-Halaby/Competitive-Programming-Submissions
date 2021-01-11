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
int freq[(int)1e5+5];

int main(){
    init();
    int n,d,ans=0;
    cin >> n >> d;
    set<int> in;
    set<long long> s;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        in.insert(x);
        if(in.find(x+d) == in.end())
            s.insert(x+d);
        if(in.find(x-d) == in.end())
            s.insert(x-d);
    }
    for(auto x : s){
        int mn = INT_MAX;
        for(auto inp : in){
            if(abs(x-inp) < mn)mn = abs(x-inp);
        }
        if(mn == d)ans++;
    }
    cout << ans;
}