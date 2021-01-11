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
#define MOD ll (1e9 + 7)


typedef long long ll;
typedef unsigned long long ull;
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

int fr[(int)1e5+10];

int main(){
    init();
    int n, m;
    cin >> n >> m;
    int arr[m];
    for(int i = 0;i < m;i++)
        cin >> arr[i];
    set<int> s;
    for(int i = 0;i < m;i++){
        if(s.find(arr[i]) == s.end())
            s.insert(arr[i]);
        else fr[arr[i]]++;
        if(s.size() == n){
            cout << 1;
            s.clear();
            for(int j = 1;j <= n;j++){
                if(fr[j] && s.find(j) == s.end()){
                    s.insert(j);
                    fr[j]--;
                }
            }
        }
        else cout << 0;
    }
}