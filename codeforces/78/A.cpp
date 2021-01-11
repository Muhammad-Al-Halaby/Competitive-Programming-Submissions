#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[]={5,7,5};
    bool ans=true;
    for(int i = 0;i<3;i++){
        string x;
        getline(cin,x);
        int counter=0;
        for(int j = 0;j<x.length();j++){
            if(x[j]=='a'||x[j]=='e'||x[j]=='i'||x[j]=='o'||x[j]=='u')counter++;
        }
        if(counter!=arr[i])ans=false;
    }
    if(ans)cout << "YES";
    else cout << "NO";
}