#include <stdio.h>
main() /* test routine for Gauss */
{
	int year,date ;
	for(year=5343; ;year++)
	{	date=Gauss(year,1,(int*)0);
		if(date<=-365 || date>= 365) break;
	}
	printf("break at %d, date= %d\n",year,date);
}
#include "../gauss.c"
