/*
 * =====================================================================================
 *
 *       Filename:  test_string_list.c
 *
 *    Description:  test for my string_list 
 *
 *        Version:  1.0
 *        Created:  2014年06月30日 22时43分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include	<stdio.h>
#include	"./string_list.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{

	String_list my_list;
	my_list=Init_String_List();
	Insert_String_List(my_list, "qeesung" , "012");
	Insert_String_List(my_list, "qeesung" , "003");
	Insert_String_List(my_list, "qeesung" , "520");
	Insert_String_List(my_list, "qinshicheng" , "038");
	Insert_String_List(my_list, "zhouwenxin" , "067");
	Insert_String_List(my_list, "weepinside" , "046");
	printf("\n ++++++++++++++after insert+++++++++++\n ");
	Print_String_List(my_list);
//	Delete_String_List(my_list,"weepinside",-1);
//	Delete_String_List(my_list,"qeesung",3);
//	printf("\n ++++++++++++++after delete+++++++++++\n ");
//	Print_String_List(my_list);
	printf("\n ++++++++++++++write to file +++++++++++\n ");
	Write_String_List("/root/suanfa/String/book_search_string/source_file/index_file",my_list);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
