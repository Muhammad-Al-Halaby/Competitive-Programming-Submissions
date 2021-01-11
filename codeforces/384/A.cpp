#include<bits/stdc++.h>
using namespace std; 

int main(){
    int n;
    cin >> n;
    (n%2==0)?cout<<(n*n)/2<<endl:cout<<(n*n)/2+1<<endl;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i%2!=0){
                if(j%2!=0)cout << "C";
                else cout << ".";
            }
            else{
                if(j%2==0)cout << "C";
                else cout << ".";
            }
        }
        if(i!=n)cout << endl;
    }
} 