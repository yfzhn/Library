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
#ifndef BOOKINFOTABLEC
	#include "BookInfoTable.c"
	#define BOOKINFOTABLEC
#endif


/*
*user interface menu1
*/
int UserMenu()
{
	int chioce;
	while(1)
	{
		printf("\nPlease chioce doing:\n");
		printf("1.Find book\n");
		printf("2.Back book\n");				
		printf("3.Borrow book\n");
		printf("4.AddBook\n");
		printf("5.Quit\n");
		
		scanf("%d",&chioce);
		printf("\n");
		if(chioce == 1 || chioce == 2 || chioce == 3 || chioce == 4 || chioce == 5)
		{
			break;
		}
	}
	return chioce;
}

/*
*Find book type
*/
BookQueryType FindbookType()
{
	BookQueryType type;
	int chioce;
	while(1)
	{
		printf("1.Index\n");
		printf("2.Bookname\n");
		printf("3.Author\n");
		printf("4.Category\n");
		printf("5.Press\n");
		printf("6.Any\n");
		printf("7.Quit\n");

		scanf("%d",&chioce);
		printf("\n");
		if(chioce == 1 || chioce == 2 || chioce == 3 || chioce == 4 || chioce == 5 || chioce == 6 || chioce == 7)
		{
			break;
		}
	}
	type =(BookQueryType)chioce;
	return type;
}


/*
*find book
*/
void FindBook(Book *bookHead)
{
	BookQueryType type;		
	type = FindbookType(); 
	switch(type)
	{
		case Index:
			FindBookByIndex(bookHead);
			break;
		case Bookname:
			FindBookByName(bookHead);
			break;
		case Author:
			FindBookByAuthor(bookHead);
			break;
		case Category:
			FindBookByCategory(bookHead);
			break;
		case Press:
			FindBookByPress(bookHead);
			break;
		case Any:			
			PutAllBook(bookHead);
			break;
		case Quit:
			puts("Quit");
			break;
	}
}

/*
*User interface doing
*/
int UserInterface()
{
	int menu1;
	Book *bookHead;
	BookTable *bookTableHead;
	
	bookHead = ReadBook(); 
	bookTableHead = ReadBookTable();
	menu1 = UserMenu();
	while(1)
	{
		switch(menu1)
		{
			case 1://Find book
				{
					FindBook(bookHead);
				}
				break;
			case 2://Back book
				{
					BackBook(bookTableHead);
					RealseAllBookTable(bookTableHead);
					bookTableHead = ReadBookTable();
				}
				break;
			case 3://Borrow book
				{
					BorrowBook(bookHead,bookTableHead);
					RealseAllBookTable(bookTableHead);
					bookTableHead = ReadBookTable();
				}
				break;
			case 4://AddBook
				{
					AddBook(bookHead);
					ReleaseAllBook(bookHead);
					bookHead = ReadBook(); 
				}
				break;
			case 5://Quit
				ReleaseAllBook(bookHead);
				RealseAllBookTable(bookTableHead);
				return;
		}
		menu1 = UserMenu();
	}
	return 0;
}



