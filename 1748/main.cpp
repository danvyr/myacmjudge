// самое сложное число
/*
исходные данные
5
1
10
100
1000
10000

результат

1 1
6 4
60 12
840 32
7560 64
  */

#include <iostream>
#include <vector>
//#include <math.h>
using namespace std;

struct md
{
    unsigned long long int num;
    unsigned int index;
    unsigned long long int sortnum;
    unsigned int difficult;

};


int main()
{
    //vector <long int> numbers;
    //vector <int> diff;


    unsigned int n;
    register unsigned int i;
    cin >>n;

    md* matrix= new md[n];



    // long int input;

    for (i =0;i<n;i++)
    {
        cin >>matrix[i].num;
        matrix[i].sortnum=matrix[i].num;
        matrix[i].index=i;
        //input;
        //numbers.push_back(input);
    }

//    cout<<endl;
    //сортировка

    bool iter= 0;
    unsigned long long int temp;
    unsigned int tempi;

    // для единицы предрасчёт

    for ( unsigned int j=0; j<n; j++)
    {
        for (i=0;i<(n-1);i++)
            if (  matrix[i].sortnum > matrix[i+1].sortnum )
            {
                temp= matrix[i].sortnum;
                tempi=matrix[i].index;

                matrix[i].sortnum= matrix[i+1].sortnum;
                matrix[i].index=matrix[i+1].index;

                matrix[i+1].sortnum= temp;
                matrix[i+1].index=tempi;

                iter= 1;
            }

        if ( iter==0 )
            break;
        else
            iter= 0;
    }


    unsigned int index=0;
    for (i=0;i<n;i++)
    {
        if (matrix[i].sortnum==1)
        {
            index++;
            matrix[i].difficult=1;
        }

        else if (matrix[i].sortnum==2)
        {
            index++;
            matrix[i].difficult=2;
        }

        else if (matrix[i].sortnum==3)
        {
            index++;
            matrix[i].difficult=2;
            matrix[i].sortnum=2;
        }

        else if (matrix[i].sortnum==4)
        {
            index++;
            matrix[i].difficult=3;
        }

        else if (matrix[i].sortnum==5)
        {
            index++;
            matrix[i].difficult=3;
            matrix[i].sortnum=4;
        }

        else if (matrix[i].sortnum==6)
        {
            index++;
            matrix[i].difficult=4;
        }

        else if (matrix[i].sortnum<12)
        {
            index++;
            matrix[i].difficult=4;
            matrix[i].sortnum=6;

        }
    }


/*
    {/// правельный но долгий алгоритм
        int di=0,max=0;

        di=2;

        long int k,y,max_num=0;

        for(i=3;i<(matrix[n-1].sortnum+1);i++)    // перебор всех чисел до числа
        {
            di=2;
            temp=i%2;
            y=(i-temp)/2+temp+2;

            for(k=2;k<y;k++)  // узнаём на сколько чисел делится число
            {

                if (i%k==0)
                    di+=1;

            }

            if (max<di)
            {
                max=di;
                max_num=i;
            }

            if (  i==matrix[index].sortnum )
            {
                matrix[index].sortnum=max_num;
                matrix[index].difficult=max;
                index++;
            }
        }
    } */
    // вначале пощитать максимум введёных чисел  и далее считать один раз до максимума выделяя самое сложное число для интервала


//    for (i=0;i<n;i++)
//        cout<<matrix[i].num << "  " << matrix[i].index << "   " << matrix[i].sortnum<<"   "<< endl;

//    cout<<" Ввод успешен "<<endl<<endl;


//    cout<<" значения для цикла: "<<endl<<" matrix[n].sortnum+1:   "<< matrix[n-1].sortnum+1<<endl<<endl;

    // добваить на ся и считать до половины +1



    {
        unsigned int di=0,max=0;

        di=4;

        unsigned long long int k,y,max_num=0;

        for(i=7;i<(matrix[n-1].sortnum+1);i++)    // перебор всех чисел до числа
        {
            di=2;
            temp=i%2;
            y=(i-temp)/2+temp+2;

            if(i%6==0)
            {
                di+=1;

                for(k=3;k<y;k++)  // узнаём на сколько чисел делится число
                    if (i%k==0)
                        di+=1;

            }
            if (max<di)
            {
                max=di;
                max_num=i;
            }

            if (  i==matrix[index].sortnum )
            {
                matrix[index].sortnum=max_num;
                matrix[index].difficult=max;
                index++;
            }
        }
    }



//***************

    // найти все одинаковые значение и отработать их тоже?!


//******
//    cout<<"вывод"<<endl;

    // сортировка для правильного вывода
    for (i=0;i<n;i++)
    {
        index=0;
        while (matrix[index].index!=i)
            index++;
        cout<<matrix[index].sortnum<<" "<< matrix[index].difficult<<endl;
    }

    //    for (i=0;i<n;i++)
    //        cout<<matrix[i].num<<" "<< matrix[n].difficult<<endl;


    return 0;
}
