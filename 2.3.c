#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief считывает вещественное значение с клавиатуры с проверкой ввода
 * @return возвращает считанное значение
 */
double getDouble(void);

/**
 * @brief Проверяет, что минимальное значение меньше максимального
 * @param min минимальное значение промежутка
 * @param max максимальное значение промежутка
 */
void checkMinMax(const double min, const double max);

/**
 * @brief Проверяет, что шаг функции больше нуля.
 * @param step значение шага функции
 */
void checkStep(const double step);

/**
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const double value);

/**
 * @brief Вычисляет косинус от x
 * @param x значение параметра x
 * @return рассчитанное значение
 */
double cosFunc(const double x);

/**
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param i текущий индекс
 * @param x значение параметра x
 * @return рассчитанное значение коэффициента
 */
double getRecurent(const int i, const double x);

/**
 * @brief рассчитывает сумму членов последовательности с точностью e
 * @param e заданная точность
 * @param x значение параметра x
 * @return рассчитанное значение
 */
double getSumE(const double e, const double x);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    printf("Insert min:\n");
    const double min = getDouble();
    printf("Insert max:\n");
    const double max = getDouble();
    checkMinMax(min, max);
    printf("Insert step:\n");
    const double step = getDouble();
    checkStep(step);
    printf("Insert e:\n");
    double e = getDouble();
    checkPositive(e);
    for (double x = min; x < max + step; x += step) {
        printf("x = %.6lf, cos(x) = %.6lf, S = %.6lf\n", x, cosFunc(x), getSumE(e, x));
        }
    return 0;
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

void checkMinMax(const double min, const double max) {
    if (min > max || fabs(min - max) <= DBL_EPSILON) {
        fprintf(stderr, "Max must be more than min.");
        exit(1);
    }
}

void checkStep(const double step) {
    if (step < DBL_EPSILON) {
        fprintf(stderr, "Step must be more than 0");
        exit(1);
    }
}

void checkPositive(const double value)
{
    if (value < 0)
    {
        fprintf(stderr, "Input error.");
        exit(1);
    }
}

double cosFunc(const double x) {
    return cos(x);
}

double getRecurent(const int i, const double x)
{
    return -(x * x)/((2 * i - 1) * (2 * i));
}

double getSumE(const double e, const double x)
{
    double current = 1;
    double result = current;
    for (int i = 1; fabs(current) > e; i++)
    {
        current *= getRecurent(i, x);
        result += current;
    }
    return result;
}
