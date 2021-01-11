#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> pieces;
    vector<int> s;

    for(int i = 0;i<m;i++){int x; cin >> x; pieces.push_back(x);}
    sort(pieces.begin(),pieces.end());

    for(int i = 0;i<m;i++){
                int max = *max_element(pieces.begin()+i,pieces.begin()+i+n);
                int min = *min_element(pieces.begin()+i,pieces.begin()+i+n);
                int num = max - min;
                int posmax = find(pieces.begin(), pieces.end(), max) - pieces.begin();
                int posmin = find(pieces.begin(), pieces.end(), min) - pieces.begin();
                if(posmax < pieces.size() && posmin < pieces.size()) s.push_back(num);
    }
    cout << *min_element(s.begin(),s.end());
}