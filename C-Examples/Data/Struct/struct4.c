#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book;

int main( ) {

   struct book book1;
   book book2;
   book *book3;

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

   /* book 3 creation and specification */
   book3 = malloc(sizeof(book));
   strcpy( book3->title, "Wizard of Oz");
   strcpy( book3->author, "L. Frank Baum");
   strcpy( book3->subject, "Shenanigans");
   book3->book_id = 1010101;

   /* print Book1 info */
   printf( "Book 1 title : %s\n", book1.title);
   printf( "Book 1 author : %s\n", book1.author);
   printf( "Book 1 subject : %s\n", book1.subject);
   printf( "Book 1 book_id : %d\n", book1.book_id);

   /* print Book2 info */
   printf( "Book 2 title : %s\n", book2.title);
   printf( "Book 2 author : %s\n", book2.author);
   printf( "Book 2 subject : %s\n", book2.subject);
   printf( "Book 2 book_id : %d\n", book2.book_id);

   /* print Book3 info */
   printf( "Book 3 title : %s\n", book3->title);
   printf( "Book 3 author : %s\n", book3->author);
   printf( "Book 3 subject : %s\n", book3->subject);
   printf( "Book 3 book_id : %d\n", book3->book_id);

   return 0;
}
