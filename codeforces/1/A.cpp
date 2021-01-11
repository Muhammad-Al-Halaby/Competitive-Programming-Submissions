#include <iostream>
#include<math.h>

using namespace std;

int main(){
    double n,m,k;
    cin >> n >> m >> k;
    long long column = ceil(n/k);
    long long row = ceil(m/k);
    long long flagstones = column * row;
    cout << flagstones << endl;
}