/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QTextEdit *outputTextEdit;
    QTextEdit *inputTextEdit;
    QProgressBar *progressBar;
    QPushButton *resetButton;
    QGraphicsView *graphicsView;
    QLabel *label;
    QLabel *manualInputLabel;
    QLabel *label_3;
    QPushButton *importButton;
    QPushButton *generateButton;
    QLineEdit *countLineEdit;
    QComboBox *functionComboBox;
    QTextEdit *fileContentTextEdit;
    QTextEdit *algorithmSummaryTextEdit;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *generateInputLabel;
    QTextEdit *generatedArrayTextEdit;
    QPushButton *saveToFileButton;
    QLabel *timeLabel;
    QTextEdit *finalResultTextEdit;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(650, 430, 56, 18));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(190, 330, 191, 21));
        outputTextEdit = new QTextEdit(centralwidget);
        outputTextEdit->setObjectName("outputTextEdit");
        outputTextEdit->setGeometry(QRect(430, 330, 341, 81));
        inputTextEdit = new QTextEdit(centralwidget);
        inputTextEdit->setObjectName("inputTextEdit");
        inputTextEdit->setGeometry(QRect(190, 480, 191, 31));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(460, 470, 281, 23));
        progressBar->setValue(24);
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(480, 430, 56, 18));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(30, 20, 741, 271));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 330, 151, 16));
        manualInputLabel = new QLabel(centralwidget);
        manualInputLabel->setObjectName("manualInputLabel");
        manualInputLabel->setEnabled(true);
        manualInputLabel->setGeometry(QRect(70, 480, 101, 16));
        manualInputLabel->setScaledContents(false);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(430, 310, 91, 16));
        importButton = new QPushButton(centralwidget);
        importButton->setObjectName("importButton");
        importButton->setGeometry(QRect(90, 480, 56, 18));
        generateButton = new QPushButton(centralwidget);
        generateButton->setObjectName("generateButton");
        generateButton->setGeometry(QRect(90, 520, 56, 18));
        countLineEdit = new QLineEdit(centralwidget);
        countLineEdit->setObjectName("countLineEdit");
        countLineEdit->setGeometry(QRect(190, 480, 51, 20));
        functionComboBox = new QComboBox(centralwidget);
        functionComboBox->setObjectName("functionComboBox");
        functionComboBox->setGeometry(QRect(190, 430, 191, 22));
        fileContentTextEdit = new QTextEdit(centralwidget);
        fileContentTextEdit->setObjectName("fileContentTextEdit");
        fileContentTextEdit->setGeometry(QRect(190, 480, 191, 31));
        algorithmSummaryTextEdit = new QTextEdit(centralwidget);
        algorithmSummaryTextEdit->setObjectName("algorithmSummaryTextEdit");
        algorithmSummaryTextEdit->setGeometry(QRect(190, 360, 191, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 360, 71, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 430, 121, 16));
        generateInputLabel = new QLabel(centralwidget);
        generateInputLabel->setObjectName("generateInputLabel");
        generateInputLabel->setEnabled(true);
        generateInputLabel->setGeometry(QRect(30, 480, 151, 16));
        generateInputLabel->setScaledContents(false);
        generatedArrayTextEdit = new QTextEdit(centralwidget);
        generatedArrayTextEdit->setObjectName("generatedArrayTextEdit");
        generatedArrayTextEdit->setGeometry(QRect(190, 520, 191, 31));
        saveToFileButton = new QPushButton(centralwidget);
        saveToFileButton->setObjectName("saveToFileButton");
        saveToFileButton->setGeometry(QRect(680, 530, 56, 18));
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setGeometry(QRect(570, 450, 51, 16));
        finalResultTextEdit = new QTextEdit(centralwidget);
        finalResultTextEdit->setObjectName("finalResultTextEdit");
        finalResultTextEdit->setGeometry(QRect(520, 520, 141, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(450, 530, 61, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Choose your sort algorithms", nullptr));
        manualInputLabel->setText(QCoreApplication::translate("MainWindow", "Enter your arrays", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Steps", nullptr));
        importButton->setText(QCoreApplication::translate("MainWindow", "Import", nullptr));
        generateButton->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Summary", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Choose your method", nullptr));
        generateInputLabel->setText(QCoreApplication::translate("MainWindow", "Enter your number of array", nullptr));
        saveToFileButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        timeLabel->setText(QCoreApplication::translate("MainWindow", "Time: 0 ms", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Final result", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
