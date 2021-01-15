#include "NanHao_main_candidates.h"
#include "NanHao__main.h"
#include <qdir.h>
#include <qfiledialog.h>
#include <qfileinfo.h>
#include <qstandardpaths.h>
#include <qdebug.h>
#include <qmessagebox.h>
#include <qinputdialog.h>
#include <QAxObject>
#include <iostream>
using namespace std;
#pragma execution_character_set("utf-8")  

QString NanHao_main_candidates::name = " ";
QString NanHao_main_candidates::models = " ";


NanHao_main_candidates::NanHao_main_candidates(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//dlg_candidate = this;
}

NanHao_main_candidates::~NanHao_main_candidates()
{
	/*delete tmps;*/
}


QString NanHao_main_candidates::import()
{
	if (name != " ")
	{
		QMessageBox::StandardButton refresh= QMessageBox::warning(this, "提示", "您已导入候选人，是否重新导入？", QMessageBox::Yes | QMessageBox::Cancel, QMessageBox::Cancel);
		switch (refresh)
		{
		case QMessageBox::Yes:
			name = " ";
			break;
		case QMessageBox::Cancel:
			return 0;
		default:
			break;
		}
	}
	QString txt_name = QFileDialog::getOpenFileName(this, "选择文件", "", tr("txt file(*.txt)"));
	//qDebug() << txt_name << endl;
	QFile file(txt_name);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::StandardButton imp_name = QMessageBox::warning(this, "提示", "未成功导入候选人，请重新导入！",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
		switch (imp_name)
		{
		case QMessageBox::Ok:
			import();
			break;
		case QMessageBox::Cancel:
			break;
		default:
			break;
		}
		qDebug() << file.errorString();
		return 0;
	}
	file.seek(0);

	QTextStream shuru(&file);
	while (!shuru.atEnd())
	{
		QString line = shuru.readLine();
		name += line + ",";
		//qDebug() << line;
	}
	QMessageBox::warning(this, "导入", "导入成功！", QMessageBox::Ok, QMessageBox::Ok);
	if (name[name.length() - 1] == ",")
	{
		name[name.length() - 1] = ' ';
		//cout << namess.simplified().split(",").count();
	}
	file.close();
	qDebug() << name;
	return name;
}


QString NanHao_main_candidates::import_model()
{
	if (models != " ")
	{
		QMessageBox::StandardButton refresh = QMessageBox::warning(this, "提示", "您已导入模板，是否重新导入？", QMessageBox::Yes | QMessageBox::Cancel, QMessageBox::Cancel);
		switch (refresh)
		{
		case QMessageBox::Yes:
			models = " ";
			break;
		case QMessageBox::Cancel:
			return 0;
		default:
			break;
		}
	}
	QString dic_name = QFileDialog::getOpenFileName(this, "选择文件", "", tr("dic file(*.dic)"));
	models = dic_name;
	QMessageBox::warning(this, "导入", "导入成功！", QMessageBox::Ok, QMessageBox::Ok);
	return models;
}



