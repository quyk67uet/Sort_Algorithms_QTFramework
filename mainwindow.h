#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QLineEdit>
#include <QRandomGenerator>
#include <QElapsedTimer>
#include <QComboBox>
#include <QLabel>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSortButtonClicked();
    void onResetButtonClicked();
    void onImportButtonClicked();
    void onGenerateButtonClicked();
    void onFunctionComboBoxChanged(int index);
    void onAlgorithmComboBoxChanged(const QString &algorithm);
    void onSaveToFileButtonClicked();


private:
    Ui::MainWindow *ui;
    QProgressBar *progressBar;
    QPushButton *resetButton;
    QPushButton *importButton;
    QGraphicsScene *scene;
    QPushButton *generateButton;
    QPushButton *saveToFileButton;
    QLineEdit *countLineEdit;
    QComboBox *functionComboBox;
    QTextEdit *fileContentTextEdit;
    QTextEdit *generatedArrayTextEdit;
    QLabel *manualInputLabel;
    QLabel *generateInputLabel;
    QTextEdit *algorithmSummaryTextEdit;
    QLabel *timeLabel;
    QTextEdit *finalResultTextEdit;
};

#endif // MAINWINDOW_H
