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
#define MAX_SINGLE_TERM_OPS		16    /*ÿ���ն����16��DO��*/
#define MAX_SINGLE_TERM_IPS			16    /*ÿ���ն����16��DI��*/
#define MAX_OTIME					 9999

#define OPRESET			0     /*����*/
#define OPSET			1     /*����*/
#define SEND_OPRESET	'0'     /*����*/
#define SEND_OPSET		'1'     /*����*/
#define OUT_UPDATE		0x8000 /*�����������*/


#define OPTIMED			4     /*��ʱ����*/
#define OPFAILED			5     /*����ʧ��*/
#define BYTE_SHIFT		8     /*��ַλ��*/
/*Error Conditions reported in reply [1]*/
#define NO_GRP			1     /*û�������*/
#define NO_OP			2     /*û�������*/
#define NO_TERM			3     /*û���ն�*/
#define TERM_DISABLED	4     /*�ն�û������*/



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
}__attribute__((packed))OP_DATA_LIST;/*��������ANC_OUTPUT�г���*/

typedef struct op_command
{
	COUNT	op_msg_type;
	ULONG	op_term_number;
	COUNT	op_count;
	TEXT	op_data;
} OP_COMMAND;

typedef struct anc_output
 {
   int		  	op_id;               /*��8λ�������ţ���24����������ڵ��ն˺�*/
   TEXT  		op_name[26];    
   UCOUNT  	op_active_state;     /*����״̬*/     
   UCOUNT  	op_duration;         /*�������ʱ��*/
   UCOUNT  	op_group1;           /*���������1*/
   UCOUNT  	op_group2;           /*���������2*/
   UCOUNT  	op_group3;           /*���������3*/
   struct  	op_input_link ip_link;  /*������������*/
 }ANC_OUTPUT;

#endif
