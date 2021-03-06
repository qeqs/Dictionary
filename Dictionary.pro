#-------------------------------------------------
#
# Project created by QtCreator 2017-04-08T11:09:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dictionary
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    dictionary.cpp \
    xmlparser.cpp \
    filehelper.cpp \
    wordlinker.cpp \
    initializer.cpp

HEADERS  += mainwindow.h \
    dictionary.h \
    xmlparser.h \
    filehelper.h \
    wordlinker.h \
    constants.h \
    initializer.h

FORMS    += mainwindow.ui

win32: LIBS += -L$$PWD/../../Desktop/tinyxml2-4.0.1/tinyxml2/bin/x64-Debug-Dll -ltinyxml2

INCLUDEPATH += $$PWD/../../Desktop/tinyxml2-4.0.1
DEPENDPATH += $$PWD/../../Desktop/tinyxml2-4.0.1

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../Desktop/tinyxml2-4.0.1/tinyxml2/bin/x64-Debug-Dll/tinyxml2.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../Desktop/tinyxml2-4.0.1/tinyxml2/bin/x64-Debug-Dll/libtinyxml2.a
