#include <iostream>
#include<vector>

using namespace std;

int main(){
    int n,temp;
    cin >> n;
    vector<int> cards;
    for(int i = 0;i<n;i++){
            cin >> temp;
            cards.push_back(temp);
    }
    int player_num=1,sereja=0,dima=0;
    for(int i=0;i<n;i++){
        if(player_num == 1){
            if(cards.at(0) >= cards.at(cards.size()-1)){
               sereja += cards.at(0);
               cards.erase(cards.begin(),cards.begin()+1);
            }
            else{
               sereja += cards.at(cards.size()-1);
               cards.erase(cards.begin()+cards.size()-1,cards.end());
            }
            player_num = 2;
            continue;
        }
        if(player_num == 2){
            if(cards.at(0) >= cards.at(cards.size()-1)){
               dima += cards.at(0);
               cards.erase(cards.begin(),cards.begin()+1);
            }
            else{
               dima += cards.at(cards.size()-1);
               cards.erase(cards.begin()+cards.size()-1,cards.end());
            }
            player_num = 1;
            continue;
        }
    }

    cout << sereja << " " << dima << endl;

}