class matrix2d
{
    private:
        int nrows;
        int ncolumns;
        double **array;

        // Обработчик ошибок
        void ErrorHandler(int) const;
    
    public:
        // Конструктор с параметрами
        matrix2d(int, int);

        // Коструктор копирования
        matrix2d(const matrix2d&);

        // Деструктор
        ~matrix2d();

        // Сеттер элемента i-той строки j-того столбца
        void SetIJ(int, int, double);

        // Геттер элемента i-той строки j-того столбца
        void GetIJ(int, int, double&) const;

        // Геттер кол-ва строк
        int GetNlines() const;

        // Геттер кол-ва столбцов
        int GetNcolumns() const;

        friend void PrintMatrix(const matrix2d&);
};