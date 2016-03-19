#include "stdio.h"
#include <malloc.h>
#include <string.h>

#ifndef SBOOKH
	#include "SBook.h"
	#define SBOOKH
#endif
#ifndef CONFIGH
	#include "config.h"
	#define CONFIGH
#endif
#ifndef BOOKINFOTABLEH
	#include "BookInfoTable.h"
	#define BOOKINFOTABLEH
#endif


/*
*put a book
*/
void PutBook(int id,Book *book)
{
	if(book == NULL)
	{
		return;
	}	
	printf("ID:%-5d\nIndex:%-5d\nBookname:%-20s\nAuthor:%-20s\nPress:%-20s\nCategory:%-20s\n",
		id,book->index,book->bookname,book->author,book->press,book->category);
}

/*
*put all book
*/
void PutAllBook(Book *bookHead)
{
	Book *tmp;
	int id;
	tmp = bookHead;
	id = 1;
	while(tmp != NULL)
	{
		printf("%s\n",split);
		PutBook(id,tmp);
		id++;
		tmp = tmp->next;
	}
	printf("%s\n",split);
}

/*
*write book
*/
void WriteAllBook(Book *bookHead)
{
	Book *tmp;
	FILE *fp;
	int bookSize;
	
	tmp = bookHead;
	fp = fopen(bookInfoFile,"ab");
	if(fp == NULL)
	{
		fp = fopen(bookInfoFile,"wb");
	}
	if(fp == NULL)
	{
		printf("open %s failed\n",bookInfoFile);
		return;
	}

	bookSize = sizeof(Book);
	while(tmp != NULL)
	{
		if(fwrite(tmp,bookSize,1,fp) != 1)
		{
			printf("write file error\n");
			return;
		}
		tmp = tmp->next;
	}
	if(fclose(fp) == EOF)
	{
		printf("Close file failed\n");	
	}
}

