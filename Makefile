#############################################################################
# Makefile for building: QtPersons
# Generated by qmake (3.0) (Qt 5.3.2)
# Project:  QtPersons.pro
# Template: app
# Command: /Users/kthorri/Qt/5.3/clang_64/bin/qmake -spec macx-clang CONFIG+=debug CONFIG+=x86_64 CONFIG+=x86_64 -o Makefile QtPersons.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = /Applications/Forritun/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang
CXX           = /Applications/Forritun/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++
DEFINES       = -DQT_CORE_LIB
CFLAGS        = -pipe -g -isysroot /Applications/Forritun/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk -mmacosx-version-min=10.6 -Wall -W -fPIE $(DEFINES)
CXXFLAGS      = -pipe -g -isysroot /Applications/Forritun/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk -mmacosx-version-min=10.6 -Wall -W -fPIE $(DEFINES)
INCPATH       = -I../../../../Qt/5.3/clang_64/mkspecs/macx-clang -I. -I../../../../Qt/5.3/clang_64/lib/QtCore.framework/Versions/5/Headers -I. -F/Users/kthorri/Qt/5.3/clang_64/lib
LINK          = /Applications/Forritun/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++
LFLAGS        = -headerpad_max_install_names -Wl,-syslibroot,/Applications/Forritun/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk -mmacosx-version-min=10.6
LIBS          = $(SUBLIBS) -F/Users/kthorri/Qt/5.3/clang_64/lib -framework QtCore 
AR            = /Applications/Forritun/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ar cq
RANLIB        = /Applications/Forritun/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib -s
QMAKE         = /Users/kthorri/Qt/5.3/clang_64/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		person.cpp \
		consoleui.cpp \
		personrepository.cpp \
		search.cpp \
		service.cpp \
		sort.cpp 
OBJECTS       = main.o \
		person.o \
		consoleui.o \
		personrepository.o \
		search.o \
		service.o \
		sort.o
DIST          = ../../../../Qt/5.3/clang_64/mkspecs/features/spec_pre.prf \
		../../../../Qt/5.3/clang_64/mkspecs/qdevice.pri \
		../../../../Qt/5.3/clang_64/mkspecs/features/device_config.prf \
		../../../../Qt/5.3/clang_64/mkspecs/common/shell-unix.conf \
		../../../../Qt/5.3/clang_64/mkspecs/common/unix.conf \
		../../../../Qt/5.3/clang_64/mkspecs/common/mac.conf \
		../../../../Qt/5.3/clang_64/mkspecs/common/macx.conf \
		../../../../Qt/5.3/clang_64/mkspecs/common/gcc-base.conf \
		../../../../Qt/5.3/clang_64/mkspecs/common/gcc-base-mac.conf \
		../../../../Qt/5.3/clang_64/mkspecs/common/clang.conf \
		../../../../Qt/5.3/clang_64/mkspecs/common/clang-mac.conf \
		../../../../Qt/5.3/clang_64/mkspecs/qconfig.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_bluetooth.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_clucene_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_core.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_core_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_dbus.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_declarative.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_declarative_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_designer.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_designer_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_enginio.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_enginio_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_gui.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_gui_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_help.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_help_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_macextras.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_macextras_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_multimedia.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_network.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_network_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_nfc.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_nfc_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_opengl.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_openglextensions.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_positioning.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_positioning_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qml.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qml_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_quick.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_quick_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_script.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_script_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_scripttools.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_sensors.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_sensors_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_serialport.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_serialport_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_sql.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_sql_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_svg.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_svg_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_testlib.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_uitools.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_webkit.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_webkit_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_websockets.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_websockets_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_widgets.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_xml.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_xml_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/features/qt_functions.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/qt_config.prf \
		../../../../Qt/5.3/clang_64/mkspecs/macx-clang/qmake.conf \
		../../../../Qt/5.3/clang_64/mkspecs/features/spec_post.prf \
		.qmake.stash \
		../../../../Qt/5.3/clang_64/mkspecs/features/exclusive_builds.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/default_pre.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/mac/default_pre.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/resolve_config.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/default_post.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/mac/sdk.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/mac/default_post.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/mac/objective_c.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/warn_on.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/qt.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/resources.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/moc.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/unix/thread.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/mac/rez.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/testcase_targets.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/exceptions.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/yacc.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/lex.prf \
		QtPersons.pro main.cpp \
		person.cpp \
		consoleui.cpp \
		personrepository.cpp \
		search.cpp \
		service.cpp \
		sort.cpp
