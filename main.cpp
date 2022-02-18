#include <iostream>

class matrix_2d
{
    private:
        std::string name;
        int nlines;
        int ncolumns;
        double **array;
        
    public:
        // Конструктор по умолчанию
        matrix_2d();
        
        // Конструктор с параметрами
        matrix_2d(std::string, int, int);

        // Коструктор копирования с добавлением "_copy" к имени(name) матрицы
        matrix_2d(const matrix_2d&);

        // Деструктор
        ~matrix_2d();

        // Сеттер элемента i-той строки j-того столбца
        void SetIJ(int, int, double);

        // Геттеры
        double GetIJ(int, int);

        void GetFull();
};

matrix_2d::matrix_2d()
{
    nlines = ncolumns = 3;
    name = "E_Matrix";
    array = new double *[nlines];

    int i, j;
    for(i = 0; i < nlines; i++)
    {
        array[i] = new double[ncolumns];
        for(j = 0; j < ncolumns; j++)
        {
            if(i == j)
            {
                array[i][j] = 1;  
            }
            array[i][j] = 0;
        }
    }
}

matrix_2d::matrix_2d(std::string t_name, int t_nlines, int t_ncolumns)
{
    name = t_name;
    nlines = t_nlines;
    ncolumns = t_ncolumns;
    array = new double *[nlines];

    int i, j;
    for(i = 0; i < nlines; i++)
    {
        array[i] = new double[ncolumns];
        for(j = 0; j < ncolumns; j++)
        {
            array[i][j] = 0;
        }
    }
}

matrix_2d::matrix_2d(const matrix_2d& t_matrix)
{
    name = t_matrix.name + "_copy";
    nlines = t_matrix.nlines;
    ncolumns = t_matrix.ncolumns;
    array = new double *[nlines];

    int i, j;
    for(i = 0; i < 0; i++)
    {
        for(j = 0; j < 0; j++)
        {
            array[i][j] = t_matrix.array[i][j];
        }
    }
}

matrix_2d::~matrix_2d()
{
    int i;
    for (i = 0; i < nlines; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}

void matrix_2d::SetIJ(int i, int j, double value)
{
    if ( i >= 0 && j >= 0)
    {
        array[i][j] = value;
    }
    else
    {
        return;
    }
}

double matrix_2d::GetIJ(int i, int j)
{
    if ( i >= 0 && j >= 0)
    {
        return array[i][j];
    }
    else
    {
        return 0x0001;
    }
}

void matrix_2d::GetFull()
{
    if(nlines > 0 && ncolumns > 0)
    {
        int i, j;
        for(i = 0; i < nlines; i++)
        {
            for(j = 0; j < ncolumns; j++)
            {
                printf(" %4.2lf ", array[i][j]);
            }
            printf("\n");
        }
    }
}

int main()
{   
    matrix_2d m0("m0", 3, 3);

    m0.SetIJ(0, 0, 112);
    m0.SetIJ(1, 1, 112);
    m0.SetIJ(2, 2, 112);

    m0.GetFull();

    return 0;
}
