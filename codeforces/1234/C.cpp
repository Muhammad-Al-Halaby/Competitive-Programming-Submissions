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
typedef pair<ll,ll> pll;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

const int N = 1e5 + 9, M = 600, OO = 0x3f3f3f3f;
const ll llOO = 1e18;

int visited[2][N];

int main(){
    init();

    int q;  cin >> q;
    while(q--){
        int n;  cin >> n;
        char arr[n][2];
        for(int i = 0;i < n;i++)    cin >> arr[i][0];
        for(int i = 0;i < n;i++)    cin >> arr[i][1];

        for(int i = 0;i < n;i++){
            if(arr[i][0] == '1')    arr[i][0] = '2';
            if(arr[i][1] == '1')    arr[i][1] = '2';
        }

        if(arr[0][0] <= '2')    arr[0][0] = '2';
        else arr[0][0] = '4';


        int i = 0, j = 0, ans = 1;
        while(true){
            int curr = arr[i][j] - '0';
            if(i == n - 1 && j == 1 && (arr[i][j] == '2' || arr[i][j] == '6')){
                break;
            }
            else if(curr == 2){
                if(i + 1 == n){
                    ans = 0;    break;
                }
                if(arr[i+1][j] > '2'){
                    if(j == 0)
                        arr[i+1][j] = '4';
                    else
                        arr[i+1][j] = '5';
                }
                i++;
            }
            else if(curr == 3){
                if(i + 1 == n){
                    ans = 0; break;
                }
                if(arr[i+1][j] != '2')  arr[i+1][j] = '4';
                i++;
            }
            else if(curr == 4){
                if(j + 1 == 2){
                    ans = 0; break;
                }
                if(arr[i][j+1] == '2'){
                    ans = 0; break;
                }
                arr[i][j+1] = '6';
                j++;
            }
            else if(curr == 5){
                if(j - 1 < 0){
                    ans = 0;    break;
                }
                if(arr[i][j - 1] == '2'){
                    ans = 0;    break;
                }

                arr[i][j - 1] = '3';
                j--;
            }
            else if(curr == 6){
                if(i + 1 == n){
                    ans = 0; break;
                }
                if(arr[i+1][j] != '2') arr[i+1][j] = '5';
                i++;
            }
        }
        if(ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}