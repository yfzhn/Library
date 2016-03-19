/*
*book struct
*/
typedef struct BookInfo
{
	int index; //索引
	char bookname[100]; //书名
	char author[20]; //作者
	char press[100];  //出版社
	char category[20];//计算机  文学  小说
	struct BookInfo *pre; //上一个
	struct BookInfo *next; //下一个
}Book;

/*
*Query book type
*/
typedef enum BookQueryTypeInfo
{
	Index = 1,
	Bookname = 2,
	Author = 3,
	Category = 4,
	Press = 5,
	Any	= 6,
	Quit = 7
}BookQueryType;


