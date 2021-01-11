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
//#define modulo ll (1e9 + 7)
#define modulo ll (1e6 + 3)
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

int check[(int)1e5+5];

int main(){
    init();
    int n;
    cin >> n;
    string arr[2 * n - 2];
    string a, b;
    int f = 1;
    for(int i = 0;i < 2 * n - 2;i++){
        string s;
        cin >> s;
        if(s.size() == n - 1){
            if(f)a = s, f = 0;
            else b = s;
        }
        arr[i] = s;
    }

    char ans[2 * n - 2];

    string x, y;
    x = a[0] + b;
    swap(a, b);
    y = a[0] + b;


    if(x.size() > 0){
        int check[300] = {0}, cnt = 0;
        for(int i = 1;i < n;i++){
            string h = x.substr(0, i);
            for(int j = 0;j < 2 * n - 2;j++){
                if(h == arr[j] && !check[j]){
                    check[j] = 1;
                    ans[j] = 'P';
                    cnt++;
                    break;
                }
            }
        }

        for(int i = 1;i < n;i++){
            string h = x.substr(n - i);
            for(int j = 0;j < 2 * n - 2;j++){
                if(h == arr[j] && !check[j]){
                    check[j] = 1;
                    ans[j] = 'S';
                    cnt++;
                    break;
                }
            }
        }
        if(cnt == n * 2 - 2){
            for(char c : ans)
                cout << c;
            return 0;
        }
    }

    {
        int check[300] = {0}, cnt = 0;
        for(int i = 1;i < n;i++){
            string h = y.substr(0, i);
            for(int j = 0;j < 2 * n - 2;j++){
                if(h == arr[j] && !check[j]){
                    check[j] = 1;
                    ans[j] = 'P';
                    cnt++;
                    break;
                }
            }
        }

        for(int i = 1;i < n;i++){
            string h = y.substr(n - i);
            for(int j = 0;j < 2 * n - 2;j++){
                if(h == arr[j] && !check[j]){
                    check[j] = 1;
                    ans[j] = 'S';
                    cnt++;
                    break;
                }
            }
        }
        if(cnt == n * 2 - 2){
            for(char c : ans)
                cout << c;
            return 0;
        }

    }
}