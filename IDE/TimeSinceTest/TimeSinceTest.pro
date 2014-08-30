#-------------------------------------------------
#
# Project created by QtCreator 2014-08-30T11:32:36
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_timesincetesttest
CONFIG   += console \
			c++11
CONFIG   -= app_bundle

TEMPLATE = app

DESTDIR = ../Bin/

SOURCES += tst_timesincetesttest.cpp \
    ../../Src/TimeSinceTest/TimeSinceTest.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

INCLUDEPATH += ../../Src/

HEADERS += \
    ../../Src/TimeSinceTest/Test_Entry.h \
    ../../Src/TimeSinceTest/Test_EntryManager.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Bin/ -lTimeSince
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Bin/ -lTimeSinced
else:unix: LIBS += -L$$PWD/../../Bin/ -lTimeSince

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Bin/libTimeSince.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Bin/libTimeSinced.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Bin/TimeSince.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Bin/TimeSinced.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../Bin/libTimeSince.a
