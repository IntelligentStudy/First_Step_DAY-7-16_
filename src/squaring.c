#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a\n");
        return 0;
    }
    squaring(data, n);
    output(data, n);

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

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        (*p) *= (*p);
    }
}
