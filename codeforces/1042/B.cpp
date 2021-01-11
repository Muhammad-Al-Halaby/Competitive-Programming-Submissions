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
typedef pair<int,int> pi;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

int fr[200];
int main(){
    init();
    int n;
    cin >> n;
    pair<int, string> arr[n];
    int ans, a, b, c;
    ans = a = b = c = 1000000;
    for(int i = 0;i < n;i++){
        cin >> arr[i].F >> arr[i].S;
        if(arr[i].S == "A")
            a = min(a, arr[i].F);
        else if(arr[i].S == "B")
            b = min(b, arr[i].F);
        else if(arr[i].S  == "C")
            c = min(c, arr[i].F);
        else if(arr[i].S.size() == 3 && arr[i].S[0] != arr[i].S[1] && arr[i].S[0] != arr[i].S[2] && arr[i].S[1] != arr[i].S[2])
            ans = min(ans, arr[i].F);
    }
    ans = min(ans, a + b + c);

    for(int i = 0;i < n;i++){

        for(int j = i + 1;j < n;j++){
            int vit[3] = {0};
            for(int k = 0;k < arr[i].S.size();k++)vit[arr[i].S[k] - 'A'] = 1;
            for(int k = 0;k < arr[j].S.size();k++)vit[arr[j].S[k] - 'A'] = 1;
            if(vit[0] + vit[1] + vit[2] == 3)
                ans = min(ans, arr[i].F + arr[j].F);
        }
    }
    if(ans == 1000000)
        cout << -1;
    else
        cout << ans;
}