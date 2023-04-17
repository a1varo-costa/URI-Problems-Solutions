#include <iostream>
#include <array>

using mat2 = std::array<std::array<int, 2>, 2>;
using vec2 = std::array<int, 2>;

int last_digit(uint64_t x, int base) {
    return x % base;
}

mat2 matrix_mult(mat2 a, mat2 b, int base = 10) {
    mat2 res;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int sum = 0;
            for (int k = 0; k < 2; k++) {
                sum += a[i][k] * b[k][j];
            }
            res[i][j] = last_digit(sum, base);
        }
    }
    return res;
}

vec2 vec_mult(mat2 a, vec2 b, int base = 10) {
    vec2 res;

    for (int i = 0; i < 2; i++) {
        int sum = 0;
        for (int k = 0; k < 2; k++) {
            sum += a[i][k] * b[k];
        }
        res[i] = last_digit(sum, base);
    }
    return res;
}

mat2 matrix_pow(mat2 mat, uint64_t k, int base = 10) {
    mat2 res = mat;

    
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            res[i][j] = i == j ? 1 : 0;
        }
    }

    if (k == 0) {
        return res;
    } 
    
    if (k == 1) {
        return mat;
    }

    while (k > 0) {
        if (k % 2 == 0) {
            mat = matrix_mult(mat, mat, base);
            k /= 2;
        }
        else {
            res = matrix_mult(res, mat, base);
            k--;
        }
    }

    return res;
}

int fib(uint64_t n, int base) {
    mat2 mat = {1, 1, 
                1, 0};
    vec2 vec = {1, 1};

    mat2 res = matrix_pow(mat, n, base);

    return res[0][1];
}

// calls(n) = 2*fib(n + 1) - 1
int num_calls(uint64_t n, int base) {
    int x = last_digit(2 * fib(n + 1, base), base);
    
    if (x == 0) {
        x = base - 1;
    }
    else {
        x -= 1;
    }
    return last_digit(x, base);
}

int main() {
    uint64_t n;
    int b;
    int c = 1;

    while (true) {
        std::cin >> n >> b;

        if (n == 0 && b == 0) {
            break;
        }

        std::cout << "Case " << c << ": ";
        std::cout << n << " " << b << " " << num_calls(n, b) << "\n";
        c++;
    }

    return 0;
}