#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e5 + 9, M = 15, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n, m;   cin >> n >> m;

    int r[n] = {0}, c[m] = {0};
    int grid[n][m], out[n][m];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int x;  cin >> x;
            grid[i][j] = x;
            r[i] += x;
            c[j] += x;
        }
    }


    int ror[n] = {0}, cor[m] = {0};
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(grid[i][j] == 1 && r[i] == m && c[j] == n)
                out[i][j] = 1;
            else
                out[i][j] = 0;

            ror[i] |= out[i][j];
            cor[j] |= out[i][j];
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(grid[i][j] != (ror[i] | cor[j]))
                return cout << "NO", 0;
        }

    }

    cout << "YES\n";
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout << out[i][j] << " ";
        }
        cout << '\n';
    }
}