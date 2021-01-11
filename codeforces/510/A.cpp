#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int status = 1;
    for(int i = 0;i<n;i++){
            if((i+1) % 2 != 0 && status == 0) status = 1;
            else if((i+1) % 2 != 0 && status == 1) status = 0;

            for(int j = 0;j<m;j++){
                    if((i+1) % 2 != 0){
                        cout << "#";
                    }
                    else{
                            if(status == 0){
                                if(j+1 == m) cout << "#";
                                else cout << ".";
                                continue;
                            }
                            else{
                                if(j == 0) cout << "#";
                                else cout << ".";
                                continue;
                            }
                    }
            }
            cout << endl;
    }
}