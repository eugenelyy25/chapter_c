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
