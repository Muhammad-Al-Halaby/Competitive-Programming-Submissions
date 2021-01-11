#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> coins;

    for(int i =0;i<n;i++){
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }

    sort(coins.begin(),coins.end());

    int sum=0,numOfCoins=0;
    bool found = false;
    for(int i =0;i<n;i++){
            sum += coins[coins.size()-1];
            numOfCoins++;
            coins.pop_back();
            int s = accumulate(coins.begin(),coins.end(),0);
            if(sum > s){
                found = true;
                break;
            }
    }

    if(found) cout << numOfCoins;
    else cout << 0;

}