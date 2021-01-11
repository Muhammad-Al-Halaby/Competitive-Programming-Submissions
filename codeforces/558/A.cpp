#include <iostream>
#include <algorithm>
#include<vector>
#include<math.h>
#include<iomanip>
#include<utility>
#include<numeric>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n][2];
    int forsum[n];

    for(int i = 0;i<n;i++){
        int x,a;
        cin >> x >> a;
        arr[i][0] = x;
        arr[i][1] = a;
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(j+1 < n  && arr[j][0] > arr[j+1][0]){
                int t1,t2;
                t1 = arr[j][0];
                t2 = arr[j][1];

                arr[j][0] = arr[j+1][0];
                arr[j][1] = arr[j+1][1];

                arr[j+1][0] = t1;
                arr[j+1][1] = t2;
            }
        }
    }
    for(int i = 0;i<n;i++){
        forsum[i] = arr[i][1];
    }

    int pos_plus = -1;
    int pos_minus = -1;

    for(int i = 0;i<n;i++){
        if(arr[i][0] > 0){pos_plus = i;pos_minus = i-1; break;}
    }

    int sum = 0;

    if(pos_minus == -1){
            sum = forsum[0];
    }
    if(pos_plus == -1){
        sum = forsum[n-1];
    }
    else{
        if(n-pos_plus == pos_minus +1){
                sum = accumulate(forsum,forsum+n,0);
        }
        else if(n-pos_plus < pos_minus +1){
                int sum1 = accumulate(forsum+((pos_minus+1)-(n-pos_plus+1)),forsum+pos_minus+1,0);
                int sum2 = accumulate(forsum+pos_plus,forsum+n,0);
                sum = sum1 + sum2;
        }
        else if(pos_minus +1 < n-pos_plus){

                int sum1 = accumulate(forsum,forsum+pos_minus+1,0);
                int sum2 = accumulate(forsum+pos_plus,forsum+(pos_plus+pos_minus+1+1),0);
                sum = sum1 + sum2;
        }
    }
    cout << sum;
}