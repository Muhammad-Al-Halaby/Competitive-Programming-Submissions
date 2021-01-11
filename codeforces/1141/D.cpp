#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

#define loop(x,a,n) for(int x = a;x < n;x++)
#define NumofDigits(n) ((int)log10(n)+1)
#define CountofNumber(array,n,x)  (upper_bound(array, array+n, x)-lower_bound(array, array+n, x))
#define readline(s) getline(cin,s)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;


typedef long long ll;
typedef unsigned long long ull;
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

int main(){
    init();

    int n;
    cin >> n;
    string l,r;
    cin >> l >> r;
    vector<int> left[26];
    vector<int> right[26];
    vector<int> leftQ;
    vector<int> rightQ;

    for(int i = 0;i < n;i++){
        if(l[i] != '?')left[l[i] - 'a'].push_back(i + 1);
        else leftQ.push_back(i + 1);

        if(r[i] != '?')right[r[i] - 'a'].push_back(i + 1);
        else rightQ.push_back(i + 1);
    }
    vector<pair<int, int> >pairs;

    int ileft = 0, iright = 0;

    for(int i = 0;i < 26;i++){
        int mn = min(left[i].size(), right[i].size());
        for(int j = 0;j < mn;j++){
            pairs.push_back(MP(left[i][j],right[i][j]));
        }

        int j = mn;
        while(j < left[i].size() && iright < rightQ.size())
            pairs.push_back(MP(left[i][j++],rightQ[iright++]));

        j = mn;
        while(j < right[i].size() && ileft < leftQ.size())
            pairs.push_back(MP(leftQ[ileft++], right[i][j++]    ));
    }


    while(ileft < leftQ.size() && iright < rightQ.size())
        pairs.push_back(MP(leftQ[ileft++],rightQ[iright++]));

    cout << pairs.size() << '\n';

    for(auto p : pairs)
        cout << p.F << " " << p.S << '\n';

}