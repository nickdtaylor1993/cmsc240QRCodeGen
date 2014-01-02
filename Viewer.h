#ifndef __VIEWER_H__
#define __VIEWER_H__

#include <QApplication>
#include <QWidget> // inherits QObject and QPaintDevice
#include <QPainter>
#include "ModuleMatrix.h"

using namespace std;

class Viewer: public QWidget
{
    public:
        // displays the matrix on the screen using some panel
        // USE ONLY THE ACCESSOR FIELD IN THE MODULE MATRIX CLASS TO GET
        // ELEMENTS, or parameters of matrix
        void displayMatrix(ModuleMatrix& matrix);

    protected:
        void paintEvent(QPaintEvent *);

    private:
        ModuleMatrix* myMatrix;

        const static int CELL = 5; // pixels for square cell
        const static int BUFFER = 20; // 20 pixels for space on all sides
};

#endif
