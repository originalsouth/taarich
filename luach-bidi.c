#ident "$Id: luach-bidi.c,v 1.134 2005-11-03 15:42:21+02 rl Exp $"
/*
 * Hebrew - Gregorian Calendar (HTML)
 *
 * Author:
 *      Dr. Zvi Har'El,                             ד"ר צבי הראל
 *      Department of Mathematics,              הפקולטה למתמטיקה
 *      Technion, Israel Institute of Technology, הטכניון - מט"ל
 *      Haifa 32000, Israel.                   חיפה 32000, ישראל
 *      E-Mail: rl@math.technion.ac.il
 *
 */
#include <stdlib.h>
#include <stdio.h>
extern int Gauss(int year, int g,int *day);
extern void alef(int n, int i);
extern void holidays(int month, int length, int head, int dflag, int hflag,
	int year);
extern void reading(int month, int length, int head, int leap, int dflag,
	int hflag);

int
main(int argc, const char **argv)
{
    int year,	/* Hebrew year (A.M.) */
	g,	/* Gregorian flag */
	kvia,	/* excess of length of the Hebrew year over 353 */
	Wd,	/* day in the week (mod. 7) */
	Hm,	/* month in the Hebrew year (0:12) */
	Gm,	/* month in the Gregorian year (0:11) */
	Hl,	/* length of Hebrew month Hm */
	Gl,	/* length of Gregorian month Gm */
	Hd,	/* day in the Hebrew month (1:Hl) */
	Gd,	/* day in the Gregorian month (1:Gl) */
	skip,	/* empty cells to skip */
	table = 0,  /* tabe number */
	dflag = 0,  /* Israel/Diaspora style */
	hflag = 0,  /* English/Hebrew printout */
	jflag = 0;  /* Gregorian/Julian calendar */
    const char *p;
    static char *Hmonth[13][2] = {
	{ "Tishri",  "תשרי" },
	{ "Heshvan", "חשון" },
	{ "Kislev",  "כסלו" },
	{ "Tevet",    "טבת" },
	{ "Shevat",   "שבט" },
	{ "Adar I", "אדר א" },
	{ "",            "" },
	{ "Nisan",   "ניסן" },
	{ "Iyyar",    "איר" },
	{ "Sivan",   "סיון" },
	{ "Tammuz",  "תמוז" },
	{ "Av",        "אב" },
	{ "Elul",     "אלול"}
    };
    static int Hlen[13] = {
	30, 0, 0, 29, 30, 30, 29, 30, 29, 30, 29, 30, 29
    };
    static const char *Gmonth[13][2] = {
	{ "January",    "ינואר" },
	{ "February",  "פברואר" },
	{ "March",        "מרס" },
	{ "April",      "אפריל" },
	{ "May",          "מאי" },
	{ "June",        "יוני" },
	{ "July",        "יולי" },
	{ "August",    "אוגוסט" },
	{ "September", "ספטמבר" },
	{ "October",  "אוקטובר" },
	{ "November",  "נובמבר" },
	{ "December",  "דצמבר" },
	{ "January",    "ינואר" }
    };
    static const char *Gabbrev[13][2] = {
	{ "Jan",  "ינו" },
	{ "Feb",  "פבר" },
	{ "Mar",  "מרס" },
	{ "Apr",  "אפר" },
	{ "May",  "מאי" },
	{ "Jun", "יוני" },
	{ "Jul", "יולי" },
	{ "Aug",  "אוג" },
	{ "Sep",  "ספט" },
	{ "Oct",  "אוק" },
	{ "Nov",  "נוב" },
	{ "Dec",  "דצמ" },
	{ "Jan",  "ינו" }
    };
    static int Glen[13] = {
	31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31
    };
    while (--argc > 0) {
	if (*(p = *++argv) == '-') {
	    while (*++p) switch(*p) {
	    case 'e':	/* English printout */
		hflag = 0;
		break;
	    case 'h':	/* Hebrew printout */
		hflag = 1;
		break;
	    case 'i':	/* reading Israel style */
		dflag = 0;
	    break;
	    case 'd':	/* reading Diaspora style, second holidays */
		dflag = 1;
		break;
	    case 'g': /* Gregorian calendar */
		jflag = 0;
		break;
	    case 'j':	/* Julian Calendar */
		jflag = 1;
		break;
	    default:
		fprintf(stderr,"illegal option: %s\n", *argv);
		exit(1);
	    }
	} else if ((year = atoi(*argv))) {
	    printf("<H1>");
	    if (hflag) {
		printf("לוח לשנת ");
		alef (year, 0);
	    } else {
		printf("Calendar for %d", year);
	    }
	    printf("</H1>\n");
	    g = !jflag && year >= 5343;
	    Gd = Gauss(year - 1, g, &Wd);
	    kvia = Gauss(year, g, NULL) - Gd + 12;
	    year -= 3760;
	    printf("<H2>");
	    if (hflag) {
		printf("שנים %sיניות %d-%d", g ? "גרגור" : "יול", year - 1,
			year);
	    } else {
		printf("%sian years %d-%d", g ? "Gregor" : "Jul", year - 1,
			year);
	    }
	    printf("</H2>\n");
	    printf("<H3>");
	    if (hflag) {
		printf("שבתות ומועדים נוסח %s", dflag ? "הגולה" : "ישראל");
	    } else {
		printf("Saturdays and Holidays %s Style", dflag ? "Diaspora" :
			"Israel");
	    }
	    printf("</H3>\n");
	    printf("<TABLE ID=\"t%d\" WIDTH=\"100%%\" DIR=%s>\n",
		    table, hflag ? "RTL": "LTR");
	    Glen[1] = 28;
	    if ((year % 4 == 0 && (!g || year%100 != 0)) || year % 400 == 0) {
		kvia++;
		Glen[1]++;
	    }
	    if (hflag) {
		Hmonth[6][1] = (kvia >= 30) ? "אדר ב" : "אדר";
	    } else {
		Hmonth[6][0] = (kvia >= 30) ? "Adar II" : "Adar";
	    }
	    Hlen[1] = (kvia % 30 == 2) ? 30 : 29;
	    Hlen[2] = (kvia % 30 == 0) ? 29 : 30;
	    Wd += 2;
	    if (Gd <= 21) {
		Gd += 10;
		Gm = 7;
	    } else if (Gd <= 51) {
		Gd -= 21;
		Gm = 8;
	    } else {
		Gd -= 51;
		Gm = 9;
	    }
	    for (Hm = 0; Hm < 13; Hm++) {
		if (Hm == 5 && kvia < 30) Hm++;
		Hl = Hlen[Hm];
		skip = (Wd - 1) % 7;
		Wd += Hl;
		reading(Hm, Hl, (skip + 1) % 7, kvia >= 30, dflag, hflag);
		printf("\n<TR><TH>%s", Hmonth[Hm][hflag]);
		if (skip == 1) printf("<TD>");
		else if (skip) printf("<TD COLSPAN=%d>", skip);
		holidays(Hm, Hl, (skip + 1) % 7, dflag, hflag, year + 3760);
		Gl=Glen[Gm];
		if (Gl - Gd >= Hl - 1) {
		    printf("\n<TR CLASS=g><TH>%s",Gmonth[Gm][hflag]);
		    if (skip == 1) printf("<TD>");
		    else if (skip) printf("<TD COLSPAN=%d>", skip);
		    for (Hd = 1; Hd <= Hl; Hd++) {
			printf("<TD>%d", Gd++);
		    }
		} else if (Glen[Gm + 1] + Gl - Gd >= Hl - 1) {
		    printf("\n<TR CLASS=g><TH>%s-%s",
			    Gabbrev[Gm][hflag], Gabbrev[Gm + 1][hflag]);
		    if (skip == 1) printf("<TD>");
		    else if (skip) printf("<TD COLSPAN=%d>", skip);
		    if (year == 1583 && !Hm) {
			Gd -= 10;
			Hl = 18;
		    }
		    for (Hd = 1; Gd <= Gl; Hd++) {
			printf("<TD>%d", Gd++);
		    }
		    Gl = Glen[++Gm];
		    for (Gd = 1; Hd <= Hl; Hd++) {
			printf("<TD>%d", Gd++);
		    }
		    if (Hl == 18){
			Hl = 30;
			for (Gd += 10; Hd<=Hl; Hd++) {
			    printf("<TD>%d", Gd++);
			}
		    }
		} else {
		    printf("\n<TR CLASS=g><TH>%s-%s",
			    Gabbrev[Gm][hflag], Gabbrev[Gm + 2][hflag]);
		    if (skip == 1) printf("<TD>");
		    else if (skip) printf("<TD COLSPAN=%d>", skip);
		    for (Hd = 1; Gd <=Gl; Hd++) {
			printf("<TD>%d", Gd++);
		    }
		    Gl = Glen[++Gm];
		    for (Gd = 1; Gd <= Gl; Hd++) {
			printf("<TD>%d", Gd++);
		    }
		    Gl = Glen[++Gm];
		    for (Gd = 1; Hd <= Hl; Hd++) {
			printf("<TD>%d", Gd++);
		    }
		}
		if (Gd > Gl) {
		    Gd -= Gl;
		    Gm++;
		}
		if (Gm >= 12) Gm -= 12;
		printf("\n");
	    }
	    printf("</TABLE>\n");
	    printf("<SCRIPT TYPE=\"text/javascript\">");
	    printf("today(\"t%d\", %d,%d,%d,%d)</SCRIPT>\n",
		    table++, year, Gm, Gd, kvia + 353);
	} else {
	    fprintf(stderr,"illegal argument: %s\n",*argv);
	    exit(1);
	}
    }
    exit(0);
}

