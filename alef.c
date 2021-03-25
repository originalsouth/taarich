#ident "$Id: alef.c,v 1.9 2003-07-18 13:29:58+03 rl Exp $"
/*
 * print Hebrew numerals
 *
 *   Author:‭
 *       Dr. Zvi Har'El,                             לארה יבצ ר"ד
 *       Department of Mathematics,              הקיטמתמל הטלוקפה
 *       Technion, Israel Institute of Technology, ל"טמ - ןוינכטה
 *       Haifa 32000, Israel.                   לארשי ,32000 הפיח
 *       E-Mail: rl@math.technion.ac.il
*/
#include <stdio.h>

void
alef(int n)
{
    static char *digits[3][9] = {
	{"א","ב","ג","ד","ה","ו","ז","ח","ט"},
	{"י","כ","ל","מ","נ","ס","ע","פ","צ"},
	{"ק","ר","ש","ת","קת","רת","שת","תת","קתת"}
    };
    static char *special[2] = {"וט","זט"};
    int i = 0;

    while (n) {
	if (i == 3) {
	    i = 0;
	    fputs("'", stdout);
	}
	if (!i && (n%100 == 15 || n%100 == 16)) {
	    fputs(special[n%100 - 15], stdout);
	    n /= 100;
	    i = 2;
	} else {
	    if (n%10) fputs(digits[i][n%10 - 1], stdout);
	    n /= 10;
	    i++;
	}
    }
}
