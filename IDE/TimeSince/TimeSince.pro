#-------------------------------------------------
#
# Project created by QtCreator 2014-08-30T11:31:21
#
#-------------------------------------------------

QT       -= gui

TARGET = TimeSince
TEMPLATE = lib
CONFIG += staticlib \
			c++11

DESTDIR = ../Bin/

SOURCES += ../../Src/TimeSince/Entry.cpp \
    ../../Src/TimeSince/EntryManager.cpp

HEADERS += ../../Src/TimeSince/Entry.h \
	../../Src/TimeSince/EntryManager.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
