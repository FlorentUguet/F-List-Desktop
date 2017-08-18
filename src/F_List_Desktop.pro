#-------------------------------------------------
#
# Project created by QtCreator 2017-08-18T11:04:02
#
#-------------------------------------------------

QT       += core gui websockets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = F_List_Desktop
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


SOURCES += \
        main.cpp \
        widget.cpp \
    commands/fcommand.cpp \
    commands/aoc.cpp \
    commands/acb.cpp \
    commands/awc.cpp \
    commands/bro.cpp \
    commands/cbl.cpp \
    controller/fclient.cpp \
    ui/fserverdebugwidget.cpp \
    commands/idn.cpp \
    controller/floginclient.cpp \
    ui/floginwidget.cpp \
    tests.cpp \
    utils/jsonutils.cpp \
    jsoncpp/jsoncpp.cpp

HEADERS += \
        widget.h \
    commands/fcommand.h \
    commands/aoc.h \
    commands/acb.h \
    commands/awc.h \
    commands/bro.h \
    commands/cbl.h \
    controller/fclient.h \
    ui/fserverdebugwidget.h \
    commands/idn.h \
    defines.h \
    controller/floginclient.h \
    ui/floginwidget.h \
    tests.h \
    utils/jsonutils.h \
    jsoncpp/json/json.h \
    jsoncpp/json/json-forwards.h

DISTFILES += \
    json/sconscript
