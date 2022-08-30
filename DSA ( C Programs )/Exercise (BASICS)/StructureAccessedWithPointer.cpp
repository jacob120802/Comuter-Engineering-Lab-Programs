#include <stdio.h>
#include <stdlib.h>
struct shopping_list
{
   int quantity;
   char item_name[30];
   int price;
};
int main()
{
   struct shopping_list *ptr;
   int i, n, total, total1;
   printf("Enter the no. of items in shopping list: ");
   scanf("%d", &n);
   ptr = (struct shopping_list*) malloc(n * sizeof(struct shopping_list));
   for(i = 0; i < n; ++i)
   {
       printf("Enter %d, item name quantity & price respectively: ", i+1);
       scanf("%s %d %d", (ptr+i)->item_name, &(ptr+i)->quantity, &(ptr+i)->price);
   }
   printf("\nDisplaying Shopping list:\n");
   for(i = 0; i < n; ++i){
       printf("Item name: %s\t\tQuantity: %d\t\tPrice: Rs %d\n", (ptr+i)->item_name, (ptr+i)->quantity, (ptr+i)->price);
   }
   total=0;
   for(i=0; i<=n; i++)
   {
   	total1=(((ptr+i)->quantity) *  ((ptr+i)->price));
   	total += total1;
   }
   printf("\nTotal cost = Rs %d", total);
   return 0;
}