QMAKE_TARGET  = QtPersons
DESTDIR       = #avoid trailing-slash linebreak
TARGET        = QtPersons

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-g \
		-isysroot \
		/Applications/Forritun/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk \
		-mmacosx-version-min=10.6 \
		-Wall \
		-W



first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: QtPersons.pro ../../../../Qt/5.3/clang_64/mkspecs/macx-clang/qmake.conf ../../../../Qt/5.3/clang_64/mkspecs/features/spec_pre.prf \
		../../../../Qt/5.3/clang_64/mkspecs/qdevice.pri \
		../../../../Qt/5.3/clang_64/mkspecs/features/device_config.prf \
		../../../../Qt/5.3/clang_64/mkspecs/common/shell-unix.conf \
		../../../../Qt/5.3/clang_64/mkspecs/common/unix.conf \
		../../../../Qt/5.3/clang_64/mkspecs/common/mac.conf \
		../../../../Qt/5.3/clang_64/mkspecs/common/macx.conf \
		../../../../Qt/5.3/clang_64/mkspecs/common/gcc-base.conf \
		../../../../Qt/5.3/clang_64/mkspecs/common/gcc-base-mac.conf \
		../../../../Qt/5.3/clang_64/mkspecs/common/clang.conf \
		../../../../Qt/5.3/clang_64/mkspecs/common/clang-mac.conf \
		../../../../Qt/5.3/clang_64/mkspecs/qconfig.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_bluetooth.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_clucene_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_core.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_core_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_dbus.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_declarative.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_declarative_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_designer.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_designer_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_enginio.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_enginio_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_gui.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_gui_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_help.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_help_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_macextras.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_macextras_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_multimedia.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_network.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_network_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_nfc.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_nfc_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_opengl.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_openglextensions.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_positioning.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_positioning_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qml.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qml_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_quick.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_quick_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_script.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_script_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_scripttools.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_sensors.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_sensors_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_serialport.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_serialport_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_sql.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_sql_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_svg.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_svg_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_testlib.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_uitools.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_webkit.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_webkit_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_websockets.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_websockets_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_widgets.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_xml.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_xml_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../../../Qt/5.3/clang_64/mkspecs/features/qt_functions.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/qt_config.prf \
		../../../../Qt/5.3/clang_64/mkspecs/macx-clang/qmake.conf \
		../../../../Qt/5.3/clang_64/mkspecs/features/spec_post.prf \
		.qmake.stash \
		../../../../Qt/5.3/clang_64/mkspecs/features/exclusive_builds.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/default_pre.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/mac/default_pre.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/resolve_config.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/default_post.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/mac/sdk.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/mac/default_post.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/mac/objective_c.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/warn_on.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/qt.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/resources.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/moc.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/unix/thread.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/mac/rez.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/testcase_targets.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/exceptions.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/yacc.prf \
		../../../../Qt/5.3/clang_64/mkspecs/features/lex.prf \
		QtPersons.pro \
		/Users/kthorri/Qt/5.3/clang_64/lib/QtCore.framework/QtCore.prl
	$(QMAKE) -spec macx-clang CONFIG+=debug CONFIG+=x86_64 CONFIG+=x86_64 -o Makefile QtPersons.pro
