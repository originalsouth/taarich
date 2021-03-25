# $Id: makefile,v 1.35 2004-04-07 13:30:19+03 rl Exp $
#
#	Author:
#       Dr. Zvi Har'El,
#       Department of Mathematics,
#       Technion, Israel Institute of Technology,
#       Haifa 32000, Israel.
#       E-Mail: rl@math.technion.ac.il

TROFF=groff
NROFF=groff -Tutf8 -P-c -P-b -P-u
CC=gcc
CFLAGS=-Werror -Wall -O -s
PROGS =	luach.c taarich.c gauss.c alef.c \
	luach-bidi.c taarich-bidi.c alef-bidi.c
MSS = luach.man taarich.man gauss.ms reading.ms
all:	luach taarich
bidi:	luach-bidi taarich-bidi

luach:	luach.o gauss.o alef.o
	$(CC) $(CFLAGS) luach.o gauss.o alef.o -o luach

taarich:	taarich.o gauss.o alef.o
	$(CC) $(CFLAGS) taarich.o gauss.o alef.o -o taarich

luach-bidi:	luach-bidi.o gauss.o alef-bidi.o
	$(CC) $(CFLAGS) luach-bidi.o gauss.o alef-bidi.o -o luach-bidi

taarich-bidi:	taarich-bidi.o gauss.o alef-bidi.o
	$(CC) $(CFLAGS) taarich-bidi.o gauss.o alef-bidi.o -o taarich-bidi

cpio:	gauss.rcs.gz gauss.cpio.gz

gauss.rcs.gz:	RCS
	find RCS -print | cpio -voc | gzip -9 -v >$@

gauss.cpio.gz:	$(PROGS) $(MSS) makefile
	find $(PROGS) $(MSS) makefile -print | cpio -voc | gzip -9 -v >$@

doc:	luach.ps luach.txt taarich.ps taarich.txt gauss.ps gauss.txt \
	reading.txt reading.ps

luach.ps:	luach.man
	$(TROFF) -tman $? >$@

luach.txt:	luach.man
	$(NROFF) -tman $? >$@

taarich.ps:	taarich.man
	$(TROFF) -man $? >$@

taarich.txt:	taarich.man
	$(NROFF) -man $? >$@

gauss.ps:	gauss.ms
	$(TROFF) -tems $? >$@

gauss.txt:	gauss.ms
	$(NROFF) -tems $? >$@

reading.ps:	reading.ms
	$(TROFF) -tems $? >$@

reading.txt:	reading.ms
	$(NROFF) -tems $? >$@

clean:
	rm -f *.o
