#include "stdio.h"
#include <malloc.h>
#include <string.h>

#ifndef SBOOKH
	#include "SBook.h"
	#define SBOOKH
#endif
#ifndef SBOOKC
	#include "SBook.c"
	#define SBOOKC
#endif
#ifndef BOOKINFOTABLEH
	#include "BookInfoTable.h"
	#define BOOKINFOTABLEH
#endif



/*
*Realse bookTable
*/
void RealseAllBookTable(BookTable *head)
{
	BookTable *tmp;
	BookTable *next;
	
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
		next = (BookTable *)next->next;
	}
}


/*
*Modify bookTable
*/
void WriteAllBookTable(BookTable *head)
{
	BookTable *tmp;
	FILE *fp;
	int bookSize;
	
	tmp = head;
	fp = fopen(bookTableFile,"wb");
	if(fp == NULL)
	{
		printf("open %s failed\n",bookTableFile);
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
*Chioce book
*/
Book *ChioceBook(Book *bookHead)
{
	int bookIndex;
	Book *tmp;
	Book *book;
	int bookTableSize;
	
	bookTableSize = sizeof(Book);
	tmp = bookHead;
	book = NULL;
	
	while(1)
	{
		while(1)
		{
			printf("Please input book's index:\n");
			scanf("%d",&bookIndex);
			printf("\n");
		
			if(bookIndex > 0)
			{
				break;
			}
			else
			{
				printf("bookIndex not less 0\n");	
				continue;	
			}
		}
	
		book = QueryBookByIndex(bookIndex,bookHead);
	
		if(book == NULL)
		{
			printf("can not find bookIndex %d book\n",bookIndex);
			printf("Please reinput bookindex\n");		
			continue;
		}
		else
		{
			break;
		}
	}
	return book;
}

/*
*chioce booktable
*/
BookTable *QueryBookTableByBookIndex(BookTable *bookTableHead,int bookIndex)
{
	BookTable *tmp;
	BookTable *bookTable;

	tmp = bookTableHead;
	bookTable = NULL;	
	
	while(tmp != NULL)
	{
		if(tmp->index == bookIndex)
		{
			bookTable = tmp;
			break;
		}
		else
		{
			tmp = tmp->next;
		}
	}
	if(bookTable == NULL)
	{
		printf("Query book table error,please check book index\n");
	}
	return bookTable;
}


/*
*Borrow Book
*/
void BorrowBook(Book *bookHead,BookTable *bookTableHead)
{
	Book *book;
	BookTable *bookTable;
	int borrowCount;

	if(bookTableHead == NULL)
	{
		return;	
	}
	
	book = ChioceBook(bookHead);
	if(book == NULL)
	{
		return;		
	}
	
	bookTable = QueryBookTableByBookIndex(bookTableHead,book->index);
	if(bookTable == NULL)
	{
		return;	
	}
	
	printf("Book:%s total %d ,current have %d count:\n",book->bookname,bookTable->count,bookTable->currentCount);
	if(bookTable->currentCount == 0)
	{
		printf("Current book can not borrow\n");	
		RealseAllBookTable(bookTableHead);
		return;
	}
	
	printf("please input borrow count:\n");
	scanf("%d",&borrowCount);
	printf("\n");
	
	if(bookTable->currentCount < borrowCount)
	{
		printf("count error\n");
		return;
	}

	bookTable->currentCount = bookTable->currentCount - borrowCount;
	WriteAllBookTable(bookTableHead);
}

/*
*Back book
*/
void BackBook(BookTable *bookTableHead)
{
	int bookIndex;
	BookTable *bookTable;
	int backCount;
	bookTable = NULL;

	if(bookTableHead == NULL)
	{
		return;	
	}
	
	while(1)
	{
		printf("Please input book index:\n");
		scanf("%d",&bookIndex);
		printf("\n");
	
		bookTable = QueryBookTableByBookIndex(bookTableHead,bookIndex);
		if(bookTable == NULL)
		{
			printf("can not find bookIndex %d book\n",bookIndex);
			continue;	
		}
		else
		{
			break;
		}
	}
	
	while(1)
	{
		printf("please input back count:\n");
		scanf("%d",&backCount);
		printf("\n");
	
		if(backCount < 0)
		{
			printf("back count can not less 0\n");
			continue;
		}
		
		if(backCount + bookTable->currentCount > bookTable->count)
		{
			printf("back count can not greater %d\n",(bookTable->count - bookTable->currentCount));
			continue;
		}
		else
		{
			break;
		}
	}

	bookTable->currentCount = bookTable->currentCount + backCount;
	WriteAllBookTable(bookTableHead);
}
