//*****************************************************************************
//
//  Module:        	anc_output.h
//
//  Program:        
//
//  Description:	Contains structure definitions for the ANC2440 
//					Output database.
//
//  Author:        	Rc
//
//  Initiated:     	2011-10-25
//
//  Copyright (c)  	Rec Inc., 2011
//
//
//    - Revision History -
//
// Who       When		What
//
//*****************************************************************************
#include "anc_ctype.h"
#ifndef _ANC_OUTPUT_H_INCLUDED_
#define _ANC_OUTPUT_H_INCLUDED_

#define MAX_OUTPUT_GROUP			512
#define MAX_SINGLE_TERM_OPS		16    /*每个终端最多16个DO点*/
#define MAX_SINGLE_TERM_IPS			16    /*每个终端最多16个DI点*/
#define MAX_OTIME					 9999

#define OPRESET			0     /*重置*/
#define OPSET			1     /*设置*/
#define SEND_OPRESET	'0'     /*重置*/
#define SEND_OPSET		'1'     /*设置*/
#define OUT_UPDATE		0x8000 /*输出动作掩码*/


#define OPTIMED			4     /*定时控制*/
#define OPFAILED			5     /*控制失败*/
#define BYTE_SHIFT		8     /*地址位移*/
/*Error Conditions reported in reply [1]*/
#define NO_GRP			1     /*没有输出组*/
#define NO_OP			2     /*没有输入点*/
#define NO_TERM			3     /*没有终端*/
#define TERM_DISABLED	4     /*终端没有启用*/



typedef struct op_input_link
{
	ULONG	ip_term_number;
	UCOUNT	ip_number;
	UCOUNT	ip_state;
} OP_INPUT_LINK;

typedef struct op_data_list
{
	COUNT	op_number;
	COUNT	op_state;
	ULONG	op_duration;
}__attribute__((packed))OP_DATA_LIST;/*不对齐在ANC_OUTPUT中出错*/

typedef struct op_command
{
	COUNT	op_msg_type;
	ULONG	op_term_number;
	COUNT	op_count;
	TEXT	op_data;
} OP_COMMAND;

typedef struct anc_output
 {
   int		  	op_id;               /*低8位是输出点号，高24是输入点所在的终端号*/
   TEXT  		op_name[26];    
   UCOUNT  	op_active_state;     /*输出活动状态*/     
   UCOUNT  	op_duration;         /*输出控制时间*/
   UCOUNT  	op_group1;           /*所在输出组1*/
   UCOUNT  	op_group2;           /*所在输出组2*/
   UCOUNT  	op_group3;           /*所在输出组3*/
   struct  	op_input_link ip_link;  /*报警输入联动*/
 }ANC_OUTPUT;

#endif
