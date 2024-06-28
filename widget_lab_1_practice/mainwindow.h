#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>

class QLabel;
class QLineEdit;
class QPushButton;
class QCheckBox;
class QComboBox;
class QDialog;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void calculateButtonClicked();
    void showInputDialog();
    void saveResultToFile();

private:
    QLabel *shapeLabel;
    QComboBox *shapeComboBox;
    QLabel *lengthLabel;
    QLineEdit *lengthLineEdit;
    QLabel *widthLabel;
    QLineEdit *widthLineEdit;
    QLabel *heightLabel;
    QLineEdit *heightLineEdit;
    QLabel *resultLabel;
    QPushButton *calculateButton;
    QCheckBox *saveToFileCheckBox;

    QDialog *inputDialog;

    qreal calculateSquare(qreal length, qreal width, qreal height);
    bool validateInput(qreal length, qreal width, qreal height);
};

#endif // MAINWINDOW_H
