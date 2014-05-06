struct boot
{
   unsigned int   jump;
   unsigned char  nop;
   char           fabr[8];
   unsigned int   b_por_setor;
   unsigned char  sets_por_cluster;
   unsigned int   sets_Reserv;
   unsigned char  num_Fats;
   unsigned int   entrs_em_root;
   unsigned int   sets_total;
   unsigned char  ID_disco;
   unsigned int   sets_Fat;
   unsigned int   sets_Trilha;
   unsigned int   faces;
   unsigned long  reserv1;
   unsigned long  d_rigido;
   unsigned int   reserv2;
   unsigned char  assinatura;
   unsigned long  ID_volume;
   char           volume[11];
   char           reserv3[8];
   char           prog_boot[448];
   char           fim1;
   char           fim2;
};

