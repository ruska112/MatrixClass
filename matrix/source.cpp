#include <iostream>
#include "matrix.hpp"

void matrix2d::ErrorHandler(int error) const
{
    if (error == 1)
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

int main()
{
    matrix2d m0(3, 3);
    matrix2d m1(m0);

    m0.SetIJ(1, 1, 34);

    return 0;
}
