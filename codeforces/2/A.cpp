#include <iostream>
#include <algorithm>
#include<vector>
#include<math.h>
#include<iomanip>
#include<utility>
#include<numeric>
#include<set>

using namespace std;

int main(){
    vector<string> names;
    vector<int> scores;
    vector<pair<string,int> > details;
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        string name;
        int score;
        cin >> name >> score;
        details.push_back(make_pair(name,score));
        if(find(names.begin(),names.end(),name) == names.end())names.push_back(name);
    }
    for(int i = 0;i<names.size();i++){
        string name = names[i];
        int sum = 0;
        for(int i = 0;i<n;i++){
            if(details[i].first == name){
                //if(details[i].second >= 0){
                    details[i].second += sum;
                    sum = details[i].second;
                //}
            }
        }
        scores.push_back(sum);
    }
    int max_sum = *max_element(scores.begin(),scores.end());
    for(int i = 0;i<n;i++){
        int pos = find(names.begin(),names.end(),details[i].first)-names.begin();
        if(details[i].second >= max_sum && scores[pos] == max_sum){
            cout << details[i].first;
            break;
        }
    }
}