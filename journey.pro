QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller.cpp \
    editportefoliodialog.cpp \
    edittradedialog.cpp \
    main.cpp \
    mainwindow.cpp \
    portefolio.cpp \
    portefoliolistview.cpp \
    portefoliomodel.cpp \
    portefolioview.cpp \
    trade.cpp \
    trademodel.cpp \
    tradeview.cpp

HEADERS += \
    controller.h \
    editportefoliodialog.h \
    edittradedialog.h \
    portefolio.h \
    portefoliolistview.h \
    portefoliomodel.h \
    portefolioview.h \
    trade.h \
    trademodel.h \
    mainwindow.h \
    tradeview.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    ressources.qrc
