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
#define EPS 1e-6


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int prefix[(int)1e5+5];
int seen[(int)1e5+5];
int freq[(int)1e5+5];

int main(){
    init();
    string s1,s2;
    cin >> s1 >> s2;
    int p1=0,n1=0,p2=0,n2=0,q=0;
    vector<char> possible;
    for(int i = 0;i<s1.length();i++){
        if(s1[i] == '+')p1++;
        else n1++;
        if(s2[i] == '+')p2++;
        else if(s2[i] == '-')n2++;
        else{
            q++;
        }
    }
    int pos=0,neg=0;
    pos = p1 - p2;
    neg = n1 - n2;
    if(pos >=0 && neg >= 0 && q == pos + neg){
        for(int i = 0;i<pos;i++)
            possible.push_back('+');
        for(int i = 0;i<neg;i++)
            possible.push_back('-');
        sort(possible.begin(),possible.end());
        double prob=0, all =1;
        if(q) all = pow(2,q);
        do{
            prob++;
        }while(next_permutation(possible.begin(),possible.end()));
        printf("%.9f",prob / all);
        return 0;
    }
    cout << 0.0;
}