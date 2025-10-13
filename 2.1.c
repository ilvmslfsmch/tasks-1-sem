#include <float.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief Рассчитывает функцию sum (сумма x и y) по заданным параметрам
 * @param x значение параметра x
 * @param y значение параметра y
 * @return возвращает функцию назад
 */
double getSum(const double x, const double y);

/**
 * @brief Рассчитывает функцию dif (разность x и y) по заданным параметрам
 * @param x значение параметра x
 * @param y значение параметра y
 * @return возвращает функцию назад
 */

double getDif(const double x, const double y);

/**
 * @brief Рассчитывает функцию mult (произведение x и y) по заданным параметрам
 * @param x значение параметра x
 * @param y значение параметра y
 * @return возвращает функцию назад
 */

double getMult(const double x, const double y);

/**
 * @brief Рассчитывает функцию sep (частное x и y) по заданным параметрам
 * @param x значение параметра x
 * @param y значение параметра y
 * @return возвращает функцию назад
 */

double getSep(const double x, const double y);

/**
 * @brief sum - сумма чисел
 * @brief dif - разность чисел
 * @brief mult - произведение чисел
 * @brief sep - частное чисел
 */

enum {sum = 1, dif, mult, sep};

/**
 * @brief считывает значение, введённое с клавиатуры, и проверяет корректность ввода.
 * @return возвращает функцию назад, если выполнена корректно, 3 - если функция экстренно завершена.
 */
double checkValue();

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно; 1 - если некорректно
 */

int main(void) {
    int choice = 0;
    printf("Insert x and y (via Enter):\n");
    double x = checkValue();
    double y = checkValue();
    printf ("insert function number which you want to complete:\n%d - sum (x + y)\n%d - difference (x - y)\n%d - multiplication (x * y)\n%d - separation (x / y)\n", sum, dif, mult, sep);
    scanf("%d", &choice);
    switch (choice) {
        case sum:
            printf("Using sum. Result = %.2lf\n", getSum(x, y));
            break;
        case dif:
            printf("Using dif. Result = %.2lf\n", getDif(x, y));
            break;
        case mult:
            printf("Using mult. Result = %.2lf\n", getMult(x, y));
            break;
        case sep:
            if (fabs(y) < DBL_EPSILON) {
                printf("Y must not be 0.");
            }
            else {
                printf("Using sep. Result = %.2lf\n", getSep(x, y));
            }
            break;
        default:
            printf("Incorrect answer. Restart program and try again.");
            return 1;
    }
    return 0;
}

double getSum(const double x, const double y) {
    return x + y;
}

double getDif(const double x, const double y) {
    return x - y;
}

double getMult(const double x, const double y) {
    return x * y;
}

double getSep(const double x, const double y) {
    return x / y;
}

double checkValue() {
    double value = 0;
    if (!scanf("%lf", &value)) {
        printf("Error.\n");
        abort();
    }
    return value;
}
