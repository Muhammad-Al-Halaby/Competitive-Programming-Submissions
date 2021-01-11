#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

#define loop(a,n) for(int i = a;i<n;i++)
#define NumofDigits(n) ((int)log10(n)+1)
#define CountofNumber(array,n,x)  (upper_bound(array, array+n, x)-lower_bound(array, array+n, x))
#define readline(s) getline(cin,s)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

int visited[1005];

int main(){
    init();
    int n;
    cin >> n;
    string arr[n][2];
    for(int i = 0;i < n;i++)
        cin >> arr[i][0] >> arr[i][1];

    vector<string> v;
    for(int i = 0;i < n;i++){
        if(visited[i])continue;
        string s = arr[i][0], t = arr[i][0];
        for(int j = i;j < n;j++){
            if(not visited[j] && t == arr[j][0]){
                visited[j] = 1;
                t = arr[j][1];
            }
        }
        v.push_back(s + " " + t);
    }
    cout << v.size() << '\n';
    for(string s : v)
        cout << s << '\n';
}
