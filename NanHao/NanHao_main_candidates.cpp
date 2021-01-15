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
		QMessageBox::StandardButton refresh= QMessageBox::warning(this, "��ʾ", "���ѵ����ѡ�ˣ��Ƿ����µ��룿", QMessageBox::Yes | QMessageBox::Cancel, QMessageBox::Cancel);
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
	QString txt_name = QFileDialog::getOpenFileName(this, "ѡ���ļ�", "", tr("txt file(*.txt)"));
	//qDebug() << txt_name << endl;
	QFile file(txt_name);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::StandardButton imp_name = QMessageBox::warning(this, "��ʾ", "δ�ɹ������ѡ�ˣ������µ��룡",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
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
	QMessageBox::warning(this, "����", "����ɹ���", QMessageBox::Ok, QMessageBox::Ok);
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
		QMessageBox::StandardButton refresh = QMessageBox::warning(this, "��ʾ", "���ѵ���ģ�壬�Ƿ����µ��룿", QMessageBox::Yes | QMessageBox::Cancel, QMessageBox::Cancel);
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
	QString dic_name = QFileDialog::getOpenFileName(this, "ѡ���ļ�", "", tr("dic file(*.dic)"));
	models = dic_name;
	QMessageBox::warning(this, "����", "����ɹ���", QMessageBox::Ok, QMessageBox::Ok);
	return models;
}



QString NanHao_main_candidates::importExcel()
{
	///QAxObject

	QString strFile = QFileDialog::getOpenFileName(this, QStringLiteral("ѡ��Excel�ļ�"), "", tr("Exel file(*.xls *.xlsx)"));

	if (strFile.isEmpty())
	{
		return 0;
	}

	QAxObject excel("Excel.Application"); //����Excel����    
	excel.setProperty("Visible", false); //����ʾExcel���棬���Ϊtrue�ῴ��������Excel����   
	QAxObject* pWorkBooks = excel.querySubObject("WorkBooks");
	pWorkBooks->dynamicCall("Open (const QString&)", strFile);//��ָ���ļ�
	QAxObject* pWorkBook = excel.querySubObject("ActiveWorkBook");
	QAxObject* pWorkSheets = pWorkBook->querySubObject("Sheets");//��ȡ������   
	int nSheetCount = pWorkSheets->property("Count").toInt();  //��ȡ���������Ŀ



	if (nSheetCount > 0)
	{
		QAxObject* pWorkSheet = pWorkBook->querySubObject("Sheets(int)", 1);//��ȡ��һ�ű�       
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
			char cZimu = 1 + 64; //1-26�ֱ����A-Z������Excel����б�ʶ            
								 //Ai��Ai+nSectionEnd������,����Ϊ�˲���һ���Ƕ�ȡ20��
			params << QString("%1%2").arg(cZimu).arg(i) << QString("%1%2").arg(cZimu).arg(nSectionEnd);
			QAxObject* pCell = pWorkSheet->querySubObject("Range(QVariant,QVariant)", params);
			varData = pCell->dynamicCall("Value2()");
			//qDebug() << varData;
		}
		//qDebug() << varData;

		QVariantList varList = varData.toList(); //�����һ��List 
												 //qDebug() << varList;
												 //qDebug() << varList.count(); //20
		if (varList.count() <= 0)//��ֹ�ڴ����       
		{
			qDebug() << "�����ݣ�";
			pWorkBooks->dynamicCall("Close()");
			return 0;
		}

		QVariantList varLstData;
		QString tmp;
		for (int v = 0; v < varList.count(); v++)
		{
			//qDebug() << varList[v];
			varLstData = varList[v].toList(); //����ڶ���List 
			if (varLstData.count() <= 0)
			{
				qDebug() << "�����ݣ�";
				pWorkBooks->dynamicCall("Close()");
				return 0;
			}
			//qDebug() << varLstData;
			if (QString(varLstData[0].typeName()) == "QString")   //�ж��������ͣ���ֹת������ 
			{
				tmp = varLstData[0].toString();
				name = name + tmp + ",";
				if (v == varLstData.count() - 1)
				{
					QMessageBox::information(this, "����Excel", "����ɹ���", QMessageBox::Ok, QMessageBox::Ok);
				}
			}
			//if (QString(varLstData[0].typeName()) == "double")
			//{
			//	double dData = varLstData[0].toDouble(); //ȡ������           
			//	qDebug() << dData;
			//	//ע�⣬int�Ͷ�����Ҳ��double������һ��Ҫע��ת��        
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
	QString text = QInputDialog::getText(this, "Input", "����������", QLineEdit::Normal, 0, &ok);
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