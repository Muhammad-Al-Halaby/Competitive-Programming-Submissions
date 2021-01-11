#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
}

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int child[N][128];
int childNum[N];
int isEnd[N];
char childChars[N][128];
int nodes;

int addNode(){
    memset(child[nodes], -1, sizeof child[nodes]);
    childNum[nodes] = 0;
    isEnd[nodes] = 0;
    return nodes++;
}

void initTrie(){
    nodes = 0;
    addNode();
}

void insert(char* str){
    int cur;
    for(cur = 0 ; *str ; ++str){
        int& nxt = child[cur][*str];
        if(nxt == -1){
            nxt = addNode();
            childChars[cur][childNum[cur]++] = *str;
        }
        cur = nxt;
    }
    isEnd[cur]++;
}

int dp[N][2];

// 0: lose,   1: win
int solve(int u, bool goal){
    if(childNum[u] == 0)
        return !goal;

    int &ret = dp[u][goal];
    if(~ret)    return ret;

    ret = 0;
    for(int i = 0 ; i < childNum[u] ; ++i){
        char c = childChars[u][i];
        if(!solve(child[u][c], goal))   return ret = 1;
    }
    return ret;
}

int n, k;
char s[N];

int main(){
//    init();

    initTrie();
    scanf("%d%d", &n, &k);
    while(n--){
        scanf("%s", s);
        insert(s);
    }

    memset(dp, -1, sizeof dp);

    bool canWin = solve(0, 1);
    bool canLose = solve(0, 0);

    if(canWin && canLose)   return cout << "First", 0;
    if(canWin && (k & 1))   return cout << "First", 0;

    cout << "Second";
}
