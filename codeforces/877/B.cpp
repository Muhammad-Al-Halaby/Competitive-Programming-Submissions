#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

const int N = 5e3 + 5;
int a[N], b[N];

int main(){
    init();
	
    string s;
	cin >> s;
	
	int n = s.size();
	
	for(int i = 0;i < n;i++){
		a[i + 1] += (s[i] == 'a') + a[i];
		b[i + 1] += (s[i] == 'b') + b[i];
	}
	
	int deleted = N;
	for(int i = 0;i <= n;i++)
		for(int j = i + 1;j <= n;j++)
			deleted = min(deleted, (b[i]) + (a[j - 1] - a[i]) + (b[n] - b[j]));
		
	cout << n - deleted;
}