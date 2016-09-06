#-------------------------------------------------
#
# Project created by QtCreator 2016-09-06T21:14:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DigitRecognition
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../NN-XOR/neuronslayer.cpp \
    ../NN-XOR/neuron.cpp \
    ../NN-XOR/neuralnetwork.cpp

HEADERS  += mainwindow.h \
    ../NN-XOR/neuronslayer.h \
    ../NN-XOR/neuron.h \
    ../NN-XOR/neuralnetwork.h

FORMS    += mainwindow.ui
