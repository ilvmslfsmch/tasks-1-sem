#include <stdio.h>

/**
 * @brief Рассчитывает, на сколько изменилась температура ложки
 * @param c удельная теплоёмкость ложки (нержавеющей стали)
 * @param Q Количество теплоты, отданное ложкой при остывании
 * @param M Масса ложки (в килограммах)
 * @return возвращает функцию назад
 */
double t(double c, double Q, double M);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно, 1 - если некорректно
 */
int main(void) {
    const double c = 500;
    double m;
    double Q;
    printf("insert m(g) & Q(J)\n");
    scanf("%lf %lf", &m, &Q);
    double M = m * 0.001;
    printf("T = %.2lf\n", t(c, Q, M));
    return 0;
}

double t(double c, double Q, double M) {
    return Q / (c * M);
}
