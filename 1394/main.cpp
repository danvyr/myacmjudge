// ships
#include <iostream>
//#include <vector>

/*
class rows
{

      0 начальное кол-во рядов
      1 индекс связывающий начальное кол-во с отсортированным
      2 сортиировнные кол-ва рядов

      3 число караблей в этом ряду
      4 сумма длинн караблей



public:
    int* row, index, irow, numkor, sumkor;
    int **matrix;

    rows(const int m,const int nm)
    {
        int **matrix = new int*[m];
        for (int i = 0; i < m; ++i)
            matrix[i] = new int[nm];

        int *row =new int[m];
        int *index =new int[m];
        int *irow =new int[m];
        int *numkor =new int[m];
        int *sumkor =new int[m];


    }
    ~rows()
    {
        delete []matrix;

    }


};
    */


int main()
{
    int n,m,i;
    std::cin >>n>>m;

    char c;
    std::cin.get(c);

    // массив N

    int **ln = new int*[2];
    for (i = 0; i < 2; i++)
        ln[i] = new int[n];

    // матрица M

    int nm;

    {
        int tempk;
        tempk=n%m;
        nm=(n-tempk)/m+tempk+5;
    }
    int **lm = new int*[m];
    for (i = 0; i < m; ++i)
        lm[i] = new int[nm];

    // M

    // rows *mrow = new rows(m,nm);



    //      Ввод данных   *

    for ( i=0;i<n;i++)
        std::cin >> ln[0][i];

    for ( i=0;i<m;i++)
        //std::cin >> mrow->row[i];
        std::cin >>lm[i][0];
    //      Ввод данных закончен  *


    // вывод полученных   ****


    for ( i=0;i<n;i++)
        std::cout << ln[0][i] <<"   ";
    std::cout << std::endl;

    for ( i=0;i<m;i++)
        //std::cout << mrow->row[i] <<"  ";
        std::cout <<lm[i][0]<<"  ";
    std::cout << std::endl;

    /*
       сортировка матрицы караблей       ************************************
       найти минимальный карабль
       и наверное надо иметь

    */
    bool iter= 0;
    int temp;

    for ( int j=0; j<n; j++)
    {
        for (i=0;i<(n-1);i++)
            if ( ln[0][i] < ln[0][i+1] )
            {
                temp= ln[0][i];
                ln[0][i]= ln[0][i+1];
                ln[0][i+1]= temp;

                iter= 1;
            }

        if ( iter==0 )
            break;
        else
            iter= 0;
    }

    // end сортировака         *******************************




    /*
      0 начальное кол-во рядов
      1 индекс связывающий начальное кол-во с отсортированным
      2 сортиировнные кол-ва рядов

      3 число караблей в этом ряду
      4 сумма длинн караблей


    */

    // сортировка матрицы рядов       ************************************

    for (i=0;i<m;i++)
    {
        lm[i][1]=i;
        lm[i][2]=lm[i][0];
    }

    int tempk;
    iter= 0;

    for ( int j=0; j<m; j++)
    {
        for (i=0;i<(m-1);i++)
            if ( lm[i][2] < lm[i+1][2] )
            {
                temp= lm[i][2];
                tempk=lm[i][1];

                lm[i][2]= lm[i+1][2];
                lm[i][1]= lm[i+1][1];

                lm[i+1][2]= temp;
                lm[i+1][1]= tempk;

                iter= 1;
            }

        if ( iter==0 )
            break;
        else
            iter= 0;
    }
    // конец сортировка матрицы рядов       ************************************

    std::cout << "after" << std::endl;

    for ( i=0;i<n;i++)
        std::cout <<ln[0][i]<<"   ";
    std::cout << std::endl << std::endl;

    for ( i=0;i<m;i++)
        std::cout <<lm[i][0]<<"  ";
    std::cout << std::endl;

    for ( i=0;i<m;i++)
        std::cout <<lm[i][1]<<"  ";
    std::cout << std::endl;

    for ( i=0;i<m;i++)
        std::cout <<lm[i][2]<<"  ";
    std::cout << std::endl;

    std::cout << "nm=  "<<nm<<std::endl;




    int sumkor=0, sumras=0, minkor=ln[0][0];

    for (i=0;i<n;i++)
    {
        sumkor+=ln[0][i];

        if (minkor>ln[0][i])
            minkor=ln[0][i];

        ln[1][i]=-1;
    }

    for (i=0;i<m;i++)
    {
        lm[i][3]=0;
        lm[i][4]=0;
    }

    //    iter= 1;

    /*
      сначало раскидываем большие числа в большие ряды
      учитыая сортировку - это будет просто по порядку.
      Но прежде чем закинуть, проверять сможет ли туда залесть минимальный элемент, или есть ли элемент который может залесть туда

      если не может залесть один элемент идём далее по списку,
      хотя учитывая сортировку это должно появится только на втроой проходке

      ! критерий законченности, сумма капраблей равана сумме распределённых караблей
    */
    /*
      0 начальное кол-во места в ряде

      1 индекс связывающий начальное кол-во с отсортированным
      2 сортиировнные кол-ва места ряде

      3 число караблей в этом ряду
      4 сумма длинн караблей        lm[i][4];
      ln[0][i] - длинна карабля  -   ln[1][i] -
    */
    int j;
    while(sumkor!=sumras)
    {
        //        iter=0;
        sumras=0;

        for (i=0;i<n;i++) // проход по караблям
        {
            for(j=0;j<m;j++)  // проход по рядам
            {
                if (  ( ln[0][i] == lm[j][2] )  &&  ( ln[1][i] == -1)  ) // длинна карабля = длинне ряда
                {
                    ln[1][i]=j;  // паркуем карабль в ряд

                    lm[j][3]+=1;  // добавляем 1 карабль в ряду
                    lm[j][4]+=ln[0][i];  // добавляем сумму караблей в ряду
                    lm[j][ 4 + lm[j][3] ]=ln[0][i];  // закидываем в матрицу карабль


                }

            }
        }

        for (i=0;i<n;i++)
            sumras+=lm[i][4];
    }





    delete []ln;
    delete []lm;

    return 0;
}
