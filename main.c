#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
	#define OS 0
	#define C() system( "cls" )
#else
	#define OS 1
	#include <unistd.h>
	#define C() system( "clear" )
#endif

void S( clock_t t )
	{
		clock_t end_time;
		end_time = clock() + t * CLOCKS_PER_SEC;
		while( clock() < end_time ) {}
	};

#define P printf
char* e;
char cc[ 50 ];
#define T( c, t )                                                     \
	for( i = c; i--; )                                                  \
		S( 1 ), g &&P( "\r%02d:%02d", i / 60, i % 60 ), fflush( stdout ); \
	P( "\n" );                                                          \
	sprintf( cc, OS ? "./%s %d" : "start %s %d", e, t );                \
	system( cc )

#define A

int main( int _a, char* _s[] )
{
	e = _s[ 0 ];
	if( _a == 2 )
	{
		printf( ( _s[ 1 ][ 0 ] == '1' ) ? ( "/////// END OF POMODORO /////// " ) : ( "/////// END OF BREAK /////// " ) );
		while( getchar() != '\n' ) {};
	}
	else
	{
		char ch;
		int i, g, c = 1;
		P( "\n> Show progress? (y/n) " );
		ch = getchar();
		while( getchar() != '\n' ) {};
		g = ch == 'y' || ch == 'Y';
		for( ;; )
		{
			for( c = 1; c < 5; c++ )
			{
				P( "\n> Press Enter to Start Pomodoro " );
				while( getchar() != '\n' ) {};
				T( 1500, 1 );
				P( "\n> Press Enter to Start Break " );
				while( getchar() != '\n' ) {};
				T( ( c == 4 ) ? 1500 : 300, 2 );
			}
			P( "\n> Press Enter to Restart " );
			while( getchar() != '\n' ) {};
			C();
		}
	}
}
