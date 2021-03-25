.\" $Id: gauss.ms,v 1.24 2005-10-17 09:54:52+02 rl Exp $
.if !c\(*d .char \(*d delta
.if !c\(*D .char \(*D DELTA
.if n \{\
.nr PO 0
.nr LL 78n
.\}
.de LM
.FS
Last modified: \\$2 \\$3
.FE
..
.EQ
delim $$
tdefine / 'over'
define mod 'roman "mod"'
.EN
.TL
Gauss Formula for the Julian Date of Passover
.AU
Zvi Har'El
.AI
Department of Mathematics
Technion \- Israel Institute of Technology
Haifa 32000, Israel
E - Mail: rl@math.technion.ac.il
.NH
Definitions.
.PP
\fINisan origin\fP is the instant occurring before the beginning of 1 Nisan, in 
a time difference which is equal to the difference between the new moon, or \fImolad\fP,
of Tishri and the beginning of 1 Tishri of the following Hebrew year.
.PP
Nisan origin of the year 1 \s-2AM\s0\**
.FS
\fIanno mundi\fP.
.FE
is 29 Adar, 14 hours,
because molad Tishri of the year 2 \s-2AM\s0 was on Friday, 14 hours,
and 1 Tishri was a Saturday.
.PP
\fIMarch origin\fP is the instant occurring one day before the beginning of 1 
March.
Thus, the March date of a given instant will be in fact the time
difference between that instant and March origin.
.PP
Note that Nisan origin of the year 1 \s-2AM\s0 is 33 March, 14 hours,
because the Julian date of 1 Nisan 1 \s-2AM\s0 was 3 April, i.e., 34 March.
Here we assume the Julian day begins in the previous evening (at 6 \s-2PM\s0),
as the Hebrew day does, to simplify the discussion.
.PP
Let $H ( A ) $ denote the Nisan origin and $J ( A ) $ the March origin
of the Hebrew year $A$. 
Let $T$ be Nisan origin of the year 1 \s-2AM\s0, in March days:
.EQ (1)
T = H ( 1 ) - J ( 1 ) = 33:14:0 = 403 / 12 .
.EN
Time intervals are given in the Talmudic units: An hour is divided
into 1080 parts, so that $d$ days, $h$ hours and $p$ parts are written as
$d:h:p = ( p /1080 + h ) /24 + d$.
Let $K$ be 1/19 of the length of the lunar month: 
.EQ
K = {29:12:793} / 19 = 765433 / 492480 . 
.EN
A cycle of 19 consecutive lunar years contains 235 lunar months,
arranged in 12 common years containing 12 months each, and 7 leap years,
containing 13 month each.
Conventionally, leap years are the 3rd, 6th, 8th, 11th, 14th, 17th, 19th in
each cycle.
Let $L$ be the average solar excess, i.e., difference in length between a
solar year and an average lunar year:
.EQ
L = 365:6:0 - 235K = {0:1:485} / 19 = 313 / 98496 .
.EN
Note: Using decimals,
.EQ
T approx 33.58333333 ,
.EN
.EQ
K approx 1.554241797 ,
.EN
.EQ
L approx 0.003177794022 .
.EN
.NH
Nisan origin.
.PP
The length of a leap lunar year is $13 cdot 19K = 247K$,
while the length of a common lunar year is $12 cdot 19K = 228K$.
Subtracting these quantities from $L + 235K$, the length of the solar year,
we get the common solar excess, $L + 7K$,
and the (negative) leap solar excess, $L - 12K$.
.PP
From these observations we get 
.EQ
H ( A ) - H ( 1 ) = 365:6:0 ( A - 1 ) - Delta ( A ) ,
.EN
where $Delta ( A ) $ is the cumulative solar excess. It is given in the
following table, with leap years marked by an asterisk:
.TS
center box;
n|c .
$A$	$Delta ( A ) $
_
1	$0$
2	$L + 7K$
*3	$2L - 5K$
4	$3L + 2K$
5	$4L + 9K$
*6	$5L - 3K$
7	$6L + 4K$
*8	$7L - 8K$
9	$8L - K$
10	$9L + 6K$
*11	$10L - 6K$
12	$11L + K$
13	$12L + 8K$
*14	$13L - 4K$
15	$14L + 3K$
16	$15L + 10K$
*17	$16L - 2K$
18	$17L + 5K$
*19	$18L - 7K$
20	$19L$
.TE
.PP
Each year we add $L + 7K$, unless the year is leap, when we add $L - 12K$
(since we compute in effect the next molad Tishri). In this way, the coefficient of $L$
is incremented continuously, while the coefficient of $K$ is increased by 7 each time,
until a moment when it becomes 11 or higher, when it is decreased by 19. Since the lowest 
possible value of this coefficient is - 8, and this value is obtained at $A = 8 ( mod~19 ) $,
we get that the running value is $ - 8 + ( 7 ( A - 8 ) ) |19$, where $x|k$ is $x - k [x/k]$.
Therefore, the coefficient of $K$ is 
.EQ
- 8 + ( 7 ( A - 8 ) ) |19 mark = - 8 + ( 7A + 1 ) |19
.EN
.EQ
lineup = - 8 + ( 18 - ( 18 - ( 7A + 1 ) ) |19 ) 
.EN
.EQ
lineup = 10 - ( 17 - 7A ) |19
.EN
.EQ
lineup = 10 - ( 12A + 17 ) |19
.EN
(using the identity $x|k = ( k - 1 ) - ( ( k - 1 ) - x ) |k$).
Denoting
.EQ
a = ( 12A + 17 ) |19 ,
.EN
we get
.EQ
Delta ( A ) = ( 10 - a ) K + ( A - 1 ) L ,
.EN
or finally
.EQ (2)
H ( A ) - H ( 1 ) = ( A - 1 ) 365:6:0 + ( a - 10 ) K - ( A - 1 ) L .
.EN
.PP
As an added bonus, we can divide the cycle years into 4 categories,
according to the value of the coefficient of $K$ in the cumulative solar
excess:
.TS
center box;
c|c|c|c|c.
$10 - a$	$a$	$A - 1$	$A$	$A + 1$
_
 \-8...\-2	18...12	common	leap	common
 \-1...3	11...7	leap	common	common
4...5	6...5	leap	common	leap
6...10	4...0	common	common	leap
.TE
.NH
March origin.
.PP
Set
.EQ
J ( A ) - J ( 1 ) = ( A - 1 ) 365 + delta ( A ) ,
.EN
where $delta ( A ) $ is the number of Julian intercalary days (29 February)
between 1 March 1 \s-2AM\s0 and 1 March of the year $A$.
Since the Hebrew year 1 \s-2AM\s0 corresponds\**
.FS
At least, its major part containing 1 March.
.FE
to the Julian year
3760 \s-2BCE\s0, or \-3759 \s-2CE\s0
which gives a remainder of 1 when divided by 4,
we obtain that the year $A$ will contain a intercalary day
if and only if $A == 0 ~ ( mod~4 )$.
Thus $delta ( A ) = [A/4]$, or, denoting
.EQ
b = A|4 ,
.EN
we get
.EQ
delta ( A ) = A /4 - b /4 .
.EN
Therefore
.EQ
J ( A ) - J ( 1 ) = ( A - 1 ) 365 + A /4 - b /4 ,
.EN
or, finally
.EQ (3)
J ( A ) - J ( 1 ) = ( A - 1 ) 365:6:0 - b /4 + 0:6:0 .
.EN
.NH
March date of Passover.
.PP
Subtracting (3) from (2) and using (1), we get
.EQ
H ( A ) - J ( A ) = T + ( a - 10 ) K - ( A - 1 ) L + b /4 - 0:6:0 ,
.EN
or
.EQ
H ( A ) - J ( A ) = ( T - 10K + L ) + aK - AL + b /4 - 0:6:0 .
.EN
This is the March date of Nisan origin of the Hebrew year $A$.
We add 6 hours to implement the rule that
if molad Tishri is at noon or later\**,
.FS
\fIMolad Zaken\fP.
.FE
1 Tishri is postponed to the following day.
Finally we add 14 days to get the March date of 15 Nisan.
.PP
Setting
.EQ
m sub 0 = T - 10K + L + 14 = 3156215 / 98496 ,
.EN
we get
.EQ
M + m = {m sub 0} + aK - AL + b /4 ,
.EN
where M is the integral part and m the fractional part of the right hand side.
Unless further exceptions apply (see below), $M$ is the Julian March date of the
first day of Passover of the Hebrew year $A$.
.PP
Note: Using decimals,
.EQ
m sub 0 approx 32.04409316 .
.EN
.NH
Week day of Passover.
.PP
Calculating modulo 7, we obtain:
.EQ
J ( A ) - J ( 1 ) mark == ( A - 1 ) 365:6:0 - b /4 + 0:6:0
.EN
.EQ
 lineup == ( A - 1 ) 1:6:0 - b /4 + 0:6:0
.EN
.EQ
 lineup == 5A /4 - b /4 - 1
.EN
.EQ
 lineup == A - 1 + ( A - b ) /4
.EN
.EQ
 lineup == A - 1 + 8 ( A - b ) /4
.EN
.EQ
 lineup == A - 1 + 2 ( A - b ) 
.EN
.EQ
 lineup == 3A - 2b - 1
.EN
.EQ
 lineup == 3A + 5b - 1 ~ ( mod~7 )
.EN
Since March origin 1 \s-2AM\s0 was on Friday, we get for $M$ March of
the Hebrew year $A$,
.EQ
c = ( M + 3A + 5b + 5 ) |7 .
.EN
$c$ is the day in the week of $M$ March, with $c = 0$ for Saturday.
.NH
Exceptions.
.PP
In the discussion above, we assumed that 1 Tishri is the day on which
molad Tishri has taken place, and established that the Julian date of
15 Nisan is $M$ March. We already mentioned one exception.
If molad Tishri is at noon or later, 1 Tishri is
postponed to the following day. We implemented this exception by adding 6 hours
to Nisan origin. However, there are three more exceptions.
.PP
The second exception is the rule that 1 Tishri is excluded from being a Sunday, Wednesday
or Friday\**,
.FS
\fIAdu\fP.
.FE
and is postponed to the following day.
To implement this rule, we notice that 15 Nisan and the following 1 Tishri
are  152 days apart, i. e., 22 weeks minus 2 days.
Thus, 15 Nisan is excluded from being a Friday, Monday of Wednesday,
respectively.
.PP
The last two exceptions are derived from the previous one, and from a
restriction on the length of the Hebrew year. As we have seen,
the length of the common lunar year is $12 cdot 19K  = 354:8:876$ days,
and the length of the leap lunar year is $13 cdot 19K = 383:21:589$ days.
Of course, a calendar year must have an integral number of days.
Thus, a common Hebrew year has 353, 354 or 355 days\**,
.FS
12 months, alternating between 30 and 29 days each, give
a total of 354 days.
This number may increase by adding one to the 29 days of Heshvan,
or decrease by subtracting one from the 30 days of Kislev.
.FE
while a leap Hebrew year has 383, 384 or 385 days\**.
.FS
The intercalary month, Adar Rishon, has 30 days.
.FE
.PP
The third exception follows from restricting the common year to have at most
355 days.
Molad Tishri of a common year $A+1$ and its successor are 354:8:876 days apart,
i. e., 51 full weeks minus 2:15:204 days.
Thus, if molad Tishri of $A+1$, after being moved 6 hours ahead, is on Tuesday,
15 hours and 204 parts or later\**,
.FS
The molad being on Tuesday, 9 hours and 204 parts or later (\fIGatrad\fP).
.FE
its successor is on Sunday.
Then, 1 Tishri $A+2$ is a Monday, and if 1 Tishri $A+1$ is not postponed from
Tuesday (to Thursday, as Wednesday is excluded),
the year $A+1$ will have 356 days.
.PP
Similarly, the fourth exception follows from restricting the leap year to have
at least 383 days.
Molad Tishri of a leap year $A$ and its successor are 383:21:589 days apart,
i. e., 54 full weeks plus 5:21:589 days.
Thus, if molad Tishri of $A+1$, after being moved 6 hours ahead, is on Monday,
21 hours and 589 parts or later\**,
.FS
The molad being on Monday, 15 hours and 589 parts or later (\fIBetu Takpat\fP). 
.FE
its predecessor is on Wednesday.
Then, 1 Tishri $A$ is a Thursday, and if 1 Tishri $A+1$ is not postponed from
Monday (to Tuesday), the year $A$ will have 382 days.
.PP
To implement the last two exceptions, we notice that that 1 Tishri $A+1$ being
a Monday or Tuesday implies that 15 Nisan $A$ is a Saturday or Sunday,
respectively.
Also, if we consider the table in Section 2, we notice that $A$ is leap
if $a >= 12$ and $A + 1$ is common if $a >= 7$.
.PP
Thus, setting
.EQ
m sub 1 = (13 cdot 19K)|1 = 0:21:589 = 23269 / 25920 ,
.EN
.EQ
m sub 2 =  1 - (12 cdot 19K)|1 = 0:15:204 =  1367 / 2160 ,
.EN
we find that the Julian date the first day of Passover is:
.IP \(bu
$M + 1$ March, if $c = 0$, $a >= 12$ and $m >= m sub 1$,
.IP \(bu
$M + 2$ March, if $c = 1$, $a >= 7$ and $m >= m sub 2$,
.IP \(bu
$M + 1$ March, if $c = 2$, 4 or 6,
.IP \(bu
$M$ March, otherwise.
.PP
Note: Using decimals,
.EQ
m sub 1 approx 0.897723765 ,
.EN
.EQ
m sub 2 approx 0.63287037 .
.EN
.NH
References.
.PP
.IP 1.
Adler, Cyrus, \fICalendar, History of\fP, in: Singer, Isidore (ed.),
The Jewish Encyclopedia, Vol. 3, pp. 498-500. Ktav Publishing House, Inc.,
New York, 1901.
.IP 2.
Dershowitz, N. and Reingold, E. M., \fICalendrical Calculations\fP,
Software \- Practice and Experience, 20 (1990), 899-928.
.IP 3.
Friedl\(:ander, Michael, \fICalendar\fP, in: Singer, Isidore (ed.),
The Jewish Encyclopedia, Vol. 3, pp. 501-508. Ktav Publishing House, Inc.,
New York, 1901.
.IP 4.
Gauss, Karl Friedrich, \fIBerechnung Des J\(:udishen Osterfestes\fP,
Montaliche Correspondenz zur Bef\(:orderung der Erd- und Himmels-Kunde,
herausgegeben vom Freiherrn von Zach. Mai 1802. Werke, Vol 6, pp. 80-81.
.IP 5.
Gauss, Karl Friedrich, \fIBerechnung Des Neumonds Tisri F\(:ur Jedes
J\(:udische Jahr A\fP, Handschriftlische Eintragung in Christian Wolf,
Elementa matheseos universae, tomus IV. - Von Gauss 1800 erworben.
Werke, Vol. 11, pp. 215-218.
.IP 6.
Resnikoff, Louis A., \fIJewish Calendar Calculations\fP, Scripta Math.,
9 (1943), 191-195.
.NH
Appendix: A Computer Implementation.
.sp 2
.nf
.ie \n(.g .fam C
.el \{\
.fp 1 CW
.fp 2 CI
.fp 3 CB
.fp 4 CX
\}
\s-2\f1/*\f2
* Gauss formula for Passover
*
* Arguments:
*	year \- Hebrew year (anno mundi)
*	g \- boolean flag, 0 for Julian dates, 1 for Gregorian.
*	day \- optional pointer to an integer,
*	to return the day\-of\-the week.
* Return value:
*	March date of the first day of Passover.
\f1*/

/*\f2 Fundamental constants \f1*/
#\f3define\f1 T  (33. + 14. / 24.)
#\f3define\f1 L  ((1.  + 485. / 1080.) / 24. / 19.)
#\f3define\f1 K  ((29. + (12. + 793. / 1080.) / 24. )/ 19.)

/*\f2 Derived constants \f1*/
#\f3define\f1 m0 (T \- 10. * K + L + 14.)
#\f3define\f1 m1 ((21. + 589. / 1080.) / 24.)	/*\f2 13*19*K mod 1 \f1*/
#\f3define\f1 m2 ((15. + 204. / 1080.) / 24.)	/*\f2 1 \- (12*19*K mod 1) \f1*/

\f3int\f1 
Gauss(\f3int\f1 year, \f3int\f1 g, \f3int\f1 *day)\kx\s+2\f4\h'|\n(.lu-\w'Gauss'u'Gauss\f1\s0\h'|\nxu'
.ds r Gauss
{	\f3int\f1 a, b, c, M;
	\f3double\f1 m;
	a = (12 * year + 17) % 19;
	b = year % 4;
	m = m0 + K * a +  b / 4. \- L * year;
	\f3if\f1 (m < 0) m\-\-;
	M = m;
	\f3if\f1 (m < 0) m++;
	m \-= M;
	\f3switch\f1 (c = (M + 3 * year + 5 * b + 5) % 7) {
	\f3case\f1 0:
		\f3if\f1 (a >= 12 && m >= m1) {
			c = 1; M++;
		}
		\f3break\f1;
	\f3case\f1 1:
		\f3if\f1 (a >= 7 && m >= m2) {
			c = 3; M += 2;
		}
		\f3break\f1;
	\f3case\f1 2:
		c = 3; M++;
		\f3break\f1;
	\f3case\f1 4:
		c = 5; M++;
		\f3break\f1;
	\f3case\f1 6:
		c = 0; M++;
		\f3break\f1;
	}
	\f3if\f1 (day) *day = c;
	\f3if\f1 (g) /*\f2 Gregorian Calendar \f1*/
		M += (year \- 3760) / 100 \- (year \- 3760) / 400 \- 2;
	\f3return\f1 M;
}\s0
.LM $$Date: 2005-10-17 09:54:52+02 $$
