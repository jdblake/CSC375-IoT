#include <stdio.h>
#include <string.h>

struct books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

/* function declaration */
void printBook( struct books *book );
int main( ) {

   struct books book1;        /* Declare book1 of type Book */
   struct books book2;        /* Declare book2 of type Book */

   /* book 1 specification */
   strcpy( book1.title, "C Programming");
   strcpy( book1.author, "Nuha Ali");
   strcpy( book1.subject, "C Programming Tutorial");
   book1.book_id = 6495407;

   /* book 2 specification */
   strcpy( book2.title, "Telecom Billing");
   strcpy( book2.author, "Zara Ali");
   strcpy( book2.subject, "Telecom Billing Tutorial");
   book2.book_id = 6495700;

   /* print book1 info by passing address of book1 */
   printBook( &book1 );

   /* print book2 info by passing address of book2 */
   printBook( &book2 );

   return 0;
}

void printBook( struct books *book ) {

   printf( "Book title : %s\n", book->title);
   printf( "Book author : %s\n", book->author);
   printf( "Book subject : %s\n", book->subject);
   printf( "Book book_id : %d\n", book->book_id);
}
