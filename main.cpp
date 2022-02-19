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

        // Конструктор матрицы, являющейся суммой двух других матриц
        matrix_2d(const matrix_2d&, const matrix_2d&);

        // Деструктор
        ~matrix_2d();

        // Сеттер элемента i-той строки j-того столбца
        int SetIJ(int, int, double);

        // Геттер элемента i-той строки j-того столбца
        int GetIJ(int, int, double&) const;

        // Геттер кол-ва строк
        int GetNlines() const;

        // Геттер кол-ва столбцов
        int GetNcolumns() const;

        // Вывод всей матрицы
        int PrintFull() const;
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

int matrix_2d::SetIJ(int i, int j, double value)
{
    int result = 1;

    if ( (i >= 0) && (j >= 0) && (i <= nlines) && (j <= ncolumns) )
    {
        array[i][j] = value;

        result = 0;
    }
    
    return result;
}

int matrix_2d::GetIJ(int i, int j, double& t_ij) const
{
    int result = 1;

    if ( (i >= 0) && (j >= 0) && (i <= nlines) && (j <= ncolumns) )
    {
        t_ij = array[i][j];
        result = 0;
    }

    return result;
}

int matrix_2d::GetNlines() const
{
    return nlines;
}

int matrix_2d::GetNcolumns() const
{
    return ncolumns;
}

int matrix_2d::PrintFull() const
{
    int result = 1;

    std::cout << name << std::endl;

    if( (nlines > 0) && (ncolumns > 0) )
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
        printf("\n");

        result = 0;
    }

    return result;
}

matrix_2d::matrix_2d(const matrix_2d& m0, const matrix_2d& m1)
{
    if ( (m0.nlines == m1.nlines) && (m0.ncolumns == m1.ncolumns) )
    {
        name = "sum_" + m0.name + "_" + m1.name;
        nlines = m0.nlines;
        ncolumns = m0.ncolumns;
        array = new double *[nlines];
        
        int i, j;
        double tmp0, tmp1;

        for (i = 0; i < nlines; i++)
        {
            array[i] = new double[ncolumns];
            for (j = 0; j < ncolumns; j++)
            {
                
                m0.GetIJ(i, j, tmp0);
                m1.GetIJ(i, j, tmp1);
                
                array[i][j] = tmp0 + tmp1;
            }
        }
    }
}

int main()
{   
    matrix_2d m0("M_0", 3, 3);
    matrix_2d m1("M_1", 3, 3);
    matrix_2d sum_m0_m1;

    int i, j;
    double tmp;

    for (i = 0; i < m0.GetNlines(); i++)
    {
        for (j = 0; j < m0.GetNcolumns(); j++)
        {
            scanf("%lf", &tmp);
            m0.SetIJ(i, j, tmp);
        }
    }
    m0.PrintFull();

    for (i = 0; i < m1.GetNlines(); i++)
    {
        for (j = 0; j < m1.GetNcolumns(); j++)
        {
            scanf("%lf", &tmp);
            m1.SetIJ(i, j, tmp);
        }
    }
    m1.PrintFull();

    matrix_2d sum(m0, m1);

    sum.PrintFull();

    return 0;
}
