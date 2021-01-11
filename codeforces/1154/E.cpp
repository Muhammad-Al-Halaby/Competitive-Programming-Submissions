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

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )

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
    int arr[n],ans[n];
    pair<int,int> mx[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        mx[i].F = arr[i];
        mx[i].S = i;
    }

    sort(mx, mx + n);
    reverse(mx, mx + n);
    bool  taken[n] = {0};

    set<int> indices;
    for(int i = 0;i < n;i++)
        indices.insert(i);

    int curr_mx = 0, p = 1;

    while(true){
        //current max
        while(curr_mx < n && taken[mx[curr_mx].S])curr_mx++;
        if(curr_mx == n)break;
        int idx = mx[curr_mx].S;
        taken[idx] = 1;
        ans[idx] = p;

        indices.erase(indices.find(idx));

        //right & left
        int choose = k;
        while(choose){
            auto it = indices.upper_bound(idx);
            if(it == indices.end())break;
            else{
                choose--;
                int x = *it;
                indices.erase(it);
                taken[x] = 1;
                ans[x] = p;
                idx = x;
            }
        }
        choose = k;
        while(choose){
            auto it = indices.lower_bound(idx);
            if(it != indices.begin()){
                it--;
                choose--;
                int x = *it;
                indices.erase(it);
                taken[x] = 1;
                ans[x] = p;
                idx = x;
            }
            else
                break;
        }

        if(p == 1)
            p = 2;
        else
            p = 1;
    }

    for(int i = 0;i < n;i++)
        cout << ans[i];
}