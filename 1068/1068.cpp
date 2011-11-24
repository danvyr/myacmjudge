#include <iostream>


int main()
{
   int a,sum=1;
	
			
   std::cin >> a;
	if (a<0)
		for(int i=a;i<1;i++)
			sum+=i;
	else
			for(int i=a;i>1;i--)
			sum+=i;

   std::cout << sum << std::endl;
   return 0;
}
