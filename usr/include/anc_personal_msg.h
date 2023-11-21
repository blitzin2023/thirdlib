//////////////////////////////////////////////////////////////////////////////
//
//  Module:        	anc_personal_msg.h
//
//  Program:
//
//  Description:   	Contains structure definitions for the ANC2440
//					personal msg database.
//
//  Author:        	RC
//
//  Initiated:     	2013-7-19
//
// Who When		What
//
//////////////////////////////////////////////////////////////////////////////

#ifndef _ANC_PERSONAL_MSG_H_INCLUDED_
#define _ANC_PERSONAL_MSG_H_INCLUDED_

//������Ϣ����
#define PERSONAL_MSG_LENGTH 96

typedef struct anc_personal_msg
{
	ULONG		c_inter_num;		/*��������ֽ�*/
	ULONG		c_inter_num_hi;	/*��������ֽ�*/
	USHORT		pm_id;			/*������ϢID��*/
	char		pm_msg[PERSONAL_MSG_LENGTH+1];  	/*��Ϣ���� ��Ӧ�ĺ��ֻ�Ӣ��ASCII��,���96���ֽ�*/
} ANC_PERSONAL_MSG;
#endif



