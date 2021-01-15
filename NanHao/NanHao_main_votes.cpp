#include "NanHao_main_votes.h"
#include <qdebug.h>
#include <vector>
#include <io.h>
#include<string>
#include <QTextCodec>
#include <qdir.h>
#include <algorithm>

#include "NanHao__main.h"

#pragma execution_character_set("utf-8")  

bool cmp_by_value(const PAIR& lhs, const PAIR& rhs)
{
	return lhs.second < rhs.second;
}

ostream& operator<<(ostream& out, const PAIR& p)
{
	return out << p.first << "\t" << p.second;
}

int NanHao_main_votes::getVotes = 0;
int NanHao_main_votes::invalidVotes = 0;
QString NanHao_main_votes::sortName = ",";
vector<PAIR> NanHao_main_votes::sort_votes_name_vec;
int NanHao_main_votes::set_ = 0;
int NanHao_main_votes::a[100] = { 0 };
int NanHao_main_votes::sizeStart = 0;
int NanHao_main_votes::firstSize = 0;

NanHao_main_votes::NanHao_main_votes(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->createlist();
	getFiles(filePath, firstFiles);
	firstSize = firstFiles.size();
}

NanHao_main_votes::~NanHao_main_votes()
{
	//delete m_scan;
	//delete model;
}

void NanHao_main_votes::createlist()
{

	ui.listTv->setShowGrid(true);//背景网格线设置//显示
	ui.listTv->setGridStyle(Qt::SolidLine);

	//设置表
	ui.listTv->verticalHeader()->setVisible(true);
	//ui.listTv->setSortingEnabled(true);  //自动排序
	model = new QStandardItemModel();
	//QStringList labels = QStringLiteral("试卷类型,准考证号").simplified().split(",");
	//model->setHorizontalHeaderLabels(labels);
	ui.listTv->setModel(model);
	ui.listTv->show();

}
long long int f(const string& str) 
{
	long long int res = 0;
	for (int i = 0; i < str.size(); i++)
	{
		res = res * 10 + str[i] - '0';

	}
	return res;
}
bool comparator(const string& src1, const string& src2)
{

	string find_src = ".pcd";

	long long int num1 = f(src1.substr(0, src1.find(find_src)));
	long long int num2 = f(src2.substr(0, src2.find(find_src)));
	if (num1 > num2) {
		return 0;
	}
	else
	{
		return 1;
	}
}

