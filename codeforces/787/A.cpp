#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include <sstream>
using namespace std;


int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
        bool f=0;
        for(int i = 0;i<10000;i++){
            for(int j = 0;j<10000;j++){
                if((b+a*i)==(d+j*c)){
                    cout << b+a*i;
                    f=1;
                    break;
                }
                if(f)break;
            }
            if(f)return 0;
        }
    cout << -1;
}