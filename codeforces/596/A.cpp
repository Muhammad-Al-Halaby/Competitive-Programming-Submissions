#include<bits/stdc++.h>

using namespace std;

void calculateArea(int x1,int y1,int x2,int y2,int x3,int y3){
    int area = 0;
    int height = sqrt(((x3-x1)*(x3-x1))+((y3-y1)*(y3-y1)));
    int width  = sqrt(((x3-x2)*(x3-x2))+((y3-y2)*(y3-y2)));
    area = height * width;
    cout << area;
}
int main(){
    int n;
    cin >> n;
    int arr[n][2];
    for(int i = 0;i<n;i++){
        cin >> arr[i][0];
        cin >> arr[i][1];
    }
    if(n == 1)cout << -1;
    else if(n == 2){
        if(arr[0][0] != arr[1][0] && arr[0][1] != arr[1][1]){
            calculateArea(arr[0][0],arr[0][1],arr[1][0],arr[1][1],arr[0][0],arr[1][1]);
        }
        else cout << -1;
    }
       
    else if(n == 3){
        if(arr[0][0] != arr[1][0] && arr[0][1] != arr[1][1]){
            calculateArea(arr[0][0],arr[0][1],arr[1][0],arr[1][1],arr[2][0],arr[2][1]);
        }
        else if(arr[0][0] != arr[2][0] && arr[0][1] != arr[2][1]){
            calculateArea(arr[0][0],arr[0][1],arr[2][0],arr[2][1],arr[1][0],arr[1][1]);
        }
        else if(arr[1][0] != arr[2][0] && arr[1][1] != arr[2][1]){
            calculateArea(arr[1][0],arr[1][1],arr[2][0],arr[2][1],arr[0][0],arr[0][1]);
        }
        else cout << -1;
    }
    else if(n == 4){
        if(arr[0][0] != arr[1][0] && arr[0][1] != arr[1][1]){
            calculateArea(arr[0][0],arr[0][1],arr[1][0],arr[1][1],arr[0][0],arr[1][1]);
        }
        else if(arr[0][0] != arr[2][0] && arr[0][1] != arr[2][1]){
            calculateArea(arr[0][0],arr[0][1],arr[2][0],arr[2][1],arr[0][0],arr[2][1]);
        }
        else if(arr[1][0] != arr[2][0] && arr[1][1] != arr[2][1]){
            calculateArea(arr[1][0],arr[1][1],arr[2][0],arr[2][1],arr[1][0],arr[2][1]);
        }
        else if(arr[0][0] != arr[3][0] && arr[0][1] != arr[3][1]){
            calculateArea(arr[0][0],arr[0][1],arr[3][0],arr[3][1],arr[0][0],arr[3][1]);
        }
        else if(arr[1][0] != arr[3][0] && arr[1][1] != arr[3][1]){
            calculateArea(arr[1][0],arr[1][1],arr[3][0],arr[3][1],arr[1][0],arr[3][1]);
        }
        else if(arr[2][0] != arr[3][0] && arr[2][1] != arr[3][1]){
            calculateArea(arr[2][0],arr[2][1],arr[3][0],arr[3][1],arr[2][0],arr[3][1]);
        }
        else cout << -1;
    }
}