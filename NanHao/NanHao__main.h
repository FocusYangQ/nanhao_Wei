#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_NanHao__main.h"

//class NanHao_main_votes;
//class NanHao_main_statistics;

#include "NanHao_main_votes.h"
#include "NanHao_main_statistics.h"

/*#include "paper_template_definition.h"
#include "graphics.h"
#include "scanxprlib.h"

#include "qstandarditemmodel.h"
#include <QDebug>
#include <qmessagebox.h>*/

#include <iostream>
using namespace std;

class NanHao_main_candidates;

class NanHao__main : public QWidget
{
	Q_OBJECT

public:
	NanHao__main(QWidget *parent = Q_NULLPTR);
	~NanHao__main();


	private slots:
	void votes();     //ÉùÃ÷²Ûº¯Êý
	void candidate();
	void statistics();
	void exit();
	//void clear();
	//void setting_scanner();
	//void on_readingBar_clicked();

private:
	Ui::NanHao__main ui;
	

public:
	NanHao_main_candidates dlg_candidate;
	NanHao_main_votes dlg_votes;
	NanHao_main_statistics dlg_statistics;
	//NanHao__main *win_main;
};
