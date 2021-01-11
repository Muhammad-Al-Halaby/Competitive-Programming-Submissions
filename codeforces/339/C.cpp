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
typedef pair<int,int> pii;
typedef pair<int,ll> pill;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

int weights[11];
vector<int> ans;
int m;
int solve(int a, int b, int last, int turn, int used){
    if(used == m)return 0;
    int res = INT_MAX;
    for(int i = 1;i <= 10;i++){
        if(weights[i] && i != last){
            if(!turn && a + i > b){
                ans.push_back(i);
                res = min(res, solve(a + i, b, i, !turn, used+1));
                if(res)
                    ans.pop_back();
                else break;
            }
            if(turn && b + i > a){
                ans.push_back(i);
                res = min(res, solve(a, b + i, i, !turn, used+1));
                if(res)
                    ans.pop_back();
                else break;
            }
        }
    }
    return res;
}

int main(){
    init();
    string s;
    cin >> s;
    for(int i = 0;i < 10;i++)
        weights[i+1] = s[i] - '0';
    cin >> m;
    solve(0,0,0,0,0);
    if(ans.empty())
        cout << "NO";
    else{
        cout << "YES\n";
        for(int x : ans)
            cout << x << " ";
    }
}