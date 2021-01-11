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

struct request{
    int people, cost, idx;
    bool operator <(const request &b)const{
        if(cost == b.cost)
            return people < b.people;
        return cost > b.cost;
    }
};

int taken[1005];

int main(){
    init();
    int k;
    cin >> k;
    request arr[k];
    for(int i = 0;i < k;i++){
        int p, c;
        cin >> p >> c;
        arr[i].idx = i + 1;
        arr[i].people = p;
        arr[i].cost = c;
    }
    int n;
    cin >> n;
    pii tables[n];
    for(int i = 0;i < n;i++){
        cin >> tables[i].F;
        tables[i].S = i + 1;
    }
    sort(arr, arr + k);
    sort(tables, tables + n);
    vector<pii> ans;
    int requests = 0, money = 0;
    for(int i = 0;i < k;i++){
        int idx = lower_bound(tables, tables + n, MP(arr[i].people,-1)) - tables;

        while(idx < n && taken[tables[idx].S])idx++;
        if(idx == n)continue;
        requests++;
        money += arr[i].cost;
        ans.push_back(MP(arr[i].idx,tables[idx].S));
        taken[tables[idx].S] = 1;
    }

    cout << requests << " " << money << '\n';
    for(auto p : ans){
        cout << p.F << " " << p.S << '\n';
    }
}