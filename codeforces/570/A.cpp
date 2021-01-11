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

int main(){
    init();
    int n, m;
    cin >> n >> m;
    int winner[105] = {0};
    for(int i = 0;i < m;i++){
        int mx = 0, win = 0;
        for(int j = 0;j < n;j++){
            int x;
            cin >> x;
            if(x > mx){
                mx = x;
                win = j;
            }
        }
        winner[win]++;
    }

    int mx = 0, win = 0;
    for(int i = 0;i < n;i++){
        if(winner[i] > mx){
            mx = winner[i];
            win = i;
        }
    }
    cout << win + 1;
}