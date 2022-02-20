#include <cstdio>
#include <iostream>
#include "matrix.h"

void ErrorHandler(int error)
{
    if (error == -1)
    {
        printf("Ошибка замены элемента, проверьте корректность данных\n");
    }
    else if (error == -2)
    {
        printf("Ошибка получения элемента, проверьте корректность данных\n");
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

matrix2d::~matrix2d()
{
    int i;
    for (i = 0; i < nrows; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}

void matrix2d::SetIJ(int i, int j, double value)
{
    if ( (i >= 0) && (j >= 0) && (i <= nrows) && (j <= ncolumns) )
    {
        array[i][j] = value;
    }
    else
    {
        ErrorHandler(-1);
    }
}

void matrix2d::GetIJ(int i, int j, double& t_ij) const
{
    if ( (i >= 0) && (j >= 0) && (i <= nrows) && (j <= ncolumns) )
    {
        t_ij = array[i][j];
    }
    else
    {
        ErrorHandler(-2);
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

int main()
{
    matrix2d m0(3, 3);
    matrix2d m1(m0);

    m0.SetIJ(-1, -1, 34);

    return 0;
}