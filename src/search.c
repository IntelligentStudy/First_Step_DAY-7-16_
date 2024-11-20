
#include <math.h>
#include <stdio.h>

#define NMAX 30

int input(int *a, int *n);
int even(int a);
double mean(int *a, int n);
double variance(int *a, int n);
int search(int *a, int n);
double sigm(int *a, int n);
void output(int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a\n");
        return 0;
    }
    output(search(data, n));

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

int even(int a) {
    if (a % 2 == 0)
        return 0;
    else
        return 1;
}

double mean(int *a, int n) {
    double meanp = 0.0;
    for (int *p = a; p - a < n; p++) {
        meanp += (double)*p;
    }
    return meanp / (double)(n);
}

int search(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (even(*p) != 0)
            continue;
        else if (mean(a, n) > *p)
            continue;
        else if (sigm(a, n) < *p)
            continue;
        else if (*p == 0)
            continue;
        return *p;
    }
    return 0;
}

double variance(int *a, int n) {
    double var = 0.0;
    for (int *p = a; p - a < n; p++) {
        var += powl((double)(*p) - mean(a, n), 2.0);
    }
    return var / (double)(n);
}
double sigm(int *a, int n) { return (double)(mean(a, n)) + 3.0 * sqrt(variance(a, n)); }
void output(int n) { printf("%d\n", n); }
