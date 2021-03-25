#ident "$Id: taarich.c,v 1.16 2003-08-27 18:27:59+03 rl Exp $"
/*
 * Find the Hebrew equivalent of a given Gregorian date,
 * of the form day month year.
 *
 * If no parameters are given, the current date is used,
 * with the hebrew date incremented after 18:00 local time.
 *
 * Dates before 15 October 1582 are considered Julean.
 * The year Y B.C. is referred to as -Y+1.
 *
 *   Author:‭
 *       Dr. Zvi Har'El,                             לארה יבצ ר"ד
 *       Department of Mathematics,              הקיטמתמל הטלוקפה
 *       Technion, Israel Institute of Technology, ל"טמ - ןוינכטה
 *       Haifa 32000, Israel.                   לארשי ,32000 הפיח
 *       E-Mail: rl@math.technion.ac.il
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
extern int Gauss(int year, int g,int *day);
extern void alef(int n);

int
main(int argc, char **argv)
{
    int m, y, pesach, kvia, hy, g, hflag;
    long d;
    static char *hebrew[2][12] = {
	{"ןסינ", "ריא", "ןויס", "זומת", "בא", "לולא",
	"ירשת", "ןושח", "ולסכ", "תבט", "טבש", "רדא"},
	{"Nisan", "Iyyar", "Sivan", "Tammuz", "Av", "Elul",
	"Tishri", "Heshvan", "Kislev", "Tevet", "Shevat", "Adar"}
    };
    if (argc > 1 && !strcmp(argv[1], "-h")) {
	hflag = 1;
	argc--;
	argv++;
    } else hflag = 0;
    if (argc == 1) {
	long clock;
	struct tm *tmbuf;
	clock = time(0);
	tmbuf = localtime(&clock);
	d = tmbuf->tm_mday;
	if (tmbuf->tm_hour >= 18) d++;
	m = tmbuf->tm_mon + 1;
	y = tmbuf->tm_year + 1900;
    } else if (argc == 4) {
	char *pd, *pm, *py;
	d = strtol(argv[1], &pd, 10);
	m = strtol(argv[2], &pm, 10);
	y = strtol(argv[3], &py, 10);
	if (*pd || *pm || *py || d <= 0 || d > 31 || m <= 0 || m > 12) {
	    fprintf(stderr, "Usage: %s [-h] [day month year]\n", argv[0]);
	    exit(1);
	}
    } else {
	fprintf(stderr, "Usage: %s [-h] [day month year]\n", argv[0]);
	exit(1);
    }
    g = y > 1582 || (y == 1582 && m > 10) || (y == 1582 && m == 10 && d >= 15);
    if ((m -= 2) <= 0) { /*January or February*/
	m += 12;
	y--;
    }
    d += 7*m/12 + 30*(m - 1); /*day in March*/
    pesach = Gauss(hy = y + 3760, g, 0);
    if (d <= pesach - 15) {/*before 1 Nisan*/
	kvia = pesach;
	d += 365;
	if ((y%4 == 0 && (!g || y%100 != 0)) || (g && y%400 == 0)) d++;
	y--;
	pesach = Gauss(--hy, g, 0);
    } else kvia = Gauss (hy + 1, g, 0);
    d -= pesach - 15; /*day in Nisan*/
    kvia -= pesach - 12; /*length of hebrew year minus 353: 0,1,2,30,31,32*/
    y++;
    if ((y%4 == 0 && (!g || y%100 != 0)) || (g && y%400 == 0)) kvia++;
    for (m = 0; m < 11; m++) {
	int days;
	if (m == 7 && kvia%30 == 2) days = 30; /*Heshvan*/
	else if (m == 8 && kvia%30 == 0) days = 29; /*Kislev*/
	else days = 30 - m%2;
	if (d <= days) break;
	d -= days;
    }
    if (m == 11 && kvia >= 30) { /*Adar*/
	if (d > 30) {
	    hebrew[0][11] = "ב רדא";
	    hebrew[1][11] = "Adar II";
	    d -= 30;
	} else {
	    hebrew[0][11] = "א רדא";
	    hebrew[1][11] = "Adar I";
	}
    }
    if (m >= 6) hy++; /*after Rosh Hashana*/
    if (hflag) {
	alef(hy);
	printf (" %s ", hebrew[0][m]);
	alef(d);
    } else printf("%ld %s %d", d, hebrew[1][m], hy);
	printf("\n");
	exit(0);
}
