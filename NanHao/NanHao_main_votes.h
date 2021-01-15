#pragma once

#include <QDialog>
#include "ui_NanHao_main_votes.h"
#include "paper_template_definition.h"
#include "graphics.h"
#include "scanxprlib.h"
#include "NanHao_main_candidates.h"

#include "qstandarditemmodel.h"
#include <qmessagebox.h>
#include <map>
#include <iostream>
using namespace std;
using namespace ScanXprLib;
using namespace QtMetaTypePrivate;
typedef pair<string, int> PAIR;
class NanHao__main;

class NanHao_main_votes : public QDialog
{
	Q_OBJECT
public:
	NanHao_main_votes(QWidget *parent = Q_NULLPTR);
	~NanHao_main_votes();
	void createlist();
	void getFiles(string path, vector<string>& files);
	//List<File> getFileSort(String path);
	bool test_temp_dict_1(paper_template_definition *ptd);
	int get_getVotes();   //��ȡ��Ʊ��
	int get_invalidVotes(); //��ȡ��ЧƱ��
	vector<PAIR> get_sort_votes_name(); //��ȡ����
	void clearFiles(const QString &folderFullPath);  //����ļ���

													 //NanHao__main *mainWin;

private:
	Ui::NanHao_main_votes ui;
	QStandardItemModel *model;
	QStandardItem *item;
	paper_template_definition ptds;
	NanHao_main_candidates cand;
	static int getVotes;    //��Ʊ��
	static int invalidVotes;  //��ЧƱ
	static QString sortName;  //����
	map<string, int> votes_name_map;
	static vector<PAIR> sort_votes_name_vec; //����
	static int a[100];

	static int set_;
	static int sizeStart;
	static int firstSize;

	ScanXpress m_scan;
	int keys[100];
	string str_name;
	vector<string> firstFiles;

	string filePath = "test";

	public slots:
	void setting_scanner();
	void scan();
	void clear();
	void returns();
};
