/*
 * =====================================================================================
 *
 *       Filename:  string.c
 *
 *    Description:  This is dynamic string c file 
 *
 *        Version:  1.0
 *        Created:  2014年06月26日 04时42分37秒
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
#include"./string.h"



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Str_Assign
 *  Description:  copy a new string!
 * =====================================================================================
 */
	String
Str_Assign ( String string )
{
	int i;
	String new_string;
	new_string	= malloc ( sizeof(struct string) );
	if ( new_string==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	new_string->length=string->length;
	
	new_string->ch	= malloc ( sizeof(char) * new_string->length );
	if ( new_string->ch==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}

	for(i=0;i<string->length;i++)
	{
		new_string->ch[i]=string->ch[i];
	}
	return new_string;
}		/* -----  end of function Str_Assign  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Str_Length
 *  Description: get the length of  a string; 
 * =====================================================================================
 */
	int
Str_Length ( String string)
{
	return string->length;
}		/* -----  end of function Str_Length  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Str_Compare
 *  Description:  compare two strings
 * =====================================================================================
 */
	int
Str_Compare ( String string1 , String string2 )
{
	int i;
	for(i=0;i<string1->length && i<string2->length;i++)
	{
		if(string1->ch[i] != string2->ch[i])
		return string1->ch[i]-string2->ch[i];
	}
	return string1->length-string2->length;

}		/* -----  end of function Str_Compare  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Clear_String
 *  Description:  delete a string
 * =====================================================================================
 */
	void
Clear_String (String string )
{
	if(string == NULL)
	{
		return;
	}
	if(string->ch==NULL)
	{
		free(string);
		string=NULL;
	}
	else
	{
		free(string->ch);
		string->ch=NULL;
		free(string);
		string=NULL;
	}
	return ;
}		/* -----  end of function Clear_String  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Concat
 *  Description:  merge two string into only one 
 * =====================================================================================
 */
	String
Concat (String string1 , String string2 )
{
	String new_string;
	int i;
	new_string	= malloc ( sizeof(struct string) );
	if ( new_string==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	
	new_string->ch	= malloc ( sizeof(char) * (string1->length + string2->length) );
	if ( new_string->ch==NULL ) {
		free(new_string);
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	
	for(i=0;i<string1->length;i++)
	{
		new_string->ch[i]=string1->ch[i];
	}
	for(i=string1->length;i<string1->length+string2->length;i++)
	{
		new_string->ch[i]=string2->ch[i-string1->length];
	}
	new_string->length=string1->length+string2->length;

	return new_string;
}		/* -----  end of function Concat  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Sub_String
 *  Description:  get a part of the string form pos with length len
 * =====================================================================================
 */
	String
Sub_String ( String string , int pos , int len )
{
	String child_string;
	int i;
	if(pos<1 || pos > string->length || pos+len-1 > string->length)
	{
		fprintf(stderr, "\n please input rigth parameter\n");
		return NULL;
	}
	child_string	= malloc ( sizeof(struct string) );
	if ( child_string==NULL ) {
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	
	child_string->ch	= malloc ( sizeof(char ) *(len) );
	if ( child_string->ch==NULL ) {
		free(child_string);
		fprintf ( stderr, "\ndynamic memory allocation failed\n" );
		exit (EXIT_FAILURE);
	}
	for(i=0;i<len;i++)
	{
		child_string->ch[i]=string->ch[i+pos];
	}
	child_string->length=len;
	return child_string;
}		/* -----  end of function Sub_String  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Str_Insert
 *  Description:  Insert a string into new  string
 * =====================================================================================
 */
	void
Str_Insert ( String string , int pos , String new_string )
{
	int i;
	if(new_string == NULL || new_string->ch==NULL)
	{
		fprintf(stderr, "\n the string is empty\n ");
		 return ;
	}
	string->ch=realloc(string->ch , (string->length + new_string->length));
	if(string->ch==NULL)
	{
		fprintf(stderr,"\n out of space \n ");
		return ;
	}
	string->length=string->length+ new_string->length;

	for(i=string->length;i>pos+new_string->length;i--)
	{
		string->ch[i]=string->ch[i-new_string->length];// copy to the rear;
	}
	for(i=pos;i<pos+new_string->length;i++)
	{
		string->ch[i]=new_string->ch[i-pos];
	}
	return ;
}		/* -----  end of function Str_Insert  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Init String
 *  Description:  init a string
 * =====================================================================================
 */
	String
Init_String ( char * msg )
{
	int i;
	String new_string;
	i=0;
	while(msg[i]!='\0')
	{
		i++;
	}
	new_string=malloc(sizeof(struct string));
	if(new_string == NULL)
	{
		fprintf(stderr,"\n out of space \n ");
		return ;
	}
	new_string->ch=malloc(sizeof(char ) * i);
	if(new_string->ch==NULL)
	{
		fprintf(stderr,"\n out of space \n ");
		free(new_string);
		return NULL;
	}

	new_string->length=i;
	for(i=0;i<new_string->length;i++)
	{
		new_string->ch[i]=msg[i];
	}
	return new_string;
}		/* -----  end of function Init String  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Print_String
 *  Description:  print all the char in the string
 * =====================================================================================
 */
	void
Print_String ( String string )
{
	if(string==NULL || string->ch == NULL)
	{
		fprintf(stderr, "\n the string is empty \n");
		return ;
	}
	printf("%s\n",string->ch);
	return ;
}		/* -----  end of function Print_String  ----- */
