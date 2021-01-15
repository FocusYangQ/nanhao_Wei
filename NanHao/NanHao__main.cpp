#include "NanHao__main.h"
#include "NanHao_main_candidates.h"
#pragma execution_character_set("utf-8")
#include <qtimer.h>

//#include <gdiplus.h>

NanHao__main::NanHao__main(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//win_main = this;
	//win_main = new NanHao__main;
	//setAttribute(Qt::WA_DeleteOnClose);
}

NanHao__main::~NanHao__main()
{
	//delete win_main;
}



void NanHao__main::votes()
{
	//dlg_votes = new NanHao_main_votes;
	dlg_votes.showFullScreen();
	QTime dieTime = QTime::currentTime().addMSecs(10);
	while (QTime::currentTime()<dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
	}
	this->hide();
	dlg_votes.exec();
	this->showFullScreen();
}


void NanHao__main::candidate()
{
	//dlg_candidate = new NanHao_main_candidates;
	dlg_candidate.showFullScreen();
	QTime dieTime = QTime::currentTime().addMSecs(10);
	while (QTime::currentTime()<dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
	}
	this->hide();
	dlg_candidate.exec();
	this->showFullScreen();
}
void NanHao__main::statistics()
{
	//dlg_statistics = new NanHao_main_statistics;
	dlg_statistics.showFullScreen();
	QTime dieTime = QTime::currentTime().addMSecs(10);
	while (QTime::currentTime()<dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
	}
	this->hide();
	dlg_statistics.exec();
	this->showFullScreen();
}


void NanHao__main::exit()
{
	QMessageBox::StandardButton result = QMessageBox::warning(this, "退出", "确定要退出吗？", QMessageBox::Yes | QMessageBox::Cancel, QMessageBox::Yes);
	switch (result)
	{
	case QMessageBox::Yes:
		this->close();
		//close();
		break;
	case QMessageBox::Cancel:
		break;
	default:
		break;
	}

}

/*void nanhao_sys3::on_readingBar_clicked()
{

}*/