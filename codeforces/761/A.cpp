#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int even,odd,sum;
    cin >> even >> odd;
    sum = even + odd;
    if(sum == 0 || abs(even-odd) > 1)cout << "NO";
    else cout << "YES";
}