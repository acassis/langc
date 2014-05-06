void cardio(int col,int lin,int r)
{
   int p[6];
   fillellipse(col-r,lin,r,r);
   fillellipse(col+r,lin,r,r);
   pieslice(col,lin,180,210,2*r);
   pieslice(col,lin,330,360,2*r);
   p[0]=col-(1.75*r);p[1]=0.98*r+lin;
   p[2]=col;p[3]=3.3*r+lin;
   p[4]=col+(1.75*r);p[5]=0.98*r+lin;
   fillpoly(3, p);
   p[2]=col;
   p[3]=lin;
   fillpoly(3, p);
}
   /*setfillstyle( SOLID_FILL, 15 );
   circle(col,lin,r);
   pieslice(col,lin,0,180,r);
   line(col,3.3*r+lin,col+(1.75*r),0.98*r+lin);
   line(col,3.3*r+lin,col-(1.75*r),0.98*r+lin);
   fillellipse(col-(r/2),lin,r/2,r/2);
   arc(col,lin,0 ,180, r);
   setfillstyle( SOLID_FILL,0);
   fillellipse(col+(r/2),lin,r/2,r/2);
   setcolor(0);
   arc(col+(r/2),lin,180,360, r/2);
   setcolor(15);
   circle(col,lin,r);
   setfillstyle( SOLID_FILL, RED);
   setfillstyle( SOLID_FILL,0 );
   fillellipse(col-(r/2),lin,r/4,r/4);
   setfillstyle( SOLID_FILL, 15 );
   fillellipse(col+(r/2),lin,r/4-1,r/4-1);*/