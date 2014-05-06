void yang (int col,int lin,int r)
{
   setfillstyle( SOLID_FILL, 15 );
   circle(col,lin,r);
   pieslice(col,lin,0,180,r);
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
   fillellipse(col+(r/2),lin,r/4-1,r/4-1);
}