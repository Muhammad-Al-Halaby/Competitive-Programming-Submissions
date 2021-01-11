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

    string s;   cin >> s;   int n = s.size();
    string st = ""; st.push_back(s[0]);


    int j = 0, p = 0;
    for(int i = 1;i < n;i++){

        while(j > 0 && st[j - 1] != s[i]){
            p++;
            st.pop_back();  j--;
        }

        st.push_back(s[i]); j++;
    }


    cout << (p & 1 ? "First" : "Second");
}