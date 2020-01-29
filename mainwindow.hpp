#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // Methods
    void handleOperation(const std::string & operation);
    QString getLastDigit(const QString & str);


    // Members
    Ui::MainWindow *ui;


private slots:
    void onDigitClicked();
    void onPushButtonDotClicked();
    void onPushButtonPlusClicked();
    void onPushButtonMinusClicked();
    void onPushButtonMultiplyClicked();
    void onPushButtonDivideClicked();
    void onPushButtonSpaceClicked();
    void onPushButtonBackspaceClicked();
    void onPushButtonCalculateClicked();
};
#endif // MAINWINDOW_HPP
