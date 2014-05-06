void cardio2(int col,int lin,int r)
{
   arc(col-r,lin,0,180,r);
   arc(col+r,lin,0,180,r);
   arc(col,lin,180,210,2*r);
   arc(col,lin,330,360,2*r);
   line(col,3.3*r+lin,col+(1.75*r),0.98*r+lin);
   line(col,3.3*r+lin,col-(1.75*r),0.98*r+lin);
}
