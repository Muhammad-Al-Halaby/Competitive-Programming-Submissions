#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
#define debug(x) cerr << #x << " = " << (x) << '\n'
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
#endif
}

const int N = 100, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


int freq[10] = {0};

vector<int> x[3];


void print(){
    int s = accumulate(freq, freq + 10, 0);
    if(!s || !freq[0])  cout << -1;
    else if(s == freq[0]) cout << 0;
    else for(int i = 9;~i;i--)  for(int j = 0;j < freq[i];j++)  cout << i;
    exit(0);
}


int main(){
    init();

    int n;  cin >> n;
    int sum = 0;
    for(int i = 0;i < n;i++){
        int x;  cin >> x;
        freq[x]++;
        sum += x;
    }


    for(int i = 0;i < 10;i++){
        if(!freq[i])    continue;
        if(i % 3){
            for(int j = 0;j < freq[i];j++)  x[i % 3].PB(i);
        }
    }

    if(sum % 3 == 0)    print();
    if(sum % 3 == 1){
        if(x[1].size()) freq[x[1][0]]--, print();
        if(x[2].size() >= 2) freq[x[2][0]]--, freq[x[2][1]]--, print();
    }

    if(x[2].size()) freq[x[2][0]]--, print();
    if(x[1].size() >= 2) freq[x[1][0]]--, freq[x[1][1]]--, print();

    print();
}