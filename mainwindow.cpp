#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sorting_algorithms.h"
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    progressBar = ui->progressBar;
    progressBar->setValue(0);

    timeLabel = ui->timeLabel;
    timeLabel->setText("Time: 0 ms");

    // Tạo scene
    scene = new QGraphicsScene(this);

    // Tải ảnh
    QPixmap pixmap(":/images/sorting-algorithms.png");

    // Thêm ảnh vào scene
    scene->addPixmap(pixmap);

    // Đặt scene cho graphicsView
    ui->graphicsView->setScene(scene);

    resetButton = ui->resetButton;
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::onResetButtonClicked);

    importButton = ui->importButton;
    connect(importButton, &QPushButton::clicked, this, &MainWindow::onImportButtonClicked);

    generateButton = ui->generateButton;
    connect(generateButton, &QPushButton::clicked, this, &MainWindow::onGenerateButtonClicked);

    countLineEdit = ui->countLineEdit;

    functionComboBox = ui->functionComboBox;
    functionComboBox->addItem("Manual Input");
    functionComboBox->addItem("Import from File");
    functionComboBox->addItem("Generate Random");
    connect(functionComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onFunctionComboBoxChanged);

    fileContentTextEdit = ui->fileContentTextEdit; // Khởi tạo QTextEdit
    fileContentTextEdit->setVisible(false);
    fileContentTextEdit->setReadOnly(true);

    generatedArrayTextEdit = ui->generatedArrayTextEdit; // Khởi tạo QTextEdit
    generatedArrayTextEdit->setVisible(false);
    generatedArrayTextEdit->setReadOnly(true); // Đặt chế độ chỉ đọc

    generateInputLabel = ui->generateInputLabel;
    generateInputLabel->setVisible(false);

    manualInputLabel = ui->manualInputLabel; // Khởi tạo QLabel
    manualInputLabel->setVisible(false); // Ẩn ban đầu

    algorithmSummaryTextEdit = ui->algorithmSummaryTextEdit; // Khởi tạo QTextEdit
    algorithmSummaryTextEdit->setReadOnly(true); // Đặt chế độ chỉ đọc

    finalResultTextEdit = ui->finalResultTextEdit;
    finalResultTextEdit->setReadOnly(true);

    // Kết nối comboBox thuật toán với hàm xử lý
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &MainWindow::onAlgorithmComboBoxChanged);

    connect(ui->saveToFileButton, &QPushButton::clicked, this, &MainWindow::onSaveToFileButtonClicked);

    onFunctionComboBoxChanged(functionComboBox->currentIndex());

    // Thêm tên các thuật toán vào comboBox
    ui->comboBox->addItem("Insertion Sort");
    ui->comboBox->addItem("Selection Sort");
    ui->comboBox->addItem("Bubble Sort");
    ui->comboBox->addItem("Merge Sort");
    ui->comboBox->addItem("Quick Sort");
    ui->comboBox->addItem("Heap Sort");
    ui->comboBox->addItem("Shell Sort");
    ui->comboBox->addItem("Radix Sort");
    ui->comboBox->addItem("Counting Sort");
    ui->comboBox->addItem("Bucket Sort");
    ui->comboBox->addItem("Tim Sort");
    ui->comboBox->addItem("Comb Sort");
    ui->comboBox->addItem("Gnome Sort");
    ui->comboBox->addItem("Pigeonhole Sort");
    ui->comboBox->addItem("Cycle Sort");
    ui->comboBox->addItem("Odd-Even Sort");
    ui->comboBox->addItem("Bitonic Sort");
    ui->comboBox->addItem("Pancake Sort");
    ui->comboBox->addItem("Cocktail Shaker Sort");
    ui->comboBox->addItem("Stooge Sort");

    // Kết nối nút bấm với hàm xử lý
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onSortButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onResetButtonClicked() {
    ui->inputTextEdit->clear();
    ui->outputTextEdit->clear();
    progressBar->setValue(0);
    finalResultTextEdit->clear();
    ui->fileContentTextEdit->clear();
    ui->generatedArrayTextEdit->clear();
    ui->countLineEdit->clear();
}

void MainWindow::onImportButtonClicked() {
    // Reset các thành phần liên quan
    ui->outputTextEdit->clear();
    progressBar->setValue(0);

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Cannot open file: ") + file.errorString());
        return;
    }

    QTextStream in(&file);
    QString numbers = in.readAll();
    ui->fileContentTextEdit->setText(numbers);
}

void MainWindow::onGenerateButtonClicked() {
    // Reset các thành phần liên quan
    ui->outputTextEdit->clear();
    progressBar->setValue(0);

    bool ok;
    int count = countLineEdit->text().toInt(&ok);
    if (!ok || count <= 0) {
        QMessageBox::warning(this, tr("Invalid Input"), tr("Please enter a valid number of elements."));
        return;
    }

    QStringList numbers;
    for (int i = 0; i < count; ++i) {
        int randomNum = QRandomGenerator::global()->bounded(100); // Sinh số ngẫu nhiên từ 0 đến 99
        numbers << QString::number(randomNum);
    }

    QString generatedArray = numbers.join(" ");
    ui->generatedArrayTextEdit->setText(generatedArray);
}

