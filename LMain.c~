#include "stdio.h"
#include "User.c"
#include "UserInterface.c"

int main()
{
	int mmenu;
	int ret;
	User *user;
	int userInterfaceRet;
	user = NULL;
	
	while(1)
	{
		mmenu = MainMenu();	
		switch(mmenu)
		{
			case 1://Register
				{	
					ret = RegisterUser();
					if(ret == 0)
					{
						printf("Register succes,please login\n");
					}
					else
					{
						printf("Register failed\n");
					}
				}
				break;
			case 2://Login
				{
					user = UserLogin();
					if(user == NULL)
					{
						continue;
					}
					else
					{
						userInterfaceRet = UserInterface();						
						
					}
				}
				break;
			case 3://Quit
				{
					if(user != NULL)
					{
						free(user);
					}
					return 0;
				}
				break;
			default:
				break;
		}
	}
	return 0;	
}
