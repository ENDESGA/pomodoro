#include <stdio.h>
#ifdef _WIN32
	#include <windows.h>
	#define B Beep( 77, 777 )
	#define S( s ) Sleep( s * 1000 )
	#define C() system( "cls" )
#else
	#include <unistd.h>
	#define B system( "beep -f 77 -l 777 >/dev/null 2>&1 || echo -e '\\007'" )
	#define S( s ) sleep( s )
	#define C() system( "clear" )
#endif

#define P printf

#define T( c )                                                        \
	for( i = c; i--; )                                                  \
		S( 1 ), g &&P( "\r%02d:%02d", i / 60, i % 60 ), fflush( stdout ); \
	P( "\n" );                                                          \
	B

int main()
{
	char ch;
	int i, g, c = 1;
	P( "\n> Show progress? (y/n) " );
	ch = getchar();
	while( getchar() != '\n' ) {};
	g = ch == 'y' || ch == 'Y';
	for(;;)
	{
		for( c = 1; c < 5; c++ )
		{
			P( "\n> Press Enter to Start Pomodoro " );
			while( getchar() != '\n' ) {};
			T( 1500 );
			P( "/////// END OF POMODORO /////// " );
			P( "\n> Press Enter to Start Break " );
			while( getchar() != '\n' ) {};
			T( ( c == 4 ) ? 1500 : 300 );
			P( "/////// END OF BREAK /////// " );
		}
		P( "\n> Press Enter to Restart " );
		while( getchar() != '\n' ) {};
		C();
	}
}