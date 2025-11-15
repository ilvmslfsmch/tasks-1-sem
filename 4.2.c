#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
 * @brief Создаёт копию массива
 * @param arr массив
 * @param size размер массива
 * @return
 */
int* copyArray(const int* arr, const size_t size);


int replaceFirstNegativeFirstPositive(int* copyArr, const size_t size);


int deleteDif7BelongsRange(int* copyArr, const size_t size);


void fromDtoA(int* copyArr, const size_t size);

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
    deleteDif7BelongsRange(copyArr, size);
    fromDtoA(copyArr, size);
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
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (end - start + 1) + start;
    }
}

int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = malloc(sizeof(int)*size);
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
    bool checkPositive = false;
    bool checkNegative = false;
    for (size_t i = 0; i < size; i++) {
        if (copyArr[i] < 0) {
            firstNegative = copyArr[i];
            checkNegative = true;
            negativeIndex = i;
        }
        if (copyArr[i] > 0) {
            firstPositive = copyArr[i];
            checkPositive = true;
        }
        if (checkPositive == true && checkNegative == true) {
            break;
        }
    }
    if (firstPositive == 0) {
        printf("No positive elements.\n");
        return 0;
    }
    if (firstNegative == 0) {
        printf("No negative elements");
        return 0;
    }
    copyArr[negativeIndex] = firstPositive;
    printf("Your new array is:\n");
    for (size_t j = 0; j < size; j++) {
        printf("%d ", copyArr[j]);
    }
    printf("\n");
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
    for (size_t i = 0; i < size;) {
        if (copyArr[i] % 7 == 0 && min <= copyArr[i] && copyArr[i] <= max && copyArr[i] != 0) {
            if (i + 1 == size) {
                copyArr[i] = 0;
            }
            else {
                for (size_t j = i; j < size - 1; j++) {
                    copyArr[j] = copyArr[j+1];
                }
                copyArr[size] = 0;
            }
        }
        else i++;
    }
    printf("New array:\n");
    for (size_t j = 0; j < size; j++) {
        printf("%d ", copyArr[j]);
    }
    printf("\n");
    return 1;
}

void fromDtoA(int* copyArr, const size_t size) {
    printf("Forming array A:\n");
    for (size_t i = 0; i < size; i++) {
        if (copyArr[i] != 0) {
            if (i % 2 == 0) {
                copyArr[i] = copyArr[i] * copyArr[i] + i;
            }
            else {
                copyArr[i] = copyArr[i] * i;
            }
        }
    }
    for (size_t j = 0; j < size; j++) {
        printf("%d ", copyArr[j]);
    }
    printf("\n");
}

/*    for (size_t i = 0; i < size;) {
if (copyArr[i] % 7 == 0 && min <= copyArr[i] && copyArr[i] <= max && copyArr[i] != 0) {
    if (i + 1 == size) {
        copyArr[i] = 0;
    }
    else {
        for (size_t j = i; j < size - 1; j++) {
            copyArr[j] = copyArr[j+1];
        }
        copyArr[size] = 0;
    }
}
else i++;
    }
printf("New array:\n");
for (size_t j = 0; j < size; j++) {
    printf("%d ", copyArr[j]);
}
printf("\n");
return 1;
}
*/
