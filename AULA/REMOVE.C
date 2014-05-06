#include <stdio.h>
void main(int a,char *ar[]){
if (remove(ar[1]) == 0)
   printf("Removed %s",ar[1]);
else
   perror("remove");

}
