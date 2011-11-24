#include <iostream>
using namespace std;

int main()
{
    unsigned int n,i;
    cin >>n>>i;

    if (  (n*i-1)%2==0 )
        cout <<"[second]=:]"<<endl;
    else
        cout <<"[:=[first]"<<endl;

    return 0;
}
