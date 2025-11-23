#include <stdio.h>
#include <math.h>

/**
 * @brief Рассчитывает функцию А по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return возвращает функцию назад
 */
double a(const double x, const double y, const double z);

/**
 * @brief Рассчитывает функцию B по заданной формуле
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return возвращает функцию назад
 */
double b(const double x, const double y, const double z);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main(void) {
    const double x = -0.5;
    const double y = 1.7;
    const double z = 0.44;
    printf("\nx = %.1lf\ny = %.1lf\nz = %.2lf\n", x, y, z);
    printf("a = %lf\nb = %lf\n", a(x, y, z), b(x, y, z));
    return 0;
}

double a(const double x, const double y, const double z) {
    return exp(-y * z) * sin(x * z-y) - sqrt(fabs(y * z + x));
}

double b(const double x, const double y, const double z) {
    return y * sin(a(x,y,z) * pow(z, 2) * cos(2 * z)) - 1;
}
