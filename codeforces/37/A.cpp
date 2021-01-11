/**
 * @file <CF37-D2-A.cpp>
 * @author <Muhammad Al-Halaby>
 * @date <25-1-2018>
 *
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,maxheight=1,towers=1,height=1;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++)cin >> arr[i];
    sort(arr,arr+n);
    for(int i = 1;i<n;i++){
        if(arr[i] != arr[i-1])
            towers++,height = 1;
        else height++;
        maxheight = max(maxheight,height);
    }
    cout << maxheight << " " << towers;
}