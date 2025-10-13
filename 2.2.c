#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief считывает вещественное значение с клавиатуры и проверяет на правильность ввода
 * @return возвращает считанное значение, если оно введено корректно, 3 - если некорректно
 */
double getValue();

/**
 * @brief рассчитывает функцию 1 по заданным параметрам
 * @param x значение переменной x
 * @return возвращает функцию назад
 */
double func1(const double x);

/**
 * @brief рассчитывает функцию 2 по заданным параметрам
 * @param x значение переменной x
 * @param a значение переменной y
 * @return возвращает функцию назад
 */
double func2(const double x, const double a);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно, 1 - если некорректно.
 */
int main(void) {
    const double a = 1.65;
    printf("Insert x:\n");
    double x = getValue();
    if (x - 1.4 <= DBL_EPSILON) {
        if (fabs(x) < DBL_EPSILON) {
            printf("Idiot. x must not be = 0;");
        }
        else {
            printf("y = %.3lf.", func1(x));
        }
        }
    else {
        printf("y = %.3lf", func2(x,a));
    }
    return 0;
}

double getValue() {
    double value = 0;
    if (!scanf("%lf", &value)) {
        printf("Error.\n");
        abort();
    }
    return value;
}

double func1(const double x) {
    return (M_PI * pow(x, 2)) - (7 / pow(x, 2));
}

double func2(const double x, const double a) {
    return log(x + 7 * sqrt(x + 2));
}
