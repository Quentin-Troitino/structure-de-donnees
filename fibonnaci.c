
unsigned long long fibo_naive(unsigned int n)
{
    if (n==0 || n==1)
        return n;
    else
        return fibo_naive(n-1) + fibo_naive(n-2)
}

unsigned long long fibo_dynamic(unsigned int n, unsigned long long memo[]) {
   if (memo[n] != ULLONG_MAX) {
        return memo[n];
   }

   if (n<=1) {
        memo[n] = n;
   } else {
        memo[n] = fibo_dynamic(n-1, memo) + fibo_dynamic(n-2, memo);
   }

   return memo[n];
}

int main() {
    unsigned int n;
    clock_t start;
    clock_t end;
    start = clock();
    unsigned long long naive_result = fibo_naive(n);
    //voir photo
    return 0;    
}