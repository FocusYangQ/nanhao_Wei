#pragma once
#include "ui_NanHao_main_candidates.h"
#include "scanxprlib.h"
using namespace ScanXprLib;
class NanHao__main;

class NanHao_main_candidates : public QDialog
{
	Q_OBJECT

public:
	NanHao_main_candidates(QWidget *parent = Q_NULLPTR);
	~NanHao_main_candidates();
	QString importExcel();
	QString inputName();
	QString get_names();
	QString get_models();

private:
	Ui::NanHao_main_candidates ui;

public slots:
	void returns();
	QString import();
	QString import_model();
	//NanHao__main *tmps;
public:
	//QString namess;
	static QString name;
	static QString  models;
	
	//NanHao_main_candidates *dlg_candidate;
};
