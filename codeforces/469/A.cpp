#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
int n,p,q;
cin >> n >> p;
vector<int>  pq;
for(int i = 0;i<p;i++){
int x;
cin >> x;
if( find(pq.begin(),pq.end(),x) == pq.end()) pq.push_back(x);
}
cin >> q;
for(int i = 0;i<q;i++){
int x;
cin >> x;
if(find(pq.begin(),pq.end(),x) == pq.end()) pq.push_back(x);
}

if(pq.size() == n) cout << "I become the guy.";
else cout << "Oh, my keyboard!";
}