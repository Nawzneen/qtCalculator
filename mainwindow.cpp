#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

double firstNum;
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
    connect(ui->pushButton_percent, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
    connect(ui->pushButton_multiply, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_devide, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_add, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_minus, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    ui->pushButton_add->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_devide->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
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
    if(ui->pushButton_add->isChecked() || ui->pushButton_minus->isChecked() || ui->pushButton_multiply->isChecked() ||ui->pushButton_devide->isChecked() )
    {
        labelNumber = button->text().toDouble();
    }else{
        labelNumber = (ui->label->text() + button->text()).toDouble();
    }

    // labelNumber = newLabelText.toDouble();
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
    if(button->text()=="%"){
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabelText = QString::number(labelNumber, 'g', 15);
        ui->label-> setText(newLabelText);
    }
}


void MainWindow::on_pushButton_clear_released()
{
    firstNum = 0;
    ui->label->setText("0");

}


void MainWindow::on_pushButton_equals_released()
{
    double labelNumber, secondNum;
    secondNum =ui-> label->text().toDouble();
    QString newLabelText;
    if(ui->pushButton_add->isChecked())
    {
        labelNumber = firstNum + secondNum;
        newLabelText = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabelText);
        ui->pushButton_add-> setChecked(false);

    }
    else if(ui->pushButton_minus->isChecked())
    {
        labelNumber = firstNum - secondNum;
        newLabelText = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabelText);
        ui->pushButton_minus-> setChecked(false);
    }
    else if(ui->pushButton_multiply->isChecked())
    {
        labelNumber = firstNum * secondNum;
        newLabelText = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabelText);
        ui->pushButton_multiply-> setChecked(false);
    }
    else if(ui->pushButton_devide->isChecked())
    {
        labelNumber = firstNum / secondNum;
        newLabelText = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabelText);
        ui->pushButton_devide-> setChecked(false);
    }


}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    firstNum = ui->label->text().toDouble();
    button->setChecked(true);


}
