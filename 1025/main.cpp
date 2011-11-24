
struct gr
{
    unsigned int gro;
    unsigned int gromin;


};

#include <iostream>
using namespace std;

int main()
{

    unsigned int n,i;
    cin >>n;

    gr*  group= new gr[n];

    for (i =0;i<n;i++)
    {
        cin >>group[i].gro;

    }

    bool iter= 0;
    unsigned int temp,j;

    for (i =0;i<n;i++)
    {
        for (j=0;j<(n-1);j++)
        {
            if (group[j].gro>group[j+1].gro)
            {
                temp=group[j].gro;
                group[j].gro=group[j+1].gro;
                group[j+1].gro=temp;
            }
            iter =1;
        }

        if ( iter==0 )
            break;
        else
            iter= 0;
    }

    for (i=0;i<n;i++)
        group[i].gromin= (group[i].gro+1)/2;


    temp=n%2;
    unsigned int half=(n-temp)/2+temp;

    temp=0;

    for (i=0;i<half;i++)
        temp+=group[i].gromin;

          cout <<temp<<endl;

    return 0;
}
