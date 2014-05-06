main()
{
 int m1[5],m2[5],m3[20],i=0,j=0,k=0;
 clrscr();
 puts("entre com uma matriz:");
 for(i=0;i<5;i++)
    scanf("%d",&m1[i]);
 puts ("entre com outra matriz");
 for(i=0;i<5;i++)
     scanf("%d",&m2[i]);
 for (i=0,k=0;i<10;k++,k++,i++)
     m3[k]=m1[i];
 for (i=0,k=1;k<10;k++,k++,i++)
     m3[k]=m2[i];
     for (j=0;j<10;j++)
     printf("%d",m3[j]);
}