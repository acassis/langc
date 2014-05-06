main()
{
  int val1[15],val2[15],val3[15],i=0;
  clrscr();
  puts("entre com 15 inteiros:");
  for (i=0;i<15;i++)
      scanf("%d",&val1[i]);
  puts("entre com mais 15 inteiros:");
  for (i=0;i<15;i++)
      scanf("%d",&val2[i]);
  for (i=0;i<15;i++)
      val3[i]=(val2[i]+val1[i]);
  for (i=0;i<15;i++)
      printf("%d",val3[i]);
}