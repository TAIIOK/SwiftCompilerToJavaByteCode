QT += core
QT -= gui

CONFIG += c++11

TARGET = swiftcomp
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    lex.yy.c \
    swift.tab.c \
    main.cpp \
    semantic.cpp

HEADERS += \
    semantic_tables.h \
    swift.y \
    swift.yy \
    tree_nodes.h \
    tree_nodes_funcs.h \
    tree_print.h \
    swift.tab.h \
    semantic.h \
    semantic_structs.h
