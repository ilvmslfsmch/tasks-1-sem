#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define scanf_s scanf

/**
 * @return Ввод данных типа int
 * @return Введенное значение
 */
int Value();

/**
 * @brief Выводит текстовое сообщение о необходимости ввода размера массива, проверяет ввод на правильность, задаёт размер массива
 * @param message текстовое сообщение о необходимости ввода массива
 * @return размер массива (количество его элементов)
 */
size_t getSize(char* message);

/**
 * @brief Считывает значения элементов массива
 * @param arr массив
 * @param rows количество строк массива
 * @param columns количество столбцов массива
 */
void fillArray(int** arr, const size_t rows,const size_t columns);

/**
 * @brief Выводит массив на экран
 * @param arr массив
 * @param rows количесство строк массива
 * @param columns количество столбцов массива
 */
void printArray(int** arr, const size_t rows,const size_t columns);

/**
 * @brief Заполняет массив случайными числами в выбранном пользователе диапазоне
 * @param arr массив
 * @param rows количество строк
 * @param columns количество столбцов
 */
void fillRandom(int** arr, const size_t rows,const size_t columns);

/**
 * @brief Создаёт массив по указанным пользователем вводным данным
 * @param rows количество строк
 * @param columns количество столбцов
 * @return полученный массив
 */
int** getArray(const size_t rows, const size_t columns);

/**
 * @brief Освобождает память, выделенную под массив
 * @param arr массив
 * @param rows количество строк
 */
void freeArray(int** arr, const size_t rows);

/**
 * @brief Заменяет минимальный по модулю элемент каждого столбца на противоположный
 * @param copyArr массив
 * @param rows количество строк массива
 * @param columns количство столбцов массива
 */
void replaceMinOpposite(int** copyArr, const size_t rows, const size_t columns);

/**
 * @brief Удаляет все строки массива с максимальным значением
 * @param copyArr массив
 * @param rows количество строк массива
 * @param columns количество столбцов массива
 * @return 0, если были удалены все строки, иначе 1.
 */
int delRowsWithMax(int** copyArr, const size_t rows, const size_t columns);

/**
 * @brief Проверяет, что минимальное значенье меньше максимального
 * @param min минимальное значение
 * @param end максимальное значение
 */
void checkRange(const int min, const int end);

/**
 * @brief Создаёт копию массива для дальнейшей работы с ней
 * @param arr изначальный массив
 * @param rows количество строк
 * @param columns количество столбцов
 * @return копию массива
 */
int** copyArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введённого пользователем диапазона
 * @brief MANUAL - заполнение массива вручную
 */
enum {RANDOM = 1, MANUAL};

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{

    size_t rows = getSize("Input quantity of rows of an array:\n");
    size_t columns = getSize("Input quantity of columns of an array:\n");
    int** arr = getArray(rows,columns);
    printf("Chose the method of filling the array:\n%d - by random\n%d - manually\n", RANDOM, MANUAL);
    int choice = Value();
    switch(choice)
        {
            case RANDOM:
                fillRandom(arr, rows, columns);
                break;
            case MANUAL:
                fillArray(arr, rows, columns);
                break;
            default:
                printf("error");
                freeArray(arr, rows);
                return 1;
        }
    printArray(arr, rows, columns);
    int** copyArr = copyArray(arr, rows, columns);
    printf("Replacing min absolute element in every column:\n");
    replaceMinOpposite(copyArr, rows, columns);
    printArray(copyArr, rows, columns);
    printf("Deleting rows with max elements:\n");
    delRowsWithMax(copyArr, rows, columns);
    freeArray(arr, rows);
    freeArray(copyArr, rows);
    return 0;
}

int Value(void)
    {
        int value = 0;
        int result = scanf("%d", &value);
        if (result != 1){
            fprintf(stderr, "Input error");
            exit(1);
        }
        return value;
    }

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        printf("ERROR");
        abort();
    }
    return (size_t)value;
}

void fillArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j<columns; j++)
        {
            printf("Input a[%zu,%zu] = ", i, j);
            arr[i][j] = Value();
        }
    }
}

void printArray(int** arr, const size_t rows, const size_t columns)
{
    printf("Your array is:\n");
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j=0; j<columns; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fillRandom(int** arr, const size_t rows,const size_t columns)
{
    printf("Input min:\n");
    int min = Value();
    printf("Input max:\n");
    int max = Value();
    checkRange(min, max);
    srand(time(NULL));
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            arr[i][j] = (rand() % (max - min + 1)) + min;
        }
    }
}

int** getArray(const size_t rows, const size_t columns)
{
    int** arr = malloc(rows * sizeof(int*));
    for (size_t i = 0; i<rows; i++ ) {
        arr[i] = malloc(columns * sizeof(int));
        if (arr == NULL)
        {
            fprintf(stderr,"error");
            freeArray(arr, rows);
            exit(1);
        }
    }
    return arr;
}

void freeArray(int** arr, const size_t rows)
{
    for (size_t i = 0; i<rows; i++ )
    {
        free(arr[i]);
    }
    free(arr);
}


void checkRange(const int min, const int max)
{
    if(min > max)
    {
        printf("Error\n");
        exit(1);
    }
}

void replaceMinOpposite(int** copyArr, const size_t rows, const size_t columns) {
    for (size_t j = 0; j < columns; j++) {
        size_t minIndex = 0;
        int minAbs = abs(copyArr[0][j]);
        for (size_t i = 1; i < rows; i++) {
            if (minAbs > abs(copyArr[i][j])) {
                minAbs = abs(copyArr[i][j]);
                minIndex = i;
            }
        }
        copyArr[minIndex][j] = -copyArr[minIndex][j];
    }
}

int** copyArray(int** arr, const size_t rows, const size_t columns) {
    int** copyArr = malloc(rows * sizeof(int*));
    for (size_t i = 0; i<rows; i++ )
    {
        copyArr[i] = malloc(columns * sizeof(int));
    }
    if (copyArr == NULL)
    {
        printf("error");
        freeArray(copyArr, rows);
        exit(1);
    }
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            copyArr[i][j] = arr[i][j];
        }
    }
    return copyArr;
}

int delRowsWithMax(int** copyArr, const size_t rows, const size_t columns) {
    int max = copyArr[0][0];
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            if (copyArr[i][j] > max) {
                max = copyArr[i][j];
            }
        }
    }
    for (size_t i = 0; i < rows; i++) {
        bool containsMax = false;
        for (size_t j = 0; j < columns; j++) {
            if (copyArr[i][j] == max) {
                containsMax = true;
                break;
            }
        }
        if (containsMax == true) {
            for (size_t j = 0; j < columns; j++) {
                copyArr[i][j] = 0;
            }
        }
    }
    bool noChoicedRows = true;
    for (size_t i = 0; i < rows; i++) {
        bool noZeroRow = false;
        for (size_t j = 0; j < columns; j++) {
            if (copyArr[i][j] != 0) {
                noZeroRow = true;
                break;
            }
        }
        if (noZeroRow == true) {
            noChoicedRows = false;
            for (size_t j=0; j<columns; j++)
            {
                printf("%5d", copyArr[i][j]);
            }
            printf("\n");
        }
    }
    if (noChoicedRows == true) {
        printf("All rows were deleted.");
        return 0;
    }
    return 1;
}
