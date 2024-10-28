#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int bin_it(int k, const int *a, int l, int r);
int bin_rec(int k, const int *a, int l, int r);
int interp(int k, const int *a, int l, int r);
int* parse_args(int argc, char* argv[], int* n, int* srch);

int main(int argc, char* argv[])
{
    int i, n, srch;
    int* a;
    int (*p[3])(int k, const int *a, int l, int r) = {bin_it, bin_rec, interp};

    a = parse_args(argc, argv, &n, &srch);

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        a[i] = 2 * i;
    }
    
    for (i = 0; i < 5000000; i++) {
        assert((*p[srch])(a[rand() % n], a, 0, n - 1) >= 0);
    }

    free(a);
    return 0;
}

int bin_it(int k, const int* a, int l, int r)
{
    while (l <= r) {
        int m = (l + r) / 2;
        if (k == a[m]) {
            return m;
        }
        else {
            if (k > a[m]) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
    }
    return -1;
}

int bin_rec(int k, const int* a, int l, int r)
{
    if (l > r) {
        return -1;
    }
    int m = (l + r) / 2;
    if (k == a[m]) {
        return m;
    }
    else {
        if (k > a[m]) {
            return bin_rec(k, a, m + 1, r);
        }
        else {
            return bin_rec(k, a, l, m - 1);
        }
    }
}

int interp(int k, const int* a, int l, int r)
{
    int m;
    double md;
    while (l <= r) {
        md = ((double)(k - a[l]) /
              (double)(a[r] - a[l]) *
              (double)(r - l)) + (double)(l);
        m = 0.5 + md;

        if ((m > r) || (m < l)) {
            return -1;
        }
        if (k == a[m]) {
            return m;
        }
        else {
            if (k > a[m]) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
    }
    return -1;  // Return -1 if the key is not found
}