#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "polish_calc_exceptions.hpp"
#include "polish_calc.hpp"
#include "operations.hpp"

const char space = ' ';

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(onDigitClicked()));

    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(onPushButtonPlusClicked()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(onPushButtonMinusClicked()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(onPushButtonMultiplyClicked()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(onPushButtonDivideClicked()));

    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(onPushButtonDotClicked()));
    connect(ui->pushButton_space, SIGNAL(clicked()), this, SLOT(onPushButtonSpaceClicked()));
    connect(ui->pushButton_backspace, SIGNAL(clicked()), this, SLOT(onPushButtonBackspaceClicked()));

    connect(ui->pushButton_calculate, SIGNAL(clicked()), this, SLOT(onPushButtonCalculateClicked()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::onDigitClicked()
{
    const QPushButton * const button = (QPushButton *)sender();
    QString newLine = button->text();
    if (ui->lineEditResult->text() != "0") {
        newLine = (ui->lineEditResult->text() + button->text());
    }
    ui->lineEditResult->setText(newLine);
}

void MainWindow::onPushButtonDotClicked()
{
  QString number = getLastDigit(ui->lineEditResult->text());
  if (number.isNull()) {
    ui->lineEditResult->setText(ui->lineEditResult->text() + "0.");
  } else if (!number.contains('.')) {
    ui->lineEditResult->setText(ui->lineEditResult->text() + '.');
  }
}

void MainWindow::onPushButtonPlusClicked()
{
  handleOperation(polish_calc::plus);
}

void MainWindow::onPushButtonMinusClicked()
{
  handleOperation(polish_calc::minus);
}

void MainWindow::onPushButtonMultiplyClicked()
{
  handleOperation(polish_calc::multiply);
}

void MainWindow::onPushButtonDivideClicked()
{
  handleOperation(polish_calc::divide);
}

void MainWindow::onPushButtonSpaceClicked()
{
  if (ui->lineEditResult->text().back() != space) {
    ui->lineEditResult->setText(ui->lineEditResult->text() + space);
  }
}

void MainWindow::onPushButtonBackspaceClicked()
{
  if (!ui->lineEditResult->text().isEmpty()) {
    const int len = ui->lineEditResult->text().length();
    QString newLine = ui->lineEditResult->text().mid(0, len-1);
    ui->lineEditResult->setText(newLine);
  }
}

void MainWindow::onPushButtonCalculateClicked()
{
  try {
    const std::string result = polish_calc::process(ui->lineEditResult->text().toStdString());
    ui->lineEditResult->setText(result.c_str());
  } catch (const polish_calc::InvalidOperandsNumberException & e) {
    // todo
  } catch (const polish_calc::InvalidOperandException & e) {
    // todo
  }
}

void MainWindow::handleOperation(const std::string &operation)
{
  QString newLine;
  if (ui->lineEditResult->text().isEmpty() || ui->lineEditResult->text().back() == space) {
    newLine = (ui->lineEditResult->text() + operation.c_str() + space);
  } else {
    newLine = (ui->lineEditResult->text() + space + operation.c_str() + space);
  }
  ui->lineEditResult->setText(newLine);
}

QString MainWindow::getLastDigit(const QString &str)
{
  QString result;
  if (!str.isEmpty() && str.back() != space) {
      const int index = str.lastIndexOf(space);
      if (index == -1) {
        result = str;
      } else {
        result = str.mid(index);
      }
  }
  return result;
}
