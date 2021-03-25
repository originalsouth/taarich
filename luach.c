#ident "$Id: luach.c,v 1.35 2005-11-03 15:43:06+02 rl Exp $"
/*
 * Hebrew - Gregorian Calendar (groff, command line input)
 *
 * Author:‭
 *      Dr. Zvi Har'El,                             לארה יבצ ר"ד
 *      Department of Mathematics,              הקיטמתמל הטלוקפה
 *      Technion, Israel Institute of Technology, ל"טמ - ןוינכטה
 *      Haifa 32000, Israel.                   לארשי ,32000 הפיח
 *      E-Mail: rl@math.technion.ac.il
 *
 * Note:
 *	For Hebrew printout, pipe into “iconv -f utf8 -t hebrew”
 *	or “recode u8..hebrew” before piping into groff.
 *	Hebrew fonts for groff are available from the author.
 */
#include <stdlib.h>
#include <stdio.h>
extern int Gauss(int year, int g,int *day);
extern void alef(int n);
extern void holidays(int month, int length, int head, int diaspora, int hflag);
extern void reading(int month, int head, int abundant, int leap, int diaspora);

int
main(int argc, char **argv)
{
    int first = 1,
	year,	/* Hebrew year (A.M.) */
	g,	/* Gregorian flag */
	kvia,	/* excess of length of the Hebrew year over 353 */
	Wd,	/* day in the week (mod. 7) */
	Hm,	/* month in the Hebrew year (0:12) */
	Gm,	/* month in the Gregorian year (0:11) */
	Hl,	/* length of Hebrew month Hm */
	Gl,	/* length of Gregorian month Gm */
	Hd,	/* day in the Hebrew month (1:Hl) */
	Gd,	/* day in the Gregorian month (1:Gl) */
	read = -1,  /* Reading type (-1:1)*/
	hflag = 0,  /* English/Hebrew printout */
	jflag = 0;  /* Gregorian/Julian calendar */
	char *tabs; /* tabs for shifted printout */
    static char *week[2][7] = {
	{"ש","א","ב","ג","ד","ה","ו"},
	{"Sa","Su","M","Tu","W","Th","F"}
    };
    static char *Hmonth[2][13] = {
	{"ירשת","ןושח","ולסכ","תבט","טבש",
	"א רדא","","ןסינ","ריא","ןויס","זומת","בא","לולא"},
	{"Tishri","Heshvan","Kislev","Tevet","Shevat",
	"AdarI","","Nisan","Iyyar","Sivan","Tammuz","Av","Elul"}
    };
    static int Hlen[13] = {
	30,0,0,29,30,30,29,30,29,30,29,30,29
    };
    static char *Gmonth[2][13] = {
	{"ראוני","ראורבפ","סרמ","לירפא","יאמ","ינוי","ילוי",
	"טסוגוא","רבמטפס","רבוטקוא","רבמבונ","רבמצד","ראוני"},
	{"January","February","March","April","May","June","July",
	"August","September","October","November","December","January"}
    };
    static char *Gabbrev[2][13] = {
	{"וני","רבפ","סרמ","רפא","יאמ","ינוי","ילוי",
	"גוא","טפס","קוא","בונ","מצד","וני"},
	{"Jan","Feb","Mar","Apr","May","Jun","Jul",
	"Aug","Sep","Oct","Nov","Dec","Jan"}
    };
    static int Glen[13] = {
	31,0,31,30,31,30,31,31,30,31,30,31,31
    };
    printf(".ps 8\n.if t .po 2c\n.nf\n");
    tabs = "+3nC+3nC+3nC+3nC+3nC+3nC+5nC";
    printf(".if t .ta 12nC%s%s%s%s%s\n",tabs,tabs,tabs,tabs,tabs);
    tabs = "+3nL+3nL+3nL+3nL+3nL+3nL+4nL";
    printf(".if n .ta 12nL%s%s%s%s%s\n",tabs,tabs,tabs,tabs,tabs);
    while (--argc > 0) {
	if (**++argv == '-') {
	    switch(*(*argv+1)) {
	    case 'e':	/* English printout */
		hflag = 0;
		printf (".fp 1 R\n.fp 2 I\n.fp 3 B\n.fp 4 BI\n");
		break;
	    case 'h':	/* Hebrew printout */
		hflag = 1;
		printf (".fp 3 DeadSea\n.fp 1 OldJaffa\n.fp 4 TelAviv\n");
		break;
	    case 'n':	/* no reading */
		read = -1;
		break;
	    case 'i':	/* reading Israel style */
		read = 0;
	    break;
		case 'd':	/* reading diaspora style, second holidays */
	    read = 1;
		break;
	    case 'g': /* Gregorian calendar */
		jflag = 0;
		break;
	    case 'j':	/* Julian Calendar */
		jflag = 1;
		break;
	    case '.':	/* troff option request */
		printf(".am OP\n%s\n..\n",*argv+1);
		break;
	    default:
		fprintf(stderr,"illegal option: %s\n", *argv);
		exit(1);
	    }
	} else if ((year = atoi(*argv))) {
	    if (first)
		first = 0;
	    else
		printf(".bp\n");
	    printf(".OP\n.rm OP\n\n\n\n.ce\n\\s+4\\f3");
	    if (hflag) {
		alef (year);
		printf(" תנשל חול");
	    } else {
		printf("Calendar for %d", year);
	    }
	    printf("\n\n.ce\n\\s0\\f4(");
	    g = !jflag && year >= 5343;
	    Gd = Gauss(year-1,g,&Wd);
	    kvia = Gauss(year,g,(int*)0) - Gd + 12;
	    year -= 3760;
	    if (hflag)
		printf("%d -ו %d תויני%s םינש", year, year-1, g ? "רוגרג" :
			"לוי");
	    else
		printf("%sian years %d & %d", g ? "Gregor" : "Jul", year-1,
			year);
	    printf (")\n\n");
	    if (read >= 0) {
		printf(".ce\n\\f3(");
		if (hflag)
		    printf("%s חסונ האירק םע", read ? "הלוגה" : "לארשי");
		else
		    printf("with reading %s style", read ? "diaspora" :
			    "Israel");
		printf(")\n\n");
	    }
	    Glen[1] = 28;
	    if ((year % 4 == 0 && (!g || year%100 != 0)) || year % 400 == 0) {
		kvia++;
		Glen[1]++;
	    }
	    if (hflag)
		Hmonth[0][6] = (kvia >= 30) ? "ב רדא" : "רדא";
	    else
		Hmonth[1][6] = (kvia >= 30) ? "AdarII" : "Adar";
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
		if (Hm == 5 && kvia < 30)
		    Hm++;
		Hl = Hlen[Hm];
		tabs = "\t\t\t\t\t\t" + 6 - (Wd - 1) % 7;
		printf("\n%s\\f3",tabs);
		for (Hd=1;Hd<=Hl;Hd++)
		    printf("\t%s", week[!hflag][(Wd++) % 7]);
		printf("\n%s%s", Hmonth[!hflag][Hm], tabs);
		holidays(Hm, Hl, (Wd-Hl)%7, read==1, hflag);
		Gl=Glen[Gm];
		if (Gl-Gd >= Hl-1) {
		    printf("\n\\f4%s%s\\f2",Gmonth[!hflag][Gm], tabs);
		    for (Hd=1; Hd<=Hl; Hd++)
			printf("\t%d", Gd++);
		} else if (Glen[Gm+1]+Gl-Gd >= Hl-1) {
		    printf("\n\\f4%s-%s%s\\f2", Gabbrev[!hflag][Gm+hflag],
			    Gabbrev[!hflag][Gm+!hflag], tabs);
		    if (year==1583&&!Hm) {
			Gd-=10;
			Hl=18;
		    }
		    for (Hd=1;Gd<=Gl;Hd++)
			printf("\t%d",Gd++);
		    Gl = Glen[++Gm];
		    for (Gd=1;Hd<=Hl;Hd++)
			printf("\t%d",Gd++);
		    if (Hl==18){
			Hl=30;
			for (Gd+=10;Hd<=Hl;Hd++)
			    printf("\t%d",Gd++);
		    }
		} else {
		    printf("\n\\f4%s-%s%s\\f2", Gabbrev[!hflag][Gm+2*hflag],
			    Gabbrev[!hflag][Gm+2*!hflag], tabs);
		    for (Hd=1;Gd<=Gl;Hd++)
			printf("\t%d",Gd++);
		    Gl = Glen[++Gm];
		    for (Gd=1;Gd<=Gl;Hd++)
			printf("\t%d",Gd++);
		    Gl = Glen[++Gm];
		    for (Gd=1;Hd<=Hl;Hd++)
			printf("\t%d",Gd++);
		}
		if (Gd>Gl) {
		    Gd -= Gl;
		    Gm++;
		}
		if (Gm>=12) Gm -= 12;
		printf("\n");
		if (read >= 0) {
		    printf("\\f1");
		    reading(Hm, (Wd - Hl) % 7, Hl == 30, kvia >= 30, read);
		}
	    }
	    printf("\n");
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
	int diaspora, /* Diaspora second holidays (0:1) */
	int hflag /* Hebrew printout */)
{
    static int short_kislev, font[30];
    int i;
    font[29]=3;/*Rosh Chodesh*/
    font[1]=1;
    switch (month) {
    case 0:/*Rosh Hashana, Tzom Gdalia, Yom Kipur, Succot*/
	font[9]=font[14]=3;
	font[1]=0;
	font[10]=font[22+diaspora]=1;
	if (head==5) {
	    font[3]=3;
	    font[2]=font[4]=1;
	}else font[3]=1;
	break;
    case 2:/*Hannuka begins*/
	short_kislev=length==29;
	font[24]=3;
	break;
    case 3:/*Hannuka ends, 10 Tevet*/
	font[i=9+(head==5)]=3;
	font[1]=0;
	font[2+short_kislev]=font[i+1]=1;
	break;
    case 4:/*15 Shevat*/
	font[14]=3;
	font[15]=1;
	break;
    case 6:/*Taanit Ester, Purim*/
	if (head==2) {
	    font[10]=font[13]=3;
	    font[11]=1;
	} else font[12]=3;
	    font[15]=1;
	break;
    case 7:/*Pesach, Yom Hashoa*/
	font[14]=font[26]=3;
	font[21+diaspora]=font[27]=1;
	break;
    case 8:/*Yom Hazikaron, Yom Haatzmaut, Lag Baomer, Yom Yerushalaim*/
	font[i=head==3?1:head==2?2:3]=font[17]=font[27]=3;
	font[i+2]=font[18]=font[28]=1;
	break;
    case 9:/*Shavuot*/
	font[5]=3;
	font[6+diaspora]=1;
	break;
    case 10:/*17 Tammuz*/
	font[i=16+(head==5)]=3;
	font[i+1]=1;
	break;
    case 11:/*9 Av*/
	font[i=8+(head==6)]=3;
	font[i+1]=1;
	break;
    }
    for (i=0;i<length;) {
	printf("\t");
	if (font[i]) {
	    printf("\\f%d",font[i]);
	    font[i]=0;
	}
	if (hflag)
	    alef(++i);
	else
	    printf("%d", ++i);
    }
}

void
reading(int month, /* Hebrew Month (0:12) */
	int head, /* Week day of the first day of the month (0:6) */
	int abundant, /* abundant month (0:1) */
	int leap, /* leap year (0:1) */
	int diaspora /* reading diaspora style (0:1) */)
{
    int i,holiday[5], weeks;
    static int seq;
/* Mark Saturdays which fall in a holiday in Tishri, Nisan and Sivan */
/* Initialize reading seqequence in Tishri */
    for (i = 0; i < 5; i++) holiday[i] = 0;
    if (month == 0) {/*Tishri*/
	holiday[2] = 1;/*Succoth*/
	if (head == 0) {
	    seq = 53;/*Haazinu*/
	    holiday[0] = 1;/*Rosh Hashana*/
	    holiday[3] = 1;/*Shmini Atzereth*/
	} else if (head == 5) {
	    seq = 53;/*Haazinu*/
	    holiday[1] = 1;/*Yom Kipur*/
	} else seq = 52;/*Vayelech*/
    } else if (month == 7) {/*Nisan*/
	holiday[2] = 1;
	if (diaspora && head == 0) holiday[3] = 1;/*8th day of Pesach*/
    } else if (month == 9 && diaspora && head == 1) {/*Sivan*/
	holiday[0] = 1;/*2nd day of Shavuoth*/
    }
/* Count Saturdays in the month */
    if (head == 0 || (head == 6 && abundant)) weeks = 5;
    else weeks = 4;
    for (i = 0; i < weeks; i++) {
/* Print reading sequence */
    printf("\t\t\t\t\t\t\t");
    if (holiday[i]) {
	printf("***");
	continue;
    }
    printf("%d", seq);
/* Check for possible joined reading */
    if ((seq == 22 /*Vayakhel+Pekudei*/ && !leap && (head != 0 || i == 4)) ||
	    (seq == 27 /*Tazria+Metzora*/ && !leap) ||
	    (seq == 29 /*Acharei+Kedoshim*/ && !leap) ||
	    (seq == 32 /*Behar+Bechukotai*/ && !leap && (diaspora ||
		head != 2)) ||
	    (seq == 39 /*Chukat+Balak*/ && diaspora && head == 3) ||
	    (seq == 42 /*Matot+Masei*/ && (!leap || (diaspora && month == 11)
		|| (month == 10 && (head == 3 || (head == 1 && i == 3))))) ||
	    (seq == 51 /*Nitzavim+Vayelech*/ && (head == 4 || head == 6))) {
	printf("+");
	seq++;
    }
    if (++seq > 53)
	seq = 1;
    }
}
