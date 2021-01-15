#pragma once

#include <QWidget>
#include "ui_NanHao.h"
#include "NanHao__main.h"


class NanHao : public QMainWindow
{
	Q_OBJECT

public:
	NanHao(QWidget *parent = Q_NULLPTR);

	private slots:
	void on_loginBt_clicked();  //ÉùÃ÷²Ûº¯Êý
	void on_registerBt_clicked();

private:
	Ui::NanHaoClass ui;
	NanHao__main win2;
};
