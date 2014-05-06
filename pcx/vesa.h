typedef struct {
        char manufacturer;
        char version;
        char encoding;
        char BitsPerPixel;
        short int x1, y1;
        short int x2, y2;
        short int hres;
        short int vres;
        char palette[48];
        char reserved;
        char colour_planes;
        short int BytesPerLine;
        short int PaletteType;
        char dummy[58];
} PCXHEADER;

PCXHEADER Header;

typedef struct  {
                 unsigned char Palette[768];
                 unsigned char *PcxBuffer;
                 unsigned int DWidth;
                 unsigned int DHeight;
                 unsigned int ScreenMode;
                 unsigned int PageNumber;
                 unsigned int LastPage;
                } PCX_VARS;

PCX_VARS Pcx_vars;

void Open_SvgaPcx(char *FilePcxName)
{
FILE *PcxFile;
int Width, Height;

if ( (PcxFile = fopen(FilePcxName, "rb")) == NULL)
        {
         Text_Mode();
         printf("ERROR_1: I can't load %s - check the path",FilePcxName);
         fclose(PcxFile);
         exit(1);
        }

fread(&Header, sizeof(PCXHEADER), 1, PcxFile);

if (Header.BitsPerPixel!=8)
        {
         Text_Mode();
         printf("ERROR_2: I can't load %s - This Pcx has a wrong number of colors",FilePcxName);
         fclose(PcxFile);
         exit(1);
        }
Width = (Header.x2 - Header.x1) + 1;
Height = (Header.y2 - Header.y1) + 1;

Pcx_vars.PcxBuffer = malloc(Pcx_vars.DWidth*Pcx_vars.DHeight);

memset(Pcx_vars.PcxBuffer, 0, Pcx_vars.DWidth * Pcx_vars.DHeight);

UnpackSvgaPcx(PcxFile, (char *)Pcx_vars.PcxBuffer,Width, Height);
fclose(PcxFile);
}

///////////////////////////////////////////////////////////////////////
//                 This function is very complex                    //
//                 try to understand... if you can!                  //
///////////////////////////////////////////////////////////////////////

void UnpackSvgaPcx(FILE *fh, char *Buffer, int Width, int Height)
{
char *wbuf, *wptr, c, l;
int Offset, j, k, WHeight;

fseek(fh, -768L, SEEK_END);
fread(Pcx_vars.Palette, 768, 1, fh);

fseek(fh, sizeof(PCXHEADER), SEEK_SET);
wptr=wbuf=malloc(Width);

if (Pcx_vars.DHeight > Height)
   WHeight = Height;
else
   WHeight = Pcx_vars.DHeight;

for (j=0; j<WHeight; j++)
   {
   for (k=0; k<Width;)
      {
      c = fgetc(fh);
      if (((unsigned char)c) > 191)
         {
         l = c - 192;
         c = fgetc(fh);
         memset(wptr, c, l);
         wptr += l;
         k += l;
         }
      else
         {
         *wptr = c;
         wptr++;   k++;
         }
      }
   if (Pcx_vars.DWidth >= Width)
      memcpy(Buffer+(j*Pcx_vars.DWidth), wbuf, Width);
   else
      memcpy(Buffer+(j*Pcx_vars.DWidth), wbuf, Pcx_vars.DWidth);

   wptr = wbuf;
   }

fclose(fh);
}

//Set the palette

void SetPcxPalette(char *Palette)
{
short int i;
char far *p;

for (i=0; i<768; i++)
    Palette[i] = Palette[i] >> 2;

p = Palette;

outp(0x3c6, 0xff);
for (i=0; i<=255; i++)
    {
    outp(0x3c8, i);
    outp(0x3c9, *p++);
    outp(0x3c9, *p++);
    outp(0x3c9, *p++);
    }
}

/*
/////////////////////////////////////////////////////////////////////////////
                        Let's set the VESA mode

                       Mode=
                           - 0x0101 640*480 256col
                           - 0x0103 800*600 256col
                           - 0x0105 1024*768 256col

/////////////////////////////////////////////////////////////////////////////
*/

int VESA_SetMode(int Mode)
{
//union REGS regs;

asm mov ax,0x4F02
asm mov bx,Mode
asm int 10h

Pcx_vars.PageNumber = (Pcx_vars.DWidth * Pcx_vars.DHeight) / 65536;
Pcx_vars.LastPage = (Pcx_vars.DWidth * Pcx_vars.DHeight) - (Pcx_vars.PageNumber * 65536);

if (_AL == 0)
	return(0);
else
	return(1);

}

/*
/////////////////////////////////////////////////////////////////////////////
                               Do not TOUCH !!!
/////////////////////////////////////////////////////////////////////////////
*/

void VESA_SetPage(short int Page)
{

union REGS r;

asm mov ax,0x4F05
asm mov bx,0
asm mov dx, Page
asm int 10h

}

/*
/////////////////////////////////////////////////////////////////////////////
                     Returns in Text mode (80 x 24)
/////////////////////////////////////////////////////////////////////////////
*/
void Text_Mode()
{
    asm mov ax,3
    asm int 10h
}

// Hi boy,see you later..
