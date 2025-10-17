#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Считывает значение с клавиатуры с проверкой ввода
 * @return Считанное значение
 */
double getValue();

/**
 * @brief Проверяет, что минимальное значение меньше максимального
 * @param min минимальное значение промежутка
 * @param max максимальное значение промежутка
 */
void checkMinMax(const double min, const double max);

/**
 * @brief Проверяет, что шаг функции больше нуля.
 * @param dx значение шага функции
 */
void checkStep(const double dx);

/**
 * @brief Проверяет, принадлежит ли X области определения функции (x > 0)
 * @param i значение переменной x
 * @return Возвращает 0, если X принадлежит ООФ, 1 - если не принадлежит.
 */
int checkZero(const double i);

/**
 * @brief Рассчитывает значение функции по заданной переменной
 * @param i значение переменной x
 * @return Возвращает значение функции
 */
double func(const double i);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно, 1 - если некорректно.
 */
int main(void) {
    printf("Insert X min:\n");
    double min = getValue();
    printf("Insert X max:\n");
    double max = getValue();
    checkMinMax(min, max);
    printf("Insert step(dx):\n");
    double dx = getValue();
    checkStep(dx);
    for (double i = min; i < max + dx; i += dx) {
        if (checkZero(i) == 1) {
            printf("x = %.3lf. X doesn`t belongs SoFD\n", i);
        }
        else {
            printf("x = %.3lf, y = %.3lf\n", i, func(i));
        }
    }
    return 0;
}

void checkMinMax(const double min, const double max) {
    if (min > max || fabs(min - max) <= DBL_EPSILON) {
        printf("max must be more than min.");
        abort();
    }
}

void checkStep(const double dx) {
    if (dx < DBL_EPSILON) {
        printf("Step must be more than 0");
        abort();
    }
}

double getValue() {
    double value = 0;
    if (!scanf("%lf", &value)) {
        printf("Error.\n");
        abort();
    }
    return value;
}

int checkZero(const double i) {
    if (i < DBL_EPSILON) {
        return 1;
    }
    return 0;
}

double func(const double i) {
    return sin(log(i)) - cos(log(i)) + 2 * log(i);
}
