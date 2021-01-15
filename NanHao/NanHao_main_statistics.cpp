#include "NanHao_main_statistics.h"
#include <qinputdialog.h>
#include <qmessagebox.h>
#include <qdebug.h>
#include <qfiledialog.h>
#include <qfileinfo.h>
#include <QTextCodec>
#include "NanHao__main.h"
#include <iostream>
using namespace std;
#pragma execution_character_set("utf-8") 

NanHao_main_statistics::NanHao_main_statistics(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->votes_statistics_table();
	this->sort_table();
	db_sort = QSqlDatabase::addDatabase("QSQLITE");
	db_sort.setDatabaseName("electionResults.db");
	db_sort.open();
	QSqlQuery sql;
	sql.exec("CREATE TABLE election_results('name' TEXT NOT NULL, 'votes' INTEGER NOT NULL);");

	//PRIMARY KEY('排名' AUTOINCREMENT),
	//sql.exec("INSERT INTO election_results('排名','姓名','所获票数') VALUES('1','wei','9');");

}

NanHao_main_statistics::~NanHao_main_statistics()
{
}

void NanHao_main_statistics::votes_statistics_table()
{
	votes_model = new QStandardItemModel();
	ui.votesTv->setShowGrid(true);//背景网格线设置//显示
	ui.votesTv->setGridStyle(Qt::SolidLine);
	ui.votesTv->setEditTriggers(QAbstractItemView::NoEditTriggers);

	votes_model->setRowCount(3);                       //设置列字段名
													   //votes_model->setHeaderData(0, Qt::Vertical, "发票数");
	votes_model->setHeaderData(0, Qt::Vertical, "收票数");
	votes_model->setHeaderData(1, Qt::Vertical, "有效票");
	votes_model->setHeaderData(2, Qt::Vertical, "无效票");

	votes_model->setColumnCount(1);
	votes_model->setHeaderData(0, Qt::Horizontal, "数量");
	ui.votesTv->setModel(votes_model);
	ui.votesTv->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	ui.votesTv->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
}

void NanHao_main_statistics::sort_table()
{
	sort_model = new QStandardItemModel();
	sort_model->setColumnCount(2);
	sort_model->setHeaderData(0, Qt::Horizontal, "排名");
	sort_model->setHeaderData(1, Qt::Horizontal, "所获票数");
	ui.sortTv->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.sortTv->setModel(sort_model);
	ui.sortTv->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	ui.sortTv->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
}


