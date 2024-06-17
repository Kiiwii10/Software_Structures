// 123456789
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

enum { STEP = 2 };

int find_factors(int num);
void handle_factor(int factor, int *num, int *factor_multiple);
long long int mod_power(long long int base, long long int exponent,
                        long long int mod);

/**
 * @brief find all prime factors of a number
 * @param num the number to find factors of
 * @return a multiple of all factors of num
 */
int find_factors(int num){

    if (num == 1){
        return 1;
    }
    int factor_multiple = 1;
    int factor = 2;
    handle_factor(factor, &num, &factor_multiple);
    factor++;
    while(num > 1){
        handle_factor(factor, &num, &factor_multiple);
        factor += 2;
    }
    return factor_multiple;
}

/**
 * @brief handle a factor of a number
 * @param factor the factor to handle
 * @param num the number to handle the factor of
 * @param factor_multiple a multiple of all factors of num
 * 
 */  
void handle_factor(int factor, int *num, int *factor_multiple){
    if (*num % factor == 0){
        *factor_multiple *= factor;
        while(*num % factor == 0){
            *num /= factor;
        }
    }
}

/**
 * @brief calculate base^exponent % mod in steps
 * @param base the base in the exponentiation
 * @param exponent the exponent in the exponentiation
 * @param mod the modulus of the exponentiation
 * @return base^exponent % mod
 */
long long int mod_power(long long int base, long long int exponent,
                        long long int mod) {
    long long int result = 1;
    base %= mod;
    while (exponent > 0) {
        if (exponent % STEP) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= STEP;
    }
    return result;
}

/**
 * @brief Calculate the smallest N for which N^N % A == 0
 * @return Non-zero value in case of an error
 */
int main() {
    long long int a;
    scanf("%lld", &a);
    int n = find_factors(a);
    int i = 2;
    while (mod_power(n, n, a) != 0) {
        n *= i;
        i++;
    }
    printf("%d\n", n);
    return 0;
}