#include <iostream>
#include<vector>
#include<numeric>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> cards;
    int temp,five=0,zero=0;
    for(int i =0;i<n;i++){
        cin >> temp;
        if(temp == 0){
            zero++;
        }
        else{
            five++;
            cards.push_back(temp);
        }
    }
    for(int i =0;i<zero;i++){
        cards.push_back(0);
    }
    int sum=0,is=0;
    for(int i = 0;i<n;i++){
         sum = accumulate(cards.begin(), cards.end(), 0);
        if(sum % 9 == 0 && zero > 0){
            is = 1;
            break;
        }
        else if(sum % 9 == 0 && zero == 0){
            is = 0;
            break;
        }

        else if(sum % 9 != 0 && cards.size() > 1) {
                cards.erase(cards.begin(),cards.begin()+1);
                sum = 0;
                i = -1;
        }
        else{
            is = 0;
            break;
        }
    }
    if(is == 1){
        if(sum != 0){
          for(int i = 0;i<cards.size();i++){
            cout << cards.at(i);
          }
        }
        else if(sum == 0 && zero >0){
            cout << 0;
        }
    }
    else{
        cout << -1;
    }
}