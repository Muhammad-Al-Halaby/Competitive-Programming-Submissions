#include <bits/stdc++.h>
using namespace std;

inline void init()
{
    cin.tie(0);
    cin.sync_with_stdio(0); 
};

#include<bits/stdc++.h>
using namespace std;

int main(){
init();
string s; 
cin >> s; 
int ans = 0, l = 0, r = s.size()-1;
while(l<r){
if(s[l] != s[r])ans++;
l++;
r--;
}

if(ans == 1 || (!ans && s.size() % 2))
cout << "YES";
else 
cout << "NO";

}