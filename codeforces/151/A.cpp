#include <iostream>

using namespace std;

int main(){
    int n,k,l,c,d,p,nl,np;
    cin >> n >> k  >> l  >> c  >> d  >> p  >> nl  >> np;
    int milliliters=k*l;
    int limes = c*d;
    int salt = p/np;
    int bottles=0;
    bool is=true;
    while(is){
            if(milliliters - nl >= 0 && limes - 1 >=0 && salt - 1 >= 0){
                milliliters -= nl;
                limes -= 1;
                salt -= 1;
                bottles++;
                is = true;
            }

            else{
                is = false;
            }
    }
    cout << bottles/n << endl;
}