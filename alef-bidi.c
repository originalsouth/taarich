#ident "$Id: alef-bidi.c,v 1.10 2003-08-02 19:28:05+03 rl Exp $"
/*
 * print Hebrew numerals
 *
 *   Author:
 *       Dr. Zvi Har'El,                             ד"ר צבי הראל
 *       Department of Mathematics,              הפקולטה למתמטיקה
 *       Technion, Israel Institute of Technology, הטכניון - מט"ל
 *       Haifa 32000, Israel.                   חיפה 32000, ישראל
 *       E-Mail: rl@math.technion.ac.il
*/
#include <stdio.h>

void
alef(int n, int i)
{
    static const char *digits[3][9] = {/*LRO‭*/
	{ "א", "ב", "ג", "ד", "ה", "ו", "ז", "ח", "ט" },
	{ "י", "כ", "ל", "מ", "נ", "ס", "ע", "פ", "צ" },
	{ "ק", "ר", "ש", "ת", "תק", "תר", "תש", "תת", "תתק" }
    };
    static const char *special[2] = { "טו", "טז" };
    static const char *geresh = { "׳" };

    if ((n % 100 == 15 || n % 100 == 16) && !(i % 3)) {
	alef (n / 100,  i + 2);
	fputs(special[n % 100 - 15], stdout);
    } else if (n) {
	alef (n / 10, i + 1);
	if (n % 10) fputs(digits[i % 3][n % 10 - 1], stdout);
    }
    if ((i) && !(i % 3)) {
	fputs(geresh, stdout);
    }
}
