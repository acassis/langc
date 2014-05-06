void main()
{
      char ch=255,nome[]="",ext[]=".exe";
      strcpy(nome,"copy c:\\alan.bmp c:\\");
      strcat(nome,ch);
      strcat(nome,ext);
      system(nome);
}