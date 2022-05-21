#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QMessageBox>
#include <QColorDialog>
#include <QPainter>
#include <QFileDialog>
#include <QPen>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QInputDialog>
#include <QStack>
#include <QVector>
#include <QStringList>
#include <QList>



#include"mycircle.h"
#include"myline.h"
#include "mysquare.h"
#include "shape.h"

#include <QtCore>
#include <QtGui>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();







private slots:

    void on_openfile_triggered();

    void on_draw_a_line_triggered();

    void on_draw_a_rectangle_triggered();

    void on_draw_a_circle_triggered();

    void on_color_triggered();

    void on_about_triggered();

    void on_undo_triggered();

    void on_redo_triggered();

    void on_close_triggered();

    void on_savefile_triggered();

    void on_sortButton_clicked();

    void on_searchButton_clicked();



    void on_actionclear_triggered();

    void on_pushButton_clicked();

private:

    //bubblesort function
    QVector<Shape *> bubbleSort(QVector<Shape *> arr, int size) {
        for (int i = 0; i < size; i++)
        {
            int swaps = 0; //detect there is swaps or not
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (arr[j]->getPerimeter() > arr[j + 1]->getPerimeter()) //when current value is bigger than next
                {
                    std::swap(arr[j], arr[j + 1]);
                    swaps = 1;
                }
            }
            if (!swaps) //when there are no swaps then the list is sorted
                break;
        }
        return arr;
    }

    Shape *findShape(QString shapeName){
        for(auto item: shapes){
             QString r = item->name;
             if (r == shapeName){
                 return item;
             }
        }
        return nullptr;
    }



    Ui::MainWindow *ui;



    QPen pen;
    QString name;
    QStack<Shape *> stack;
    QStack<Shape *> redoStack;
    QVector<Shape *> shapes;


    QGraphicsScene *scene;
    MySquare *square;
    MyCircle *circle;
    MyLine *line;



    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;

    void setPen(QPen &pen);
    bool isUsed(QString name);







};
#endif // MAINWINDOW_H
