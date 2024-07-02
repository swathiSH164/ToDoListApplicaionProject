QT += quick
QT+=sql
CONFIG += c++17
INCLUDEPATH += /home/pthinks1/Qt/5.15.2/gcc_64/include
LIBS +=-L/home/pthinks1/Documents/Swathi/TODOListApplication/googletest-main/build/lib/ -lgtest -lgtest_main -lgmock -lgmock_main

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    TaskListInterface.cpp \
    TaskManagement.cpp \
    TaskManager.cpp \
    TaskModelList.cpp \
    Tests/TestContact.cpp \
        main.cpp \
    TaskModel.cpp \
    DBManager.cpp \
    sqlite-amalgamation-3440000/shell.c \
    sqlite-amalgamation-3440000/sqlite3.c \
    Task.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    TaskListInterface.h \
    TaskManagement.h \
    TaskManager.h \
    TaskModel.h \
    DBManager.h \
    TaskModelList.h \
    Tests/TestContact.h \
    sqlite-amalgamation-3440000/sqlite3.h \
    Task.h \
    sqlite-amalgamation-3440000/sqlite3ext.h

DISTFILES += \
    task.db
