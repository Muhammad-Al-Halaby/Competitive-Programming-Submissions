#include<bits/stdc++.h>
using namespace std; 

int main(){
    int n,zs,os,sum=0,counter=0;
    cin >> n;
    int b[n];
    vector<int> sums;
    for(int i = 0;i<n;i++){cin >> b[i];sum+=b[i];};

    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            int lsum=0;
            for(int k = i;k<=j;k++){
                if(b[k]==0)lsum++;
                else lsum--;
            }
            lsum++;
            sums.push_back(lsum);
        }
    }
    cout << sum+*max_element(sums.begin(),sums.end())-1;
}