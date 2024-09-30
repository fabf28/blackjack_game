TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        Card.cpp \
        Hand.cpp \
        Deck.cpp \
        GenericPlayer.cpp \
        Player.cpp \
        House.cpp \
        Game.cpp

HEADERS += \
        Card.h \
        Hand.h \
        Deck.h \
        GenericPlayer.h \
        Player.h \
        House.h \
        Game.h
