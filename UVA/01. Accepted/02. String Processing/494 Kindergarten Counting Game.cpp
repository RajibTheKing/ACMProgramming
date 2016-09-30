#include  <stdio.h>
#include  <ctype.h>
#include  <string.h>

int main ()
{
	long word, letter, i, len ;
	char line[100000] ;

    //freopen ( "kinder.txt", "r", stdin ) ;

	while ( gets(line) )
	{
		len = strlen ( line ) ;

		for ( i = 0, letter = 0, word = 0; i < len; i++ )
		{
			if ( isalpha ( line[i] ) )
			{
				letter++ ;
				if ( i + 1 < len )
					continue ;
			}
			if ( letter > 0 )
			{
				word++ ;
				letter = 0 ;
			}
		}
		printf ( "%ld\n", word ) ;
	}
	return 0;
}

