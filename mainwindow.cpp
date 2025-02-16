#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

double firstNum;
bool userIsTypingSecondNumber = false;
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
    QString buttonText = button->text();
    qDebug() << button;
    double labelNumber;
    QString newLabelText;

    if((ui->pushButton_add->isChecked() || ui->pushButton_minus->isChecked() || ui->pushButton_multiply->isChecked() ||ui->pushButton_devide->isChecked()) && !userIsTypingSecondNumber)
    {
        userIsTypingSecondNumber = true;
        // labelNumber = button->text().toDouble();
        ui->label->setText(buttonText);
    }else{
        ui->label->setText(ui->label->text()=="0" ? buttonText : ui->label->text() + buttonText);
        // labelNumber = (ui->label->text() + button->text()).toDouble();
    }

    // if(ui->label->text()=="0" || ui->label->text()=="LabelText"){
    //     newLabelText = button->text();
    // }else{
    //     newLabelText= ui->label->text() + button->text();
    // }


    // // labelNumber = newLabelText.toDouble();
    // newLabelText = QString::number(labelNumber, 'g',15);
    // ui->label->setText(newLabelText);
}

void MainWindow::on_pushButton_decimal_released()
{
    if(!ui->label->text().contains(".")){
       ui->label->setText( ui->label->text() + ".");
    }

}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    firstNum = ui->label->text().toDouble();
    button->setChecked(true);
    userIsTypingSecondNumber = false;


}


void MainWindow::on_pushButton_clear_released()
{
    firstNum = 0;
    userIsTypingSecondNumber= false;
    ui->label->setText("0");

}

void MainWindow::unary_operation_pressed()
{
    // QPushButton * button = (QPushButton*) sender()
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    double labelNumber = ui->label->text().toDouble();


    if(button->text()=="+/-"){
        labelNumber = labelNumber * -1;


    }
    if(button->text()=="%"){
        labelNumber = labelNumber * 0.01;
    }
    QString newLabelText;
    newLabelText = QString::number(labelNumber, 'g', 15);
    ui->label-> setText(newLabelText);
}

void MainWindow::on_pushButton_equals_released()
{
    double secondNum =ui-> label->text().toDouble();
    double result = 0;

    if(ui->pushButton_add->isChecked())
    {
        result = firstNum + secondNum;
        ui->pushButton_add->setChecked(false);

    }
    else if(ui->pushButton_minus->isChecked())
    {
        result = firstNum - secondNum;
        ui->pushButton_minus->setChecked(false);

    }
    else if(ui->pushButton_multiply->isChecked())
    {
        result = firstNum * secondNum;
        ui->pushButton_multiply->setChecked(false);

    }
    else if(ui->pushButton_devide->isChecked())
    {
        result = firstNum / secondNum;
        ui->pushButton_devide->setChecked(false);
    }
    ui->label->setText(QString::number(result, 'g', 15));
    userIsTypingSecondNumber = false;


}


