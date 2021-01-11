#include <iostream>
using namespace std;

int main()
{
    int k,l,m,n,d,damaged=0;
    cin >> k >> l >> m >> n >> d;
    if ( k >= 1 && k <= 10 && l >= 1 && l <= 10 && m >= 1 && m <= 10 && n >= 1 && n <= 10 && d >= 1 && d <= 1e5 ){
        for(int i = 1;i<=d;i++){
            if(i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0 ){
                    damaged++;
            }
        }
        cout << damaged;
    }

}
