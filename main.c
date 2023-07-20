#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
	#define OS 0
	#define C() system( "cls" )
#else
	#define OS 1
	#include <unistd.h>
	#define C() system( "clear" )
#endif

#define P printf
char* e;
char cc[ 50 ];
#define T( c, t )                                                                         \
	for( i = c; i--; )                                                                      \
		system( "timeout 1 >nul" ), g &&P( "\r%02d:%02d", i / 60, i % 60 ), fflush( stdout ); \
	P( "\n" );                                                                              \
	sprintf( cc, OS ? "./%s %d" : "start %s %d", e, t );                                    \
	system( cc )

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