/*
*Read book
*/
Book *ReadBook()
{
	Book *head;
	Book *last;
	Book *tmp;
	FILE *fp;
	int bookSize;
	fp = fopen(bookInfoFile,"rb");

	head = NULL;
	last = NULL;
	tmp = NULL;
	
	if(fp == NULL)
	{
		printf("Open file failed\n");
		return head;
	}
	
	bookSize = sizeof(Book);
	do
	{
		tmp = (Book*)(malloc(bookSize));
		tmp->next = NULL;
		tmp->pre = NULL;
		if(fread(tmp,bookSize,1,fp) == 0)
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
			last->next = (struct BookInfo *)tmp;
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
*Read all bookTable
*/
BookTable *ReadBookTable()
{
	BookTable *head;
	BookTable *last;
	BookTable *tmp;
	FILE *fp;
	int bookSize;
	fp = fopen(bookTableFile,"rb");

	head = NULL;
	last = NULL;
	tmp = NULL;
	
	if(fp == NULL)
	{
		printf("Open file %s failed\n",bookTableFile);
		return head;
	}
	
	bookSize = sizeof(BookTable);
	do
	{
		tmp = (BookTable*)(malloc(bookSize));
		tmp->next = NULL;
		tmp->pre = NULL;
		if(fread(tmp,bookSize,1,fp) == 0)
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
			last->next = (struct BookInfoTable *)tmp;
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
*Modify bookTable
*/
void WriteNewAllBookTable(BookTable *head)
{
	BookTable *tmp;
	FILE *fp;
	int bookSize;
	
	tmp = head;
	fp = fopen(bookTableFile,"ab");
	if(fp == NULL)
	{
		fp = fopen(bookTableFile,"wb");
	}
	
	if(fp == NULL)
	{
		printf("open file %s failed\n",bookTableFile);
		return;
	}

	bookSize = sizeof(BookTable);
	while(tmp != NULL)
	{
		if(fwrite(tmp,bookSize,1,fp) != 1)
		{
			printf("write file error\n");
			return;
		}
		tmp = tmp->next;
	}
	if(fclose(fp) == EOF)
	{
		printf("Close file failed\n");	
	}
}

/*
*Validate book index
*/
int ValidateBookIndex(int index,Book *bookHead)
{
	Book *tmp;
	
	if(index < 0)
	{
		printf("index not less 0\n");
		return -1;
	}
	
	tmp = bookHead;
	while(tmp != NULL)
	{
		if(tmp->index == index)
		{
			printf("exist index %d book\n",index);
			return 1;
		}
		tmp = tmp->next;
	}
	
	return 0;
}


/*
*Add book
*/
void AddBook(Book *bookHead)
{
	Book book;
	BookTable bt;
	
	book.pre = NULL;
	book.next = NULL;
	bt.pre = NULL;
	bt.next = NULL;
	
	while(1)
	{
		printf("Input book index:\n");
		scanf("%d",&book.index);
		if(ValidateBookIndex(book.index,bookHead) == 0)
		{
			break;
		}
		else
		{
			continue;
		}
	}
	
	while(1)
	{
		printf("Input bookname:\n");
		scanf("%s",book.bookname);
		if(strcmp(book.bookname,"") != 0)
		{
			break;
		}
		else
		{
			printf("bookname can not null\n");
			continue;
		}
	}
	
	while(1)
	{
		printf("Input author:\n");
		scanf("%s",book.author);
		if(strcmp(book.author,"") != 0)
		{
			break;
		}
		else
		{
			printf("author can not null\n");
			continue;
		}
	}
	
	while(1)
	{
		printf("Input press:\n");
		scanf("%s",book.press);
		if(strcmp(book.press,"") != 0)
		{
			break;
		}
		else
		{
			printf("press can not null\n");
			continue;
		}
	}
	
	while(1)
	{
		printf("Input category:\n");
		scanf("%s",book.category);
		if(strcmp(book.category,"") != 0)
		{
			break;
		}
		else
		{
			printf("category can not null\n");
			continue;
		}
	}
	
	while(1)
	{
		printf("Input book count:\n");
		scanf("%d",&bt.count);
		if(bt.count > 0)
		{
			break;
		}
		else
		{
			printf("book count not less 0\n");
			continue;
		}
	}
		
	bt.currentCount = bt.count;
	bt.index = book.index;
	
	WriteNewAllBookTable(&bt);	
	WriteAllBook(&book);
}

/*
*Relase book
*/
void ReleaseAllBook(Book *bookHead)
{
	Book *tmp;
	Book *next;
	
	if(bookHead == NULL)
	{
		return;
	}

	tmp = bookHead;
	next = tmp->next;
	
	while(1)
	{
		free(tmp);
		if(next == NULL)
		{
			break;
		}
		tmp = next;
		next = (Book *)next->next;
	}
}

/*
*Copy book
*/
void BookCopy(Book *target,Book *sources)
{
	target->index = sources->index;//索引
	strcpy(target->bookname,sources->bookname);//book name
	strcpy(target->author,sources->author);//作者
	strcpy(target->press,sources->press);//出版社
	strcpy(target->category,sources->category);	//备注
	target->pre = sources->pre; //上一个
	target->next = sources->next; //下一个
}

/*
*Query Book By bookIndex
*/
Book *QueryBookByIndex(int bookIndex,Book *bookHead)
{
	Book *book;
	Book *tmp;
	
	tmp = bookHead;
	book = NULL;
	while(tmp != NULL)
	{
		if(tmp->index == bookIndex)
		{
			book = (Book*)(malloc(sizeof(Book)));
			BookCopy(book,tmp);
			book->pre = NULL;
			book->next = NULL;
			break;
		}
		else
		{
			tmp = tmp->next;
		}
	}
	return book;
}

/*
*find book by bookindex
*/
void FindBookByIndex(Book *bookHead)
{
	int bookIndex;
	Book *tmp;
	Book *book;
	int bookSize;
	
	bookSize = sizeof(Book);
	tmp = bookHead;
	book = NULL;
	
	printf("Please input book's index:\n");
	scanf("%d",&bookIndex);
	printf("\n");
	
	book = QueryBookByIndex(bookIndex,bookHead);
	
	if(book != NULL)
	{
		PutBook(1,book);
		ReleaseAllBook(book);
	}
}

/*
*find book by bookname
*/
void FindBookByName(Book *bookHead)
{
	char bookname[100]; //书名
	Book *tmp;
	Book *lastBook;
	Book *retHead;
	Book *retBook;
	int bookSize;
	
	bookSize = sizeof(Book);
	tmp = bookHead;
	lastBook = NULL;
	retHead = NULL;
	retBook = NULL;	
	
	printf("Please input book's bookname:\n");
	scanf("%s",bookname);
	printf("\n");
	
	while(tmp != NULL)
	{
		if(strcmp(tmp->bookname,bookname) == 0)
		{
			retBook = (Book*)(malloc(bookSize));
			BookCopy(retBook,tmp);
			retBook->pre = NULL;
			retBook->next = NULL;
					
			if(retHead == NULL)
			{
				retHead = retBook;
			}
			else
			{
				lastBook->next = retBook;
			}
			lastBook = retBook;
		}

		tmp = tmp->next;
	}
	if(retHead != NULL)
	{
		PutAllBook(retHead);
		ReleaseAllBook(retHead);
	}
}

/*
*find book by Author
*/
void FindBookByAuthor(Book *bookHead)
{
	char author[20]; //作者
	Book *tmp;
	Book *lastBook;
	Book *retHead;
	Book *retBook;
	int bookSize;
	
	bookSize = sizeof(Book);
	tmp = bookHead;
	lastBook = NULL;
	retHead = NULL;
	retBook = NULL;	
	
	printf("Please input book's author:\n");
	scanf("%s",author);
	printf("\n");
	
	while(tmp != NULL)
	{
		if(strcmp(tmp->author,author) == 0)
		{
			retBook = (Book*)(malloc(bookSize));
			BookCopy(retBook,tmp);
			retBook->pre = NULL;
			retBook->next = NULL;
					
			if(retHead == NULL)
			{
				retHead = retBook;
			}
			else
			{
				lastBook->next = retBook;
			}
			lastBook = retBook;
		}

		tmp = tmp->next;
	}
	if(retHead != NULL)
	{
		PutAllBook(retHead);
		ReleaseAllBook(retHead);
	}
}


/*
*find book by Category
*/
void FindBookByCategory(Book *bookHead)
{
	char category[20];//计算机  文学  小说
	Book *tmp;
	Book *lastBook;
	Book *retHead;
	Book *retBook;
	int bookSize;
	
	bookSize = sizeof(Book);
	tmp = bookHead;
	lastBook = NULL;
	retHead = NULL;
	retBook = NULL;	
	
	printf("Please input book's category:\n");
	scanf("%s",category);
	printf("\n");
	
	while(tmp != NULL)
	{
		if(strcmp(tmp->category,category) == 0)
		{
			retBook = (Book*)(malloc(bookSize));
			BookCopy(retBook,tmp);
			retBook->pre = NULL;
			retBook->next = NULL;
					
			if(retHead == NULL)
			{
				retHead = retBook;
			}
			else
			{
				lastBook->next = retBook;
			}
			lastBook = retBook;
		}

		tmp = tmp->next;
	}
	if(retHead != NULL)
	{
		PutAllBook(retHead);
		ReleaseAllBook(retHead);
	}
}

/*
*find book by Category
*/
void FindBookByPress(Book *bookHead)
{
	char press[100];//计算机  文学  小说
	Book *tmp;
	Book *lastBook;
	Book *retHead;
	Book *retBook;
	int bookSize;
	
	bookSize = sizeof(Book);
	tmp = bookHead;
	lastBook = NULL;
	retHead = NULL;
	retBook = NULL;	
	
	printf("Please input book's press:\n");
	scanf("%s",press);
	printf("\n");
	
	while(tmp != NULL)
	{
		if(strcmp(tmp->press,press) == 0)
		{
			retBook = (Book*)(malloc(bookSize));
			BookCopy(retBook,tmp);
			retBook->pre = NULL;
			retBook->next = NULL;
					
			if(retHead == NULL)
			{
				retHead = retBook;
			}
			else
			{
				lastBook->next = retBook;
			}
			lastBook = retBook;
		}

		tmp = tmp->next;
	}
	if(retHead != NULL)
	{
		PutAllBook(retHead);
		ReleaseAllBook(retHead);
	}
}

