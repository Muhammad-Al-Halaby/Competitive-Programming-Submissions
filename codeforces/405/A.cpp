#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int box[n];
    for(int i=0;i<n;i++){
        cin >> box[i];
    }
    int temp=0;
    for(int i=0;i<n;i++){
        if(i + 1 < n && box[i] > box[i+1]){
            temp = box[i]-box[i+1];
            box[i+1] = box[i+1] + temp;
            box[i] = box[i] - temp;
            i=-1;
        }
        else{
            continue;
        }
    }

    for(int i=0;i<n;i++){
        cout << box[i] << " ";
    }
}