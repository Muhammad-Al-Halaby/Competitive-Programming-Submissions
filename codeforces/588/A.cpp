#include <iostream>

using namespace std;

int main(){
    int n,a,price,p,answer;
    cin >> n >> a >> p;
    answer = a * p;
    price = p;
    for(n;n>1;n--){
        cin >> a >> p;
        if(price < p)answer+=a*price;
        else{
            price = p;
            answer+=a*price;
        }
    }
    cout << answer;
}