void
holidays(int month, /* Hebrew Month (0:12) */
	int length, /* Length of the month (29:30) */
	int head, /* Week day of the first day of the month (0:6) */
	int dflag, /* Diaspora second holidays */
	int hflag, /* Hebrew printout */
	int year /* Hebrew year */)
{
    static int short_kislev;
    static char *holiday[30];
    int i;
    holiday[0] = holiday[29] = !hflag ? "Rosh Chodesh" : "ראש חדש";
    switch (month) {
    case 0:
	holiday[0] = holiday[1] = !hflag ? "Rosh Hashana" : "ראש השנה";
	if (head == 5) {
	    holiday[3] = !hflag ? "Tzom Gdalia" : "צום גדליה";
	} else {
	    holiday[2] = !hflag ? "Tzom Gdalia" : "צום גדליה";
	}
	holiday[9] = !hflag ? "Yom Kipur" : "יום כפור";
	for (i = 14; i < 15 + dflag; i++) {
	    holiday[i] = !hflag ? "Succot" : "סכות";
	}
	for ( ; i < 20; i++) {
	    holiday[i] = !hflag ? "Chol Hamoed Succot" : "חול המועד סכות";
	}
	holiday[20] = !hflag ? "Hosha’ana Raba" : "הושענא רבה";
	if (!dflag) {
	    holiday[21] = !hflag ? "Shmini Atzeret/Simchat Tora" :
		    "שמיני עצרת/שמחת תורה";
	} else {
	    holiday[21] = !hflag ? "Shmini Atzeret" : "שמיני עצרת";
	    holiday[22] = !hflag ? "Simchat Tora" : "שמחת תורה";
	}
	break;
    case 2:
	short_kislev = length == 29;
	for (i = 24; i < 29; i++) {
	    holiday[i] = !hflag ? "Hannuka" : "חנכה";
	}
	holiday[29] = !hflag ? "Hannuka/Rosh Chodesh" : "חנכה/ראש חדש";
	break;
    case 3:
	holiday[0] = !hflag ? "Hannuka/Rosh Chodesh" : "חנכה/ראש חדש";
	for (i = 1; i < 2 + short_kislev; i++) {
	    holiday[i] = !hflag ? "Hannuka" : "חנכה";
	}
	holiday[9+(head==5)] = !hflag ? "Tzom Asara B’Tevet" : "צום עשרה בטבת";
	break;
    case 4:
	holiday[14] = !hflag ? "Tu BiShevat" : "ט״ו בשבט";
	break;
    case 6:
	if (head==2) {
	    holiday[10] = !hflag ? "Taanit Ester" : "תענית אסתר";
	} else {
	    holiday[12] = !hflag ? "Taanit Ester" : "תענית אסתר";
	}
	holiday[13] = !hflag ? "Purim" : "פורים";
	holiday[14] = !hflag ? "Shushan Purim" : "שושן פורים";
	break;
    case 7:
	for (i = 14; i < 15 + dflag; i++) {
	    holiday[i] = !hflag ? "Pesach" : "פסח";
	}
	for ( ; i < 20; i++) {
	    holiday[i] = !hflag ? "Chol Hamoed Pesach" : "חול המועד פסח";
	}
	for ( ; i < 21 + dflag; i++) {
	    holiday[i] = !hflag ? "Pesach" : "פסח";
	}
	holiday[26] = !hflag ? "Yom Hashoa" : "יום השואה";
	break;
    case 8:
	holiday[i=head==3?1:head==2?2:head==5&&year>=5764?4:3] =
			!hflag ? "Yom Hazikaron" : "יום הזכרון";
	holiday[i+1] = !hflag ? "Yom Haatzmaut" : "יום העצמאות";
	holiday[17] = !hflag ? "Lag Baomer" : "ל״ג בעמר";
	holiday[27] = !hflag ? "Yom Yerushalaim" : "יום ירושלים";
	break;
    case 9:
	for (i = 5; i < 6 + dflag; i++) {
	    holiday[i] = !hflag ? "Shavuot" : "שבועות";
	}
	break;
    case 10:
	holiday[16+(head==5)] = !hflag ? "Tzom Shiv’a Asar B’Tammuz" :
		"צום שבעה עשר בתמוז";
	break;
    case 11:
	holiday[8+(head==6)] = !hflag ? "Tzom Tish’a B’Av" :
		"צום תשעה באב";
	holiday[14] = !hflag ? "Tu B’Av" : "ט״ו באב";
	break;
    }
    for (i = 0;i < length; i++) {
	if (holiday[i]) {
	    printf("<TD TITLE=\"%s\" CLASS=h>", holiday[i]);
	    holiday[i] = NULL;
	} else {
	    printf("<TD>");
	}
	if (hflag)
	    alef(i + 1, 0);
	else
	    printf("%d", i + 1);
    }
}

