#pragma once
#include <windows.h>
#pragma comment(lib, "graphics.lib")



#ifndef IMPORT
#define IMPORT __declspec(dllimport)
#endif



class IMPORT Bitmap
{
public:
	Bitmap();
	~Bitmap();

	enum  COLOR{ GRAY, BGR, BGRA };
	void  CreateBitmap(COLOR eColor, int nWidth, int nHeight);

	HDC   GetMemHDC(){ return m_hDCMem; }
	COLOR GetColor(){ return m_eColor; }
	int   GetWidth(){ return m_nWidth; }
	int   GetHeight(){ return m_nHeight; }
	BYTE* GetBitmapBits(){ return m_pBits; }
	bool  IsReady(){ return m_pBits!=NULL; }
	
	// conversion between pixels and bitmap bits
	bool  SetData(COLOR eColor, byte *pData);
	bool  GetData(COLOR eColor, byte *pData);

	// read and write *.bmp, *.jpg, *.png, *.gif, *.tif files
	bool  ReadImage(const char *szFileName, bool asBGR = true);
	bool  ReadImage(int nLen, const char *pBuf, bool asBGR = true); // read a memory image
	bool  WriteImage(const char *szFileName, int nQuality = 100);

	// draw bitmaps
	void  DrawBitmap(HDC hDC, int xDest, int yDest, int wDest, int hDest);
	void  DrawBitmapTranparent(HDC hDC, int xDest, int yDest, int wDest, int hDest, DWORD dwTran);

private:
	void  ReadBitmapData(void *pBitmap);
	void  WriteBitmapData(void *pBitmap);

	HBITMAP m_hBmp0;
	HBITMAP m_hBmp1;
	HDC   m_hDCMem;
	COLOR m_eColor;
	int   m_nWidth;
	int   m_nHeight;
	BYTE *m_pBits;
};



class IMPORT Draw
{
public:
	Draw();
	~Draw();

	// ls - solid 0, dash 1, dot 2, dash dot 3, dash dot dot 4
	void SetDraw(float lw, int ls=0, float ra=0.0f);

	// style - regular 0, bold 1, italic 2, bold italic 3, underline 4, strikeout 8
	void SetFont(const char *name, int size, int style=0, int angle=0);

	// if add some local font resources into draw class
	bool AddFontFile(const char *fontfile);
	// font - index of font resources
	void SetFont(int font, int size, int style=0, int angle=0);

	void DrawChar(HDC hDC, int x, int y, char c, DWORD argb);
	void DrawChar(HDC hDC, int x, int y, WCHAR c, DWORD argb);
	void DrawString(HDC hDC, int x, int y, int align, char *str, DWORD argb);
	void DrawString(HDC hDC, int x, int y, int align, WCHAR *str, DWORD argb);
	
	void DrawPixel(HDC hDC, int x, int y, DWORD argb);
	void DrawLine(HDC hDC, int x0, int y0, int x1, int y1, DWORD argb);
	void DrawLines(HDC hDC, int n, int *x, int *y, DWORD argb);
	void DrawRect(HDC hDC, int x0, int y0, int x1, int y1, DWORD argb);
	void DrawEllipse(HDC hDC, int x0, int y0, int x1, int y1, DWORD argb);
	void DrawRoundRect(HDC hDC, int x0, int y0, int x1, int y1, int r, DWORD argb);
	
	void FillRect(HDC hDC, int x0, int y0, int x1, int y1, DWORD argb);
	void FillEllipse(HDC hDC, int x0, int y0, int x1, int y1, DWORD argb);
	void FillRoundRect(HDC hDC, int x0, int y0, int x1, int y1, int r, DWORD argb);

	// 2d plot like matlab
	struct rectf{ float x0, y0, x1, y1; };
	void SetPlot(rectf &dst, rectf &src);
	void PlotLine(HDC hDC, rectf &line, DWORD argb);
	void PlotMarker(HDC hDC, float x, float y, DWORD argb, int mr, int ms);
	void PlotContour(HDC hDC, int n, int m, float *x, float *y, float *z, float c, DWORD argb);

private:
	void FromSrcToDst(float &x, float &y);
	void PlotCell(HDC hDC, rectf &cell, rectf &cellz, float c, DWORD argb);
	float Linear(float c, float c0, float c1, float x0, float x1);

	float m_fLineWidth;
	int   m_nLineStyle;
	float m_fDrawAngle;
	WCHAR m_wsFontName[128];
	int   m_nFontSize;
	int   m_nFontStyle;
	int   m_nFontAngle;	
	void *m_pFontFami;
	void *m_pFontColl;
	int   m_iFontFami;
	rectf m_rDst;
	rectf m_rSrc;
};