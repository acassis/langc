/*
salvar estrutura
*/
#include <stdio.h>

struct mystruct
{
  int i;
  char ch;
};

int main(void)
{  int i;
   FILE *stream;
   struct mystruct s[10];

   if ((stream = fopen("TEST.$$$", "wb")) == NULL) /* open file TEST.$$$ */
   {
      fprintf(stderr, "Cannot open output file.\n");
      return 1;
   }
   for(i=0;i<10;i++)
   {puts("entre com numero");
    scanf("%d",&s[i].i);
    puts("entre com caracter");
    s[i].ch=getche();
   }
   fwrite(&s, sizeof(s), 1, stream); /* write struct s to file */
   fclose(stream); /* close file */
     for(i=0;i<10;i++)
   {s[i].i=0;
    s[i].ch=' ';
   }

   if ((stream = fopen("TEST.$$$", "rb")) == NULL) /* open file TEST.$$$ */
   {
      fprintf(stderr, "Cannot open output file.\n");
      return 1;
   }
   while(( (fread(&s,sizeof(s),1,stream))==1 ))
   for(i=0;i<10;i++)
     printf("\ni = %d    ch = %c",s[i].i,s[i].ch);
   fclose(stream); /* close file */
   getch();
   return 0;
}

