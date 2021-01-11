#include <iostream>
#include <algorithm>
#include<vector>
#include<math.h>
#include<iomanip>
#include<utility>
#include<numeric>
using namespace std;

int main(){
    std::cout << std::fixed;
    std::cout << std::setprecision(10);

    double a,b,c,delta;
    cin >> a >> b >> c;
    delta = sqrt((b*b)-(4*a*c));
    if(a == 0 || b == 0 && c == 0){
        if(a == 0 && b == 0 && c == 0) cout << -1;
        else if(a != 0 && b == 0 && c == 0){
            cout << 1 << endl;
            cout << 0;
        }
        else if(a == 0 && b != 0 && c != 0){
            cout << 1 << endl;
            cout << -c/b;
        }
        else if(a == 0 && b == 0) cout << 0;
        else if(a == 0 && b != 0 && c == 0){
            cout << 1 << endl;
            cout << 0;
        }
    }
    else{
        if(delta > 0){
            cout << 2 << endl;
            cout << min(((-b+delta)/(2*a)),((-b-delta)/(2*a))) << endl;
            cout << max(((-b+delta)/(2*a)),((-b-delta)/(2*a)));
        }
        else if(delta == 0){
            cout << 1 << endl;
            cout << (-b / (2*a));
        }
        else if(((b*b)-(4*a*c)) < 0) cout << 0;
    }

}