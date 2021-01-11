#include<bits/stdc++.h>
using namespace std ;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n ;

    int arr[n] ;

    for(int i=0 ; i<n ; i++)
    {
        int x;
        cin >> x;

        if(x%2 == 0) arr[i] = x-1 ;
        else arr[i] = x ;
    }

    for(int i=0 ; i<n ; i++)
        cout << arr[i] << " " ;
}