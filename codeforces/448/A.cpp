#include <iostream>
#include<math.h>

using namespace std;

int main(){
    double vars[7];
    for(int i = 0;i<7;i++)
        cin >> vars[i];
    double total_Cups = ceil((vars[0] + vars[1] + vars[2])/5);
    double total_Medals = ceil((vars[3] + vars[4] + vars[5])/10);

    vars[6] -= total_Cups;
    vars[6] -= total_Medals;

    if(vars[6] >= 0) cout << "YES";
    else cout << "NO";
}