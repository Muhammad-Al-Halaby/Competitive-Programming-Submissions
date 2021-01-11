#include<bits/stdc++.h>
using namespace std; 

bool isLucky(int d){
     return (d == 4 || d == 7);
}

int main(){ 
    int n,k,ans=0;
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        int lucky_digits=0;
        string num;
        vector<int> digits;
        cin >> num;
        for(int j=0;j<num.size();j++)digits.push_back(num[j]-'0');
        lucky_digits = count_if(digits.begin(),digits.end(),isLucky);
        if(lucky_digits<= k)ans++;
    }
    cout << ans;
}