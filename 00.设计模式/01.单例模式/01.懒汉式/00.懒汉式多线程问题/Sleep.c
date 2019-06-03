#include "Sleep.h"

void sleep( time_t delay )
{
time_t timer0, timer1;
time( &timer0 );
do {
time( &timer1 );
} while (( timer1 - timer0 ) < delay );
} 