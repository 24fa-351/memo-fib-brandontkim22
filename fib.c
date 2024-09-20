#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long int fib_r(unsigned long long int n);
unsigned long long int memo[100];

// Recursive fib(). Since fibonacci #1 is 0, adjust the other values
// to fit the constraints
unsigned long long int r_fib_provider(unsigned long long int n) {
   if (n <= 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }

   // Using recursion, call the recursive memoization function
   // (wrapper) to calculate the current "n" value. This will
   // check to see if any value has already been computed.
   return fib_r(n - 1) + fib_r(n - 2);
}                                   

// Iterative fib(). Same as above, make sure fib(1) is 0. Then adjust
// the other values
unsigned long long int i_fib_provider(unsigned long long int n) {
   if (n <= 1) {
      return 0;
   } else if (n == 2) {
      return 1;                       
   }

   // Set the initial values for the iterative sequence
   unsigned long long int a = 0;
   unsigned long long int b = 1;
   unsigned long long int result = 0;                    

   // Update the result and variables for the next iteration
   for (unsigned long long int i = 3; i <= n; ++i) {
      result = a + b;
      a = b;
      b = result;
   }                                  

   // Return the result
   return result;
}                                     

// Recursive memoization function. First checks to see if the value
// at the index (current number) is in the cache. If it is, return
// the value. Otherwise, call the core recursive function to
// calculate the value and store it in the array.
unsigned long long int fib_r(unsigned long long int n) {
   if (memo[n] != -1) {
      return memo[n];
   } else if (n <= 1) {
      memo[n] = 0;
      return 0;
   } else if (n == 2) {
      memo[n] = 1;
      return 1;
   }

   memo[n] = r_fib_provider(n - 1) + r_fib_provider(n - 2);

   return memo[n];
}

// Iterative memoization function. First checks to see if the value
// at the index (current number) is in the cache. If it is, return
// the value. Otherwise, call the core iterative function to
// calculate the value and store it in the array.
unsigned long long int fib_i(unsigned long long int n) {
   if (memo[n] != -1) {
      return memo[n];
   } else if (n <= 1) {
      memo[n] = 0;
      return 0;
   } else if (n == 2) {
      memo[n] = 1;
      return 1;
   }
   
   memo[n] = i_fib_provider(n);

   return memo[n];
}

// Fill the memoization array with -1's (-1 means not computed yet)
void initialize_memo() {
   for (unsigned long long int i = 0; i <= 99; ++i) {
      memo[i] = -1;
   }
}

int main(int argc, char* argv[]) {
   // Create and store the cmd line integer into a variable
   unsigned long long int n;
   sscanf(argv[1], "%llu", &n);

   // Store the type of method
   char type = argv[2][0];

   unsigned long long int number = 0;
   initialize_memo();

   // If the type of method is iterative, call ifib() (iterative 
   // memo cache), otherwise call rfib() (recursive memo cache).
   // If the type is invalid, set the result to 0.
   if (type == 'i') {
      number = fib_i(n);
   } else if (type == 'r') {
      number = fib_r(n);
   } else {
      number = 0;
   }

   // Print the result
   printf("%llu", number);

   return 0;
}
