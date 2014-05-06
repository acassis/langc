char buffer[4096];
void savescreen(int li,int ci,int lf,int cf)
{
 gettext(ci, li, cf, lf, buffer);
}
void restorescreen(int li,int ci,int lf,int cf)
{
   puttext(ci, li, cf, lf, buffer);
}
int stst(char *c,char *d)
{
 while((*c) && (*d))
  if(*c++ != *d++)
    return 0;
return 1;
}



