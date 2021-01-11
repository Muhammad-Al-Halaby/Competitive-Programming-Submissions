#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,start=int(1e6),end=1,count=1,f=1;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        if(i > 0){
            if(arr[i] < arr[i-1] && f){
                count++;
                if(i < start)start = i;
                if(i+1 > end)end = i+1;
            }
            else if(arr[i] < arr[i-1] && !f){
                cout << "no";
                return 0;
            }
            else if(count > 1 && f)f=0;
        }
    }
    if(start == (int)1e6)start = 1;
    sort(arr+(start-1),arr+end);
    for(int i = 0;i<n-1;i++)
        if(arr[i] > arr[i+1]){
            cout << "no";
            return 0;
        }
    cout << "yes" << endl;
    cout << start << " " << end;
}