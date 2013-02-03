#-------------------------------------------------
#
# Project created by QtCreator 2012-12-28T14:25:47
#
#-------------------------------------------------

TARGET = Charms
TEMPLATE = lib

DEFINES += CHARMS_LIBRARY

SOURCES += chartplane.cpp \
    chart.cpp \
    parser/zmienna.cpp \
    parser/wyrazeniejednoargumentowe.cpp \
    parser/stalaliczbowa.cpp \
    parser/split.cpp \
    parser/sinus.cpp \
    parser/potega.cpp \
    parser/parser.cpp \
    parser/odejmowanie.cpp \
    parser/mnozenie.cpp \
    parser/logarytmnaturalny.cpp \
    parser/dzielenie.cpp \
    parser/dodawanie.cpp \
    parser/cosinus.cpp \
    parser/wyrazeniedwuargumentowe.cpp

HEADERS += chartplane.h\
        Charms_global.h \
    chart.h \
    parser/zmienna.h \
    parser/wyrazeniejednoargumentowe.h \
    parser/wyrazenie.h \
    parser/wyrazenia.h \
    parser/stalaliczbowa.h \
    parser/split.h \
    parser/sinus.h \
    parser/potega.h \
    parser/parser.h \
    parser/odejmowanie.h \
    parser/mnozenie.h \
    parser/logarytmnaturalny.h \
    parser/dzielenie.h \
    parser/dodawanie.h \
    parser/cosinus.h \
    parser/wyrazeniedwuargumentowe.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
