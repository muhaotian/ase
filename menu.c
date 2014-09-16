/**************************************************************************************************/
/* Copyright (C) muht@mail.ustc.edu.cn, SSE@USTC, 2014-2015                                       */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  MuHaotian                                                            */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  Miscrosoft Visual c++                                                */
/*  DATE OF FIRST RELEASE :  2014/09/15                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by MuHaotian, 2014/09/15
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESC_LEN    1024
#define CMD_NUM     10
#define CMD_MAX_LEN 128

typedef struct DataNode
{
    char    *cmd;
    char    *desc;
    struct  DataNode *next;
} DataNode;

static DataNode head[] =
{
    {"help","this is help cmd!",&head[1]},
    {"version","menu program v1.0",NULL}
};

void showMenuList(DataNode *x)
{
	printf("Menu List:\n");
    while(x != NULL)
    {
        printf("%s - %s\n", x->cmd, x->desc);
        x = x->next;
    }
}

void inputcmdNumber(DataNode *y,DataNode *z)
{
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        y = z;
        while(y != NULL)
        {
            if(!strcmp(y->cmd, cmd))
            {
                printf("%s - %s\n", y->cmd, y->desc);
				if(!strcmp(cmd,"help"))
				{
					showMenuList(y);
				}
                break;
            }
            y = y->next;
        }
        if(y == NULL)
        {
            printf("This is a wrong cmd!\n");
        }
    }
}
void main()
{
    DataNode *p = head;
    showMenuList(p);
    inputcmdNumber(p,head);
}