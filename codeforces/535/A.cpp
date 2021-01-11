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
    string zeroToTen[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    string tens[]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    if(n <= 19) cout << zeroToTen[n];
    else if(n > 19 && n < 100){
        (n-(n/10)*10 != 0) ? cout << tens[n/10-2] << "-" << zeroToTen[n-(n/10)*10] : cout << tens[n/10-2];
    }
}