#include <iostream>
using namespace std;

int main()
{
    int n,temp;
    cin >> n;
    if (n >= 1 && n <= 100){
        int siz = n*2;
        int rooms[siz];
        int avilabe=0;
        for(int i=0;i < n*2;i++){

            cin >> temp;
            if (temp >= 0 && temp <= 100){
                if(i % 2 != 0){
                        if(temp >= rooms[i-1] ){
                            rooms[i] = temp;
                        }
                }else if(i % 2 == 0) {
                    rooms[i] = temp;
                }
            }
        }

        if(n % 2 != 0){ siz-=1;}
        for(int i=0;i < siz;i++){
            if (rooms[i]+2 <= rooms[i+1]){
                avilabe++;
            }
            i++;
        }
        cout << avilabe << endl;


    }
}
