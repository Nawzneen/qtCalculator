#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Connect the btn click signal to the slot
    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_plusMinus, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot function that is called when the button is pressed
void MainWindow::digit_pressed()
{
    qDebug() << "test";
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    qDebug() << button;
    double labelNumber;
    QString newLabelText;

    if(ui->label->text()=="0" || ui->label->text()=="LabelText"){
        newLabelText = button->text();
    }else{
        newLabelText= ui->label->text() + button->text();
    }

    labelNumber = newLabelText.toDouble();
    newLabelText = QString::number(labelNumber, 'g',15);
    ui->label->setText(newLabelText);
}

void MainWindow::on_pushButton_decimal_released()
{
    if(ui->label->text().contains(".")){
        return;
    }else{
        ui->label->setText( ui->label->text() + ".");
    }

}
void MainWindow::unary_operation_pressed()
{
    // QPushButton * button = (QPushButton*) sender()
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    double labelNumber;
    QString newLabelText;
    if(button->text()=="+/-"){
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabelText = QString::number(labelNumber, 'g', 15);
        ui->label-> setText(newLabelText);
    }
}

