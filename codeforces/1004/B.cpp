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

int freq[(int)1e5+5];

int main(){
    init();
    int n,v;
    cin >> n >> v;
    pair<int,int> ranges[v];
    vector<bool> flowers(n+1,0);
    for(int i = 0;i<v;i++){
        int l,r;
        cin >> l >> r;
        ranges[i] = make_pair(l,r);
    }
    sort(ranges,ranges+v);
    for(int i = 0;i<v;i++){
        int l = ranges[i].first;
        int r = ranges[i].second;
        for(int j = l;j<=r;j++){
            if(!freq[j]){
                flowers[j] = (flowers[j-1]) ^ 1;
                freq[j] = 1;
            }
        }
    }
    for(int i = 1;i<=n;i++)
        cout << flowers[i];
}