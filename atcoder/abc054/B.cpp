#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e5 + 9, M = 2e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main()
{
    init();

    int n, m;
    cin >> n >> m;
    char a[n][n], b[m][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            cin >> b[i][j];

    for(int i = 0; i + m - 1< n; i++)
    {
        for(int j = 0; j + m - 1 < n; j++)
        {
            int ok = 1;
            for(int u = 0; u < m; u++)
            {

                for(int v = 0; v < m; v++)
                {
                    if(a[i + u][j + v] != b[u][v]) ok = 0;
                }
            }
            if(ok)  return cout << "Yes", 0;

        }

    }

    cout << "No";

}