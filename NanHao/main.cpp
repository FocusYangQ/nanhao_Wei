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
	if (shared.attach())  //������Դ��ռ����ֱ�ӷ���
	{
		//QMessageBox::information(NULL, "����", "Ӧ�ó������������У�");
		return 0;
	}
	shared.create(1);  //������Դû�б�ռ���򴴽�UI
	w.showFullScreen();
    return a.exec();
}
