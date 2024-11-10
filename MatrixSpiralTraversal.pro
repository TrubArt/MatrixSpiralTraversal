TEMPLATE = app
TARGET = MatrixSpiralTraversal
CONFIG += c=++11

SOURCES += Main.cpp \
	stdafx.cpp \
 	Pseudomatrix.cpp \
	MatrixSpiralTraversal.cpp \
	SpiralTraversalAlgorithm.cpp

HEADERS += stdafx.h \
	Pseudomatrix.h \
	MatrixSpiralTraversal.h \
	SpiralTraversalAlgorithm.h

FORMS += MatrixSpiralTraversal.ui

RESOURCES += MatrixSpiralTraversal.qrc
