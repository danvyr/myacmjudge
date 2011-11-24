#include <iostream>

int main()
{
    unsigned int n;

    std::cin >>n;

    if (n>999)
        std::cout<<"legion"<<std::endl;
    else if (n>499)
        std::cout<<"zounds"<<std::endl;
    else if (n>249)
        std::cout<<"swarm"<<std::endl;
    else if (n>99)
        std::cout<<"throng"<<std::endl;
    else if (n>49)
        std::cout<<"horde"<<std::endl;
    else if (n>19)
        std::cout<<"lots"<<std::endl;
    else if (n>9)
        std::cout<<"pack"<<std::endl;
    else if (n>4)
        std::cout<<"several"<<std::endl;
    else
        std::cout<<"few"<<std::endl;

    return 0;
}


