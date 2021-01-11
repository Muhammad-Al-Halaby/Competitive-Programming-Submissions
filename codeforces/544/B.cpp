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

const int N = 1e3 + 9, M = 12, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main(){
    init();

    int n, k;   cin >> n >> k;
    char grid[n][n];

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            grid[i][j] = 'S';
            if(k){
                if((i && grid[i - 1][j] == 'L') || (j && grid[i][j - 1] == 'L'));
                else grid[i][j] = 'L', k--;
            }
        }
    }

    if(k)   return cout << "NO", 0;

    cout << "YES\n";
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cout << grid[i][j];
        }
        cout << '\n';
    }

}