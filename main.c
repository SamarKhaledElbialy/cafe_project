#include <stdio.h>
#include <stdlib.h>
//declaring multi-use variables
char   Item_Name;
int    Amount;
double Total=0 , Total_selling=0 ;
//declaring arrays
int    cart[5];
char   names[5]     ={'A','B','C','D','E'};
float  prices[5]    ={3.50,5.25,6.75,8.50,9};
int    quantities[5]={10,10,10,10,10};
//functions prototype
int    print_menu();
void   list_products();
void   add_item();
void   display_cart();
int    find_index(char);
int    enough(int,int);
void   delete_item(int);
void   check_out();
void   Total_sell();
int main()
{
    do
    {
        int choice;
        print_menu();
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
        list_products();
        break;

        case 2:
        add_item();
        break;

        case 3:
        display_cart();
        break;

        case 4:
        delete_item(Item_Name);
        break;

        case 5:
        check_out();
        break;

        case 6:
        Total_sell();
        break;

        case 0:
        return 0;

        default:
        printf ("Invalid Input\n");


        }
    }

    while(1);

    return 0;
}

int print_menu()
{
    int choice;
    printf ("============================\n");
    printf ("1- List all Products\n");
    printf ("2- Add Item to Cart\n");
    printf ("3- Display Items in Cart\n");
    printf ("4- Delete Item from Cart\n");
    printf ("5- Check Out\n");
    printf ("6- Total Selling Value\n");
    printf ("0- Exit\n>> ");
    return (choice);
}
void list_products()
{
    int i;
    printf ("Product\tPrice\tQuantity\n");
    for(i=0 ; i<5 ; i++)
    {
     printf("%c\t%.2f$\t%d\n",names[i],prices[i],quantities[i]);
    }
}
void add_item()
{
    int i;
    printf("Item Name: ");
    scanf (" %c",&Item_Name);
    for ( i=0;i<5;i++)
    {
    if( names[i]==Item_Name )
    {
     printf("\nAmount: ");
     scanf ("%d",&Amount);
     break;
    }
    }

    if((names[i]==Item_Name)&&(Amount<=quantities[i]))
    {
     quantities[i]=quantities[i] - Amount;
     cart[i]=Amount;
     printf("Item added !!\n");
    }

    else if(names[i]!=Item_Name)//checking validation of product
    {
     printf("Product not found !!\n");
    }
    else if(Amount>quantities[i])//checking validation of amount
    {
     printf("There is no enough amount !!\n");
    }
}
void display_cart()
{
    int i,Sum=0;
    for( i=0 ; i<5 ; i++)
    {
    Sum+=cart[i];
    }
    if(Sum==0)
    {
     printf("cart is empty !!\n");
    }
    else
    {
    printf("Product\tPrice\tQuantity\tValue\n");
    Total=0;
    for( i=0 ; i<5 ; i++)
    {
    if(cart[i]!=0)
    printf("%c\t%.2f$\t%d\t\t%.2f$\n",names[i],prices[i],cart[i],prices[i]*cart[i]);
    Total+=(prices[i]*cart[i]);
    }
    printf("Total=%.2f$\n",Total);
    }

}
int find_index(char Item_Name)
{
    int i;
    int index = -1;
    for(i=0; i<5; i++)
    {
    if(names[i] == Item_Name)
    {
     index = i;
     break;
    }
    }
    return index;
}
int enough(int index, int Amount)
{
    int index_2 = 0;
    index=find_index(Item_Name);
    if((index != -1) && (Amount <= quantities[index]))
    {
     index_2 = 1;
    }
    return index_2;
}
void delete_item(int index)
{
    printf("Item Name: ");
    scanf(" %c",&Item_Name);
    index=find_index(Item_Name);//searching for the product generally(not in the cart)
    if(index != -1)
    {
     if((cart[index]>0))//searching for the product in the cart
     {
     cart[index]=0;
     quantities[index]+=Amount;
     printf("Item deleted !!\n");
     }
     else
     {
      printf("Item not found in cart !!\n");
     }
    }
    else
    {
     printf("Item not found !!\n");
    }
}
void check_out()
{
    printf("Check out:%.2f$\n",Total);
    printf("check added to file !!\n");

    FILE * fpointer;
    fpointer = fopen("checks.txt", "a+" );
    fprintf(fpointer,"-------------------------------------\n");
    fprintf(fpointer,"Product\tPrice\tQuantity\tValue\n");
    Total=0;
    for( int i=0 ; i<5 ; i++)
    {
    if(cart[i]!=0)
    {
    fprintf(fpointer,"%c\t%.2f$\t%d\t\t%.2f$\n",names[i],prices[i],cart[i],prices[i]*cart[i]);
    Total+=(prices[i]*cart[i]);
    }
    }
    fprintf(fpointer,"Total=%.2f$\n",Total);
    fclose(fpointer);

    for(int i=0 ; i<5 ; i++)
    {
     cart[i]=0;
    }
    Total_selling+=Total;

}
void Total_sell()
{
    printf("Total selling:%.2f$\n",Total_selling);
}