../../../../Qt/5.3/clang_64/mkspecs/features/spec_pre.prf:
../../../../Qt/5.3/clang_64/mkspecs/qdevice.pri:
../../../../Qt/5.3/clang_64/mkspecs/features/device_config.prf:
../../../../Qt/5.3/clang_64/mkspecs/common/shell-unix.conf:
../../../../Qt/5.3/clang_64/mkspecs/common/unix.conf:
../../../../Qt/5.3/clang_64/mkspecs/common/mac.conf:
../../../../Qt/5.3/clang_64/mkspecs/common/macx.conf:
../../../../Qt/5.3/clang_64/mkspecs/common/gcc-base.conf:
../../../../Qt/5.3/clang_64/mkspecs/common/gcc-base-mac.conf:
../../../../Qt/5.3/clang_64/mkspecs/common/clang.conf:
../../../../Qt/5.3/clang_64/mkspecs/common/clang-mac.conf:
../../../../Qt/5.3/clang_64/mkspecs/qconfig.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_bluetooth.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_bluetooth_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_bootstrap_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_clucene_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_concurrent.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_concurrent_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_core.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_core_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_dbus.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_dbus_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_declarative.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_declarative_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_designer.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_designer_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_designercomponents_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_enginio.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_enginio_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_gui.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_gui_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_help.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_help_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_macextras.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_macextras_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_multimedia.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_multimedia_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_multimediawidgets.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_network.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_network_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_nfc.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_nfc_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_opengl.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_opengl_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_openglextensions.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_openglextensions_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_platformsupport_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_positioning.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_positioning_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_printsupport.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_printsupport_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qml.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qml_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qmldevtools_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qmltest.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qmltest_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_quick.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_quick_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_quickparticles_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_quickwidgets.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_quickwidgets_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_script.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_script_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_scripttools.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_scripttools_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_sensors.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_sensors_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_serialport.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_serialport_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_sql.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_sql_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_svg.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_svg_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_testlib.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_testlib_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_uitools.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_uitools_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_webkit.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_webkit_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_webkitwidgets.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_websockets.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_websockets_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_widgets.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_widgets_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_xml.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_xml_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_xmlpatterns.pri:
../../../../Qt/5.3/clang_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
../../../../Qt/5.3/clang_64/mkspecs/features/qt_functions.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/qt_config.prf:
../../../../Qt/5.3/clang_64/mkspecs/macx-clang/qmake.conf:
../../../../Qt/5.3/clang_64/mkspecs/features/spec_post.prf:
.qmake.stash:
../../../../Qt/5.3/clang_64/mkspecs/features/exclusive_builds.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/default_pre.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/mac/default_pre.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/resolve_config.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/default_post.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/mac/sdk.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/mac/default_post.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/mac/objective_c.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/warn_on.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/qt.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/resources.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/moc.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/unix/thread.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/mac/rez.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/testcase_targets.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/exceptions.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/yacc.prf:
../../../../Qt/5.3/clang_64/mkspecs/features/lex.prf:
QtPersons.pro:
/Users/kthorri/Qt/5.3/clang_64/lib/QtCore.framework/QtCore.prl:
qmake: FORCE
	@$(QMAKE) -spec macx-clang CONFIG+=debug CONFIG+=x86_64 CONFIG+=x86_64 -o Makefile QtPersons.pro

qmake_all: FORCE

dist: 
	@test -d .tmp/QtPersons1.0.0 || mkdir -p .tmp/QtPersons1.0.0
	$(COPY_FILE) --parents $(DIST) .tmp/QtPersons1.0.0/ && $(COPY_FILE) --parents person.h consoleui.h personrepository.h search.h service.h sort.h .tmp/QtPersons1.0.0/ && $(COPY_FILE) --parents main.cpp person.cpp consoleui.cpp personrepository.cpp search.cpp service.cpp sort.cpp .tmp/QtPersons1.0.0/ && (cd `dirname .tmp/QtPersons1.0.0` && $(TAR) QtPersons1.0.0.tar QtPersons1.0.0 && $(COMPRESS) QtPersons1.0.0.tar) && $(MOVE) `dirname .tmp/QtPersons1.0.0`/QtPersons1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/QtPersons1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

main.o: main.cpp ../../../../Qt/5.3/clang_64/lib/QtCore.framework/Versions/5/Headers/QCoreApplication \
		../../../../Qt/5.3/clang_64/lib/QtCore.framework/Versions/5/Headers/qcoreapplication.h \
		consoleui.h \
		search.h \
		person.h \
		service.h \
		personrepository.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

person.o: person.cpp person.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o person.o person.cpp

consoleui.o: consoleui.cpp consoleui.h \
		search.h \
		person.h \
		service.h \
		personrepository.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o consoleui.o consoleui.cpp

personrepository.o: personrepository.cpp personrepository.h \
		person.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o personrepository.o personrepository.cpp

search.o: search.cpp search.h \
		person.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o search.o search.cpp

service.o: service.cpp service.h \
		person.h \
		search.h \
		personrepository.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o service.o service.cpp

sort.o: sort.cpp sort.h \
		person.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sort.o sort.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

