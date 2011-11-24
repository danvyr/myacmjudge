#include <iostream>
using namespace std;

int main()
{
    unsigned int n,i;
    cin >>n>>i;

    unsigned int k;
    if (n==i)
    {
        if ( (n*2)%i != 0)
        {
            unsigned int temp = (n*2)%i;
            k = (n*2 +(i-temp) )/i;
        }
        else
            k = (n*2)/i;
        k+=1;
    }
    else
    {
        if ( (n*2)%i != 0)
        {
            unsigned int temp = (n*2)%i;
            k = (n*2 +(i-temp) )/i;
        }
        else
            k = (n*2)/i;

    }

    cout <<k<<endl;

    return 0;
}
