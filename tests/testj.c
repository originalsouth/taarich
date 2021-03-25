#include <stdio.h>
main() /* test routine for Gauss */
{
	int year,date ;
	for(year=1; ;year++)
	{	date=Gauss(year,0,(int*)0);
		if(date<=-10 || date>= 83) break;
	}
	printf("break at %d, date= %d\n",year,date);
}
#include "../gauss.c"
