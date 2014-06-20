/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  header file for polyn 
 *
 *        Version:  1.0
 *        Created:  2014年06月21日 02时47分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */

#ifndef _LIST_H
#define _LISTH_H

struct Polyn_node
{
	int zhishu;
	int xishu;
	struct Polyn_node * next;
};
typedef struct Polyn_node * Polyn;
typedef Polyn Position;

/*-----------------------------------------------------------------------------
 *  create a empty Polyn
 *-----------------------------------------------------------------------------*/
 Polyn Create_Polyn();

 /*-----------------------------------------------------------------------------
  *  Insert into Polyn list
  *-----------------------------------------------------------------------------*/
void Insert_Polyn(Polyn  polyn , int xishu, int zhishu);


/*-----------------------------------------------------------------------------
 *  Delete form the Polyn list
 *-----------------------------------------------------------------------------*/
 void Delete_Polyn(Polyn polyn , int zhishu);

 /*-----------------------------------------------------------------------------
  *  Print the polyn all the element
  *-----------------------------------------------------------------------------*/
void Print_Polyn(Polyn polyn);
/*-----------------------------------------------------------------------------
 *  add two Polyns
 *-----------------------------------------------------------------------------*/
 void Add_Polyn(Polyn polyn1 , Polyn polyn2);

 /*-----------------------------------------------------------------------------
  *  mul two polyns
  *-----------------------------------------------------------------------------*/
  void Mul_Polyn(Polyn polyn1 , Polyn polyn2);


  /*-----------------------------------------------------------------------------
   *  Find the position 
   *-----------------------------------------------------------------------------*/
   Position Find_Position(Polyn polyn, int zhishu);

   /*-----------------------------------------------------------------------------
    *  delete all the element in the polyn list
    *-----------------------------------------------------------------------------*/
void Delete_All_Polyn(Polyn polyn);

#endif
