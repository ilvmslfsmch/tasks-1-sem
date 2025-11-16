#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define scanf_s scanf

/**
 * @brief Считывает введённое с клавиатуры целое значение и проверяет на правильность ввода
 * @return введённое значение
 */
int Value(void);

/**
 * @brief Выводит текстовое сообщение о необходимости ввода размера массива, проверяет ввод на правильность, задаёт размер массива
 * @param message текстовое сообщение о необходимости ввода массива
 * @return размер массива (количество его элементов)
 */
size_t getSize(char* message);

/**
 * @brief Считывает значения элементов массива
 * @param arr массив
 * @param size размер массива
 */
void fillArray(int* arr, const size_t size);

/**
 * @brief Выводит массив (его элементы)
 * @param arr массив
 * @param size размер массива
 */
void printArray(int* arr, const size_t size);

/**
 * @brief Заполняет массив случайными числами в пределах введённого пользователем диапазона
 * @param arr массив
 * @param size размер массива
 */
void fillRandom(int* arr, const size_t size);

/**
 * @brief Создаёт копию массива. Все дальнейшие изменения происходят в этом масссиве.
 * @param arr массив
 * @param size размер массива
 * @return полученный массив
 */
int* copyArray(const int* arr, const size_t size);

/**
 * @brief Заменяет первый отрицательный элемент массива на первый положительный
 * @param copyArr массив
 * @param size размер массива
 * @return 0, если положительный или отрицательный элементы отсутствуют, 1 - если замена выполнена успешно
 */
int replaceFirstNegativeFirstPositive(int* copyArr, const size_t size);

/**
 * @brief Удаляет элементы массива, кратные семи и лежащие в диапазоне [min; max]
 * @param copyArr массив
 * @param size размер массива
 * @return Возвращает 0, если неверно задан диапазон/отсутствуют отрицательные элементы/удалён весь массив,
 * 1 - если функция выполнена успешно.
 * @note Фактически функция заменяет все подходящие числа на нули и переставляет их в конец массива (нули также кратны семи).
 * Для перестановки нулей в конец массива используется функция replaceArray.
 * Дальнейшая работа происходит только с ненулевыми элементами.
 * Таким образом, создаётся видимость, что элементы в массиве удалились, ибо элементы массива нельзя удалить.
 * @note также вводится счётчик j, который сделан для определения, есть ли в массиве подходящие элементы и
 * не состоит ли массив целиком из таких элементов (и, как следствие, не удалится ли он полностью).
 */
int deleteDif7BelongsRange(int* copyArr, const size_t size);

/**
 * @brief Перемещает нулевые элементы в конец массива
 * @param copyArr массив
 * @param size размер массива
 * @return изменённый массив
 * @note Создаётся нулевой индекс NoZero. Нулевые элементы изначально не трогаются, затем ненулевые заменяются на
 * нетронутые нулевые по индексу NoZero.
 * После того, как все необходимые элементы заменены, нулевые элементы просто проставляются в конец массива
 * в соответствии с текущим индексом. Надеюсь, благодаря этой ремарке функция и ход моих мыслей станут яснее =)
 * @note P.S. на самом деле, если разобраться, то всё очень понятно и логично, но объясняю я плоховато, плюс те, кто видел,
 * всегда задавали вопросы, потому я решил попробовать объяснить хоть как-то.
 */
int* replaceArray(int* copyArr, const size_t size);

/**
 * @brief заменяет элементы массива по определённым в задании правилам
 * @param copyArr массив
 * @param size размер массива
 * @return 0 - если в новом массиве отсутствуют элементы, 1 - если функция выполнена успешно
 */
int fromDtoA(int* copyArr, const size_t size);

/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введённого пользователем диапазона
 * @brief MANUAL - заполнение массива вручную
 */
enum {RANDOM = 1, MANUAL};

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1.
 */
int main(void)
{
    size_t size = getSize("Input size of an array:\n");
    int* arr = malloc(size* sizeof(int));
    if (arr == NULL)
    {
        fprintf(stderr,"Error");
        exit(1);
    }
    printf("Chose the method of filling the array:\n%d - by random\n%d - manually\n", RANDOM, MANUAL);
    int choice = Value();
    switch(choice)
        {
            case RANDOM:
                fillRandom(arr, size);
                break;
            case MANUAL:
                fillArray(arr, size);
                break;
            default:
                fprintf(stderr,"Error.");
                free(arr);
                exit(1);
        }
    printArray(arr, size);
    int* copyArr = copyArray(arr, size);
    replaceFirstNegativeFirstPositive(copyArr, size);
    printf("\n");
    deleteDif7BelongsRange(copyArr, size);
    printf("\n");
    fromDtoA(copyArr, size);
    printf("\n");
    free(copyArr);
    free(arr);
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
        fprintf(stderr,"Input error");
        exit(1);
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Input %zu element of array:", i);
        arr[i] = Value();
    }
}

