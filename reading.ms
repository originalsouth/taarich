.\" $Id: reading.ms,v 1.14 2004-01-16 23:48:24+02 rl Exp $
.if !c\(dg .char \(dg +
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
define mod 'roman "mod"'
.EN
.TL
The Torah Reading Sequence
.AU
Zvi Har'El
.AI
Department of Mathematics
Technion \- Israel Institute of Technology
Haifa 32000, Israel
E - Mail: rl@math.technion.ac.il
.NH
Introduction.
.PP
The \fITorah\fP, or Pentateuch, which consists of the first five books of
the Scriptures, is traditionally divided to 54 portions.
It is customary to read these portions in Sabbath mornings during the year,
reading the last one in a special feast, \fISimchat-Torah\fP
(Rejoicing the Law).
Few of the Sabbaths fall on a holiday, and there are special readings for 
them. Thus, there is a gap between the number of Torah portions which should be 
read, and the number of ordinary Sabbaths in which they may be read.
This gap is bridged traditionally by joining selected pairs
of consecutive portions for reading in a single Sabbath.
.NH
The portions.
.PP
The following table lists the 54 portions of the Torah, complete with book,
chapter and verse  indications.
.LP
.TS
center box;
n1 l1 r | n1 l1 r.
	Portion	Verses		Portion	Verses
_
 1	Bereshit	$Genesis$ 1:1-6:8	28	Metzora	14:1-15:33
 2	Noach	6:9-11:32	29	Acharei-Mot	16:1-18:30
 3	Lech-Lecha	12:1-17:27	30	Kedoshim	19:1-20:27
 4	Vayera	18:1-22:24	31	Emor	21:1-24:23
 5	Chayei-Sarah	23:1-25:18	32	Behar	25:1-26:2
 6	Toldot	25:19-28:9	33	Bechukotai	26:3-27:34
 7	Vayetze	28:10-32:2	34	Bamidbar	$Numbers$ 1:1-4:20
 8	Vayishlach	32:3-36:43	35	Naso	4:21-7:89
 9	Vayeshev	37:1-40:23	36	Beha'alotcha	8:1-12:15
10	Miketz	41:1-44:17	37	Shelach	13:1-15:15
11	Vayigash	44:18-47:27	38	Korach	16:1-18:32
12	Vayechi	47:28-50:26	39	Chukat	19:1-22:1
13	Shemot	$Exodus$ 1:1-6:1	40	Balak	22:2-25:9
14	Vaera	6:2-9:35	41	Pinchas	25:10-30:1
15	Bo	10:1-13:16	42	Matot	30:2-32:42
16	Beshalach	13:17-17:16	43	Mase'ei	33:1-36:13
17	Yitro	18:1-20:23	44	Devarim	$Deutronomy$ 1:1-3:22
18	Mishpatim	21:1-24:18	45	Vaetchanan	3:23-7:11
19	Teruma	25:1-27:19	46	Ekev	7:12-11:25
20	Tetzave	27:20-30:10	47	Re'e	11:26-16:17
21	Ki-Tisa	30:11-34:35	48	Shoftim	16:18-21:9
22	Vayakhel	35:1-38:20	49	Ki-Tetze	21:10-25:19
23	Pekudei	38:21-40:38	50	Ki-Tavo	26:1-29:8
24	Vayikra	$Leviticus$ 1:1-5:26	51	Nitzavim	29:9-30:20
25	Tzav	6:1-8:36	52	Vayelech	31:1-31:30
26	Shemini	9:1-11:47	53	Ha'azinu	32:1-32:52
27	Tazri'a	12:1-13:59	54	Vezot-Habracha	33:1-34:12
.TE
.NH
The need for joining.
.PP
The following table summerizes the combinatorics involved in joining portions 
for reading in a single Sabbath.
Each line in the table is dedicated to a different year type,
determined by the length of the year and the week day of
its beginning, 1 Tishri.
.PP
.TS
center box;
c|c c c c c c c
n|n n n n n n n.
	$a$	$b$	$c$	$d$	$e$	$f$	$g$
_
1	353	2	5	50	2	54	6
2	353	7	3	51	4	52	5
3	354	3	7	50	2\(dg	54	6\(dg
4	354	5	2	51	3\(dg	52	4\(dg
5	355	2	7	50	2\(dg	54	6\(dg
6	355	5	3	51	3	52	4
7	355	7	5	51	4	53	6
_
8	383	2	7	54	2\(dg	54	2\(dg
9	383	5	3	55	3	52	0
10	383	7	5	55	4	53	2
11	384	3	2	55	2\(dg	53	0\(dg
12	385	2	2	55	2\(dg	53	0\(dg
13	385	5	5	55	3	53	1
14	385	7	7	55	4\(dg	53	2\(dg
.TE
.
.PP
In addition to the year type, the columns of the table are as follows:
.PP
$a$ is the length of the year, in days. Common years have 353, 354 or 355 days,
and leap years have 383, 384, or 385 days.
.PP
$b$  is the Week day of 1 Tishri.
Since the Hebrew New Year is excluded from being a Sunday, a Wednesday
or a Friday, the possible values are 2, 3, 5 and 7 (representing Sabbath).
.PP
$c$ is the week day of 1 Tishri of the next Year, $a+b( mod 7)$.
.PP
$d$ is the Total number of Sabbaths in the year:
The number of full weeks in $a$, $[a/7]$, plus one if $c<b$.
.PP
$e$ is the number of Sabbaths which fall on a holiday. As the following table
shows, 5 Sabbaths are potential candidates, with 2 more in the
Diaspora.
.TS
center box;
c|l  r|c .
Holiday	Sabbath	in ... 	Condition
_
Rosh-Hashana	1st	Tishri	$b=7$
Yom-Kipur	2nd	\^	$b=5$
Succot	3rd	\^	always
\^	4th	\^	$b=7$
_
Pesach	3rd	Nisan	always
\^	4th\(dg	\^	$c=2$
_
Shavuot	1st\(dg	Sivan	$c=7$
.TE
The Sabbaths marked by a \(dg  
refer to the Diaspora only, because of the additional festival day of the
major holidays observed by Jews there. 
They contribute an additional day to all the values marked by a \(dg of
$e$ and $g$.
.PP
$f$ is the number of portions which are to be read on ordinary Sabbaths.
Out of the 54 portions, the last one, \fIVezot-Habracha\fP,
is read on Simchat-Torah
\- the last day of Succot \- whether it is a Sabbath or not.
Portion 53, \fIHa'azinu\fP, is read in the last ordinary Sabbath before Succot.
Portion 52, \fIVayelech\fP, may be read in Tishri,
if there are two ordinary Sabbaths between Rosh-Hashana and Succot,
which is the case if $b=2$ or $b=3$. It may be read in
Elul, if in the next year there is only one ordinary Sabbath between
Rosh-Hashana and Succot, which is the case if $c=5$ or $c=7$.
Thus, it may be read twice, once, or not at all, making the number
of portions to be 54, 53, or 52 respectively.
.PP
$g$ is the number of Sabbaths in which two portions have to be joined
for reading, $f - ( d - e )$.
.NH
The rules of joining.
.PP
The following table summerizes the rules of joining, according to the year
types listed above. Each column refers to a pair of consecutive portions,
and is set to 1 if they are joined. The sum of the 1's is $g$ above.
The 0\(dg setting means that the portions are read separately in Israel,
jointly in the Diaspora.
.TS
center box;
n|n n n n n n n.
	22	27	29	32	39	42	51
	23	28	30	33	40	43	52
_
1	1	1	1	1	0	1	1
2	1	1	1	1	0	1	0
3	1	1	1	1	0\(dg	1	1
4	1	1	1	0\(dg	0	1	0
5	1	1	1	1	0\(dg	1	1
6	0	1	1	1	0	1	0
7	1	1	1	1	0	1	1
_
8	0	0	0	0	0\(dg	1	1
9	0	0	0	0	0	0	0
10	0	0	0	0	0	1	1
11	0	0	0	0	0	0\(dg	0
12	0	0	0	0	0	0\(dg	0
13	0	0	0	0	0	0	1
14	0	0	0	0	0\(dg	1	1
.TE
.PP
We now elaborate on the theory behind each column.
.PP
\fIVayakhel\fP and \fIPekudey\fP (portions 22, 23) are joined in
every common year, except type 6 ($b=5$ and $c=3$).
This provides for \fIPekudey\fP to be read before 1 Nisan,
which is needed so that \fITzav\fP (portion 24) is read before Pesach.
.PP
\fITazri'a\fP and \fIMetzora\fP (portions 27, 28) are joined in
every common year.
.PP
\fIAcharei-Mot\fP and \fIKedoshim\fP (portions 29, 30) are joined in
every common year.
.PP
\fIBehar\fP and \fIBechukotai\fP (portions 32, 33) are joined in
every common year, except in Israel if $c=2$.
This provides for \fIBechukotai\fP to be read before 1 Sivan,
which is needed so that \fIBamidbar\fP (portion 34) will be read before Shavuot.
(It is said in \fIMegila\fP 32:2 that Ezra ruled that \fIBechukotai\fP will
be read in the Sabbath preceding Shavuot, but later it was moved a week
earlier, so that the curses in this portion will not be read right before
the holiday).
.PP
\fIChukat\fP and \fIBalak\fP (portions 39, 40)  are joined in
the Diaspora, if $c=7$.
.PP
\fIMatot\fP and \fIMase'ei\fP (portions 42, 43) are joined in
every common year, in leap years if $b=7$ or
$c=7$, and in the Diaspora also if $c=2$. This provides for \fIDevarim\fP
(portion 44) to be read before the Fast of Av.
.PP
\fINitzavim\fP and \fIVayelech\fP (portions 51, 52) are joined
if $c=5$ or $c=7$,
when \fIVayelech\fP is read in Elul. This provides for \fINitzavim\fP to be
read in the last Sabbath of the year.
.LM $$Date: 2004-01-16 23:48:24+02 $$
