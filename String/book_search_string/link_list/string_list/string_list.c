/*
 * =====================================================================================
 *
 *       Filename:  string_list.c
 *
 *    Description:  this is string_list C file
 *
 *        Version:  1.0
 *        Created:  2014年06月30日 21时45分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"string_list.h"
#include"../index_list/index_list.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init_String_List
 *  Description:  init a string list to store the source
 * =====================================================================================
 */
	String_list
Init_String_List ( )
{
	String_list new_string_list;

	new_string_list	= malloc ( sizeof(struct string_node) );
	if ( new_string_list==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	
	new_string_list->book_index=Init_Index_List();// init the index_list in the string_list
	new_string_list->next==NULL;
	return new_string_list;
}		/* -----  end of function Init_String_List  ----- */




/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insert_String_List
 *  Description:  insert a new word or old word into the string list
 * =====================================================================================
 */
	void
Insert_String_List ( String_list list , char * word , char * index_number )
{
	String_position temp, temp1;
	String_position new_string_node;
	if(list==NULL)
	{
		fprintf(stderr,"\n the list have not init \n ");
		return ;
	}
	temp=Find_Position(list , word);
	if(temp==NULL)
	{
		// this is a new_word
		temp=Find_Insert_Position(list , word);
		//+++++++++++++++++++++++++++++++++++++++
		new_string_node	= malloc ( sizeof(struct string_node) );
		if ( new_string_node==NULL ) {
			fprintf ( stderr, "\ndynamic memory allocation failed\n" );
			exit (EXIT_FAILURE);
		}
		new_string_node->book_word=word;
		new_string_node->book_index=Init_Index_List();
		//+++++++++++++++++++++++++++++++++++++++++++
		temp1=temp->next;
		temp->next=new_string_node;
		temp->next->next=temp1,
		//insert the index number into the new word index list
		Insert_Index_List(new_string_node->book_index, index_number);
		
	}
	else
	{
		// the word has been existed
		// only need to insert index_number
		Insert_Index_List(temp->next->book_index,index_number);
	}

	return ;
}		/* -----  end of function Insert_String_List  ----- */




/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Delete_String_List
 *  Description: delete a word with index_number:-1 and delete a index with index_number > 0 
 * =====================================================================================
 */
	void
Delete_String_List ( String_list list , char * word , char * index_number  )
{
	String_position temp, temp1;
	if(list==NULL)
	{
		fprintf(stderr,"\n the list has not been init \n ");
		return;
	}
	temp=Find_Position(list , word);
	if(temp==NULL)
	{
		fprintf(stderr, "\n can not find the word : %s \n",word);
		return ;
	}
	if(strcmp(index_number, "-1")==0)
	{
		/*  index_number==-1  would delete the word from the list  */
		temp1=temp->next->next;
		Destory_Index_List(temp->next->book_index);
		free(temp->next);
		temp->next=temp1;
	}
	else
	{
		/*  if index_number > 0 would delete a index_number in a word */
		Delete_Index_List(temp->next->book_index,index_number);
	}
	return ;
}		/* -----  end of function Delete_String_List  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_String_List
 *  Description:  print all the element in the string list
 * =====================================================================================
 */
	void
Print_String_List ( String_list list )
{
	String_position string_temp;
	Index_position index_temp;
	while(list->next!=NULL)
	{
		printf("%s----->:",list->next->book_word);
		Print_Index_List(list->next->book_index);
		list=list->next;
	}
	return;
}		/* -----  end of function Print_String_List  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Find_Position
 *  Description:  find a word previous pointer
 * =====================================================================================
 */
	String_position
Find_Position ( String_list list , char * word )
{
	String_position pos;
	while(list->next!=NULL && strcmp(list->next->book_word,word)!=0)
	{
		list=list->next;
	}
	if(list->next==NULL)
	{
//		fprintf(stderr,"\n can not find the word : %s \n ", word);
		return NULL;
	}
	if(strcmp(list->next->book_word,word)==0)
	{
		return list;
	}
}		/* -----  end of function Find_Position  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Find_Insert_Position
 *  Description:  find a position can insert a new word
 * =====================================================================================
 */
	String_position
Find_Insert_Position ( String_list list , char * word )
{
	while(list->next!=NULL&& strcmp(list->next->book_word, word)<0)
	{
		list=list->next;
	}
	return list;
	
}		/* -----  end of function Find_Insert_Position  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Write_String_List
 *  Description:  write the String list into a file
 * =====================================================================================
 */
	void
Write_String_List (char * filename, String_list list )
{
	FILE * file ;
	system("rm -f ../../source_file/index_file");
	while(list->next!=NULL)
	{
		file=fopen(filename, "a+");
		if(file==NULL)
		{
			fprintf(stderr,"\n open the file : %s failed \n ", filename);
			return ;
		}
		fputs(list->next->book_word,file);
		fputs(":",file);
		fclose(file);
		Write_Index_List(filename, list->next->book_index);
		list=list->next;
	}
	return ;
}		/* -----  end of function Write_String_List  ----- */
