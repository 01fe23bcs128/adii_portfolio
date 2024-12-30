HASHING

#include <stdio.h>
#include <stdlib.h>
// A global variable to hold the values for the supplied key
int hash_table[100];
// Function: menu
// Description: prints the menu option
// Input Params: NIL
// Return Type: void
void menu() {
printf("\n ** MENU ** \n");
printf("------------------------\n");
printf("1-Insert a key\n");
printf("2-Search a Key\n");
printf("3-Delete a key\n");
printf("4-Display Hash Table\n");
printf("5-Exit\n");
printf("------------------------\n");
}
// Function: insert_key
// Description: computes hash and inserts the key into the hash table
// Input Params: NIL
// Return Type: void
void insert_key()
{
int roll = 0, index = 0;
printf("Enter the roll number\n");
scanf("%d", &roll);
// A simple hash computation using % operation.
// You can Notice here that hash function simple takes the
// mod 100 of the supplied key
index = roll % 100;
hash_table[index] = roll;
}
// Function: search_key
// Description: searches the value associated for the given key
// Input Params: NIL
// Return Type: void
void search_key()
{
int roll = 0, index = 0;
printf("Enter the roll number to be searched\n");
scanf("%d", &roll);
index = roll % 100;
if(hash_table[index] == -1)
printf("No Such Data Exists\n");
else
printf("You have reached the %d Roll number Student\n", hash_table[index]);
}
// Function: delete_key
// Description: deletes the supplied key entry from the hash table
// Input Params: NIL
// Return Type: void
void delete_key()
{
int roll = 0, index = 0;
printf("Enter the roll number\n");
scanf("%d", &roll);
index = roll % 100;
if(hash_table[index] == -1)
printf("No Such Data Exists\n");
else {
hash_table[index] = -1;
printf("Associated Data Deleted\n");
}
}
// Function: display_key
// Description: prints the hash table, -1 with no entries
// Input Params: NIL
// Return Type: void
void display_keys()
{
int index = 0;
printf("\nIndex\tRoll Number\n");
for(index=0;index<100;index++)
printf("%d\t%d\n", index, hash_table[index]);
}
int main()
{
int choice = 0, index = 0;
//Initialize the hash table with the value -1
for(index=0;index<100;index++)
hash_table[index] = -1;
while(1) {
menu();
printf("Enter your choice\n");
scanf("%d", &choice);
switch(choice) {
case 1: insert_key();
break;
case 2: search_key();
break;
case 3: delete_key();
break;
case 4:display_keys();
break;
case 5: printf("Terminating the Program\n");
exit(1);
default: printf("Invalid Option\n");
break;
}
}
return 0;
}