void printArray(int* arr, const size_t size)
{
    printf("Your array is:\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void fillRandom(int* arr, const size_t size)
{
    printf("diapozon start:\n");
    int start = Value();
    printf("diapozon end:\n");
    int end = Value();
    if (start > end) {
        fprintf(stderr, "Error: start cannot be greater than end\n");
        exit(1);
    }
    srand(time(NULL));
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (end - start + 1) + start;
    }
}

int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = malloc(sizeof(int)*size);
    if (arr == NULL)
    {
        fprintf(stderr,"Error");
        exit(1);
    }
    for (size_t i = 0; i<size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

int replaceFirstNegativeFirstPositive(int* copyArr, const size_t size) {
    printf("Replacing first negative element to first positive.\n");
    int firstPositive = 0;
    int firstNegative = 0;
    size_t negativeIndex = 0;
    bool checkPositive = false; // булы для проверки на то, нашлось ли положительное/отрицательное число
    bool checkNegative = false; 
    for (size_t i = 0; i < size; i++) {
        if (copyArr[i] < 0 && checkNegative != true) { //если отрицательное нашлось, мы больше ничего с положительными числами не меняем
            firstNegative = copyArr[i];
            checkNegative = true;
            negativeIndex = i;
        }
        if (copyArr[i] > 0 && checkPositive != true) { //аналогично для положительного
            firstPositive = copyArr[i];
            checkPositive = true;
        }
        if (checkPositive == true && checkNegative == true) { //досрочный выход из цикла, если оба числа найдены
            break;
        }
    }
    if (firstPositive == 0) {
        printf("No positive elements.\n");
        return 0;
    }
    if (firstNegative == 0) {
        printf("No negative elements.\n");
        return 0;
    }
    copyArr[negativeIndex] = firstPositive;
    printf("Your new array is:\n");
    for (size_t j = 0; j < size; j++) {
        printf("%d ", copyArr[j]);
    }
    return 1;
}

int deleteDif7BelongsRange(int* copyArr, const size_t size) {
    printf("Deletion all elements which separated by 7 and belongs to range.\n");
    printf("Input min:\n");
    int min = Value();
    printf("Input max:\n");
    int max = Value();
    if (min >= max) {
        printf("max must be more than min.\n");
        return 0;
    }
    int j = 0;
    for (size_t i = 0; i < size; i++) {
        if (copyArr[i] % 7 == 0 && min <= copyArr[i] && copyArr[i] <= max) {
            copyArr[i] = 0;
            j++;
        }
    }
    if (j == 0) {
        printf("There are no such elements you need in this range. Your new array equals old array.\n");
        return 1;
    }
    if (j == size) {
        printf("All of the elements are deleted.\n");
        return 1;
    }
    replaceArray(copyArr, size);
    printf("Your new array is:\n");
    for (size_t k = 0; k < size; k++) {
        if (copyArr[k] != 0) {
            printf("%d ", copyArr[k]);
            }
        }
    return 1;
}

int fromDtoA(int* copyArr, const size_t size) {
    printf("Forming array A:\n");
    int k = 0;
    for (size_t i = 0; i < size; i++) {
        if (copyArr[i] != 0) {
            if (i % 2 == 0) {
                copyArr[i] = copyArr[i] * copyArr[i] + i;
            }
            else {
                copyArr[i] = copyArr[i] * i;
            }
            k++;
        }
        if (k == 0){
            printf("There are no elements in new array.");
            return 0;
        }
    }
    for (size_t j = 0; j < size; j++) {
        if (copyArr[j] != 0) {
            printf("%d ", copyArr[j]);
        }
    }
    return 1;
}

int* replaceArray(int* copyArr, const size_t size) {
    int NoZero = 0;
    for (size_t i = 0; i < size; i++) {
        if (copyArr[i] != 0) {
            copyArr[NoZero] = copyArr[i];
            NoZero++;
        }
    }
    for (size_t j = NoZero; j < size; j++) {
        copyArr[j] = 0;
    }
    return copyArr;
}