void
reading(int month, /* Hebrew Month (0:12) */
	int length, /* Length of the month (29:30) */
	int head, /* Week day of the first day of the month (0:6) */
	int leap, /* leap year (0:1) */
	int dflag, /* Israel/Diaspora style */
	int hflag  /* English/Hebrew printout */)
{
    int i,j;
    static char *holiday[5], *special[5];
    static int seq;
    static const char *week[7][2] = {
	{ "Sa", "ש" },
	{ "Su", "א" },
	{ "M",  "ב" },
	{ "Tu", "ג" },
	{ "W",  "ד" },
	{ "Th", "ה" },
	{ "F",  "ו" }
    };
    static const char *portion[54][2] = {
	{ "Bereshit",           "בראשית" },
	{ "Noach",                  "נח" },
	{ "Lech-Lecha",          "לך־לך" },
	{ "Vayera",               "וירא" },
	{ "Chayei-Sarah",      "חיי־שרה" },
	{ "Toldot",              "תולדת" },
	{ "Vayetze",              "ויצא" },
	{ "Vayishlach",          "וישלח" },
	{ "Vayeshev",             "וישב" },
	{ "Miketz",                "מקץ" },
	{ "Vayigash",             "ויגש" },
	{ "Vayechi",              "ויחי" },
	{ "Shemot",               "שמות" },
	{ "Vaera",                "וארא" },
	{ "Bo",                     "בא" },
	{ "Beshalach",            "בשלח" },
	{ "Yitro",                "יתרו" },
	{ "Mishpatim",          "משפטים" },
	{ "Teruma",              "תרומה" },
	{ "Tetzave",              "תצוה" },
	{ "Ki-Tisa",            "כי־תשא" },
	{ "Vayakhel",            "ויקהל" },
	{ "Pekudei",             "פקודי" },
	{ "Vayikra",             "ויקרא" },
	{ "Tzav",                   "צו" },
	{ "Shemini",             "שמיני" },
	{ "Tazri’a",             "תזריע" },
	{ "Metzora",              "מצרע" },
	{ "Acharei-Mot",      "אחרי־מות" },
	{ "Kedoshim",            "קדשים" },
	{ "Emor",                  "אמר" },
	{ "Behar",                 "בהר" },
	{ "Bechukotai",          "בחקתי" },
	{ "Bamidbar",            "במדבר" },
	{ "Naso",                  "נשא" },
	{ "Beha’alotcha",       "בהעלתך" },
	{ "Shelach",               "שלח" },
	{ "Korach",                "קרח" },
	{ "Chukat",                "חקת" },
	{ "Balak",                 "בלק" },
	{ "Pinchas",             "פינחס" },
	{ "Matot",                "מטות" },
	{ "Mase’ei",              "מסעי" },
	{ "Devarim",             "דברים" },
	{ "Vaetchanan",         "ואתחנן" },
	{ "Ekev",                  "עקב" },
	{ "Re’e",                  "ראה" },
	{ "Shoftim",             "שפטים" },
	{ "Ki-Tetze",           "כי־תצא" },
	{ "Ki-Tavo",           "כי־תבוא" },
	{ "Nitzavim",            "נצבים" },
	{ "Vayelech",             "וילך" },
	{ "Ha’azinu",           "האזינו" },
	{ "Vezot-Habracha", "וזאת־הברכה" }
    };
    printf("<TR CLASS=w><TH>");
    if (head == 2) printf("<TH>");
    else if (head != 1) printf("<TH COLSPAN=%d>", (head + 6) % 7);
/* Mark Saturdays which fall in a holiday in Tishri, Nisan and Sivan */
/* Mark special Saturday in Tishri */
/* Mark 4 special Saturdays in Adar or its vicinity */
/* Initialize reading seqequence in Tishri */
    if (month == 0) {
	holiday[2] = !hflag ? "Succot" : "סכות";
	if (head == 0) {
	    seq = 53;/*Haazinu*/
	    holiday[0] = !hflag ? "Rosh Hashana" : "ראש השנה";
	    special[1] = !hflag ? "Shuva" : "שובה";
	    if (!dflag) {
		holiday[3] = !hflag ? "Shmini Atzeret/Simchat Tora" :
			"שמיני עצרת/שמחת תורה";
	    } else {
		holiday[3] = !hflag ? "Shmini Atzeret" : "שמיני עצרת";
	    }
	} else if (head == 5) {
	    seq = 53;/*Haazinu*/
	    special[0] = !hflag ? "Shuva" : "שובה";
	    holiday[1] = !hflag ? "Yom Kipur" : "יום כפור";
	} else {
	    seq = 52;/*Vayelech*/
	    special[0] = !hflag ? "Shuva" : "שובה";
	}
    } else if (month == 5 || (month == 4 && !leap)) {
	if (head != 5)
	    special[3 + (head == 0)] = !hflag ? "Shekalim" : "שקלים";
    } else if (month == 6) {
	if (head == 0)
	    special[0] = !hflag ? "Shekalim" : "שקלים";
	special[1] = !hflag ? "Zachor" : "זכור";
	special[2 + (head == 0 || head == 6)] = !hflag ? "Para" : "פרה";
	if (head != 6)
	    special[3 + (head == 0)] = !hflag ? "Hachodesh" : "החודש";
    } else if (month == 7) {
	if (head == 0)
	    special[0] = !hflag ? "Hachodesh" : "החודש";
	holiday[2] = !hflag ? "Pesach" : "פסח";
	if (dflag && head == 0) holiday[3] = !hflag ? "Pesach" : "פסח";
    } else if (month == 9 && dflag && head == 1) {
	holiday[0] = !hflag ? "Shavuot" : "שבועות";
    }
    i = -1;
    for (j = 0; j < length; j++) {
	if ((j + head) % 7) {
	    printf("<TH>%s", week[(j + head) % 7][hflag]);
	    continue;
	}
	if (holiday[++i]) {
	    printf("<TH TITLE=\"%s\" CLASS=h>%s", holiday[i], week[0][hflag]);
	    holiday[i] = NULL;
	    continue;
	}
/* Print reading sequence */
/* Check for possible joined reading */
	printf("<TH TITLE=\"%s", portion[seq-1][hflag]);
	if ((seq == 22 /*Vayakhel/Pekudei*/ &&
		    !leap && (head != 0 || i == 4)) ||
		(seq == 27 /*Tazria/Metzora*/ &&
		    !leap) ||
		(seq == 29 /*Acharei/Kedoshim*/ &&
		    !leap) ||
		(seq == 32 /*Behar/Bechukotai*/ &&
		    !leap && (dflag || head != 2)) ||
		(seq == 39 /*Chukat/Balak*/ &&
		    dflag && head == 3) ||
		(seq == 42 /*Matot/Masei*/ &&
		    (!leap || (dflag && month == 11) ||
		    (month == 10 && (head == 3 || (head == 1 && i == 3))))) ||
		(seq == 51 /*Nitzavim/Vayelech*/ &&
		    (head == 4 || head == 6))) {
	    printf("/%s", portion[seq++][hflag]);
	}
	if (special[i]) {
	    printf("/%s", special[i]);
	    special[i] = NULL;
	}
	printf("\" CLASS=r>%s", week[0][hflag]);
	if (++seq > 53)
	    seq = 1;
    }
}