void NanHao_main_votes::getFiles(string path, vector<string>& files)
{
	//文件句柄
	long   hFile = 0;
	//文件信息
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("/*.tif").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之
			//如果不是,加入列表
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFiles(p.assign(path).append("/").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("/").append(fileinfo.name));
				//files.push_back(fileinfo.name);
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

// 获取目录下所有文件(按时间排序)(JAVA)
/*static vector<string> getFileSort(vector<string>& list)
{
	if (list.empty()==false && list.size() > 0) 
	{
		Collections.sort(list, new Comparator<File>() 
		{
			public int compare(File file, File newFile) {
				if (file.lastModified() < newFile.lastModified()) {//降序<;升序>
					return 1;
				}
				else if (file.lastModified() == newFile.lastModified()) {
					return 0;
				}
				else {
					return -1;
				}
			}
		});
	}
	return list;
}*/



bool NanHao_main_votes::test_temp_dict_1(paper_template_definition *ptd)
{
	model->setHorizontalHeaderLabels((QStringList)cand.get_names().simplified().split(","));

	temp_data *td = ptd->get_temp_data(0);
	temp_dict_utils tdu(ptd);
	vector<string> recFiles;
	getFiles(filePath, recFiles);   //获取该路径下的所有文件
	sort(recFiles.begin(), recFiles.end(), comparator);
	/*for (int i = 0; i < recFiles.size(); i++)
	{
	cout << recFiles[i] << endl;
	}*/
	int size = recFiles.size();
	getVotes += size - sizeStart;

	if (size == 0)
	{
		return false;
	}
	//cout << getVotes << " " << firstSize << "  " << sizeStart << endl;
	for (int i = sizeStart; i<size; i++)
	{
		const bool print = true;
		const char *file = recFiles[i].c_str();
		Bitmap bmp;
		if (bmp.ReadImage(file, false))
		{
			int width = bmp.GetWidth(), height = bmp.GetHeight();
			byte *data = new byte[width*height + 1];
			bmp.GetData(Bitmap::GRAY, data);
			if (print)
			{
				printf("%s\n width = %d, height = %d\n", file, width, height);
			}

			bool updown = true;
			/*int id = ptd->get_best_temp(width, height, data, updown);
			cout << id << endl;*/
			td->content_match = 0.6f;
			//printf("  page id = %d, updown = %s\n", id, updown ? "true" : "false");

			if (ptd->auto_alignment_by_content(td, width, height, data, print))
			{
				bmp.SetData(Bitmap::GRAY, data);
				//bmp.WriteImage("asd.tif");
				tdu.set_temp_data(td, width, height, data);
				tdu.proc_blocks(false, file);
				/*for (int j = 0; j < tdu.tas.choice_num; j++)
				{
				cout << 1 + j << "." << tdu.tas.choice_str[j][0] << endl;
				}*/

				//投票结果
				for (int j = 0; j < tdu.tas.choice_num; j++)
				{
					if (tdu.tas.choice_str[j][0] == 'A')
					{
						a[j] += 1;
					}

				}
				//判断是否是空卡
				/*for (int j = 0, num = 0; j < tdu.tas.choice_num; j++)
				{
				for (int p = 0; p < 8; p++)
				{
				if (tdu.tas.choice_str[j][p] == 'A')
				{
				num++;
				break;
				}
				else if (tdu.tas.choice_str[j][p] == 0 && num == 0 && j == tdu.tas.choice_num - 1 && p == 7)
				{
				//cout << tdu.tas.choice_str << endl;
				invalidVotes++;
				}
				}
				}*/
			}
			else
			{
				invalidVotes++;
			}
			delete[] data;
		}
		else if (print)
		{
			printf(" error: can not read the image file %s\n", file);
		}
	}

	//cout << getVotes << " " << firstSize << "  " << sizeStart << endl;

	for (int i = 0; i < tdu.tas.choice_num; i++)
	{
		int key = a[i];
		//str_name = cand.get_names().section(",", i, i).toStdString();

		QTextCodec* pCode = QTextCodec::codecForName("gb18030");  //编码转换
		if (NULL != pCode)
		{
			str_name = pCode->fromUnicode(cand.get_names().section(",", i, i)).data();
			if (str_name.length() == 0)
			{
				str_name = pCode->fromUnicode(QString("另选他人%1").arg(i - 8));
			}
		}
		//cout << str_name << endl;
		votes_name_map[str_name] = key;
	}
	vector<PAIR>votes_name_vec(votes_name_map.begin(), votes_name_map.end());
	sort(votes_name_vec.begin(), votes_name_vec.end(), cmp_by_value);
	reverse(votes_name_vec.begin(), votes_name_vec.end());
	sort_votes_name_vec = votes_name_vec;
	//遍历测试
	/*for (int i = 0; i < sort_votes_name_vec.size(); i++)
	{
	cout << sort_votes_name_vec[i] << endl;
	}
	for (map<string, int>::iterator it = votes_name_map.begin(); it != votes_name_map.end(); ++it)
	{
	cout << *it << endl;
	}
	for (int i = 0; i < votes_name_vec.size(); i++)
	{
	cout << votes_name_vec[i] << endl;
	}*/

	return false;
}
void NanHao_main_votes::setting_scanner()
{
	if (ui.pushButton->isEnabled() == false)
	{
		qDebug() << "false" << endl;
		return;
	}
	m_scan.SetScanName("nh4080");
	if (!m_scan.ScannerLoaded())
	{
		QMessageBox::warning(this, "warning", "扫描仪加载失败，请检查是否正确连接!", QMessageBox::Ok, QMessageBox::Ok);
		return;
	}
	else
	{
		m_scan.SettingsDialog();
		//m_scan.SaveSettings();
		//m_scan.LoadSettings()
		set_ = 1;
	}
	//m_scan.About();
}
void NanHao_main_votes::scan()
{
	if (ui.pushButton_2->isEnabled() == false)
	{
		qDebug() << "false" << endl;
		return;
	}
	if (set_ == 0)
	{
		QMessageBox::warning(this, "warning", "请先设置扫描仪!", QMessageBox::Ok, QMessageBox::Ok);
		return;
	}
	else if (!m_scan.ScannerLoaded())
	{
		QMessageBox::warning(this, "warning", "扫描仪加载失败，请检查是否正确连接!", QMessageBox::Ok, QMessageBox::Ok);
		return;
	}
	//clearFiles("test");  //清空文件夹
	//model->removeRows(0, model->rowCount()); //清空qtableview
	vector<string> startFiles;
	getFiles(filePath, startFiles);   //获取该路径下的所有文件名
	sizeStart = startFiles.size();
	//cout << sizeStart << endl;
	string modelsName = cand.get_models().toStdString();
	const char *models = modelsName.c_str();
	m_scan.SetUseSchema(true);
	m_scan.SetScanFileRoot("test");
	m_scan.SetScanFileDir("test");
	if (sizeStart != 0)
	{
		m_scan.SetScanFileSchema(QString("$%1###").arg(sizeStart));
	}
	else
	{
		m_scan.SetScanFileSchema("$###");
	}

	//m_scan.SetScanFileName("test.tif");
	m_scan.SetCreateFile(true);
	m_scan.SetCreateDib(false);
	m_scan.SetScanMultiPage(false);
	m_scan.ClearScanAheadPages();
	m_scan.LoadPipe();

	//需分线程
	bool test = false;
	ui.exitBt->setEnabled(false);
	ui.exitBt_2->setEnabled(false);
	ui.pushButton->setEnabled(false);
	ui.pushButton_2->setEnabled(false);
	m_scan.ScanBatch();

	//显示正在扫描的弹窗
	//扫描结束后显示已扫描多少张，是否继续

	
	//if (ptds.load_dict("xuanpiao_9.dic"))
	if (ptds.load_dict(models))
	{
		test_temp_dict_1(&ptds);
		ui.exitBt->setEnabled(true);
		ui.exitBt_2->setEnabled(true);
		ui.pushButton->setEnabled(true);
		ui.pushButton_2->setEnabled(true);
	}
	else
	{
		QMessageBox::warning(this, "", "模板加载失败！", QMessageBox::Ok, QMessageBox::Ok);
	}

}

void NanHao_main_votes::clearFiles(const QString &folderFullPath)
{
	QDir dir(folderFullPath);
	dir.setFilter(QDir::Files);
	int fileCount = dir.count();
	for (int i = 0; i < fileCount; i++)
		dir.remove(dir[i]);
}

void NanHao_main_votes::clear()
{
	if (ui.exitBt_2->isEnabled() == false)
	{
		qDebug() << "false" << endl;
		return;
	}
	QMessageBox::StandardButton result = QMessageBox::warning(this, "清空", "确定要清空吗？", QMessageBox::Yes | QMessageBox::Cancel, QMessageBox::Yes);
	switch (result)
	{
	case QMessageBox::Yes:
		for (; getVotes >= 0; getVotes--)
		{
			model->removeRow(getVotes);
		}
		QMessageBox::warning(this, "清空", "清空成功！", QMessageBox::Ok, QMessageBox::Ok);
		//close();
		break;
	case QMessageBox::Cancel:
		break;
	default:
		break;
	}
}

void NanHao_main_votes::returns()
{
	//qDebug() << ui.exitBt->isEnabled() << endl;
	if (ui.exitBt->isEnabled()==false)
	{
		qDebug() << "false" << endl;
		return;
	}
	/*mainWin = new NanHao__main;
	mainWin->showFullScreen();
	QTime dieTime = QTime::currentTime().addMSecs(10);
	while (QTime::currentTime()<dieTime)
	{
	QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
	}*/
	this->hide();
}

int NanHao_main_votes::get_getVotes()
{
	return getVotes;
}

int NanHao_main_votes::get_invalidVotes()
{
	return invalidVotes;
}

vector<PAIR> NanHao_main_votes::get_sort_votes_name()
{
	return sort_votes_name_vec;
}
