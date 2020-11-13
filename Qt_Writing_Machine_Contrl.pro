#-------------------------------------------------
#
# Project created by QtCreator 2018-12-13T19:49:36
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serialport
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        form.cpp \
        grblconfig.cpp \
        main.cpp \
        mainwindow.cpp \
        midi.cpp \
        paintrectangle.cpp \
        paintyuan.cpp \
        src/Binasc.cpp \
        src/MidiEvent.cpp \
        src/MidiEventList.cpp \
        src/MidiFile.cpp \
        src/MidiMessage.cpp \
        src/Options.cpp \
        writepaint.cpp \
        writepaints.cpp \
        xycontrol.cpp

HEADERS += \
        form.h \
        grblconfig.h \
        include/Binasc.h \
        include/MidiEvent.h \
        include/MidiEventList.h \
        include/MidiFile.h \
        include/MidiMessage.h \
        include/Options.h \
        mainwindow.h \
        midi.h \
        paintrectangle.h \
        paintyuan.h \
        writepaint.h \
        writepaints.h \
        xycontrol.h

FORMS += \
        form.ui \
        grblconfig.ui \
        mainwindow.ui \
        paintrectangle.ui \
        paintyuan.ui \
        writepaint.ui \
        writepaints.ui \
        xycontrol.ui

RESOURCES += \
    image.qrc
RC_ICONS = Lunyeelogo.ico
