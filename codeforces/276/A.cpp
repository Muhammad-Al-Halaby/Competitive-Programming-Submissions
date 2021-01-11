#include <iostream>
#include<algorithm>

using namespace std;


int main(){
    int n,k;
    cin >> n >> k;
    int joy[n],temp_f,temp_t;
    for(int i = 0;i<n;i++){
        cin >> temp_f >> temp_t;
        if(temp_t > k){
            joy[i] = temp_f-(temp_t-k);
        }
        else{
            joy[i] = temp_f;
        }
    }

   int *max_joy = max_element(joy,joy+n);
    cout << *max_joy << endl;
}