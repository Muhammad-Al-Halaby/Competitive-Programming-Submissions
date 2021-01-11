#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge

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
int n, len[105];
int startX, startY, endX, endY;

bool visited[105][100009];

// 0 up
// 1 right
// 2 down
// 3 left
pii moveIt(int x, int y, int &dir){
    if(dir == 0){
        if(x > 0)
            x--;
        if(y > len[x])
            y = len[x];
    }
    else if(dir == 1){
        if(y < len[x])
            y++;
    }
    else if(dir == 2){
        if(x < n - 1)
            x++;
        if(y > len[x])
            y = len[x];
    }
    else{
        if(y > 0)
            y--;
    }
    return {x, y};
}

int go(){
    if(startX == endX && startY == endY)
        return 0;


    queue<pii> q;

    visited[startX][startY] = 1;

    q.push({startX, startY});

    int depth = 1, sz = 1;
    for(;!q.empty();++depth, sz = q.size()){
        while(sz--){
            int x = q.front().F;
            int y = q.front().S;
            q.pop();
            for(int i = 0;i < 4;i++){
                pii p = moveIt(x, y, i);

                int newX = p.F;
                int newY = p.S;

                if(!visited[newX][newY]){
                    if(newX == endX && newY == endY)
                        return depth;

                    visited[newX][newY] = 1;

                    q.push({newX, newY});
                }
            }
        }
    }
    return 0;
}


int main(){
    init();

    memset(visited, 0, sizeof visited);

    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> len[i];

    cin >> startX >> startY >> endX >> endY;

    startX-- , startY--, endX--, endY--;

    cout << go();
}