//int NanHao_main_statistics::count()
//{
//	bool ok;
//	QString text = QInputDialog::getText(this,"Input", "请输入发票总数", QLineEdit::Normal, 0, &ok);
//	if (ok && !text.isEmpty())
//	{
//		//cout << "successful!" << endl;
//		return text.toInt();
//	}
//	//QString error= QMessageBox::critical(NULL, "Error", QStringLiteral("输入错误！请重新输入！"), QMessageBox::Yes, QMessageBox::Yes);
//		
//
//}
void NanHao_main_statistics::result()
{
	NanHao_main_statistics tmp;
	QSqlQuery sql;
	//total_votes = tmp.count();                //总发票数
	get_votes = temp.get_getVotes();          //收票数
	invalid_votes = temp.get_invalidVotes();  //无效票
	valid_votes = get_votes - invalid_votes;  //有效票
	cand_name = candidates.get_names(); //候选人名字
	if (get_votes == 0)
	{
		QMessageBox::warning(this, "提示", "抱歉，您的收票数为0，请检查是否扫描正确！", QMessageBox::Ok, QMessageBox::Ok);
		return;
	}
	else if (cand_name==" ")
	{
		QMessageBox::warning(this, "提示", "抱歉，未检测到候选人名单，请检查是否正确导入候选人！", QMessageBox::Ok, QMessageBox::Ok);
		return;
	}
	votes_model->setItem(0, 0, new QStandardItem(QString("%1").arg(get_votes)));
	votes_model->setItem(1, 0, new QStandardItem(QString("%1").arg(valid_votes)));
	votes_model->setItem(2, 0, new QStandardItem(QString("%1").arg(invalid_votes)));

	//QString::fromLocal8Bit(temp.get_sort_votes_name().at(0).first.c_str())  //sring转qstring


	for (int i = 0; i < temp.get_sort_votes_name().size(); i++)
	{
		QString Name = QString::fromLocal8Bit(temp.get_sort_votes_name().at(i).first.c_str());
		int Votes = temp.get_sort_votes_name().at(i).second;
		sort_model->setItem(i, 0, new QStandardItem(QString("%1").arg(Name)));
		sort_model->setItem(i, 1, new QStandardItem(QString("%1").arg(Votes)));

		QString sqlquery1;
		sqlquery1 = QObject::tr("insert into election_results values('%1','%2');").arg(Name).arg(Votes);
		//sqlquery2 = QObject::tr("UPDATE election_results SET votes=%1 WHERE name=%2;").arg(Votes).arg(Name);
		//sqlquery3 = QObject::tr("SELECT name FROM election_results WHERE name=%1;").arg(Name);

		if (!sql.exec(sqlquery1))
		{
			qDebug() << sql.lastError();
		}



		//QSqlRecord rec = sql.record();

		//qDebug() << "表的列数：" << rec.count();         // 表一共有多少列 
		//qDebug() << "表的行数：" << sql.size();       // 表一共有多少行

		//int col = rec.indexOf("name");       // 获得属性"name"在表中的下标（从第0列开始数，第几列）

		//if (!sql.exec(sqlquery3))
		//{
		//	qDebug() << sql.lastError();
		//}
		//else
		//{
		//	while (sql.next())
		//	{
		//		//qDebug() << sql.value(col).toString();  // 输出列名"name"下的所有值
		//		if (sql.value(0).toString().isEmpty())
		//		{
		//			sql.exec(sqlquery1);
		//		}
		//		else
		//		{
		//			sql3.exec(sqlquery2);
		//		}
		//	}
		//}

		//sql.exec(sqlquery1);

		//sql.exec(QString("INSERT INTO election_results('姓名','所获票数') VALUES(%1,%2)").arg(Name).arg(Votes));
		//sql.exec(QString("UPDATE election_results SET 所获票数 =%1 WHERE 姓名=%2 ").arg(Votes).arg(Name));
	}
	db_sort.close();
}

void NanHao_main_statistics::txt_export()
{
	NanHao_main_statistics tmp;
	QSqlQuery sql;
	get_votes = temp.get_getVotes();          //收票数
	invalid_votes = temp.get_invalidVotes();  //无效票
	valid_votes = get_votes - invalid_votes;  //有效票
	if (get_votes == 0)
	{
		QMessageBox::warning(this, "提示", "抱歉，您的收票数为0，请检查是否扫描正确！", QMessageBox::Ok, QMessageBox::Ok);
		return;
	}
	
	QString txt_name = QFileDialog::getSaveFileName(this, tr("选择文件"), "/评选结果", tr("Text File(*.txt)"));
	//qDebug() << txt_name << endl;
	QFile file(txt_name);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		qDebug() << file.errorString();
		return;
	}
	file.seek(0);
	QTextStream xieru(&file);
	xieru.setCodec(QTextCodec::codecForName("utf-8"));
	xieru << QString::fromStdString("收票数：") << get_votes << endl << QString::fromStdString("有效票：") << valid_votes << endl << QString::fromStdString("无效票：") << invalid_votes << endl << endl << endl;
	xieru << QString::fromStdString( "排名：") << endl;
	for (int i = 0; i < temp.get_sort_votes_name().size(); i++)
	{
		QString Name = QString::fromLocal8Bit(temp.get_sort_votes_name().at(i).first.c_str());
		int Votes = temp.get_sort_votes_name().at(i).second;
		xieru << Name << ":" << Votes << endl;
	}
	QMessageBox::warning(this, "提示", "导出成功！", QMessageBox::Ok, QMessageBox::Ok);
	file.close();
}



void NanHao_main_statistics::back()
{
	/*mainWin = new NanHao__main;
	mainWin->showFullScreen();
	QTime dieTime = QTime::currentTime().addMSecs(10);
	while (QTime::currentTime()<dieTime)
	{
	QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
	}*/
	this->hide();
}