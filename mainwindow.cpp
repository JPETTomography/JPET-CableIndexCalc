#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_layer_valueChanged(int arg1){
	if(arg1<3)
		ui->detector->setMaximum(48);
	else
		ui->detector->setMaximum(96);//last layer has more detectors
}

const uint max_absolute_index=48*2+96;
void MainWindow::on_pushButton_clicked(){
	uint abs_index=(ui->layer->value()-1)*48 + ui->detector->value() - 1;
	ui->block->setValue(abs_index/32);
	ui->slot->setValue(abs_index%32);
}

void MainWindow::on_pushButton_2_clicked(){
	uint abs_index=ui->block->value()*32+ui->slot->value();
	uint layer_no=abs_index/48;
	if(layer_no>2)
		layer_no=2;//last layer has more detectors
	ui->layer->setValue(layer_no+1);
	ui->detector->setValue((abs_index-(layer_no)*48)+1);
}
