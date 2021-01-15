#pragma once

#include <QDialog>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qsqlrecord.h>
#include <QSqlError>
#include "ui_NanHao_main_statistics.h"
#include "NanHao_main_votes.h"
class NanHao__main;

class NanHao_main_statistics : public QDialog
{
	Q_OBJECT

public:
	NanHao_main_statistics(QWidget *parent = Q_NULLPTR);
	~NanHao_main_statistics();

	void votes_statistics_table();
	void sort_table();
	int count();

	//NanHao__main *mainWin;

private:
	Ui::NanHao_main_statistics ui;
	NanHao_main_votes temp;
	NanHao_main_candidates candidates;
	//int total_votes=0;    //总票数
	int get_votes;      //收票数
	int valid_votes;    //有效票
	int invalid_votes;  //无效票
	QString cand_name;
	QStandardItemModel *votes_model;
	QStandardItemModel *sort_model;
	QStandardItem *item;

	QSqlDatabase db_sort;


	public slots:

	void result();
	void txt_export();
	void back();

};
