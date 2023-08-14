//https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Randomization.html
#include <stdio.h>
#include<time.h>
int isprime(int n)
{
    if(n % 2 == 0 || n == 1)
        return 0;
    for(int i = 3; i*i <= n; i += 2) {
        if(n % i == 0)
            return 0;
    }
    return 1;
}
int randPrime(void)
{
    int r;
    while(!isprime((r = rand())));
        return r;
}

int main(int argc, char **argv)
{
    int i;
    srand(time(0));
    for(i = 0; i < 10; i++) {
        printf("%d\n", randPrime());
    }
    return 0;
}
