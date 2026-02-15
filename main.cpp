#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


double fraction( double x )
{
	return x - static_cast<double>( static_cast<int>( x ) );
}

int mant( double x )
{
	return static_cast<int>( x );
}

double calcDiff( int t, int n, double goal )
{
	double diff;
	assert( goal != 0. );
	assert( n != 0 );
	double rel = static_cast<double>( t ) / static_cast<double>( n );
	diff = ( rel - goal ) / goal;
	if ( diff < 0 )
	{
		diff = -diff;
	}
	return diff;
}

void showStatus( double number, int t, int n )
{
   double diff = calcDiff( t, n, number );
	printf( "%d / %d = %4.15g (%gppm)\n", t, n, ((double)t)/((double)n), diff*1e6 );
}

void runReal2Frac( double number )
{
	int t0 = 0, t1 = 1;
	int n0 = 1, n1 = 0;
	int t, n;
	int newFac;
	double diff = 0.;
	double x = fraction( number );
	n1 = mant( 1./x );
	x = fraction( 1. / x );
	do
	{
	   showStatus( number, t1+(static_cast<int>(number)*n1), n1 );
		diff = calcDiff( t1, n1, fraction( number ) );
		if ( diff > ( 1. / 4.e9 ) )
		{
		   newFac = mant( 1. / x );
		   t = newFac * t1 + t0;
		   n = newFac * n1 + n0;
		   t0 = t1;
		   t1 = t;
		   n0 = n1;
		   n1 = n;
		   x = fraction( 1. / x );
      }
	} while ( ( x != 0 ) && ( ( 1. / 4e9 ) < diff ) ); // 32bit integer as the largest number.
}


int main( int argc, char *argv[] )
{
   if ( argc == 2 )
   {
		runReal2Frac( atof( argv[1] ) );
	}
	else
	{
		printf( "Missing parameter\nUsage: real2frak <realnumber>\nReturns a fraction with same value as real number\n" );
	}
   return 0;
}

