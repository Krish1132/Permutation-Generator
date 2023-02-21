#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::permutation(std::string s, std::string ans)
{
    if(s.length() == 0) {
        ui->textEdit->append(QString::fromStdString(ans));
        return;
    }
    for(int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        std::string res = s.substr(0, i) + s.substr(i + 1);

        permutation(res, ans + ch);
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    std::string query = ui->lineEdit->text().toUtf8().constData();
    MainWindow::permutation(query, "");
}