QString NanHao_main_candidates::importExcel()
{
	///QAxObject

	QString strFile = QFileDialog::getOpenFileName(this, QStringLiteral("选择Excel文件"), "", tr("Exel file(*.xls *.xlsx)"));

	if (strFile.isEmpty())
	{
		return 0;
	}

	QAxObject excel("Excel.Application"); //加载Excel驱动    
	excel.setProperty("Visible", false); //不显示Excel界面，如果为true会看到启动的Excel界面   
	QAxObject* pWorkBooks = excel.querySubObject("WorkBooks");
	pWorkBooks->dynamicCall("Open (const QString&)", strFile);//打开指定文件
	QAxObject* pWorkBook = excel.querySubObject("ActiveWorkBook");
	QAxObject* pWorkSheets = pWorkBook->querySubObject("Sheets");//获取工作表   
	int nSheetCount = pWorkSheets->property("Count").toInt();  //获取工作表的数目



	if (nSheetCount > 0)
	{
		QAxObject* pWorkSheet = pWorkBook->querySubObject("Sheets(int)", 1);//获取第一张表       
		int nSection = 20;
		int nSectionEnd = 0;
		QVariantList params;
		int nRowEnd = 20;
		QVariant varData;
		for (int i = 1; i <= nRowEnd; i += nSection)
		{
			nSectionEnd = i + nSection - 1;
			if (nSectionEnd > nRowEnd)
			{
				nSectionEnd = nRowEnd;
			}
			char cZimu = 1 + 64; //1-26分别代表A-Z，符合Excel表的列标识            
								 //Ai至Ai+nSectionEnd的数据,这里为了测试一次是读取20条
			params << QString("%1%2").arg(cZimu).arg(i) << QString("%1%2").arg(cZimu).arg(nSectionEnd);
			QAxObject* pCell = pWorkSheet->querySubObject("Range(QVariant,QVariant)", params);
			varData = pCell->dynamicCall("Value2()");
			//qDebug() << varData;
		}
		//qDebug() << varData;

		QVariantList varList = varData.toList(); //解除第一层List 
												 //qDebug() << varList;
												 //qDebug() << varList.count(); //20
		if (varList.count() <= 0)//防止内存溢出       
		{
			qDebug() << "无数据！";
			pWorkBooks->dynamicCall("Close()");
			return 0;
		}

		QVariantList varLstData;
		QString tmp;
		for (int v = 0; v < varList.count(); v++)
		{
			//qDebug() << varList[v];
			varLstData = varList[v].toList(); //解除第二层List 
			if (varLstData.count() <= 0)
			{
				qDebug() << "无数据！";
				pWorkBooks->dynamicCall("Close()");
				return 0;
			}
			//qDebug() << varLstData;
			if (QString(varLstData[0].typeName()) == "QString")   //判断数据类型，防止转化出错。 
			{
				tmp = varLstData[0].toString();
				name = name + tmp + ",";
				if (v == varLstData.count() - 1)
				{
					QMessageBox::information(this, "导入Excel", "导入成功！", QMessageBox::Ok, QMessageBox::Ok);
				}
			}
			//if (QString(varLstData[0].typeName()) == "double")
			//{
			//	double dData = varLstData[0].toDouble(); //取出数据           
			//	qDebug() << dData;
			//	//注意，int型读出来也是double，所以一定要注意转化        
			//}


		}
		if (name[name.length() - 1] == ",")
		{
			name[name.length() - 1] = ' ';
			//cout << namess.simplified().split(",").count();
		}
		//qDebug() << namess;

		/*QByteArray ba = name.toLatin1();
		scname = ba.data();
		cout << scname << endl;*/
		//qDebug() << name.length();
	}
	pWorkBooks->dynamicCall("Close()");
	excel.dynamicCall("Quit(void)");
	//delete excel;
	//qDebug() << name;
	/*delete pWorkBooks;
	delete pWorkSheets;
	delete pWorkBook;*/
	return name;
}


QString NanHao_main_candidates::inputName()
{
	bool ok;
	QString text = QInputDialog::getText(this, "Input", "请输入姓名", QLineEdit::Normal, 0, &ok);
	name = text;
	return name;
}


QString NanHao_main_candidates::get_names()
{
	//qDebug() << name;
	return name;
}



QString NanHao_main_candidates::get_models()
{
	return models;
}

void NanHao_main_candidates::returns()
{
	/*mainWin = new NanHao__main;
	mainWin->showFullScreen();
	QTime dieTime = QTime::currentTime().addMSecs(10);
	while (QTime::currentTime()<dieTime)
	{
	QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
	}*/
	//NanHao__main *tmps;
	/*tmps->showFullScreen();
	QTime dieTime = QTime::currentTime().addMSecs(10);
	while (QTime::currentTime()<dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
	}*/
	this->hide();
}