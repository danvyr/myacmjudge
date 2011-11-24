// обратный корень
#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;



int main()
{
    vector <double> numbers;
    double n;

    while (cin >>n)
        numbers.push_back(sqrt(n));



    cout << fixed<< setprecision(4);
    //  cout <<"n=  "<< n<< "   numbers[0] "<< numbers[0]<< "   numbers[1] "<< numbers[1]<< endl;


    for (int i=numbers.size();i>0;i--)
        cout << numbers[i-1]<< endl;





    return 0;
}
