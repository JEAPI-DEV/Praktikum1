#include <stdio.h>
#include <math.h>

/*
 * Walk to where the waters end,
 * Sit and watch the clouds arise
 * - Wang Wei (699-761)
 */

#define kValuesLenght 3

void printTable(const int n) {
    int i, s = 0, q = 0;

    printf("   n  |  n*n  |  s(n) | q(n) \n");
    printf("------+-------+-------+-------\n");

    for (i = 1; i <= n; i++) {
        s += i;
        q += i * i;
        /* %5d => moves in this case 5 chars to the right (should be enough)
         * Expand further if needed
         * https://kuepper.userweb.mwn.de/informatik/printf.pdf
         */
        printf("%5d | %5d | %5d | %5d\n", i, i*i, s, q);
    }
}

int main() {
    double a, b, c, temp;
    int kValues[kValuesLenght] = {1, 3, 6};
    int i;

    a = 1;
    b = 2;
    temp = 0;

    /* Standard calculations limited to two after dot decimal points
     * cuz it did not make sense to print out more than that.
     */
    printf("Standard Calculations: \n");
    c = a+b;
    printf("%.02f + %.02f = %.02f\n", a, b, c);
    c = a-b;
    printf("%.02f - %.02f = %.02f\n", a, b, c);
    c = a*b;
    printf("%.02f * %.02f = %.02f\n", a, b, c);
    c = a/b;
    printf("%.02f / %.02f = %.02f\n", a, b, c);
    printf("\n\n");

    /*
     * a = 10^k + 1/3
     * b = 10^k + 1/7
     * k ∈ {1,3,6}
     *
     * a = 10^k + 1/2
     * b = 10^K + 1/4
     */
    printf("Large Calculations: \n");
    for (i = 0; i < kValuesLenght; i++) {
        /* for "pow" needed to add "target_link_libraries(Praktikum1 m)" to the makefile
         * I miss C# ngl and packet managers
         *
         * https://stackoverflow.com/questions/34625627/how-to-link-to-the-c-math-library-with-cmake
         */
        temp = pow(10, kValues[i]);

        a = temp + 1.0/3;
        b = temp + 1.0/7;

        printf("%f + %s = %f\n", temp, "1/3", a);
        printf("%f + %s = %f\n", temp, "1/7", b);
    }
    printf("\n");

    for (i = 0; i < kValuesLenght; i++) {
        temp = pow(10, kValues[i]);

        a = temp + 1.0/2;
        b = temp + 1.0/4;

        printf("%f + %s = %f\n", temp, "1/2", a);
        printf("%f + %s = %f\n", temp, "1/4", b);
    }
    printf("\n\n");

    /* table function */
    printTable(10);

    return 0;
}