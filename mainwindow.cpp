#include "mainwindow.hpp"
#include "ui_mainwindow.h"

constexpr int BASE = 12;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onDigitPressed()
{
    QPushButton const * const button = (QPushButton *)sender();
    const double digits = (ui->lineEditResult->text() + button->text()).toDouble();
    ui->lineEditResult->setText(QString::number(digits, 'g', BASE));
}


void MainWindow::on_pushButton_dot_clicked()
{
    if (!ui->lineEditResult->text().contains('.')) {
        ui->lineEditResult->setText(ui->lineEditResult->text() + '.');
    }
}
