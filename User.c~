#include "stdio.h"
#include <malloc.h>
#include <string.h>

#ifndef SUSERH
	#include "SUser.h"
	#define SUSERH
#endif
#ifndef CONFIGH
	#include "config.h"
	#define CONFIGH
#endif

/*
*main interface menu
*/
int MainMenu()
{
	int chioce;
	while(1)
	{
		printf("\nPlease chioce doing:\n");
		printf("1.Register\n");
		printf("2.Login\n");				
		printf("3.Quit\n");
		
		scanf("%d",&chioce);
		printf("\n");
		if(chioce == 1 || chioce == 2 || chioce == 3)
		{
			break;
		}
	}
	return chioce;
}

/*
*Create user pointer
*/
User *CreateUserPinter()
{
	User *user;
	user = (User*)(malloc(sizeof(User)));
	return user;
}

/*
*Read userinfo
*/
User *ReadUserInfo()
{
	User *head;
	User *last;
	User *tmp;
	FILE *fp = fopen(userInfoFile,"rb");

	head = NULL;
	last = NULL;
	tmp = NULL;
	
	if(fp == NULL)
	{
		printf("Open fiel failed\n");
		return head;
	}
	
	do
	{
		tmp = (User*)(malloc(sizeof(User)));
		tmp->next = NULL;
		tmp->pre = NULL;
		if(fread(tmp,sizeof(User),1,fp) == 0)
		{
			free(tmp);
			break;
		}
		if(head == NULL)
		{
			head = tmp;	
		}
		else
		{
			last->next = (struct UserInfo *)tmp;
		}
		last = tmp;	
	}
	while(!feof(fp));
	
	if(fclose(fp) == EOF)
	{
		printf("Close file error\n");	
	}
	
	return head;
}

/*
*Relase userinfo all
*/
void ReleaseUserInfo(User *head)
{
	User *tmp;
	User *next;
	
	if(head == NULL)
	{
		return;
	}

	tmp = head;
	next = tmp->next;
	
	while(1)
	{
		free(tmp);
		if(next == NULL)
		{
			break;
		}
		tmp = next;
		next = (User *)next->next;
	}
}

/*
*login username password validate
*/
int UsernamePasswordValidate(User *user,User *head)
{
	User *tmp;
	int ret;
	ret  = -1;
	tmp = head;
	while(tmp != NULL)
	{		 
		if(strcmp(tmp->name,user->name) == 0)
		{
			if(strcmp(tmp->pass,user->pass) == 0)
			{
				ret = 0;				
			}
			else
			{
				printf("Password error\n");
			}
			break;
		}
		else
		{
			tmp = tmp->next;
		}
	}
	return ret;
}

/*
*login username password validate
*para: flag = 1,为登陆 flag ＝ 0为注册时用户名验证，是否存在
*/
User *QueryUserByUserNameAndPassword(char *username,char *password,User *head,int flag)
{
	User *tmp;
	User *user;
	
	user = NULL;
	tmp = head;
	
	while(tmp != NULL)
	{		 
		if(strcmp(tmp->name,username) == 0)
		{
			if(flag)
			{
				if(strcmp(tmp->pass,password) == 0)
				{		
					user = CreateUserPinter();		
					strcpy(user->name,username);
					strcpy(user->pass,password);	
					user->pre = NULL;
					user->next = NULL;
				}
				else
				{
					printf("Password error\n");
				}
			}
			else
			{
				user = CreateUserPinter();		
			}
			break;
		}
		else
		{
			tmp = tmp->next;
		}
	}
	return user;
}

/*
*user register
*/
int RegisterUser()
{
	char username[20];
	char pass1[20];
	char pass2[20];
	int  passCmpRet;
	User *user;
	User *head;
	
	head = ReadUserInfo();
	
	while(1)
	{
		printf("Please input user name:\n");
		scanf("%s",username);
		printf("\n");
		user = QueryUserByUserNameAndPassword(username,"",head,0);
		if(user != NULL)
		{
			printf("exsit username %s\n",username);
		}
		else
		{
			break;
		}
	}
	
	while(1)
	{
		printf("Please input user password:\n");
		scanf("%s",pass1);
		printf("\n");
	
		printf("Please input repeat password:\n");
		scanf("%s",pass2);
		printf("\n");
	
		passCmpRet = strcmp(pass1,pass2);
		if(passCmpRet == 0)
		{
			break;
		}
		else
		{
			printf("Your password different\n");
		}
	}
	
	user = CreateUserPinter();
	strcpy(user->name,username);
	strcpy(user->pass,pass1);
	
	FILE *fp = fopen(userInfoFile,"ab");
	if(fp == NULL)
	{
		fp = fopen(userInfoFile,"Wb");
	}
	if(fp == NULL)
	{
		printf("Open fiel failed\n");
		free(user);
		return -1;
	}
	
	if(fwrite(user,sizeof(User),1,fp) != 1)
	{
		printf("Write file failed\n");	
	}
	
	if(fclose(fp) == EOF)
	{
		printf("Close file error\n");	
		return -1;
	}
	return 0;
}

/*
*User login
*/
User * UserLogin()
{
	char username[20];
	char pass[20];
	
	User *user;
	User *head;
	
	printf("Please input user name:\n");
	scanf("%s",username);
	printf("\n");
	
	printf("Please input user password:\n");
	scanf("%s",pass);
	printf("\n");
		
	head = ReadUserInfo();	
	user = QueryUserByUserNameAndPassword(username,pass,head,1);
	
	if(user != NULL)
	{
		printf("Login success\n");
		ReleaseUserInfo(head);
		return user;
	}
	else
	{
		printf("Login failed\n");
		ReleaseUserInfo(head);
		return NULL;
	}
}
