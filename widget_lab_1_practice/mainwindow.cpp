#include "mainwindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QDialog>
#include <QFormLayout>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    shapeLabel = new QLabel("Shape:");
    shapeComboBox = new QComboBox;
    shapeComboBox->addItem("Rectangle");
    shapeComboBox->addItem("Triangle");
    shapeComboBox->addItem("Circle");
    shapeComboBox->addItem("Hexagon");

    lengthLabel = new QLabel("Length:");
    lengthLineEdit = new QLineEdit;
    widthLabel = new QLabel("Width:");
    widthLineEdit = new QLineEdit;
    heightLabel = new QLabel("Height:");
    heightLineEdit = new QLineEdit;

    resultLabel = new QLabel;
    calculateButton = new QPushButton("Calculate");
    saveToFileCheckBox = new QCheckBox("Save to file");

    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::calculateButtonClicked);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(shapeLabel);
    mainLayout->addWidget(shapeComboBox);
    mainLayout->addWidget(lengthLabel);
    mainLayout->addWidget(lengthLineEdit);
    mainLayout->addWidget(widthLabel);
    mainLayout->addWidget(widthLineEdit);
    mainLayout->addWidget(heightLabel);
    mainLayout->addWidget(heightLineEdit);
    mainLayout->addWidget(resultLabel);
    mainLayout->addWidget(calculateButton);
    mainLayout->addWidget(saveToFileCheckBox);

    setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete shapeLabel;
    delete shapeComboBox;
    delete lengthLabel;
    delete lengthLineEdit;
    delete widthLabel;
    delete widthLineEdit;
    delete heightLabel;
    delete heightLineEdit;
    delete resultLabel;
    delete calculateButton;
    delete saveToFileCheckBox;
}

void MainWindow::calculateButtonClicked()
{
    qreal length = lengthLineEdit->text().toDouble();
    qreal width = widthLineEdit->text().toDouble();
    qreal height = heightLineEdit->text().toDouble();

    if (!validateInput(length, width, height))
        return;

    qreal result = calculateSquare(length, width, height);

    if (qIsInf(result) || qIsNaN(result))
    {
        QMessageBox::critical(this, "Error", "Invalid operation");
        return;
    }

    resultLabel->setText("Square: " + QString::number(result));

    if (saveToFileCheckBox->isChecked())
        saveResultToFile();
}

qreal MainWindow::calculateSquare(qreal length, qreal width, qreal height)
{
    QString shape = shapeComboBox->currentText();

    if (shape == "Rectangle")
        return length * width;
    else if (shape == "Triangle")
        return 0.5 * length * width;
    else if (shape == "Circle")
        return 3.14 * 0.25 * height * height;
    else if (shape == "Hexagon")
        return 2.598076211353316 * length * length;
    return 0.0;
}

bool MainWindow::validateInput(qreal length, qreal width, qreal height)
{
    if (length <= 0 || width <= 0 || height <= 0)
    {
        QMessageBox::critical(this, "Error", "Invalid input: please enter positive values");
        return false;
    }

    return true;
}

void MainWindow::saveResultToFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt)");

    if (!fileName.isEmpty())
    {
        QFile file(fileName);

        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            stream << "Shape: " << shapeComboBox->currentText() << "\n";
            stream << "Length: " << lengthLineEdit->text() << "\n";
            stream << "Width: " << widthLineEdit->text() << "\n";
            stream << "Height: " << heightLineEdit->text() << "\n";
            stream << "Square: " << resultLabel->text().remove("Square: ") << "\n";

            file.close();
        }
    }
}
