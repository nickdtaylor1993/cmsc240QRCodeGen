#############################################################################
# Makefile for building: FINAL_240_ECHO
# Generated by qmake (2.01a) (Qt 4.8.4) on: Sun Dec 15 10:44:31 2013
# Project:  FINAL_240_ECHO.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -o Makefile FINAL_240_ECHO.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = AlphaNumEncoder.cpp \
		APLT.cpp \
		CC_Table.cpp \
		ECC_Table.cpp \
		ECCgenerator.cpp \
		Encoder.cpp \
		Interleaver.cpp \
		ModuleMatrix.cpp \
		NumEncoder.cpp \
		Parser.cpp \
		QRCodeGenerator.cpp \
		qrgen.cpp \
		Rem_Table.cpp \
		Viewer.cpp 
OBJECTS       = AlphaNumEncoder.o \
		APLT.o \
		CC_Table.o \
		ECC_Table.o \
		ECCgenerator.o \
		Encoder.o \
		Interleaver.o \
		ModuleMatrix.o \
		NumEncoder.o \
		Parser.o \
		QRCodeGenerator.o \
		qrgen.o \
		Rem_Table.o \
		Viewer.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		FINAL_240_ECHO.pro
QMAKE_TARGET  = FINAL_240_ECHO
DESTDIR       = 
TARGET        = FINAL_240_ECHO

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: FINAL_240_ECHO.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile FINAL_240_ECHO.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile FINAL_240_ECHO.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/FINAL_240_ECHO1.0.0 || $(MKDIR) .tmp/FINAL_240_ECHO1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/FINAL_240_ECHO1.0.0/ && $(COPY_FILE) --parents AlphaNumEncoder.h APLT.h CC_Table.h ECC_Table.h ECCgenerator.h Encoder.h Interleaver.h ModuleMatrix.h NumEncoder.h Parser.h QRCode.h QRCodeGenerator.h Rem_Table.h Viewer.h .tmp/FINAL_240_ECHO1.0.0/ && $(COPY_FILE) --parents AlphaNumEncoder.cpp APLT.cpp CC_Table.cpp ECC_Table.cpp ECCgenerator.cpp Encoder.cpp Interleaver.cpp ModuleMatrix.cpp NumEncoder.cpp Parser.cpp QRCodeGenerator.cpp qrgen.cpp Rem_Table.cpp Viewer.cpp .tmp/FINAL_240_ECHO1.0.0/ && (cd `dirname .tmp/FINAL_240_ECHO1.0.0` && $(TAR) FINAL_240_ECHO1.0.0.tar FINAL_240_ECHO1.0.0 && $(COMPRESS) FINAL_240_ECHO1.0.0.tar) && $(MOVE) `dirname .tmp/FINAL_240_ECHO1.0.0`/FINAL_240_ECHO1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/FINAL_240_ECHO1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

AlphaNumEncoder.o: AlphaNumEncoder.cpp AlphaNumEncoder.h \
		Encoder.h \
		ECC_Table.h \
		Parser.h \
		CC_Table.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AlphaNumEncoder.o AlphaNumEncoder.cpp

APLT.o: APLT.cpp APLT.h \
		ECC_Table.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o APLT.o APLT.cpp

CC_Table.o: CC_Table.cpp CC_Table.h \
		ECC_Table.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CC_Table.o CC_Table.cpp

ECC_Table.o: ECC_Table.cpp ECC_Table.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ECC_Table.o ECC_Table.cpp

ECCgenerator.o: ECCgenerator.cpp ECCgenerator.h \
		ECC_Table.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ECCgenerator.o ECCgenerator.cpp

Encoder.o: Encoder.cpp Encoder.h \
		ECC_Table.h \
		Parser.h \
		CC_Table.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Encoder.o Encoder.cpp

Interleaver.o: Interleaver.cpp Interleaver.h \
		ECC_Table.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Interleaver.o Interleaver.cpp

ModuleMatrix.o: ModuleMatrix.cpp ModuleMatrix.h \
		APLT.h \
		ECC_Table.h \
		QRCode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ModuleMatrix.o ModuleMatrix.cpp

NumEncoder.o: NumEncoder.cpp NumEncoder.h \
		Encoder.h \
		ECC_Table.h \
		Parser.h \
		CC_Table.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o NumEncoder.o NumEncoder.cpp

Parser.o: Parser.cpp Encoder.h \
		ECC_Table.h \
		Parser.h \
		CC_Table.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Parser.o Parser.cpp

QRCodeGenerator.o: QRCodeGenerator.cpp QRCodeGenerator.h \
		ECC_Table.h \
		Encoder.h \
		Parser.h \
		CC_Table.h \
		AlphaNumEncoder.h \
		NumEncoder.h \
		ECCgenerator.h \
		Interleaver.h \
		QRCode.h \
		Rem_Table.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o QRCodeGenerator.o QRCodeGenerator.cpp

qrgen.o: qrgen.cpp ECC_Table.h \
		Parser.h \
		QRCodeGenerator.h \
		Encoder.h \
		CC_Table.h \
		AlphaNumEncoder.h \
		NumEncoder.h \
		ECCgenerator.h \
		Interleaver.h \
		QRCode.h \
		Rem_Table.h \
		Viewer.h \
		ModuleMatrix.h \
		APLT.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrgen.o qrgen.cpp

Rem_Table.o: Rem_Table.cpp Rem_Table.h \
		ECC_Table.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Rem_Table.o Rem_Table.cpp

Viewer.o: Viewer.cpp Viewer.h \
		ModuleMatrix.h \
		APLT.h \
		ECC_Table.h \
		QRCode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Viewer.o Viewer.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

