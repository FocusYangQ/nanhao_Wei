#pragma once
#include "public.h"
#pragma comment(lib, "paper_template_definition.lib")


// 单个答题区域数据结构
struct temp_data_block
{
	int  block_xyxy[4];
	int  block_attr;
	int  block_arg_len;
	int *block_arg;
};


// 选择题数据结构
struct temp_data_block_choice
{
	int row;       // 选项多少行
	int col;       // 选项多少列
	int xyxy[][5]; // 选项位置，填充比例[0-1000]
};


// 单个模板数据结构
struct temp_data
{
	int   id;
	int   subject;
	int   width;
	int   height;
	byte *image_bin;
	int   shrink_width;
	int   shrink_height;
	float*shrink_data;
	int   marker_num;
	int   marker_xyxy[5][4];
	int  *content;
	float content_match;
	int   block_num;
	temp_data_block **block_ptr;
};


// 字典文件结构
struct temp_dict
{
	int temp_num;
	temp_data **data_ptr;
};


class IMPORT paper_template_definition
{
public:
	paper_template_definition();
	~paper_template_definition();

	// operations for temp_data
	int  get_temp_num();
	int  get_best_temp(int width, int height, byte *bin, bool &updown);
	temp_data* push_back_temp_data();
	temp_data* get_temp_data(int index);
	bool erase_temp_data(int index);
	void set_temp_data_image(temp_data *data, int width, int height, byte *bin, float match);

	// operations for temp_data_block
	temp_data_block* push_back_temp_data_block(temp_data *data);
	temp_data_block* get_temp_data_block(temp_data *data, int index);
	bool erase_temp_data_block(temp_data *data, int index);
	void set_temp_data_block_arg_len(temp_data_block *block, int len);

	// save and load dictionary file
	bool save_dict(const char *filename);
	bool load_dict(const char *filename);

	// common image processing
	void image_color_to_binary(int width, int height, byte *bgr, byte *bin);
	void image_gray_to_binary(int width, int height, byte *gray, byte *bin);
	void image_rotate_180(int width, int height, byte *bin);
	void image_rotate_fine(int width, int height, byte *bin, double a);
	void image_translation(int width, int height, byte *bin, int dx, int dy);

	// marker based template alignment
	bool marker_auto_search(int width, int height, byte *bin, int xyxy[4]);
	double markers_to_rotation(int width, int height, int num, int xyxy[][4]);
	void markers_to_translation(int width, int height, int num, int xyxy_dict[][4], int xyxy[][4], int txy[2]);

	// content based template alignment
	double content_to_rotation(int width, int height, byte *bin);
	int  content_to_translation(int width, int height, byte *bin, temp_data *td, int txy[2]);

	// do auto alignment and save cropped block, return number of saved blocks
	bool auto_alignment_by_markers(temp_data *data, int width, int height, byte *gray, bool print);
	bool auto_alignment_by_content(temp_data *data, int width, int height, byte *gray, bool print);

	// special block processing
	rect get_block_location(temp_data *data, int width, int height, byte *bin, int iblock);
	bool search_choice_options(int width, int height, byte *bin, int xyxy[4], temp_data_block_choice *tdbc);
	void return_choice_options(int width, int height, byte *bin, int xyxy[4], temp_data_block_choice *tdbc);

protected:
	void release_temp_dict();
	void release_temp_data(temp_data* &data);
	void release_temp_data_block(temp_data_block* &block);

	int  label_regions(int w, int h, byte *im, byte b, int *L, int *s, bool br);
	void content_to_profiles(int w, int h, byte *im, int *cx, int *cy);
	void content_to_shrink(int w, int h, byte *im, int w1, int h1, float *im1);
	void segment_equal_space(int m, int *pm, int n, int *xn);
	void segment_exact_size(int m, int *pm, int n, int *xn, int *xxn);

	temp_dict dict;
};


enum temp_data_block_attr
{
	UNDEFINED,           // 未定义
	EXAM_TYPE,           // 试卷类型
	EXAM_CODE,           // 试卷编号
	STUDENT_NUM,         // 学生准考证号
	SUBJECT_SCORE,       // 主观题分
	ROW_SINGLE_CHOICE,   // 行单项选择题
	ROW_MULTI_CHOICE,    // 行多项选择题
	COL_SINGLE_CHOICE,   // 列单项选择题
	COL_MULTI_CHOICE,    // 列多项选择题
};


struct temp_answer_sheet
{
	//char exam_type;
	char exam_type;      // 试卷类型，'A'/'B'/' '
	char exam_code[16];  // 试卷编号
	char student_num[16];// 学生准考证号
	int  subject_score;  // 主观题分
	int  choice_num;     // 选择题数量
	char choice_str[512][8] = {0}; // 选择题回答
	rect choice_box[512][8]; // 选项框位置
};


class IMPORT temp_dict_utils
{
public:
	temp_dict_utils(paper_template_definition *ptd);
	~temp_dict_utils();

	void set_temp_data(temp_data *td, int width, int height, byte *data);  // binary image data[width*height]
	bool add_markers(int num, int markers[][2]);
	bool add_content();

	bool add_block_undefined(int x0, int y0, int x1, int y1);
	bool add_block_digits(temp_data_block_attr attr, int x0, int y0, int x1, int y1, int y01, int col, int *thresh);
	bool add_block_choices(temp_data_block_attr attr, int x0, int y0, int x1, int y1, int z01, int row, int col, int *thresh);

	bool proc_blocks(bool save, const char *file);
	temp_answer_sheet tas;

private:
	void read_choice(rect rb, int wb, int hb, byte *db, temp_data_block *tdb);

	paper_template_definition *ptd;
	temp_data *td;
	int width, height;
	byte *data;
	void *hdc;
};
