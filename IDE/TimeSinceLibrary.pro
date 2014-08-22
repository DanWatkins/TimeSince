#-------------------------------------------------
#
# Project created by QtCreator 2014-08-21T21:22:05
#
#-------------------------------------------------

QT       -= gui

TARGET = TimeSinceLibrary
TEMPLATE = lib

DEFINES += TIMESINCELIBRARY_LIBRARY

SOURCES += \
    ../Src/TimeSinceLibrary/TimeSinceLibrary.cpp

HEADERS += \
    ../Src/TimeSinceLibrary/TimeSinceLibrary.h \
    ../Src/TimeSinceLibrary/timesincelibrary_global.h

DESTDIR = ../../Lib/

unix {
    target.path = /usr/lib
    INSTALLS += target
}
