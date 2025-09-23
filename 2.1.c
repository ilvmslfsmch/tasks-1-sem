#include <stdio.h>

/**
 * @brief Рассчитывает функцию sum (сумма x и y) по заданным параметрам
 * @param x значение параметра x
 * @param y значение параметра x
 * @return возвращает функцию назад
 */
double sum(double x, double y);

/**
 * @brief Рассчитывает функцию dif (разность x и y) по заданным параметрам
 * @param x значение параметра x
 * @param y значение параметра x
 * @return возвращает функцию назад
 */

double dif(double x, double y);

/**
 * @brief Рассчитывает функцию mult (произведение x и y) по заданным параметрам
 * @param x значение параметра x
 * @param y значение параметра x
 * @return возвращает функцию назад
 */

double mult(double x, double y);

/**
 * @brief Рассчитывает функцию sep (частное x и y) по заданным параметрам
 * @param x значение параметра x
 * @param y значение параметра x
 * @return возвращает функцию назад
 */

double sep(double x, double y);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно; 1 - если некорректно
 */

int main(void) {
    int a;
    double x;
    double y;
    printf("Insert x and y (format:x y)\n");
    scanf("%lf %lf", &x, &y);
    printf("insert function number which you want to do (1-4):\n1 - sum\n2 - difference\n3 - multiplication\n4 - separation\n");
    scanf("%d", &a);

    if (a == 1) {
        printf("Using sum. Result = %lf\n", sum(x, y));
    }
    else if (a == 2) {
        printf("Using dif. Result = %lf\n", dif(x, y));
    }
    else if (a == 3) {
        printf("Using mult. Result = %lf\n", mult(x, y));
    }
    else if (a == 4) {
        printf("Using sep. Result = %lf\n", sep(x, y));
    }
    else {
        printf("Incorrect choice. Please try again by re-running program.");
    }
    return 0;
}

double sum(double x, double y) {
    return x + y;
}

double dif(double x, double y) {
    return x - y;
}

double mult(double x, double y) {
    return x * y;
}

double sep(double x, double y) {
    return x / y;
}
