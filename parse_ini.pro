TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "gtest/include"
INCLUDEPATH += "gtest"

SOURCES += \
        CString.cpp \
        CVector.cpp \
        main.cpp \
        gtest/src/gtest-all.cc \
        gtest/src/gtest-death-test.cc \
        gtest/src/gtest-filepath.cc \
        gtest/src/gtest-matchers.cc \
        gtest/src/gtest-port.cc \
        gtest/src/gtest-printers.cc \
        gtest/src/gtest-test-part.cc \
        gtest/src/gtest-typed-test.cc \
        gtest/src/gtest.cc \
        tree_abl.cpp

HEADERS += \
    CString.h \
    CVector.h \
    tree_abl.h
