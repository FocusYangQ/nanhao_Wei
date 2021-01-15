#include "NanHao.h"

#include <qdatetime.h>
#include <qmessagebox.h>
#pragma execution_character_set("utf-8") 

NanHao::NanHao(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void NanHao::on_loginBt_clicked()
{
	//win2 = new NanHao__main;
	win2.showFullScreen();
	QTime dieTime = QTime::currentTime().addMSecs(10);
	while (QTime::currentTime()<dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
	}
	this->close();
}
void NanHao::on_registerBt_clicked()
{
	QMessageBox::warning(this, "warning", "抱歉，此功能尚未开发!", QMessageBox::Ok, QMessageBox::Ok);
}