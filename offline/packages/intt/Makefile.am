##############################################
# please add new classes in alphabetical order

AUTOMAKE_OPTIONS = foreign

AM_CPPFLAGS = \
  -I$(includedir) \
  -I$(OFFLINE_MAIN)/include  \
  -isystem$(ROOTSYS)/include

AM_LDFLAGS = \
  -L$(libdir) \
  -L$(ROOTSYS)/lib \
  -L$(OFFLINE_MAIN)/lib

if USE_ONLINE

lib_LTLIBRARIES = \
  libintt.la 

pkginclude_HEADERS = \
  InttFelixMap.h \
  InttMapping.h

libintt_la_SOURCES = \
  InttFelixMap.cc \
  InttMapping.cc

else

lib_LTLIBRARIES = \
  libintt_io.la \
  libintt.la 

pkginclude_HEADERS = \
  InttClusterizer.h \
  InttCombinedRawDataDecoder.h \
  InttDeadMapHelper.h \
  InttFelixMap.h \
  InttFelixMapObsolete.h \
  InttMapping.h \
  InttRawDataConverter.h \
  InttRawDataDecoder.h \
  CylinderGeomIntt.h

ROOTDICTS = \
  CylinderGeomIntt_Dict.cc

pcmdir = $(libdir)
nobase_dist_pcm_DATA = \
  CylinderGeomIntt_Dict_rdict.pcm

# sources for intt library
libintt_la_SOURCES = \
  InttClusterizer.cc \
  InttCombinedRawDataDecoder.cc \
  InttDeadMapHelper.cc \
  InttFelixMap.cc \
  InttFelixMapObsolete.cc \
  InttMapping.cc \
  InttRawDataConverter.cc \
  InttRawDataDecoder.cc

libintt_la_LIBADD = \
  libintt_io.la \
  -lCLHEP \
  -lphg4hit \
  -lSubsysReco

# sources for io library
libintt_io_la_SOURCES = \
  $(ROOTDICTS) \
  CylinderGeomIntt.cc

libintt_io_la_LIBADD = \
  -lCLHEP \
  -lfun4allraw \
  -lg4detectors_io \
  -lphool \
  -ltrack_io \
  -ltrackbase_historic_io

endif

# Rule for generating table CINT dictionaries.
%_Dict.cc: %.h %LinkDef.h
	rootcint -f $@ @CINTDEFS@ $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $^

#just to get the dependency
%_Dict_rdict.pcm: %_Dict.cc ;


################################################
# linking tests

BUILT_SOURCES = testexternals.cc

noinst_PROGRAMS = \
  testexternals_intt_io \
  testexternals_intt

testexternals_intt_io_SOURCES = testexternals.cc
testexternals_intt_io_LDADD = libintt_io.la

testexternals_intt_SOURCES = testexternals.cc
testexternals_intt_LDADD = libintt.la

testexternals.cc:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

################################################

clean-local:
	rm -f *Dict* $(BUILT_SOURCES) *.pcm
