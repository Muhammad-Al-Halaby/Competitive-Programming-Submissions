#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
#define debug(x) cerr << #x << " = " << (x) << '\n'
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 2e5 + 10, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int s[N], r[N];
int main(){
    init();

        int n;  cin >> n;
        vector<int> ds, dr;
        for(int i = 0;i < n;i++){
            int x;  cin >> x;
            s[i] = x;
            if(x == 0)
                ds.push_back(i + 1);
            else    r[x - 1] = 1;
        }


        for(int i = 0;i < n;i++)
            if(r[i] == 0)   dr.push_back(i + 1);


        sort(ds.begin(), ds.end());
        sort(dr.rbegin(), dr.rend());

        int sz = ds.size();
        for(int i = 0;i < sz;i++)
            if(ds[i] == dr[i]){
            if(i == 0)
                swap(ds[sz - 1], ds[i]);
            else
                swap(ds[0], ds[i]);
        }
        for(int i = 0;i < sz;i++){
            int a = ds[i], b = dr[i];
            s[a - 1] = b;
        }

        for(int i = 0;i < n;i++)
            cout << s[i] << " ";

}