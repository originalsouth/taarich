#ident "$Id: gauss.c,v 1.10 2003-07-18 13:30:06+03 rl Exp $"
/*
 * March date and day-of-the-week for Passover by K. F. Gauss formula
 *
 *   Author:‭
 *       Dr. Zvi Har'El,                             לארה יבצ ר"ד
 *       Department of Mathematics,              הקיטמתמל הטלוקפה
 *       Technion, Israel Institute of Technology, ל"טמ - ןוינכטה
 *       Haifa 32000, Israel.                   לארשי ,32000 הפיח
 *       E-Mail: rl@math.technion.ac.il
 */
/* Basic constants */
#define T  (33. + 14. / 24.)
#define L  ((1.  + 485. / 1080.) / 24. / 19.)
#define K  ((29. + (12. + 793. / 1080.) / 24. )/ 19.)

/* Derived constants */
#define m0 (T - 10. * K + L + 14.)
#define m1 ((21. + 589. / 1080.) / 24.)	/* 13*19*K mod 1 */
#define m2 ((15. + 204. / 1080.) / 24.)	/* 1 - (12*19*K mod 1) */

int
Gauss(int year, int g, int *day)
{
    int a,b,c,M;
    double m;
    a = (12 * year + 17) % 19;
    b = year % 4;
    m = m0 + K * a +  b / 4. - L * year;
    if (m < 0) m--;
    M = m;
    if (m < 0) m++;
    m -= M;
    switch (c = (M + 3 * year + 5 * b + 5) % 7) {
    case 0:
	if (a <= 11 || m < m1) break;
	c = 1; M++; break;
    case 1:
	if (a <= 6 || m < m2) break;
	c = 3; M += 2; break;
    case 2:
	c = 3; M++; break;
    case 4:
	c = 5; M++; break;
    case 6:
	c = 0; M++; break;
    }
    if (day) *day = c;
    if (g) /* Gregorian Calendar */
	M += (year - 3760) / 100 - (year-3760) / 400 - 2;
    return M;
}
