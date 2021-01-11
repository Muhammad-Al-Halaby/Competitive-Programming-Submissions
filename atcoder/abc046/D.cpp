#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 55, M = 3e3, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    string s;   cin >> s;

    int n = s.size();

    char a[n];
    for(int i = 0;i < n;i++)    a[i] = 'p';

    int score = 0, p = 0;
    for(int i = 0;i < n;i++){
        p++;

        if(p <= (i + 1 - p));
        else p--, a[i] = 'g';

        score += (a[i] == 'p' && s[i] == 'g');
        score -= (a[i] == 'g' && s[i] == 'p');
    }

    cout << score;
}