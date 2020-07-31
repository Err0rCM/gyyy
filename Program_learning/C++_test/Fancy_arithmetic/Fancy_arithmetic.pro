TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    Affine_crypto.h \
    Caesar_crypto.h \
    Maths.h \
    Replacement_crypto.h \
    Virginia_crypto.h
