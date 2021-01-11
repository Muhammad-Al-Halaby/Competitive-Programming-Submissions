#include <iostream>

using namespace std;

int main(){
    int n,p1,p2,p3,t1,t2,amount=0,l[100],r[100];
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    for(int i =0;i < n;i++){
        cin >> l[i] >> r[i];
        if(i > 0){
            if(l[i] - r[i-1] != 0){
                    int sub=0;

                    if(l[i] - r[i-1] < t1)amount += (l[i] - r[i-1]) * p1;
                    else amount += t1 * p1;

                    if(l[i] - r[i-1] - t1 > 0){

                        if(l[i] - r[i-1] - t1 < t2){
                                amount += (l[i] - r[i-1] - t1) * p2;
                        }
                        else {
                                amount += t2 * p2;
                                sub = (l[i] - r[i-1]) - (t1+t2);
                        }
                    }
                    if(sub > 0) amount += sub * p3;
            }
            amount += (r[i] - l[i]) * p1;
        }
        else    amount += (r[i] - l[i]) * p1;
    }
    cout << amount;
}