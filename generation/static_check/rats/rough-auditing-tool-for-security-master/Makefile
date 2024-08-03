EXE_EXTN	=
OBJ_EXTN	= .o
LEXER		= lex.yyc lex.yyp lex.yyperl lex.yyphp lex.yyruby

LEX		= : 
CC		= gcc 

prefix		= /usr/local
exec_prefix	= ${prefix}
BINDIR		= ${exec_prefix}/bin
LIBDIR		= ${exec_prefix}/lib
MANDIR		= ${prefix}/man
SHAREDIR	= ${prefix}/share
INSTALL		= /usr/bin/install -c
INSTALL_PROGRAM	= ${INSTALL}
INSTALL_DATA	= ${INSTALL} -m 644
INSTALL_SCRIPT	= ${INSTALL}

CFLAGS		= -Wall -g -g -O2 -I/usr/local/include -DPACKAGE_NAME=\"\" -DPACKAGE_TARNAME=\"\" -DPACKAGE_VERSION=\"\" -DPACKAGE_STRING=\"\" -DPACKAGE_BUGREPORT=\"\" -DHAVE_LIBEXPAT=1 -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DHAVE_EXPAT_H=1  -DDATADIR=\"$(SHAREDIR)\"
LDFLAGS		= -Wall -g  -L/usr/local/lib
LEXFLAGS	= -F -8 

BIN		= rats
OBJ		= engine$(OBJ_EXTN) \
		  lex.yyc$(OBJ_EXTN) \
		  lex.yyp$(OBJ_EXTN) \
		  lex.yyperl$(OBJ_EXTN) \
		  lex.yyphp$(OBJ_EXTN) \
		  lex.yyruby$(OBJ_EXTN) \
		  hash$(OBJ_EXTN) \
		  kazhash$(OBJ_EXTN) \
		  main$(OBJ_EXTN) \
		  report$(OBJ_EXTN) \
		  vuln_db$(OBJ_EXTN)\
		  getopt$(OBJ_EXTN)
LIBS		= -lexpat 
SOURCES		= $(OBJ:$(OBJ_EXTN)=.c)

$(BIN):	$(OBJ)
	$(CC) $(LDFLAGS) -o $(BIN) $(OBJ) $(LIBS)

%$(OBJ_EXTN):	%.c
	$(CC) $(CFLAGS) -o $@ -c $<

lex:	c-lex.l python-lex.l perl-lex.l ruby-lex.l
	$(LEX) $(LEXFLAGS) -Pyyc c-lex.l
	$(LEX) $(LEXFLAGS) -Pyyp python-lex.l
	$(LEX) $(LEXFLAGS) -Pyyperl perl-lex.l
	$(LEX) $(LEXFLAGS) -Pyyphp  php-lex.l       
	$(LEX) $(LEXFLAGS) -Pyyruby ruby-lex.l     

install:	$(BIN)
	./mkinstalldirs $(BINDIR) $(LIBDIR) $(MANDIR) $(MANDIR)/man1 $(SHAREDIR)
	$(INSTALL_PROGRAM) $(BIN) $(BINDIR)
	$(INSTALL_DATA) rats-python.xml $(SHAREDIR)
	$(INSTALL_DATA) rats-c.xml $(SHAREDIR)
	$(INSTALL_DATA) rats-perl.xml $(SHAREDIR)
	$(INSTALL_DATA) rats-php.xml $(SHAREDIR)
	$(INSTALL_DATA) rats-ruby.xml $(SHAREDIR)
	$(INSTALL_DATA) rats-openssl.xml $(SHAREDIR)
	$(INSTALL_DATA) rats.1	$(MANDIR)/man1

clean:
	rm -f $(OBJ) *~ $(BIN) core

distclean:	clean
	rm -f config.log config.status config.cache Makefile

major:	distclean lex
	echo -n '#define VERSION_MAJOR ' > version.tmp
	expr `head -n1 version.h | cut -d ' ' -f 3` + 1 >> version.tmp
	echo '#define VERSION_MINOR 0' >> version.tmp
	mv -f version.tmp version.h
	cvs commit -m "Incremented major version number" version.h

minor:	distclean lex
	head -n1 version.h > version.tmp
	echo -n '#define VERSION_MINOR ' >> version.tmp
	expr `tail -n1 version.h | cut -d ' ' -f 3` + 1 >> version.tmp
	mv -f version.tmp version.h
	cvs commit -m "Incremented minor version number" version.h

# vim: noexpandtab:ts=8:sw=8:sts=0
