#include "NanHao.h"
#include "NanHao_main_votes.h"
#include <QtWidgets/QApplication>
#include <qsharedmemory.h>
#pragma execution_character_set("utf-8")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NanHao w;
    //w.show();
	QSharedMemory shared("NanHao");
	if (shared.attach())  //共享资源被占用则直接返回
	{
		//QMessageBox::information(NULL, "警告", "应用程序正在运行中！");
		return 0;
	}
	shared.create(1);  //共享资源没有被占用则创建UI
	w.showFullScreen();
    return a.exec();
}
