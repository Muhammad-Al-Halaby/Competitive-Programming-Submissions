#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[6],sum=0;
    for(int i = 0;i<6;i++){
            cin >> arr[i];
            sum += arr[i];
    }
    sort(arr,arr+6);
    do
    {
        int team1 = arr[0]+arr[1]+arr[2];
        int team2 = sum - team1;
        if(team1 == team2){
            cout << "YES";
            return 0;
        }
    }
    while(next_permutation(arr,arr+6));
    cout << "NO";
}
