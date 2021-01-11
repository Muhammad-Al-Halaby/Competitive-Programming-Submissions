#include<bits/stdc++.h>

using namespace std;
int main(){
    int p,f,time;
    cin >> p >> f;
    int arr[p][2];
    for(int i=0;i<p;i++){
        cin >> arr[i][0];
        cin >> arr[i][1];
    }
  for(int i = 0;i<p;i++){
      for(int j = 0;j<p;j++){
          if(j+1 < p && arr[j][0] < arr[j+1][0]){
              int x,y;
              x=arr[j+1][0];
              y=arr[j+1][1];
              arr[j+1][0]=arr[j][0];
              arr[j+1][1]=arr[j][1];
              arr[j][0]=x;
              arr[j][1]=y;
          }
      }
  }
  time = 0;
  for(int i = 0;i<p;i++){
      time += f - arr[i][0];
      ((arr[i][1] - time) >= 0) ? time +=arr[i][1]-time:time+=0;
      f = arr[i][0];
  }
  time += f; 
  cout << time;
}