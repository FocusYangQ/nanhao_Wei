#include <stdio.h>
#include "paper_template_definition.h"
#include "graphics.h"


bool make_temp_dict_1(paper_template_definition *ptd)
{
	Bitmap bmp;
	if(!bmp.ReadImage("1.tif", false)) return false;
	int width = bmp.GetWidth(), height = bmp.GetHeight();
	byte *data = new byte[width*height];
	bmp.GetData(Bitmap::GRAY, data);
	printf("image width = %d, height = %d\n", width, height);

	temp_data *td = ptd->push_back_temp_data();
	td->id = 1;
	td->subject = 1;

	temp_dict_utils tdu(ptd);
	tdu.set_temp_data(td, width, height, data);

	ptd->image_gray_to_binary(width, height, data, data);
	tdu.add_content();
	
	bmp.SetData(Bitmap::GRAY, data);
	bmp.WriteImage("temp.png");

	bool ret = true;
	int alphas[4] = {600, 600, 600, 600}; // A~D
	int digits[10] = {500, 500, 500, 500, 500, 500, 500, 500, 500, 500}; // 0~9

	if(ret) ret = tdu.add_block_undefined(139, 199, 475, 249); // 姓名区域
	
	//if(ret) ret = tdu.add_block_choices(EXAM_TYPE, 257, 236, 288, 392, 313, 2, 1, alphas); // 试卷类型

	if(ret) ret = tdu.add_block_digits(EXAM_CODE, 576, 217, 824, 646, 268, 5, digits); // 学生考号
	if(ret) ret = tdu.add_block_digits(STUDENT_NUM, 837, 216, 1368, 646, 268, 11, digits); // 学生考号

	//if(ret) ret = tdu.add_block_choices(COL_SINGLE_CHOICE, 56, 368, 249, 487, 393, 4, 5, alphas); // 单选题
	//if(ret) ret = tdu.add_block_choices(COL_SINGLE_CHOICE, 56, 513, 648, 632, 539, 4, 15, alphas); // 单选题
	
	delete[] data;
	return ret;
}


bool test_temp_dict_1(paper_template_definition *ptd)
{
	temp_data *td = ptd->get_temp_data(0);
	if(td==NULL) return false;

	const char* files[] =
	{
		"1.tif"
	};

	int nfiles = sizeof(files)/sizeof(char*);
	for(int i=0; i<nfiles; i++)
	{
		const bool print = true;	
		const char *file = files[i];

		Bitmap bmp;
		if(bmp.ReadImage(files[i], false))
		{
			int width = bmp.GetWidth(), height = bmp.GetHeight();
			byte *data = new byte[width*height];
			bmp.GetData(Bitmap::GRAY, data);
			if(print) printf("%s\n  width = %d, height = %d\n", file, width, height);

			if(ptd->auto_alignment_by_content(td, width, height, data, print))
			{
				temp_dict_utils tdu(ptd);
				tdu.set_temp_data(td, width, height, data);
				tdu.proc_blocks(true, file);
				printf("  exam_type = %c\n", tdu.tas.exam_type);
				printf("  exam_code = %s\n", tdu.tas.exam_code);
				printf("  student_num = %s\n", tdu.tas.student_num);
				//printf("  subject_score = %d\n", tdu.tas.subject_score);
				//printf("  choice_num = %d\n", tdu.tas.choice_num);
				for(int j=0; j<tdu.tas.choice_num; j++) printf("  %d.\t%s\n", 1+j, tdu.tas.choice[j]);
			}

			delete[] data;
		}
		else if(print) printf("  error: can not read the image file %s\n", file);
	}
	return false;
}


void main()
{
	//if(false)
	{
		paper_template_definition ptd;

		make_temp_dict_1(&ptd);

		ptd.save_dict("data.dic");
	}
	//else
	{
		paper_template_definition ptd;

		if(ptd.load_dict("data.dic"))
		{
			printf("load_dict(\"%s\") success\n", "data.dic");

			test_temp_dict_1(&ptd);
		}
	}
}
