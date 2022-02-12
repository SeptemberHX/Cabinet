QT       += core gui webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    items/PreviewMDDoc.cpp \
    main.cpp \
    mainwindow.cpp \
    widgets/CabinetMainWidget.cpp \
    widgets/FileListWidget.cpp \
    widgets/PreviewPage.cpp \
    widgets/todo/TodoItemWidget.cpp \
    widgets/todo/TodoPage.cpp

HEADERS += \
    items/PreviewMDDoc.h \
    mainwindow.h \
    widgets/CabinetMainWidget.h \
    widgets/FileListWidget.h \
    widgets/PreviewPage.h \
    widgets/todo/TodoItemWidget.h \
    widgets/todo/TodoPage.h

FORMS += \
    mainwindow.ui \
    widgets/CabinetMainWidget.ui \
    widgets/FileListWidget.ui \
    widgets/todo/TodoItemWidget.ui \
    widgets/todo/TodoPage.ui

TRANSLATIONS += \
    Cabinet_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(qmarkdowntextedit/qmarkdowntextedit.pri)

RESOURCES += \
    resources.qrc
