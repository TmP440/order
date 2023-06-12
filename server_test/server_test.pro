QT += testlib core network sql
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_server.cpp \
    ../server_beta/functions.cpp \
    ../server_beta/singletondb.cpp

DISTFILES += \
    ../server_beta/.qmake.stash \
    ../server_beta/MATH \
    ../server_beta/Makefile \
    ../server_beta/Makefile.Debug \
    ../server_beta/Makefile.Release \
    ../server_beta/UsersD4CAppDataLocalTemptmpylsm0b11

HEADERS += \
    ../server_beta/functions.h \
    ../server_beta/singletondb.h
