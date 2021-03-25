main()
{	int year,count;
	printf("Years with no February mentioned in their Hebrew/Gregorian calendar\n\n");
	for(year=5343;year<7000;year++)
	{	if(year%4!=0||(year+40)%100==0&&(year+40)%400!=0)
		{	if (Gauss(year,1,(int*)0)==45)
			{	printf("%d\t",year);
				if((++count)%10==0)printf("\n");
			}
		}
	}
	printf("\n\n Total %d years listed\n",count);
}
#include "../gauss.c"
