#include <iostream>
#include<math.h>

using namespace std;

int main(){
    int n,x;
    cin >> n;
    int n_1=0,n_2=0,n_3=0,n_4=0;
    double r_1=0,r_2=0;int r_3=0,r_4=0;
    int nTaxi = 0;
    for(int i = 0;i<n;i++){
        cin >> x;
        if(x == 1) n_1++;
        if(x == 2) n_2++;
        if(x == 3) n_3++;
        if(x == 4) n_4++;
    }

    if(n_3 >= n_1){
        nTaxi += n_3;
        r_1 = 0;
    }
    else if(n_3 < n_1){
        nTaxi += n_3;
        r_1 = n_1-n_3;
    }

    if(int(r_1) % 4 == 0){nTaxi += r_1/4;r_1 = 0;}

    else{
        nTaxi += r_1/4;
        r_1 = int(r_1) % 4;
    }

    if(n_2 % 2 == 0) nTaxi += n_2/2;

    else{
        nTaxi += n_2/2;
        r_2 = n_2 % 2;
    }



    nTaxi += n_4;

    if(r_1 > 0 && r_2 > 0){
            nTaxi += ceil((r_1 + r_2*2) / 4);
    }
    else if(r_1 > 0 && r_2 == 0){
            nTaxi += ceil(r_1/4);
    }

    else if(r_1 == 0 && r_2 > 0){
        nTaxi += ceil(r_2/2);
    }
    cout << nTaxi << endl;

}