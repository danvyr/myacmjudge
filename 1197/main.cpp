
#include <iostream>

struct cl
{
    int a;
    int b;
    int ans;
};

int main()
{
    int n;
    std::cin >>n;

    char c;
    std::cin.get(c);

    cl *a = new  cl[n];

    int p;

    for ( int i=0;i<n;i++)
    {
        std::cin.get(c);
        switch(c)
        {
        case ('a'):
            a[i].a=1;
            break;
        case ('h'):
            a[i].a=1;
            break;

        case ('b'):
            a[i].a=2;
            break;
        case ('g'):
            a[i].a=2;
            break;

        case ('c'):
            a[i].a=3;
            break;
        case ('f'):
            a[i].a=3;
            break;

        case ('d'):
            a[i].a=4;
            break;
        case ('e'):
            a[i].a=4;
            break;

        }

        std::cin.get(c);
        switch(c)
        {
        case ('1'):
            a[i].b=1;
            break;
        case ('8'):
            a[i].b=1;
            break;

        case ('2'):
            a[i].b=2;
            break;
        case ('7'):
            a[i].b=2;
            break;

        case ('3'):
            a[i].b=3;
            break;
        case ('6'):
            a[i].b=3;
            break;
        case ('4'):
            a[i].b=4;
            break;
        case ('5'):
            a[i].b=4;
            break;
        }

        std::cin.get(c);

        p=a[i].a*a[i].b;

        if (p>8)
            a[i].ans=8;
        else if (p>4)
            a[i].ans=6;
        else if (p>2)
            a[i].ans=4;
        else if (p>1)
            a[i].ans=3;
        else
            a[i].ans=2;


    }
    for ( int i=0;i<n;i++)
        std::cout<<a[i].ans<<std::endl;

    delete []a;

    return 0;

}
