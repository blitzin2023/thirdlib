#include <linux/kernel.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <semaphore.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#ifndef _PNC_PIDMSG_H_INCLUDED_
#define _PNC_PIDMSG_H_INCLUDED_ 

/* prototypes */
void ckpid_error (char *proc_name);
pid_t find_proc(char *proc_name);
int add_proc (pid_t pid, char *proc_name);
int remove_proc (pid_t pid_num, char *proc_name);


int get_msgid(char *path, char id);
int get_pidmgr_msgid();
int get_pidmgr_rx_msgid();
int get_wscomms_msgid();
int get_sendpri_msgid();
int get_sendws_msgid();
int get_device_msgid();
int get_s300_msgid();
int get_dbms_msgid();
int get_device_query_msgid();


int create_msgid(char *path, char id);
int create_pidmgr_msgid();
int create_pidmgr_rx_msgid();
int create_wscomms_msgid();
int create_sendpri_msgid();
int create_sendws_msgid();
int create_device_msgid();
int create_s300_msgid();
int create_dbms_msgid();
int create_device_query_msgid();

void print_proc_msg_key();


int Creceive(int msgid,	void *msg,	unsigned  nbytes);
int Reply(int msgid, void *msg,  unsigned  nbytes);
int Send(int sndid, void *msg, void *rmsg,  unsigned snbytes, unsigned rnbytes);


typedef struct pidmsg
{
	short	type;
	char	msg[128];
} PIDMSG;

typedef PIDMSG *pPIDMSG;

/* PIDMSG type defines */
#define PID_STATUS_TYPE	0
#define PID_ADD_TYPE	1
#define PID_REQ_TYPE	2
#define PID_REMOVE_TYPE	3

/* PID_STATUS defines */
#define PID_STAT_ACK	1
#define PID_STAT_NAK	2

/* pidmgr error codes for ckpid_errno */
#define PID_NOERROR		0	/* no error occurred */
#define PID_PIDMGR_NOT	1	/* pidmgr not running */
#define PID_ILLEGAL_RET	2	/* illegal return from pidmgr */
#define PID_ILLEGAL_OP	3	/* illegal request to pidmgr */
#define PID_NAK_RET		4	/* nak from pidmgr */

//add by xlx
#define PROC_RCV_ID   4
#define PROC_SND_ID   5
#define SND_PROC_PATH      "/bin"
#define RCV_PROC_PATH      "/home"

#define PIDMGR_MSGID_PATH          "/"
#define PIDMGR_RX_MSGID_PATH       "/"
#define WSCOMMS_MSGID_PATH       "/"
#define SENDPRI_MSGID_PATH         "/"
#define SENDWS_MSGID_PATH        "/"
#define DEVICE_MSGID_PATH          "/"
#define S300_MSGID_PATH            "/"
#define DBMS_MSGID_PATH            "/"
#define NETRESTART_MSGID_PATH      "/"
#define DEVICE_QUERY_MSGID_PATH    "/"


#define PIDMGR_MSGID_ID          1
#define PIDMGR_RX_MSGID_ID       2
#define WSCOMMS_MSGID_ID       3
#define SENDPRI_MSGID_ID         4
#define SENDWS_MSGID_ID        5
#define DEVICE_MSGID_ID          6
#define S300_MSGID_ID            7
#define DBMS_MSGID_ID            8
#define NETRESTART_MSGID_ID      9
#define DEVICE_QUERY_MSGID_ID    10



#define MAX_MSG_LEN             2048

typedef  struct msgbuf {
   long mtype;     /* message type, must be > 0 */
   char mtext[MAX_MSG_LEN];  /* message data */
 }MsgBuf;

//end add


typedef struct pid_status_msg
{
	short	status;			/* status type return code */
	char	proc_name[21];	/* requested process name */
} PID_STATUS_MSG;

typedef PID_STATUS_MSG *pPID_STATUS_MSG;

typedef struct pidadd
{
	pid_t	pid;			/* requestors pid to add */
	char	proc_name[21];	/* requestors process name */
} PID_ADD;

typedef PID_ADD *pPID_ADD;

typedef struct pid_req
{
	pid_t	req_pid;		/* requested pid id for process name */
	char	proc_name[21];	/* process name to get pid for */
} PID_REQ;

typedef PID_REQ *pPID_REQ;

typedef struct pid_remove
{
	pid_t	rem_pid;		/* pid to remove from active list */
	char	proc_name[21];	/* process name to remove from active list */
} PID_REMOVE;

typedef PID_REMOVE *pPID_REMOVE;

#endif

