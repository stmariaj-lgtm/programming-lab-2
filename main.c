#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#ifdef _MSC_VER
#include <windows.h>
#endif

static void print_result(int number, double value)
{
    if (isfinite(value))
        printf("Вираз №%d = %.4f\n", number, value);
    else
        printf("Вираз №%d: результат поза числовим діапазоном.\n", number);
}

int main(void)
{
    double x, a, b, c;
#ifdef _MSC_VER
    SetConsoleOutputCP(CP_UTF8);
#endif
    printf("Введіть x, a, b, c через пробіл: ");
    if (scanf("%lf %lf %lf %lf", &x, &a, &b, &c) != 4 ||
        !isfinite(x) || !isfinite(a) || !isfinite(b) || !isfinite(c)) {
        puts("Потрібні чотири скінченні числа.");
        return 1;
    }

    double radicand = (a * x + b) * x + c;
    if (radicand > 0 && isfinite(radicand))
        print_result(42, 1 / sqrt(radicand));
    else
        puts("Вираз №42: потрібне додатне скінченне значення під коренем.");

    if (a == 0 || fabs(cos(a)) < 1e-15)
        puts("Вираз №49: ділення на нуль або невизначений тангенс.");
    else
        print_result(49, tan(a) / a * cos(2 * x));

    double cosine = fabs(cos(x));
    if (x == 0 || cosine < 1e-15)
        puts("Вираз №8: логарифм або частка не визначені.");
    else if (fabs(x) < 1e-5)
        print_result(8, -0.5);  // Для таких x відмінність від -0.5 менша за точність виводу.
    else {
        double numerator = log(cosine);
        double denominator = fabs(x) > 1e150 ? 2 * log(fabs(x)) : log1p(x * x);
        print_result(8, numerator / denominator);
    }

    if (x == -1)
        puts("Вираз №45: знаменник дорівнює нулю.");
    else
        print_result(45, fabs(x) / fabs(x + 1));

    if (a == 0 || b == 0)
        puts("Вираз №46: a і b мають бути ненульовими.");
    else if (a < 0 && fmod(fabs(b), 2) != 1)
        puts("Вираз №46: для від’ємного a показник кореня має бути непарним цілим.");
    else {
        double root = pow(fabs(a), 1 / b);
        if (a < 0) root = -root;
        print_result(46, b * (root / a));
    }
    return 0;
}
