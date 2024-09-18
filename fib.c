#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long int fib_r(unsigned long long int n);
unsigned long long int memo[100];

unsigned long long int r_fib_provider(unsigned long long int n) { // Recursive fib(). Since
   if (n <= 1) {                      // fibonacci #1 is 0, adjust
      return 0;                       // the other values to fit
   } else if (n == 2) {               // the constraints
      return 1;
   }

   return fib_r(n - 1) + fib_r(n - 2);  // Using recursion, find fib(n)
}                                   

unsigned long long int i_fib_provider(unsigned long long int n) { // Iterative fib(). Same as
   if (n <= 1) {                      // above, make sure fib(1)
      return 0;                       // is 0. Then adjust the
   } else if (n == 2) {               // other values
      return 1;                       
   }

   unsigned long long int a = 0;               // Set the initial values for
   unsigned long long int b = 1;               // the iterative sequence
   unsigned long long int result = 0;                    

   for (unsigned long long int i = 3; i <= n; ++i) {
      result = a + b;                 // Update the result and
      a = b;                          // variables for the next
      b = result;                     // iteration
   }                                  

   return result;                     // Return the result.
}                                     

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

void initialize_memo() {
   // fill memoization array with -1's (-1 means not computed yet)
   for (unsigned long long int i = 0; i <= 99; ++i) {
      memo[i] = -1;
   }
}

int main(int argc, char* argv[]) {    // cmd line inputs for main()
   unsigned long long int n;          // Create and store the cmd
   sscanf(argv[1], "%llu", &n);       // line integer into a variable

   char type = argv[2][0];            // Store the type of method

   unsigned long long int number = 0;
   initialize_memo();

   if (type == 'i') {                 // If the type of method is 
      number = fib_i(n);               // iterative, call ifib(),
   } else if (type == 'r') {          // otherwise call rfib().
      number = fib_r(n);
   } else {                           // If the type is invalid,
      number = 0;                     // set number to 0
   }

   printf("%llu", number);            // Print the result

   return 0;
}
