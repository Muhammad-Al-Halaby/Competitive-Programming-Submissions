#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int x;
    cin >> x;
    if(x >= 0)cout << x;
    else{
        if(abs(x%10) >= abs(x/10)%10)cout << x/10;
        else cout << (x/100)*10-abs(x%10);
    }
}