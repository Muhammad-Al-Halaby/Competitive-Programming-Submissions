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


int fr[2000];
int check[2000];
int main(){
    init();
    int n;
    cin >> n;
    int arr[n * n];
    int ans[n][n];
    for(int i = 0;i < n * n;i++){
        cin >> arr[i];
        fr[arr[i]]++;
        check[arr[i]]++;
    }

    priority_queue<pii> pq;
    for(int i = 1;i <= 1000;i++){
        if(fr[i])
            pq.push(make_pair(fr[i], i));
    }

    int four_letters = (n / 2) * (n / 2);
    int two_letters = (n % 2 == 0)?0:n - 1;
    int one_letter = (n % 2 == 0)?0:1;

    int exist = 1, a = four_letters,b = two_letters,c = one_letter;
    for(int i = 1;i <= 1000;i++){
        if(check[i]){
            while(a && check[i] >= 4){
                a--;
                check[i]-=4;
            }

            while(b && check[i] >= 2){
                b--;
                check[i]-=2;
            }

            while(c && check[i] >= 1){
                c--;
                check[i]--;
            }

        }
    }

    if(a == 0 && b == 0 && c == 0)
        cout << "YES\n";
    else
        return cout << "NO", 0;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            ans[i][j] = 0;
        }
    }

    for(int i = 0;i < n / 2;i++){
        for(int j = 0;j < n / 2;j++){
            pii p = pq.top();
            int freq = p.first;
            int x = p.second;
            pq.pop();
            freq -= 4;
            ans[i][j] = x;
            ans[n-i-1][j] = x;
            ans[i][n-j-1] = x;
            ans[n-i-1][n-j-1] = x;
            if(freq)
                pq.push(MP(freq,x));
        }
    }

    if(n & 1){
        int h = n / 2;
        for(int i = 0;i < n / 2;i++){
            pii p = pq.top();
            int freq = p.first;
            int x = p.second;
            pq.pop();
            ans[h][i] = x;
            ans[h][n-i-1] = x;
            freq -= 2;
            if(freq)
                pq.push(MP(freq,x));
        }

        int half = ceil(n / 2.0);
        for(int i = 0;i < n / 2;i++){
            pii p = pq.top();
            int freq = p.first;
            int x = p.second;
            pq.pop();
            ans[i][h] = x;
            ans[n-i-1][h] = x;
            freq -= 2;
            if(freq)
                pq.push(MP(freq,x));
        }

        pii p = pq.top();
        int freq = p.first;
        int x = p.second;
        ans[h][h] = x;
    }


    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}
