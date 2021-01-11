#include<bits/stdc++.h>
using namespace std; 

int main(){ 
    int k,ans=0;
    cin >> k;
    string s,swit;
    cin >> s;
    for(int i = 0;i<s.length();i++){
        if(swit.find(s[i]) == string::npos)swit+=s[i];
    }
    if(k == 1)cout << s;
    else{
        int arr[swit.length()]={0};
        for(int i = 0;i<swit.length();i++){
            for(int j =0;j<s.length();j++){
                if(s[j] == swit[i])arr[i]+=1;
            }
        }
        for(int i = 0;i<swit.length();i++){
            if(arr[i] % k != 0){ans = -1;break;}
        }
        if(ans!=-1){
            for(int i = 0;i<k;i++){
                for(int j = 0;j<swit.length();j++){
                    for(int l = 0;l<arr[j]/k;l++){
                        cout << swit[j];
                    }
                }
            }
        }
    }
    if(ans == -1)cout << ans;
}