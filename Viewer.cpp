// echo, echo, echo...
#include "Viewer.h"

//Viewer::Viewer()
//{}

void Viewer::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // get xLength()
    int xLength = myMatrix->getWidth();

    // get yLength()
    int yLength = myMatrix->getHeight();

    int X = xLength*CELL;
    int Y = yLength*CELL;

    // set display size adding in buffer on all sides
    setFixedSize(BUFFER+X+BUFFER,BUFFER+Y+BUFFER);

    // paint cells
    for(int cellx=0; cellx < xLength; cellx++)
    {
        for(int celly=0; celly < yLength; celly++)
        {
            if(myMatrix->getElement(cellx,celly) == true)
            {
                // set color to black
                painter.fillRect( BUFFER+celly*CELL , BUFFER+cellx*CELL , CELL , CELL , Qt::black );
            }
            else // cell is false
            {
                // set color to white
                painter.fillRect( BUFFER+celly*CELL , BUFFER+cellx*CELL , CELL , CELL , Qt::white );
            }
        }
    }

    // set visibility to true
    setEnabled(true);
    setVisible(true);
    // run the window...
}

void Viewer::displayMatrix(ModuleMatrix& matrix)
{
    myMatrix = &matrix;
    repaint(); // forces call to paintEvent()
}

//Viewer::~Viewer()
//{}

