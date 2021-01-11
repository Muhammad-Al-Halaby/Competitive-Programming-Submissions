#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI 3.14159265358979323846
#define F first
#define S second


typedef long long ll;
typedef unsigned long long ull;

ll MOD = 1e9+7;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main() {
	init();
	
    int n, s, ans = 0;
    ll cost = 0;
    cin >> n >> s;
    
    int arr[n];
    for(int i = 0;i < n;i++)
    	cin >> arr[i];
    	
    int l = 1, r = n;
    while(l <= r){
    	int k = (l+r) / 2;
    	ll b[n];

    	for(int i = 0;i < n;i++)
    		b[i] = arr[i] + ll(i+1) * k;

    	sort(b, b + n);
    	partial_sum(b, b + n, b);
    	
    	if(b[k-1] <= s){
    		if(k > ans){
    			ans = k;
    			cost = b[k-1];
    		}
    		else if(k == ans)
    			cost = min(cost,b[k-1]);
    			
    		l = k + 1;
    	}
    	else
    		r = k - 1;
    }
 
    cout << ans << " " << cost;
}