#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    pen.setWidth(2);
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->textBrowser->hide();
    ui->pushButton->hide();










}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPen(QPen &pen)
{

    this->pen = pen;

    update();

}

bool MainWindow::isUsed(QString name)
{
    if(findShape(name) == nullptr){
        return false;
    }else{
        return true;
    }


}




void MainWindow::on_savefile_triggered()
{

}

void MainWindow::on_openfile_triggered()
{
     QString fileName = QFileDialog:: getOpenFileName(this, "open file", "D://");
     QFile file(fileName);

}


void MainWindow::on_draw_a_line_triggered()
{
    bool ok;
    QString lineName = QInputDialog::getText(this,"Naming","Please, Enter a name for the shape",QLineEdit::Normal,
                                             "Line", &ok);
    if(ok && !lineName.isEmpty() ){
        if(!isUsed(lineName)){
            double length = QInputDialog::getDouble(this,"size","Please, Enter the length of the line",0.0, 1, 10000, 2, &ok);
            if(ok){
                line =new MyLine(10*length, pen,lineName);
                scene->addItem(line);
                stack.push(line);
                shapes.push_back(line);

            }
        }else{
            QMessageBox::warning(this,"Error","Name is taken, Please enter another name");
        }
    }

}


void MainWindow::on_draw_a_rectangle_triggered()
{
    bool ok;
    QString rectangleName = QInputDialog::getText(this,"Naming","Please, Enter a name for the shape",QLineEdit::Normal,
                                                  "Rectangle", &ok);
    if(ok && !rectangleName.isEmpty()){
        if(!isUsed(rectangleName)){
            double w = QInputDialog::getDouble(this,"size","Please, Enter the width of the rectangle",0.0, 1, 10000, 2, &ok);
            if(ok){
                double h = QInputDialog::getDouble(this,"size","Please, Enter the height of the rectangle",0.0, 1, 10000, 2, &ok);
                if(ok){
                    square = new MySquare(10*w,10*h,pen,rectangleName);
                    scene->addItem(square);
                    stack.push(square);
                    shapes.push_back(square);
                }
            }
        }else{
            QMessageBox::warning(this,"Error","Name is taken, Please enter another name");
        }
    }

}


void MainWindow::on_draw_a_circle_triggered()
{
    bool ok;
    QString circleName = QInputDialog::getText(this,"Naming","Please, Enter a name for the shape",QLineEdit::Normal,
                                               "Circle", &ok);
    if(ok && !circleName.isEmpty()){
        if(!isUsed(circleName)){
            double r = QInputDialog::getDouble(this,"size","Please, Enter the riduas of the cricle",0.0, 1, 10000, 2, &ok);
            if(ok){
                circle = new MyCircle(10*r,pen,circleName);
                scene->addItem(circle);
                stack.push(circle);
                shapes.push_back(circle);
            }
        }else{
            QMessageBox::warning(this,"Error","Name is taken, Please enter another name");
        }
    }

}


void MainWindow::on_color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black, this);
    QPen pencolor(color);
    setPen(pencolor);

}


void MainWindow::on_about_triggered()
{
    QMessageBox::information(this,"About","this project has been made by team 12\n  \nSupervision: Eng.Muhammad Moustafa\n  \nUnder supervision of Dr.Ahmed Hesham \nthanks for your effort with us this year");


}


void MainWindow::on_undo_triggered()
{
    if(!stack.empty()){
        Shape *item = stack.top();
        scene->removeItem(item);
        redoStack.push(item);
        stack.pop();
        shapes.pop_back();
    }
}


void MainWindow::on_redo_triggered()
{
    if(!redoStack.empty()){
        Shape *item = redoStack.top();
        scene->addItem(item);
        stack.push(item);
        shapes.push_back(item);
        redoStack.pop();
    }
}


void MainWindow::on_close_triggered()
{
    QApplication::quit();
}




void MainWindow::on_sortButton_clicked() // the user should have the ablity to sort the shapes in ascending or descending order
{
    if(!shapes.empty()){
        QStringList items;
        QString sortType;
        items << tr("Ascending") << tr("Descending") ;

        bool ok;
        QString item = QInputDialog::getItem(this, tr("Sort"),
                                             tr("Please, Select sort type."), items, 0, false, &ok);
        if (ok && !item.isEmpty()){
            sortType = item;

            QVector<Shape *> sortedShapes= bubbleSort(shapes, shapes.size());
            QStringList list;
            if(sortType == "Descending"){
                std::reverse(sortedShapes.begin(), sortedShapes.end());
            }
            for(auto item: sortedShapes){
                QString r = "Name: "+item->name  + QString(", Perimeter: %1").arg(item->perimeter) + ", Color: "
                        + item->pen.color().name()+" \n";
                list<< r;
            }
            list<< QString(" ------------------------- \n");
            ui->textBrowser->insertPlainText("Sorted " + sortType + ": \n");

            for (int i = 0; i < list.size(); ++i){
                ui->textBrowser->insertPlainText(list.at(i));
            }

            ui->textBrowser->show();
            ui->pushButton->show();
         }
    }

}


void MainWindow::on_searchButton_clicked()
{
    bool ok;
    QString shapeName = QInputDialog::getText(this,"Name","Please, Enter the name of the shape",QLineEdit::Normal,
                                              "", &ok);
    if(ok && !shapeName.isEmpty()){
        Shape * sreachedShape;
        QString result;
        sreachedShape = findShape(shapeName);
        if(sreachedShape == nullptr){
            result = "Not found!\n";
        }else{
            result ="Name: "+sreachedShape->name + QString(", Perimeter: %1").arg(sreachedShape->perimeter)  + ", Color: "
                    + sreachedShape->pen.color().name()+" \n";
        }
        ui->textBrowser->insertPlainText(result);
        ui->textBrowser->show();
        ui->pushButton->show();
    }
}




void MainWindow::on_actionclear_triggered()
{

    scene->clear();
    shapes.clear();
    stack.clear();
    redoStack.clear();
}


void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->hide();
    ui->pushButton->hide();
    ui->textBrowser->clear();

}

