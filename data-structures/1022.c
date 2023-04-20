#include <stdio.h>
#include <stdlib.h>

typedef struct _Rational {
    int numerator;
    int denominator;
} Rational;

int sign(int x) {
    return x < 0 ? -1 : 1;
}

void simplify_sign(Rational *a) {
    int n = a->numerator;
    int d = a->denominator;


    if (sign(n) != sign(d)) {
        a->numerator = -1 * abs(n);
        a->denominator = abs(d);
    }
    else if (sign(n) == sign(d) && sign(n) < 0) {
        a->numerator = abs(n);
        a->denominator = abs(d);
    }
}

Rational sum(Rational a, Rational b) {
    // (N1*D2 + N2*D1) / (D1*D2)
    Rational res;
    res.numerator = a.numerator * b.denominator + a.denominator * b.numerator;
    res.denominator = a.denominator * b.denominator;

    simplify_sign(&res);
    return res;
}

Rational mult(Rational a, Rational b) {
    // (N1*N2) / (D1*D2)
    Rational res;
    res.numerator = a.numerator * b.numerator;
    res.denominator = a.denominator * b.denominator;

    simplify_sign(&res);
    return res;
}

Rational divide(Rational a, Rational b) {
    // (N1*D2)/(N2*D1)
    Rational res;
    res.numerator = a.numerator * b.denominator;
    res.denominator = a.denominator * b.numerator;

    simplify_sign(&res);
    return res;
}

int gcd(int a, int b) {
    int res;

    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    if (a == 0) {
        return b;
    }
    else {
        return gcd(a, b % a);
    }
}

Rational simplify(Rational a) {
    Rational res;
    int s = 1;

    if (sign(a.numerator) != sign(a.denominator)) {
        s = -1;
    }

    int n = abs(a.numerator);
    int d = abs(a.denominator);

    int g = gcd(n, d);

    res.numerator = s * (n / g);
    res.denominator = (d / g);

    return res;
}


int main() {
    int n;

    scanf("%d", &n);

    for ( ; n > 0; n--) {
        Rational a, b;
        Rational res_full, res_simple;

        char op;

        scanf(" %d / %d %c %d / %d", &a.numerator, &a.denominator, &op, &b.numerator, &b.denominator);

        switch (op) {
            case '+':
                res_full = sum(a, b);
                break;
            case '-':
                b.numerator *= -1;
                res_full = sum(a, b);
                break;
            case '*':
                res_full = mult(a, b);
                break;
            case '/':
                res_full = divide(a, b);
                break;
        }

        res_simple = simplify(res_full);

        printf("%d/%d = %d/%d\n", res_full.numerator, res_full.denominator, res_simple.numerator, res_simple.denominator);
    }

    return 0;
}
