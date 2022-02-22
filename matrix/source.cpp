#include <cstdio>
#include <iostream>
#include "matrix.hpp"

void matrix2d::ErrorHandler(int error) const
{
    if (error == 0)
    {
        printf("Ошибка копирования матрциы, память на копируемую матрицу не выделена!\n");
    }
    else if (error == 1)
    {
        printf("Ошибка изменения значения элемента IJ! i < 0\n");
    }
    else if (error == 2)
    {
        printf("Ошибка изменения значения элемента IJ! j < 0\n");
    }
    else if (error == 3)
    {
        printf("Ошибка изменения значения элемента IJ! i > кол-ва строк матрицы\n");
    }
    else if (error == 4)
    {
        printf("Ошибка изменения значения элемента IJ! j > кол-ва столбцов матрицы\n");
    }
    else if (error == -1)
    {
        printf("Ошибка получения значения элемента! i < 0\n");
    }
    else if (error == -2)
    {
        printf("Ошибка получения значения элемента! j < 0\n");
    }
    else if (error == -3)
    {
        printf("Ошибка получения значения элемента! i > кол-ва строк матрицы\n");
    }
    else if (error == -4)
    {
        printf("Ошибка получения значения элемента! j > кол-ва столбцов матрицы\n");
    }
}

matrix2d::matrix2d(int _nrows, int _ncolumns)
{
    nrows = _nrows;
    ncolumns = _ncolumns;
    array = new double *[nrows];

    int i, j;
    for(i = 0; i < nrows; i++)
    {
        array[i] = new double[ncolumns];
        for(j = 0; j < ncolumns; j++)
        {
            array[i][j] = 0;
        }
    }
}

matrix2d::matrix2d(const matrix2d& _matrix)
{
    if (_matrix.array != NULL) 
    {
            nrows = _matrix.nrows;
        ncolumns = _matrix.ncolumns;
        array = new double *[nrows];

        int i, j;
        for(i = 0; i < 0; i++)
        {
            array[i] = new double[ncolumns];
            for(j = 0; j < 0; j++)
            {
                array[i][j] = _matrix.array[i][j];
            }
        }
    }
    else 
    {
        ErrorHandler(0);
    }
}

matrix2d::~matrix2d()
{
    int i;
    for (i = 0; i < nrows; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    i = 0;
    nrows = 0;
    ncolumns = 0;
}

void matrix2d::SetIJ(int i, int j, double value)
{
    if ( (i >= 0) && (j >= 0) && (i <= nrows) && (j <= ncolumns) )
    {
        array[i][j] = value;
    }
    else if (i < 0)
    {
        ErrorHandler(1);
    }
    else if (j < 0)
    {
        ErrorHandler(2); 
    }
    else if (i > nrows)
    {
        ErrorHandler(3);
    }
    else if (j > ncolumns)
    {
        ErrorHandler(4);
    }
}

void matrix2d::GetIJ(int i, int j, double& t_ij) const
{
    if ( (i >= 0) && (j >= 0) && (i <= nrows) && (j <= ncolumns) )
    {
        t_ij = array[i][j];
    }
    else if (i < 0)
    {
        ErrorHandler(-1);
    }
    else if (j < 0)
    {
        ErrorHandler(-2); 
    }
    else if (i > nrows)
    {
        ErrorHandler(-3);
    }
    else if (j > ncolumns)
    {
        ErrorHandler(-4);
    }
}

int matrix2d::GetNlines() const
{
    return nrows;
}

int matrix2d::GetNcolumns() const
{
    return ncolumns;
}

void PrintMatrix(const matrix2d& t_m)
{
    int ml, mc, i, j;
    double tmp2;

    ml = t_m.GetNlines();
    mc = t_m.GetNcolumns();

    for (i = 0; i < ml; i++)
    {
        for (j = 0; j < mc; j++)
        {
            t_m.GetIJ(i, j, tmp2);
            printf(" %5.2lf ", tmp2);
        }
        printf("\n");
    }
}

int main()
{
    matrix2d m0(3, 3);
    matrix2d m1(m0);

    int m0l, m0c, i, j;
    double tmp1;

    m0l = m0.GetNlines();
    m0c = m0.GetNcolumns();

    for (i = 0; i < m0l; i++)
    {
        for (j = 0; j < m0c; j++)
        {
            printf("[%d][%d] = ", i, j);
            scanf("%lf", &tmp1);
            m0.SetIJ(i, j, tmp1);
        }
        
    }

    PrintMatrix(m0);

    return 0;
}
