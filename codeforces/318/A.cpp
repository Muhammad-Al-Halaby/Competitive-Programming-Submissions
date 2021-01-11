#include <iostream>

using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    if(k >= 1 && k <= n && n <= 1e12){
            long long odd=0;
            if(n % 2 != 0){
                odd = ((n/2)+1);
            }
            else if (n % 2 == 0){
                odd = (n/2);
            }

        if(k <= odd){
            cout << (2*k)-1 << endl;
        }
        else{
            cout << (2*(k-odd));
        }

    }
}