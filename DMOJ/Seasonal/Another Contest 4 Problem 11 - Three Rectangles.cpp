bool f (int n) {
    while (!(n & 3)) n /= 4;
    return n % 8 ^ 7;
}