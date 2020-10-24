#include <stdio.h>
#include <math.h>

const float eps = 0.000001;
const double eps_comparison = 0.0000000000000001; //Поргрешность выставлена с учетом того, что рассматриваются первые 15 цифр вещественной части

void exp_float(float start) {

    float x1, x2;
    x2 = 10000 * start - 20000;
    float prev_start = start;
    x1 = 2 - x2;
    float len = sqrtf((x1-1) * (x1-1) + (x2-1) * (x2-1));
    while(len > eps) {

        start = (start + 2.0001) / 2.0000;
        if (fabsf(start - prev_start) < eps_comparison) {

            printf("%.15f\n", start - 2);
            fprintf(stdout, "Infinite loop! Aborting experiment...\n");
            return;
        }
        prev_start = start;
        x2 = 10000.00000 * start - 20000;
        x1 = 2 - x2;
        len = sqrtf((x1-1) * (x1-1) + (x2-1) * (x2-1));
        printf("%.15f\n", start - 2);
    }
}

void exp_double(double start) {

    double x1, x2;
    x2 = 10000 * start - 20000;
    double prev_start = start;
    x1 = 2 - x2;
    double len = sqrt((x1-1) * (x1-1) + (x2-1) * (x2-1));
    while(len > eps) {

        start = (start + 2.0001) / 2.0000;
        if (fabs(start - prev_start) < eps_comparison) {

            printf("%.15f\n", start - 2);
            fprintf(stdout, "Infinite loop! Aborting experiment...\n");
            return;
        }
        prev_start = start;
        x2 = 10000.00000 * start - 20000;
        x1 = 2 - x2;
        len = sqrt((x1-1) * (x1-1) + (x2-1) * (x2-1));
        printf("%.15f\n", start - 2);
    }
    printf("Length: %.15f\n", len);
}

int main() {

    printf("%s\n", "Running float experiment...");
    printf("%s %c%c%c %s\n", "Printing difference between 2 and the number after ",'"','=','"'," in the second equation:");
    exp_float((float) 2.0002);
    printf("\n");
    printf("%s\n", "Running double experiment...");
    printf("%s %c%c%c %s\n", "Printing difference between 2 and the number after ",'"','=','"'," in the second equation:");
    exp_double((double) 2.0002);
    return 0;
}
