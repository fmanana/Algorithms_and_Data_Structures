//Author: Fezile Manana

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>


#define FIB 25

double fib_recursion(unsigned int n)
{
	unsigned int fib;
	
	if(n == 1)
	{
		return 1;
	}
	else if(n == 0)
	{
		return 0;
	}
	
	fib = fib_recursion(n-1) + fib_recursion(n-2);
		
	return fib;
}

/* Recursive power function for closed
 * form algorithm
 * */
double power_n(double base, double raised)
{
	if( raised != 0)
	{
		return (base*power_n(base, raised - 1));
	}
	else
		return 1;
}
//Closed form Algorithm
double fib_closed_form(unsigned int n)
{
	double phi1, phi2, phi3;
	double fib;
	
	phi1 = (1 + sqrt(5))/2;
	phi2 = (1 - sqrt(5))/2;
	phi3 = ((power_n(phi1, n)) - (power_n(phi2, n)));
	fib = (phi3/sqrt(5));
	
	return fib;
}
/* Creates an array of size n and
 * sums the two previous terms and
 * assigns that value to the current term
 * */
double bottom_up(unsigned int n)
{
	unsigned int i;
	double fib[n];
	
	fib[0] = 0;
	fib[1] = 1;
	
	for(i = 2; i <= n; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	
	return fib[n];
}

//Helper function for matrix exponentiation
void multiply(double F[2][2], double M[2][2])
{
  double x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  double y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  double z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  double w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
//Helper funtion for matrix exponentiation
void power(double F[2][2], double n)
{
  int i;
  double M[2][2] = {{1,1},{1,0}};
 
  // n - 1 times multiply the matrix to {{1,0},{0,1}}
  for (i = 2; i <= n; i++)
      multiply(F, M);
}

double matrix(unsigned int n)
{
  double F[2][2] = {{1,1},{1,0}};
  if (n == 0)
      return 0;
  power(F, n-1);
 
  return F[0][0];
}

int main()
{
	double fib_rec, fib_closed, fib_bu, fib_mat;
	
	//Timing the algorithms
	clock_t rec = clock();
	fib_rec = fib_recursion(FIB);
	clock_t rec2 = clock();
	
	clock_t closed = clock();
	fib_closed = fib_closed_form(FIB);
	clock_t closed2 = clock();
	
	clock_t bu = clock();
	fib_bu = bottom_up(FIB);
	clock_t bu2 = clock();
	
	clock_t mat = clock();
	fib_mat = matrix(FIB);
	clock_t mat2 = clock();
	
	printf("The fibnacci term for recursion:\t\t%lf\n", fib_rec);
	printf("The fibnacci term for closed form:\t\t%lf\n", fib_closed);
	printf("The fibnacci term for bottom up:\t\t%lf\n", fib_bu);
	printf("The fibnacci term for matrix exponentiation:\t%lf\n", fib_mat);
	
	
	printf("\nRun times:\n");
	printf("Recursion: %lf\n", (double)(rec2-rec)/(CLOCKS_PER_SEC));
	printf("Closed Form: %lf\n", (double)(closed2-closed)/(CLOCKS_PER_SEC));
	printf("Bottom Up: %lf\n", (double)(bu2-bu)/(CLOCKS_PER_SEC));
	printf("Matrix: %lf\n", (double)(mat2-mat)/(CLOCKS_PER_SEC));
	
	
	return 0;
}