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
    double x;
    double y;
    printf("Insert x and y (format:x y)\n");
    scanf("%lf %lf", &x, &y);
    printf("x + y = %lf\nx - y = %lf\nx * y = %lf\nx / y = %lf\n", sum(x, y), dif(x, y), mult(x, y), sep(x, y));
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
