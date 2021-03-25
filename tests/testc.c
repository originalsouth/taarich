#include <stdio.h>
main() /* test routine for Gauss */
{
	int year,day,date,end,g ;
	while (scanf("%d %d %d",&year,&end,&g) == 3)
	{	for(;year<=end ;year++)
		{	date=Gauss(year,g,&day);
			printf("year=%d, day=%d, date=%d\n",year,day,date);
		}
	}
}
#include "../gauss.c"
