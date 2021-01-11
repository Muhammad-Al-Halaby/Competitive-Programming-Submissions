#include <iostream>
using namespace std;

int main()
{
    int x; cin>>x;
    if(x>=1&&x<=100)
    {
        if(x%2==0 && x != 2)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
