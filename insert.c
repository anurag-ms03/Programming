#include <stdio.h>
#include <stdlib.h>
int* ptr;
int n, i, pos, x;
void read_array()
{
printf("Enter number of elements:\n");
    scanf("%d",&n);
 
    // Dynamically allocate memory using calloc()
    ptr = (int*)calloc(n,sizeof(int));
 
    // Check if the memory has been successfully
    // allocated by calloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        printf("Memory successfully allocated using calloc.\n");
 
        // Get the elements of the array
        printf("Enter the array elements \n");
        for (i = 0; i<n; ++i) {
           scanf("%d",ptr+i);
        }
    }  
}
void display_array()
{
    if(n==0)
    printf("empty array\n");
    else{
         // Print the elements of the array
        printf("The elements of the array are: \n");
        for (i = 0; i<n; ++i) {
            printf("%d ",*(ptr+i));
        }

    }
}
 void insert()
{
    printf("\n enter the position of the element to be inserted \n");
 scanf("%d",&pos);
 if(pos>=0&&pos<n){
 printf("enter the element to be inserted \n");
 scanf("%d",&x);

 n++;
  ptr=realloc(ptr,n*sizeof(int));
 printf("memory has been successfully reallocated using realloc\n");
 i=n-2;
    while(i>=pos)
 {
*(ptr+i+1)=*(ptr+i);
--i;
 }
 ptr[pos]=x;
 printf("insertion successfull\n");
 }
 else
 {
    printf("enter a valid position\n");
 }
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n******ARRAY OPERATION MENU******\n");
        printf("1. Create an array using dynamic memory allocation \n");
        printf("2. Display the array \n");
        printf("3. Insert an element to the array\n");
        printf("4. Exit Menu\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: read_array();
                    break;
            case 2: display_array();
                    break;
            case 3: insert(); 
                    break;
            case 4:   exit(0);
            default : printf("Please enter a valid choice\n");        
                    

        }
    }

}