void MainWindow::onFunctionComboBoxChanged(int index) {
    // Reset tất cả các thành phần
    ui->inputTextEdit->clear();
    ui->fileContentTextEdit->clear();
    ui->generatedArrayTextEdit->clear();
    ui->countLineEdit->clear();
    ui->outputTextEdit->clear();
    progressBar->setValue(0);
    finalResultTextEdit->clear();

    // Ẩn tất cả các thành phần
    ui->inputTextEdit->setVisible(false);
    ui->importButton->setVisible(false);
    ui->generateButton->setVisible(false);
    ui->countLineEdit->setVisible(false);
    ui->fileContentTextEdit->setVisible(false);
    ui->generatedArrayTextEdit->setVisible(false);
    manualInputLabel->setVisible(false);
    generateInputLabel->setVisible(false);

    switch (index) {
    case 0: // Manual Input
        ui->inputTextEdit->setVisible(true);
        manualInputLabel->setVisible(true); // Hiển thị nhãn
        break;
    case 1: // Import from File
        ui->importButton->setVisible(true);
        ui->fileContentTextEdit->setVisible(true);
        break;
    case 2: // Generate Random
        ui->generateButton->setVisible(true);
        ui->countLineEdit->setVisible(true);
        ui->generatedArrayTextEdit->setVisible(true);
        ui->generateInputLabel->setVisible(true);
        break;
    }
}

void MainWindow::onAlgorithmComboBoxChanged(const QString &algorithm) {
    QString summary;

    if (algorithm == "Insertion Sort") {
        summary = "Insertion Sort: Builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms.";
    } else if (algorithm == "Selection Sort") {
        summary = "Selection Sort: Divides the input list into two parts: a sorted sublist of items which is built up from left to right and a sublist of the remaining unsorted items.";
    } else if (algorithm == "Bubble Sort") {
        summary = "Bubble Sort: Repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.";
    } else if (algorithm == "Merge Sort") {
        summary = "Merge Sort: A divide and conquer algorithm that was invented by John von Neumann in 1945. It divides the unsorted list into n sublists, each containing one element.";
    } else if (algorithm == "Quick Sort") {
        summary = "Quick Sort: Picks an element as pivot and partitions the given array around the picked pivot.";
    } else if (algorithm == "Heap Sort") {
        summary = "Heap Sort: A comparison-based sorting technique based on Binary Heap data structure.";
    } else if (algorithm == "Shell Sort") {
        summary = "Shell Sort: An in-place comparison sort. It can be seen as either a generalization of sorting by exchange or sorting by insertion.";
    } else if (algorithm == "Radix Sort") {
        summary = "Radix Sort: A non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by the individual digits which share the same significant position and value.";
    } else if (algorithm == "Counting Sort") {
        summary = "Counting Sort: An integer sorting algorithm that operates by counting the number of objects that have each distinct key value.";
    } else if (algorithm == "Bucket Sort") {
        summary = "Bucket Sort: Distributes the elements of an array into a number of buckets. Each bucket is then sorted individually.";
    } else if (algorithm == "Tim Sort") {
        summary = "Tim Sort: A hybrid stable sorting algorithm, derived from merge sort and insertion sort, designed to perform well on many kinds of real-world data.";
    } else if (algorithm == "Comb Sort") {
        summary = "Comb Sort: An improvement on bubble sort. It eliminates turtles, or small values near the end of the list, since in a bubble sort these slow the sorting down tremendously.";
    } else if (algorithm == "Gnome Sort") {
        summary = "Gnome Sort: A sorting algorithm originally proposed by an Iranian computer scientist Hamid Sarbazi-Azad in 2000.";
    } else if (algorithm == "Pigeonhole Sort") {
        summary = "Pigeonhole Sort: A sorting algorithm that is suitable for sorting lists of elements where the number of elements and the number of possible key values are approximately the same.";
    } else if (algorithm == "Cycle Sort") {
        summary = "Cycle Sort: An in-place, unstable sorting algorithm, a comparison sort that is theoretically optimal in terms of the total number of writes to the original array.";
    } else if (algorithm == "Odd-Even Sort") {
        summary = "Odd-Even Sort: A simple sorting algorithm that alternates between comparing and swapping adjacent elements on odd and even indexed positions.";
    } else if (algorithm == "Bitonic Sort") {
        summary = "Bitonic Sort: A parallel sorting algorithm that builds bitonic sequences and sorts them.";
    } else if (algorithm == "Pancake Sort") {
        summary = "Pancake Sort: A sorting algorithm that sorts by flipping subarrays.";
    } else if (algorithm == "Cocktail Shaker Sort") {
        summary = "Cocktail Shaker Sort: A variation of Bubble Sort that sorts in both directions.";
    } else if (algorithm == "Stooge Sort") {
        summary = "Stooge Sort: A recursive sorting algorithm with high time complexity.";
    } else {
        summary = "Select an algorithm to see its summary.";
    }

    algorithmSummaryTextEdit->setText(summary);
}

