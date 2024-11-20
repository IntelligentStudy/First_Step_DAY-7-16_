#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a\n");
        return 0;
    }
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    return 0;
}

int input(int *a, int *n) {
    char k;
    if (scanf("%d%c", n, &k) != 2 || (k != '\n' && k != ' ') || (*n <= 0 || *n > NMAX)) return 1;
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d%c", p, &k) != 2 || (k != '\n' && k != ' ')) return 1;
    }
    return 0;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p - a == n - 1)
            printf("%d\n", *p);
        else
            printf("%d ", *p);
    }
}

int max(int *a, int n) {
    int max = *a;
    for (int *p = a; p - a < n; p++) {
        if (max < *p) max = *p;
    }
    return max;
}

int min(int *a, int n) {
    int min = *a;
    for (int *p = a; p - a < n; p++) {
        if (min > *p) min = *p;
    }
    return min;
}

double mean(int *a, int n) {
    double meanp = 0.0;
    for (int *p = a; p - a < n; p++) {
        meanp += (double)*p;
    }
    return meanp / (double)(n);
}

double variance(int *a, int n) {
    double var = 0.0;
    for (int *p = a; p - a < n; p++) {
        var += powl(*p - mean(a, n), 2.0);
    }
    return var / (double)(n);
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf\n", max_v, min_v, mean_v, variance_v);
}
