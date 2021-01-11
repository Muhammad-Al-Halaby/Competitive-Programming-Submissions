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
#define MAXNODES 100009

struct DSU
{
    int parent[MAXNODES];
    int groupSize[MAXNODES];

    DSU()
    {
        for(int i = 0; i < MAXNODES; i++)
        {
            parent[i] = i;
            groupSize[i] = 1;
        }
    }

    int findRoot(int i)
    {
        if(parent[i] == i)  return i;

        return parent[i] = findRoot(parent[i]);
    }

    bool sameGroup(int x, int y)
    {
        int root1 = findRoot(x);
        int root2 = findRoot(y);

        return root1 == root2;
    }


    void mergeGroups(int x, int y)
    {
        int root1 = findRoot(x);
        int root2 = findRoot(y);

        if(root1 == root2)  return;

        if(groupSize[root1] > groupSize[root2])
        {
            parent[root2] =  root1;
            groupSize[root1] += groupSize[root2];
        }

        else
        {
            parent[root1] =  root2;
            groupSize[root2] += groupSize[root1];
        }
    }

    int getSize(int x)
    {
        int root = findRoot(x);
        return groupSize[root];
    }
};

int n, m;
int visited[1005];

int main(){
    init();
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0;i < n;i++)
        cin >> arr[i];
    string s;
    cin >> s;
    int l = 0, r = 0;

    ll ans = 0;
    priority_queue<int> pq;
    for(int i = 0;i <= n;i++){
        if(i < n && (i == 0 || s[i] == s[i-1]))
            pq.push(arr[i]);
        else{
            int x = k;
            while(!pq.empty() && x--){
                ans += pq.top();
                pq.pop();
            }
            while(!pq.empty())pq.pop();
            if(i < n)pq.push(arr[i]);
        }
    }
    cout << ans;
}
