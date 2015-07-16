#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow){
	ui->setupUi(this);
}

MainWindow::~MainWindow(){
	delete ui;
}

vector<int> layersize={48,48,96};
void MainWindow::on_pushButton_clicked(){
	static bool busy=false;
	if(busy)return;
	busy=true;
	int sidesize=0;for(int a:layersize)sidesize+=a;
	int layer=ui->layer->currentIndex();
	int globalindex=ui->detector->value()-1;
	for(int i=0;i<layer;i++)globalindex+=layersize[i];
	globalindex+=sidesize*ui->sidebox->currentIndex();
	ui->phm_index->setValue(globalindex+1);
	on_pushButton_3_clicked();
	busy=false;
}
void MainWindow::on_pushButton_2_clicked(){
	static bool busy=false;
	if(busy)return;
	busy=true;
	ui->phm_index->setValue(ui->blockbox->currentIndex()*32+ui->slot->value()+1);
	on_pushButton_3_clicked();
	busy=false;
}
void MainWindow::on_pushButton_3_clicked(){
	static bool busy=false;
	if(busy)return;
	busy=true;
	int globalnumber=ui->phm_index->value()-1;
	int sidesize=0;for(int a:layersize)sidesize+=a;
	ui->sidebox->setCurrentIndex(globalnumber/sidesize);
	int sidenumber=globalnumber%sidesize;
	int layer=0;
	while(sidenumber>=layersize[layer]){
		sidenumber-=layersize[layer];
		layer++;
	}
	ui->layer->setCurrentIndex(layer);
	ui->detector->setValue(sidenumber+1);
	ui->blockbox->setCurrentIndex(globalnumber/32);
	ui->slot->setValue(globalnumber%32);
	busy=false;
}
void MainWindow::on_layer_currentIndexChanged(int index){
	ui->detector->setMaximum(layersize[index]);
}
