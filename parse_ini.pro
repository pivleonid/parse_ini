TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "gtest/include"
INCLUDEPATH += "gtest"

SOURCES += \
        CIni.cpp \
        CString.cpp \
        main.cpp \
        gtest/src/gtest-all.cc \
        gtest/src/gtest-death-test.cc \
        gtest/src/gtest-filepath.cc \
        gtest/src/gtest-matchers.cc \
        gtest/src/gtest-port.cc \
        gtest/src/gtest-printers.cc \
        gtest/src/gtest-test-part.cc \
        gtest/src/gtest-typed-test.cc \
        gtest/src/gtest.cc

HEADERS += \
    CIni.h \
    CIni_test.h \
    CMap.h \
    CMap_test.h \
    CString.h \
    CString_test.h \
    CVector.h \
    CVector_test.h

QMAKE_CXXFLAGS += -O0
QMAKE_CXXFLAGS_WARN_ON += -Wall
