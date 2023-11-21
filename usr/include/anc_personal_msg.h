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

//个人信息长度
#define PERSONAL_MSG_LENGTH 96

typedef struct anc_personal_msg
{
	ULONG		c_inter_num;		/*卡内码低字节*/
	ULONG		c_inter_num_hi;	/*卡内码高字节*/
	USHORT		pm_id;			/*个人信息ID号*/
	char		pm_msg[PERSONAL_MSG_LENGTH+1];  	/*信息内容 对应的汉字或英文ASCII码,最多96个字节*/
} ANC_PERSONAL_MSG;
#endif



