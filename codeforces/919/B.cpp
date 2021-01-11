#include<bits/stdc++.h>

using namespace std;

bool isten(int n){
    int sum = 0;
    while(n){
        sum += n % 10;
        n/=10;
        if(sum > 10)break;
    }
    if(sum == 10)
        return 1;
    return 0;
}
int main(){
    int k,i=0,counter=0;
    cin >> k;
    while(true){
        if(isten(i)){
            counter++;
            if(counter==k)
                break;
        }
        i++;
    }
    cout << i;
}