#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long fib_r(unsigned long long number);
unsigned long long memo_cache[100];

// Recursive fib(). Since fibonacci #1 is 0, adjust the other values
// to fit the constraints
unsigned long long r_fib_provider(unsigned long long number)
{
   if (number <= 1)
   {
      return 0;
   }
   else if (number == 2)
   {
      return 1;
   }

   // Call the recursive memoization function to see if any value
   // has already been computed.
   return fib_r(number - 1) + fib_r(number - 2);
}

// Iterative fib(). Same as above, make sure fib(1) is 0. Then adjust
// the other values
unsigned long long i_fib_provider(unsigned long long number)
{
   if (number <= 1)
   {
      return 0;
   }
   else if (number == 2)
   {
      return 1;
   }

   unsigned long long previous = 0;
   unsigned long long current = 1;
   unsigned long long result = 0;

   for (unsigned long long ix = 3; ix <= number; ++ix)
   {
      result = previous + current;
      previous = current;
      current = result;
   }

   return result;
}

// Recursive memoization function
unsigned long long fib_r(unsigned long long number)
{
   if (memo_cache[number] != -1)
   {
      return memo_cache[number];
   }
   else if (number <= 1)
   {
      memo_cache[number] = 0;
      return 0;
   }
   else if (number == 2)
   {
      memo_cache[number] = 1;
      return 1;
   }

   memo_cache[number] = r_fib_provider(number - 1) + r_fib_provider(number - 2);

   return memo_cache[number];
}

// Iterative memoization function
unsigned long long fib_i(unsigned long long number)
{
   if (memo_cache[number] != -1)
   {
      return memo_cache[number];
   }
   else if (number <= 1)
   {
      memo_cache[number] = 0;
      return 0;
   }
   else if (number == 2)
   {
      memo_cache[number] = 1;
      return 1;
   }

   memo_cache[number] = i_fib_provider(number);

   return memo_cache[number];
}

// Fill the memoization array with -1's (-1 means not computed yet)
void initialize_memo_cache()
{
   for (unsigned long long ix = 0; ix <= 99; ++ix)
   {
      memo_cache[ix] = -1;
   }
}

int main(int argc, char *argv[])
{
   if (argc != 3)
   {
      printf("Usage: %s <number> <method>\n", argv[0]);
      return 1;
   }

   unsigned long long n_input;
   sscanf(argv[1], "%llu", &n_input);

   char method_type = argv[2][0];

   unsigned long long result = 0;
   initialize_memo_cache();

   if (method_type == 'i')
   {
      result = fib_i(n_input);
   }
   else if (method_type == 'r')
   {
      result = fib_r(n_input);
   }
   else
   {
      result = 0;
   }

   printf("%llu", result);

   return 0;
}
