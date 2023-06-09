QT += testlib
QT += sql
QT += network
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_ham.cpp \
    ../order-beta/functions.cpp \
    ../order-beta/mytcpserver.cpp \
    ../order-beta/singletondb.cpp

HEADERS += \
    ../order-beta/functions.h \
    ../order-beta/mytcpserver.h \
    ../order-beta/singletondb.h
