typedef struct UserInfo
{
	char name[20]; //用户名
	char pass[20]; //密码
	struct UserInfo *pre; //上一个
	struct UserInfo *next; //下一个
}User;
