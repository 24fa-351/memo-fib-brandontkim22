#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long fib_r(unsigned long long n);
unsigned long long memo[100];

// Recursive fib(). Since fibonacci #1 is 0, adjust the other values
// to fit the constraints
unsigned long long r_fib_provider(unsigned long long num) {
   if (num <= 1) {
      return 0;
   } else if (num == 2) {
      return 1;
   }

   // Call the recursive memoization function to see if any value 
   // has already been computed.
   return fib_r(num - 1) + fib_r(num - 2);
}                                   

// Iterative fib(). Same as above, make sure fib(1) is 0. Then adjust
// the other values
unsigned long long i_fib_provider(unsigned long long num) {
   if (num <= 1) {
      return 0;
   } else if (num == 2) {
      return 1;                       
   }

   unsigned long long previous = 0;
   unsigned long long current = 1;
   unsigned long long result = 0;                    

   for (unsigned long long ix = 3; ix <= num; ++ix) {
      result = previous + current;
      previous = current;
      current = result;
   }                                  

   return result;
}                                     

// Recursive memoization function
unsigned long long fib_r(unsigned long long num) {
   if (memo[num] != -1) {
      return memo[num];
   } else if (num <= 1) {
      memo[num] = 0;
      return 0;
   } else if (num == 2) {
      memo[num] = 1;
      return 1;
   }

   memo[num] = r_fib_provider(num - 1) + r_fib_provider(num - 2);

   return memo[num];
}

// Iterative memoization function
unsigned long long fib_i(unsigned long long num) {
   if (memo[num] != -1) {
      return memo[num];
   } else if (num <= 1) {
      memo[num] = 0;
      return 0;
   } else if (num == 2) {
      memo[num] = 1;
      return 1;
   }
   
   memo[num] = i_fib_provider(num);

   return memo[num];
}

// Fill the memoization array with -1's (-1 means not computed yet)
void initialize_memo() {
   for (unsigned long long ix = 0; ix <= 99; ++ix) {
      memo[ix] = -1;
   }
}

int main(int argc, char* argv[]) {
   unsigned long long n_input;
   sscanf(argv[1], "%llu", &n_input);

   char type = argv[2][0];

   unsigned long long result = 0;
   initialize_memo();

   if (type == 'i') {
      result = fib_i(n_input);
   } else if (type == 'r') {
      result = fib_r(n_input);
   } else {
      result = 0;
   }

   printf("%llu", result);

   return 0;
}
