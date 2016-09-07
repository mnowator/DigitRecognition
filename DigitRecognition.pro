#-------------------------------------------------
#
# Project created by QtCreator 2016-09-06T21:14:02
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DigitRecognition
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    neuron.cpp \
    neuronslayer.cpp \
    neuralnetwork.cpp \
    scribbler.cpp

HEADERS  += mainwindow.h \
    neuron.h \
    neuronslayer.h \
    neuralnetwork.h \
    scribbler.h

FORMS    += mainwindow.ui
