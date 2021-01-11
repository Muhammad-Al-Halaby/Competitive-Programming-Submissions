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
    int n;
    cin >> n;
    int police = 0,untreated = 0;
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        if(num == -1 && police == 0) untreated++;
        else if(num != -1) police+=num;
        else if(num == -1 && police > 0)police--;
    }
    cout << untreated;
}