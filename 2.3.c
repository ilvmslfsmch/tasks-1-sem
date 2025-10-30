#include <stdio.h>
#include <stdlib.h>

/**
 * @brief считает удвоенное произведение введённых с клавиатуры чисел
 * @param x значение параметра x
 * @param y значение параметра y
 * @return возвращает функцию назад
 */
double doubleMult(const double x, const double y);

/**
 * @brief считает полусумму введённых с клавиатуры чисел
 * @param x значение параметра x
 * @param y значение параметра y
 * @return возвращает функцию назад
 */
double halfSumm(const double x, const double y);

/**
 * @brief считывает значение, введённое с клавиатуры, и проверяет корректность ввода.
 * @return возвращает функцию назад, если выполнена корректно, 3 - если некорректно
 */
double getValue();

int main(void) {
    printf("Input x:\n");
    double x = getValue();
    printf("Input y:\n");
    double y = getValue();
    double min = 0;
    double max = 0;
    if (x > y) {
        max = x;
        min = y;
    }
    else {
        max = y;
        min = x;
    }
    printf("Your input data:\nmin = %.2lf\nmax = %.2lf\n", min, max);
    min = halfSumm(x, y);
    max = doubleMult(x, y);
    printf("Your new data is:\nmin = ((x + y) / 2) = %.2lf\nmax = (x * y * 2) = %.2lf\n", min, max);
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

double halfSumm(const double x, const double y) {
    return (x + y) / 2;
}

double doubleMult(const double x, const double y) {
    return x * y * 2;
}
