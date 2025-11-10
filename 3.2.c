#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief считывает целое значение с клавиатуры в проверкой ввода
 * @return возвращает считанное значение
 */
int getValue(void);

/**
 * @brief считывает вещественное значение с клавиатуры в проверкой ввода
 * @return возвращает считанное значение
 */
double getDouble(void);

/**
 * @brief рассчитывает сумму n членов последовательности
 * @param n - заданное число членов
 * @return рассчитанное значение
 */
double getSumN(const int n);

/**
 * @brief рассчитывает сумму членов последовательности,
 * с точностью e
 * @param e - заданная точность
 * @return рассчитанное значение
 */
double getSumE(const double e);

/**
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param i текущий индекс
 * @return рассчитанное значение коэффициента
 */
double getRecurent(const int i);

/**
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const double value);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    printf("Insert n:\n");
    int n = getValue();
    checkPositive(n);
    printf("The sum of the %d terms in the sequence is %.6lf\n", n,getSumN(n));
    printf("Insert e:\n");
    double e = getDouble();
    checkPositive(e);
    printf("The summ with the accuracy of %lf is %.6lf\n", e,getSumE(e));
    return 0;
}

int getValue()
{
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1){
        fprintf(stderr, "Input error");
        exit(1);
    }
    return value;
}

double getDouble()
{
    double value = 0;
    double result = scanf("%lf", &value);
    if (result != 1){
        fprintf(stderr, "Input error");
        exit(1);
    }
    return value;
}

double getSumN(const int n)
{
    double current = -1;
    double result = current;
    for (int i = 2; i <= n; i++ )
    {
        current *= getRecurent(i);
        result += current;
    }
    return result;
}

double getRecurent(const int i)
{
    return -1.0 / (i * i);
}

void checkPositive(const double value)
{
    if (value < 0)
    {
        fprintf(stderr, "Input error.");
        exit(1);
    }
}

double getSumE(const double e)
{
    double current = -1;
    double result = 0;
    for (int i = 2; fabs(current) > e; i++)
    {
        result += current;
        current*=getRecurent(i);
    }
    return result;
}
