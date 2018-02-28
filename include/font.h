#ifndef FONT_H_
#define FONT_H_

#include <lcd.h>

#define FONTDATAMAX 11264
#define HIGH    22
#define WIDTH   12

extern void display_string_buf(int buf_n, int x, int y, const char *str, int col);
extern void gh_change_buf(int gh_buf_n); //切换空间
extern void gh_clr_screen(int gh_buf_n,int ba_col);//指定空间清屏
extern void gh_printf(int gh_buf_n,int x,int y,const char *str,int po_col,int ba_col);
											//指定空间打印字符串
											//gh_buf_n 空间地址或空间编号
											//po_col   字体颜色
											//ba_col   背景颜色

#endif
