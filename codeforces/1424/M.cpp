#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, k;

int adj[26][26], in[26], freq[26];

void addEdge(char a, char b){
    int u = a - 'a';
    int v = b - 'a';

    if(adj[u][v])   return;
    if(adj[v][u]){
        cout << "IMPOSSIBLE";
        exit(0);
    }

    adj[u][v] = 1;
    in[v]++;
}

void go(int tc){
    cin >> n >> k;

    vector<string> a[n + 1];
    for(int i = 0;i < n;i++){
        int p;  cin >> p;
        for(int j = 0;j < k;j++){
            string s;   cin >> s;
            a[p].push_back(s);
            for(auto c : s)
                freq[c - 'a'] = 1;
        }
    }

    vector<string> v;
    for(int i = 0;i < n;i++){
        for(int j = 0; j < a[i].size(); j++){
            v.push_back(a[i][j]);
        }
    }

    for(int k = 0; k < v.size() - 1; k++){
        int i = 0, j = 0;
        while(i < v[k].size() && j < v[k + 1].size() && v[k][i] == v[k + 1][j]){
            i++;
            j++;
        }

        if(i == v[k].size() && j == v[k + 1].size())    continue;

        else if(i < v[k].size() && j < v[k + 1].size()){
            char a = v[k][i];
            char b = v[k + 1][j];
            addEdge(a, b);
            continue;
        }

        else if(j == v[k + 1].size()){
            cout << "IMPOSSIBLE";
            exit(0);
        }
    }

    int cnt = 0;
    queue<int> q;
    for(int i = 0;i < 26;i++){
        cnt += freq[i];
        if(freq[i] && in[i] == 0)  q.push(i);
    }

    vector<int> ans;
    while(q.size()){
        int u = q.front();  q.pop();
        ans.push_back(u);
        for(int v = 0;v < 26;v++){
            if(adj[u][v]){
                in[v]--;
                if(in[v] == 0)  q.push(v);
            }
        }
    }

    if(cnt != ans.size())
        return cout << "IMPOSSIBLE", void();

    for(auto x : ans)
        cout << char('a' + x);
}

int main() {
    init();

//    freopen("in.in", "r", stdin);
//    freopenA("out.out", "w", stdout);


    int t = 1, tc = 1;
//    cin >> t;
    while(t--)
        go(tc++);
}