void MainWindow::onSaveToFileButtonClicked() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Cannot open file: ") + file.errorString());
        return;
    }

    QTextStream out(&file);
    out << finalResultTextEdit->toPlainText();
    file.close();

    QMessageBox::information(this, "Success", "Results saved to file successfully.");
}

void MainWindow::onSortButtonClicked() {
    // Reset các thành phần liên quan
    ui->outputTextEdit->clear();
    progressBar->setValue(0);

    QString arrayText;

    // Xác định nguồn dữ liệu dựa trên lựa chọn của người dùng
    int selectedFunction = functionComboBox->currentIndex();
    switch (selectedFunction) {
    case 0: // Manual Input
        arrayText = ui->inputTextEdit->toPlainText();
        break;
    case 1: // Import from File
        arrayText = ui->fileContentTextEdit->toPlainText();
        break;
    case 2: // Generate Random
        arrayText = ui->generatedArrayTextEdit->toPlainText();
        break;
    default:
        QMessageBox::warning(this, "Error", "Invalid function selected.");
        return;
    }

    // Chuyển đổi chuỗi thành danh sách số nguyên
    QStringList arrayStringList = arrayText.split(" ", Qt::SkipEmptyParts);
    std::vector<int> array;
    for (const QString& numStr : arrayStringList) {
        array.push_back(numStr.toInt());
    }

    progressBar->setMaximum(array.size());

    // Lấy thuật toán đã chọn
    QString selectedAlgorithm = ui->comboBox->currentText();

    // Chuỗi để lưu kết quả từng bước
    QString resultSteps;

    // Đo thời gian thực hiện sắp xếp
    QElapsedTimer timer;
    timer.start();

    // Sắp xếp mảng dựa trên thuật toán đã chọn
    if (selectedAlgorithm == "Insertion Sort") {
        resultSteps = insertionSortWithSteps(array);
    } else if (selectedAlgorithm == "Selection Sort") {
        resultSteps = selectionSortWithSteps(array);
    } else if (selectedAlgorithm == "Bubble Sort") {
        resultSteps = bubbleSortWithSteps(array);
    } else if (selectedAlgorithm == "Merge Sort") {
        resultSteps = mergeSortWithSteps(array, 0, array.size() - 1);
    } else if (selectedAlgorithm == "Quick Sort") {
        resultSteps = quickSortWithSteps(array, 0, array.size() - 1);
    } else if (selectedAlgorithm == "Heap Sort") {
        resultSteps = heapSortWithSteps(array);
    } else if (selectedAlgorithm == "Shell Sort") {
        resultSteps = shellSortWithSteps(array);
    } else if (selectedAlgorithm == "Radix Sort") {
        resultSteps = radixSortWithSteps(array);
    } else if (selectedAlgorithm == "Counting Sort") {
        resultSteps = countingSortWithSteps(array);
    } else if (selectedAlgorithm == "Bucket Sort") {
        resultSteps = bucketSortWithSteps(array);
    } else if (selectedAlgorithm == "Tim Sort") {
        resultSteps = timSortWithSteps(array);
    } else if (selectedAlgorithm == "Comb Sort") {
        resultSteps = combSortWithSteps(array);
    } else if (selectedAlgorithm == "Gnome Sort") {
        resultSteps = gnomeSortWithSteps(array);
    } else if (selectedAlgorithm == "Pigeonhole Sort") {
        resultSteps = pigeonholeSortWithSteps(array);
    } else if (selectedAlgorithm == "Cycle Sort") {
        resultSteps = cycleSortWithSteps(array);
    } else if (selectedAlgorithm == "Odd-Even Sort") {
        resultSteps = oddEvenSortWithSteps(array);
    } else if (selectedAlgorithm == "Bitonic Sort") {
        resultSteps = bitonicSortWithSteps(array);
    } else if (selectedAlgorithm == "Pancake Sort") {
        resultSteps = pancakeSortWithSteps(array);
    } else if (selectedAlgorithm == "Cocktail Shaker Sort") {
        resultSteps = cocktailShakerSortWithSteps(array);
    } else if (selectedAlgorithm == "Stooge Sort") {
        resultSteps = stoogeSortWithSteps(array);
    } else {
        QMessageBox::warning(this, "Error", "Invalid sorting algorithm selected.");
        return;
    }

    qint64 elapsedTime = timer.elapsed(); // Thời gian thực hiện sắp xếp

    timeLabel->setText(QString("Time: %1 ms").arg(elapsedTime));

    for (int i = 0; i < array.size(); ++i) {
        progressBar->setValue(i + 1);
        QCoreApplication::processEvents();
    }

    // Hiển thị kết quả từng bước
    ui->outputTextEdit->setText(resultSteps);

    QString finalResult;
    for (size_t i = 0; i < array.size(); ++i) {
        finalResult += QString::number(array[i]) + " ";
    }
    finalResultTextEdit->setText(finalResult.trimmed());

    // Hiển thị thời gian thực hiện
    QMessageBox::information(this, "Sorting Time", QString("Sorting completed in %1 ms").arg(elapsedTime));
}
