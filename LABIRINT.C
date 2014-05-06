#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>

#define TRUE -1
#define FALSE 0

/* screen constants */
#define HEIGHT_OF_SCREEN_IN_INCHES       6
#define WIDTH_OF_SCREEN_IN_INCHES        8

/* graphics adapter constants */
#define GRAPHICS_DRIVER                VGA /* 640x480x16 VGA */
#define GRAPHICS_MODE                VGAHI /* must support red, green, yellow,
					      and 5 shades of gray */
#define NUM_X_PIXELS                   640
#define NUM_Y_PIXELS                   480
#define X_PIXEL_MIN                     10
#define X_PIXEL_MAX                    629
#define Y_PIXEL_MIN                      5
#define Y_PIXEL_MAX                    474
#define NUM_COLORS                      16
#define TOP_WALL_COLOR                  12 /* all but last 3 colors are gray */
#define FLOOR_COLOR                      9
#define LEFT_WALL_COLOR                  6
#define FRONT_WALL_COLOR                 3
#define RIGHT_WALL_COLOR                 1
#define BACKOUT_COLOR                   13
#define ADVANCE_COLOR                   14
#define SOLUTION_COLOR                  15

/* maze constants */
#define ROOM_HEIGHT_IN_Y_PIXELS         50
#define MIN_WALL_WIDTH_IN_X_PIXELS       3
#define ROOM_WIDTH_TO_WALL_WIDTH_RATIO   2 /* room excludes wall */


typedef struct corner_record
          {
            int x;
            int y;
          } corner_rec;

typedef struct stack_rec_record
          {
            char index_1;
            int  index_2;
          } stack_rec;

static void           display_maze(int,int,int,int,char **);
static void           display_solution(int,int,int,int,char **);
static void           draw_line(int,int,int,int,int,int);
static void           generate_maze(int,int,int,int,int,char **,stack_rec *,
                       char *);
static void           get_corners(double);
static void           get_cursor(unsigned char *,unsigned char *,
                       unsigned char *,unsigned char *);
static void           get_defaults(char *,int *,double *,char *);
static void           hash(int *,int *,int *,int *,int *,int *,int *,int *);
static void           increment(int *,int *,int *,int *,int *,int *,int *,
                       int *);
static void           let_user_try_to_solve(int *,int,int,int,int,char **,
                       char **);
       void           main(int,char **);
       void interrupt new_critical_error_handler(void);
       void interrupt (*old_critical_error_handler)(void);
static void           output_wall(int,int,int,int,int,int,int,int,int,int,int,
                       int,int,int,int);
static void           put_defaults(char *,int,double,char *);
static void           set_cursor_position(unsigned char,unsigned char);
static void           set_cursor_size(unsigned char,unsigned char);
static void           solve_maze(int,int,int *,int *,char **,stack_rec *);
static void           titillate(void);

extern unsigned _stklen=0x8000;

static unsigned char cursor_column;
static unsigned char cursor_row;
static unsigned char cursor_start;
static unsigned char cursor_stop;
static int           delta_x [4] [24];
static int           delta_y [4] [24];
static int           file_opened;
static char          titillator [4] = {'|','/','-','\\'};
static int           titillator_index;
static int           x_corner [2] [2] [2];
static int           y_corner [2] [2] [2];

void main(
  int  argc,
  char *argv[])
    {
      register int                color_num;
      static   char               **computer_page;
      static   int                default_num_columns;
      static   char               default_seed [256];
      static   double             default_tilt;
      static   int                ErrorCode;
      static   int                fatal_error;
      static   int                GraphDriver;
      static   int                GraphMode;
      static   char               line [256];
      static   char               *line_ptr;
      static   int                max_num_columns;
      static   int                max_x;
      static   int                max_x_plus_1;
      static   int                max_y;
      static   int                max_y_plus_1;
      static   int                min_num_columns;
      static   int                memory_allocated;
      static   int                num_columns;
      static   int                num_assigned;
      static   int                num_rooms_in_maze;
      static   int                num_rows;
      static   struct palettetype palette;
      static   int                response;
      static   char               seed [256];
      static   int                seed_index;
      static   stack_rec          *stack;
      static   double             tilt;
      static   int                tint;
      static   char               **user_page;
      static   int                user_still_interested;
      static   int                x;
  
      max_num_columns=((X_PIXEL_MAX-X_PIXEL_MIN)/MIN_WALL_WIDTH_IN_X_PIXELS-1)
       /(ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2);
      min_num_columns=(2*WIDTH_OF_SCREEN_IN_INCHES)/HEIGHT_OF_SCREEN_IN_INCHES;
      if (min_num_columns*HEIGHT_OF_SCREEN_IN_INCHES
       < 2*WIDTH_OF_SCREEN_IN_INCHES)
        min_num_columns++;
      fatal_error=FALSE;
      get_defaults(argv[0],&default_num_columns,&default_tilt,
       &default_seed[0]);
      do
        {
          clrscr();
          printf(
"                              FMAZ20 -- Maze Game\n\n"
"                             Version 2.0 (10/24/94)\n\n\n"
"     Generate and solve mazes on your VGA (or better) display.\n\n"
"     The mazes are displayed in three dimensions.\n\n"
"     To get the value surrounded by [], just press Enter.\n\n");
          do
            {
              printf("     Number of columns (%d to %d, or 0 to exit) [%d]?  ",
               min_num_columns,max_num_columns,default_num_columns);
              fflush(stdin);
              fgets(&line[0],256,stdin);
              line_ptr=&line[0];
              while ((*line_ptr == ' ') || (*line_ptr == (char) 9))
                line_ptr++;
              if ((*line_ptr == '\n') || (*line_ptr == '\0'))
                num_columns=default_num_columns;
              else
                {
                  num_assigned=sscanf(line_ptr,"%d",&num_columns);
                  if ((num_assigned == 0) || (num_assigned == EOF))
                    num_columns=-1;
                }
            }
          while ((num_columns != 0)
          &&     ((num_columns < min_num_columns) 
               || (num_columns > max_num_columns)));
          user_still_interested=num_columns;
          if (user_still_interested)
            {
              printf("\n");
              num_rows=HEIGHT_OF_SCREEN_IN_INCHES
               *num_columns/WIDTH_OF_SCREEN_IN_INCHES;
              do
                {
                  printf("     Tilt (30 to 60 degrees) [%lf]?  ",default_tilt);
                  fflush(stdin);
                  fgets(&line[0],256,stdin);
                  line_ptr=&line[0];
                  while ((*line_ptr == ' ') || (*line_ptr == (char) 9))
                    line_ptr++;
                  if ((*line_ptr == '\n') || (*line_ptr == '\0'))
                    tilt=default_tilt;
                  else
                    {
                      num_assigned=sscanf(line_ptr,"%lf",&tilt);
                      if ((num_assigned == 0) || (num_assigned == EOF))
                        tilt=(double) 0.0;
                    }
                }
              while ((tilt < (double) 30.0) || (tilt > (double) 60.0));
              printf("\n     Random number seed (8 or fewer digits) [%s]?  ",
               &default_seed[0]);
              fflush(stdin);
              fgets(&line[0],256,stdin);
              line_ptr=&line[0];
              while ((*line_ptr == ' ') || (*line_ptr == (char) 9))
                line_ptr++;
              if ((*line_ptr != '\n') && (*line_ptr != '\0'))
                {
                  seed_index=0;
                  while ((seed_index < 8) 
                  &&     (*line_ptr)
                  &&     (*line_ptr != '\n'))
                    default_seed[seed_index++]=*(line_ptr++);
                  default_seed[seed_index]='\0';
                }
              strcpy(&seed[0],&default_seed[0]);
              default_num_columns=num_columns;
              default_tilt=tilt;
              num_rooms_in_maze=num_columns*num_rows;
              if ((stack
               =(stack_rec *) malloc(num_rooms_in_maze*sizeof(stack_rec)))
               == NULL)
                {
                  printf("     Fatal error:  out of memory.\n");
                  fatal_error=TRUE;
                }
              else
                {
                  max_x=2*num_columns;
                  max_x_plus_1=max_x+1;
                  max_y=2*num_rows;
                  max_y_plus_1=max_y+1;
                  if ((computer_page
                   =(char **) malloc(max_x_plus_1*sizeof(char *))) == NULL)
                    {
                      printf("     Fatal error:  out of memory.\n");
                      fatal_error=TRUE;
                    }
                  else
                    {
                      memory_allocated=TRUE;
                      x=0;
                      while ((memory_allocated) && (x < max_x_plus_1))
                        if ((computer_page[x]
                         =(char *) malloc(max_y_plus_1*sizeof(char))) == NULL)
                          memory_allocated=FALSE;
                        else
                          x++;
                      if (memory_allocated)
                        {
                          if ((user_page
                           =(char **) malloc(max_x_plus_1*sizeof(char *)))
                           == NULL)
                            {
                              printf("     Fatal error:  out of memory.\n");
                              fatal_error=TRUE;
                            }
                          else
                            {
                              x=0;
                              while ((memory_allocated) && (x < max_x_plus_1))
                                if ((user_page[x]
                                 =(char *) malloc(max_y_plus_1*sizeof(char))) 
                                 == NULL)
                                  memory_allocated=FALSE;
                                else
                                  x++;
                              if (memory_allocated)
                                {
                                  printf(
"\n     While the maze is being generated, a spinning cursor is displayed:  ");
                                  generate_maze(num_columns,num_rows,
                                   num_rooms_in_maze,max_x,max_y,computer_page,
                                   stack,&seed[0]);
				  /*
                                     See the Borland documentation on the
                                     utilities "BINOBJ" and "TLIB" for 
                                     information on how to link "EGAVGA.BGI"
                                     into a program from "GRAPHICS.LIB".
                                  */
                                  GraphDriver=GRAPHICS_DRIVER;
                                  GraphMode=GRAPHICS_MODE;
				  initgraph(&GraphDriver,&GraphMode,"c:\\bc\\bgi");
                                  ErrorCode=graphresult();
                                  if (ErrorCode == 0)
                                    {
                                      getpalette(&palette);
                                      for (color_num=0; 
                                       color_num < (NUM_COLORS-3);
                                       color_num++)
                                        { /* evenly spaced shades of gray */
                                          tint=(63*color_num)/(NUM_COLORS-3);
                                          tint&=0xfc;
                                          setrgbpalette(
                                           palette.colors[color_num],
                                           tint,tint,tint);
                                        }
                                      setrgbpalette(
                                       palette.colors[BACKOUT_COLOR],
                                       0xfc,0xfc,0);
                                      setrgbpalette(
                                       palette.colors[ADVANCE_COLOR],
                                       0,0xfc,0);
                                      setrgbpalette(
                                       palette.colors[SOLUTION_COLOR],
                                       0xfc,0,0);
                                      settextjustify(CENTER_TEXT,BOTTOM_TEXT);
                                      settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
                                      setcolor(NUM_COLORS-4);
                                      outtextxy(NUM_X_PIXELS/2,NUM_Y_PIXELS-1,
                                      "Arrows - Move    S - Solve    Q - Quit");
                                      get_corners(tilt);
                                      display_maze(num_columns,num_rows,max_x,
                                       max_y,computer_page);
                                      let_user_try_to_solve(&response,num_rows,
                                       num_columns,max_x,max_y,computer_page,
                                       user_page);
                                      if ((response == (int) 's')
                                      ||  (response == (int) 'S'))
                                        {
                                          display_solution(num_columns,
                                           num_rows,max_x,max_y,computer_page);
                                          setcolor(NUM_COLORS-4);
                                          outtextxy(NUM_X_PIXELS/2,
                                           NUM_Y_PIXELS-1,
                                           "Press a key to continue.");
                                          response=getch();
                                          if (response == 0)
                                            response=getch();
                                        }
                                      closegraph();
                                    }
                                  else
                                    {
                                      printf("     Fatal error:  %s\n",
                                       grapherrormsg(ErrorCode));
                                      fatal_error=TRUE;
                                    }
                                  for (x=max_x; x >= 0; x--)
                                    free((void *) user_page[x]);
                                }
                              else
                                while (x > 0)
                                  free((void *) user_page[--x]);
                              free((void *) user_page);
                            }
                          for (x=max_x; x >= 0; x--)
                            free((void *) computer_page[x]);
                        }
                      else
                        while (x > 0)
                          free((void *) computer_page[--x]);
                      free((void *) computer_page);
                    }
                  free((void *) stack);
                }
            }
        }
      while ((! fatal_error) && (user_still_interested));
      if (! fatal_error)
        put_defaults(argv[0],default_num_columns,default_tilt,
         &default_seed[0]);
      return;
    }

static void get_defaults(
  char   *argv,
  int    *default_num_columns,
  double *default_tilt,
  char   *default_seed)
    {
      register int  arg_index;
      static   char *arg_ptr;
               FILE *defaults;
      static   char file_name [256];
      static   int  last_period_index;
      static   char line [256];
      static   char *line_ptr;
      static   int  num_assigned;
      static   int  seed_length;
      static   char *seed_ptr;

      arg_index=0;
      arg_ptr=argv;
      last_period_index=-1;
      while ((*arg_ptr) && (arg_index < 252))
        {
          if (*arg_ptr == '.')
            last_period_index=arg_index;
          file_name[arg_index++]=*(arg_ptr++);
        }
      if ((*arg_ptr) || (last_period_index < 0))
        {
          *default_num_columns=30;
          *default_tilt=(double) 30.0;
          default_seed[0]='1';
          default_seed[1]='\0';
        }
      else
        {
          file_name[++last_period_index]='I';
          file_name[++last_period_index]='N';
          file_name[++last_period_index]='I';
          file_name[++last_period_index]='\0';
          if ((defaults=fopen(&file_name[0],"r")) == NULL)
            {
              *default_num_columns=30;
              *default_tilt=(double) 30.0;
              default_seed[0]='1';
              default_seed[1]='\0';
            }
          else
            {
              fgets(&line[0],256,defaults);
              line_ptr=&line[0];
              while ((*line_ptr == ' ') || (*line_ptr == (char) 9))
                line_ptr++;
              if ((*line_ptr == '\n') || (*line_ptr == '\0'))
                *default_num_columns=30;
              else
                {
                  num_assigned=sscanf(line_ptr,"%d",default_num_columns);
                  if ((num_assigned == 0) || (num_assigned == EOF))
                    *default_num_columns=30;
                }
              fgets(&line[0],256,defaults);
              line_ptr=&line[0];
              while ((*line_ptr == ' ') || (*line_ptr == (char) 9))
                line_ptr++;
              if ((*line_ptr == '\n') || (*line_ptr == '\0'))
                *default_tilt=(double) 30.0;
              else
                {
                  num_assigned=sscanf(line_ptr,"%lf",default_tilt);
                  if ((num_assigned == 0) || (num_assigned == EOF))
                    *default_tilt=(double) 30.0;
                }
              fgets(&line[0],256,defaults);
              line_ptr=&line[0];
              while ((*line_ptr == ' ') || (*line_ptr == (char) 9))
                line_ptr++;
              seed_ptr=default_seed;
              if ((*line_ptr == '\n') || (*line_ptr == '\0'))
                *(seed_ptr++)='1';
              else
                {
                  seed_length=0;
                  while ((seed_length < 8)
                  &&     (*line_ptr)
                  &&     (*line_ptr != '\n')) 
                    {
                      *(seed_ptr++)=*(line_ptr++);
                      seed_length++;
                    }
                }
              *seed_ptr='\0';
              fclose(defaults);
            }
        }
      return;
    }

void interrupt new_critical_error_handler()
    {
      file_opened=FALSE;
      return;
    }

static void put_defaults(
  char   *argv,
  int    num_columns,
  double tilt,
  char   *seed)
    {
      static int  arg_index;
      static char *arg_ptr;
             FILE *defaults;
      static char file_name [256];
      static int  last_period_index;

      arg_index=0;
      arg_ptr=argv;
      last_period_index=-1;
      while ((*arg_ptr) && (arg_index < 252))
        {
          if (*arg_ptr == '.')
            last_period_index=arg_index;
          file_name[arg_index++]=*(arg_ptr++);
        }
      if ((*arg_ptr == '\0') && (last_period_index >= 0))
        {
          file_name[++last_period_index]='I';
          file_name[++last_period_index]='N';
          file_name[++last_period_index]='I';
          file_name[++last_period_index]='\0';
          old_critical_error_handler=getvect(0x24);
          setvect(0x24,new_critical_error_handler);
          file_opened=TRUE;
          if ((defaults=fopen(&file_name[0],"w")) != NULL)
            {
              setvect(0x24,old_critical_error_handler);
              if (file_opened)
                {
                  fprintf(defaults,"%d\n%lf\n%s\n",num_columns,tilt,seed);
                  fclose(defaults);
                }
            }
          else 
            setvect(0x24,old_critical_error_handler);           
        }
      return;
    }

static void get_corners(
  double tilt)
    {
      static   double cos_tilt;
      static   int    i;
      register int    j;
      register int    k;
      static   double pixels_per_unit;
      static   double radians;
      static   double radians_per_degree;
      static   double sin_tilt;
      static   double x;
      static   double x_base [2];
      static   double x_eye;
      static   double x_prime;
      static   double x_prime_max;
      static   double y;
      static   double y_base [2];
      static   double y_center;
      static   double y_offset;
      static   double y_out_max;
      static   double y_prime;
      static   double y_prime_max;
      static   double y_prime_min;
      static   double z;
      static   double z_base [2];
      static   double z_center;
      static   double z_offset;
      static   double z_out_max;
      static   double z_prime;
      static   double z_prime_max;
      static   double z_prime_min;

      x_base[0]=(double) X_PIXEL_MIN;
      x_base[1]=(double) X_PIXEL_MAX;
      y_base[0]=(double) Y_PIXEL_MIN;
      y_base[1]=(double) Y_PIXEL_MAX;
      z_base[0]=(double) 0.0;
      z_base[1]=(double) ROOM_HEIGHT_IN_Y_PIXELS;
      radians_per_degree=atan(1.0)/45.0;
      radians=tilt*radians_per_degree;
      cos_tilt=cos(radians);
      sin_tilt=sin(radians);
      x=x_base[0];
      y=y_base[0];
      z=z_base[0];
      y_prime_min=x;
      x_prime_max=y*cos_tilt+z*sin_tilt;
      z_prime_min=-y*sin_tilt+z*cos_tilt;
      y_prime_max=y_prime_min;
      z_prime_max=z_prime_min;
      for (i=0; i <= 1; i++)
        for (j=0; j <= 1; j++)
          for (k=0; k <= 1; k++)
            {
              x=x_base[k];
              y=y_base[j];
              z=z_base[i];
              y_prime=x;
              if (y_prime > y_prime_max)
                y_prime_max=y_prime;
              else
                {
                  if (y_prime < y_prime_min)
                    y_prime_min=y_prime;
                }
              x_prime=y*cos_tilt+z*sin_tilt;
              if (x_prime > x_prime_max)
                x_prime_max=x_prime;
              z_prime=-y*sin_tilt+z*cos_tilt;
              if (z_prime > z_prime_max)
                z_prime_max=z_prime;
              else
                {
                  if (z_prime < z_prime_min)
                    z_prime_min=z_prime;
                }
            }
      if ((y_prime_max-y_prime_min) > (z_prime_max-z_prime_min))
        x_eye=1.1*(y_prime_max-y_prime_min)+x_prime_max;
      else
        x_eye=1.1*(z_prime_max-z_prime_min)+x_prime_max;
      /* 1.1 for slight "fish-eye" */
      y_center=(y_prime_max+y_prime_min)/2.0;
      z_center=(z_prime_max+z_prime_min)/2.0;
      y_out_max=(double) (X_PIXEL_MAX-X_PIXEL_MIN);
      z_out_max=(double) (Y_PIXEL_MAX-Y_PIXEL_MIN);
      if (z_out_max*(y_prime_max-y_prime_min)
       > y_out_max*(z_prime_max-z_prime_min))
        {
          pixels_per_unit=y_out_max/(y_prime_max-y_prime_min);
          y_offset=0.0;
          z_offset=-(z_out_max-pixels_per_unit*(z_prime_max-z_prime_min))/2.0;
        }
      else
        if (z_out_max*(y_prime_max-y_prime_min)
         < y_out_max*(z_prime_max-z_prime_min))
          {
            pixels_per_unit=z_out_max/(z_prime_max-z_prime_min);
            y_offset=(y_out_max
             -pixels_per_unit*(y_prime_max-y_prime_min))/2.0;
            z_offset=0.0;
          }
        else
          {
            pixels_per_unit=1.0;
            y_offset=y_out_max/2.0;
            z_offset=-z_out_max/2.0;
          }
      for (i=0; i <= 1; i++)
        for (j=0; j <= 1; j++)
          for (k=0; k <= 1; k++)
            {
              x=x_base[k];
              y=y_base[j];
              z=z_base[i];
              y_prime=x;
              x_prime=y*cos_tilt+z*sin_tilt;
              z_prime=-y*sin_tilt+z*cos_tilt;
              x=x_prime;
              y=y_prime;
              z=z_prime;
              y_prime=y_center+(y-y_center)*(x_eye-x_prime_max)/(x_eye-x);
              z_prime=z_center+(z-z_center)*(x_eye-x_prime_max)/(x_eye-x);
              y=y_prime;
              z=z_prime;
              x_corner[k][j][i]=X_PIXEL_MIN
               +(int) (y_offset+pixels_per_unit*(y-y_prime_min));
              y_corner[k][j][i]=Y_PIXEL_MIN
               +(int) (z_offset+z_out_max-pixels_per_unit*(z-z_prime_min));
            }
      return;
    }

static int substitution_high [100] =
             { 4,1,2,8,8,9,9,6,5,7,2,1,2,9,8,8,6,3,5,1,9,5,4,4,9,8,6,0,8,0,
               6,0,2,4,1,9,2,0,7,4,7,3,0,0,2,6,8,9,4,0,8,3,2,3,2,5,2,4,6,9,
               7,9,1,3,5,7,1,1,4,5,8,1,6,0,5,7,8,2,3,3,7,3,5,1,7,5,4,0,3,6,
               3,7,7,1,9,4,0,5,6,6
             };
static int substitution_low [100] =
             { 1,2,2,1,5,5,4,6,4,6,4,4,5,6,6,3,0,9,6,5,7,2,0,9,3,4,2,3,9,1,
               9,9,9,3,8,9,3,4,1,5,0,5,2,7,0,8,8,0,4,5,0,3,6,8,1,7,8,8,7,1,
               3,2,7,7,1,8,0,3,7,5,2,6,4,0,9,9,7,7,4,6,2,0,0,1,7,3,6,6,1,1,
               2,4,5,9,8,2,8,8,3,5
             };
static void hash(
  int *counter_0,
  int *counter_1,
  int *counter_2,
  int *counter_3,
  int *counter_4,
  int *counter_5,
  int *counter_6,
  int *counter_7)
    {
      register int iteration;
      static   int seed_0;
      static   int seed_1;
      static   int seed_2;
      static   int seed_3;
      static   int seed_4;
      static   int seed_5;
      static   int seed_6;
      static   int seed_7;
      register int substitution_index;
      static   int tem_0;
      static   int tem_1;
      static   int tem_2;

      seed_0=(*counter_0);
      seed_1=(*counter_1);
      seed_2=(*counter_2);
      seed_3=(*counter_3);
      seed_4=(*counter_4);
      seed_5=(*counter_5);
      seed_6=(*counter_6);
      seed_7=(*counter_7);
      for (iteration=1; iteration <= 8; iteration++)
        {
          substitution_index=10*seed_1+seed_0;
          tem_0=substitution_low[substitution_index];
          tem_1=substitution_high[substitution_index];
          substitution_index=10*seed_3+seed_2;
          seed_0=substitution_low[substitution_index];
          tem_2=substitution_high[substitution_index];
          substitution_index=10*seed_5+seed_4;
          seed_2=substitution_low[substitution_index];
          seed_1=substitution_high[substitution_index];
          substitution_index=10*seed_7+seed_6;
          seed_5=substitution_low[substitution_index];
          seed_7=substitution_high[substitution_index];
          seed_3=tem_0;
          seed_6=tem_1;
          seed_4=tem_2;
        }
      (*counter_0)=seed_0;
      (*counter_1)=seed_1;
      (*counter_2)=seed_2;
      (*counter_3)=seed_3;
      (*counter_4)=seed_4;
      (*counter_5)=seed_5;
      (*counter_6)=seed_6;
      (*counter_7)=seed_7;
      return;
    }

static void increment(
  int *counter_0,
  int *counter_1,
  int *counter_2,
  int *counter_3,
  int *counter_4,
  int *counter_5,
  int *counter_6,
  int *counter_7)
    {
      register tem;

      tem=(*counter_0)+1;
      if (tem <= 9)
        (*counter_0)=tem;
      else
        {
          (*counter_0)=0;
          tem=(*counter_1)+1;
          if (tem <= 9)
            (*counter_1)=tem;
          else
            {
              (*counter_1)=0;
              tem=(*counter_2)+1;
              if (tem <= 9)
                (*counter_2)=tem;
              else
                {
                  (*counter_2)=0;
                  tem=(*counter_3)+1;
                  if (tem <= 9)
                    (*counter_3)=tem;
                  else
                    {
                      (*counter_3)=0;
                      tem=(*counter_4)+1;
                      if (tem <= 9)
                        (*counter_4)=tem;
                      else
                        {
                          (*counter_4)=0;
                          tem=(*counter_5)+1;
                          if (tem <= 9)
                            (*counter_5)=tem;
                          else
                            {
                              (*counter_5)=0;
                              tem=(*counter_6)+1;
                              if (tem <= 9)
                                (*counter_6)=tem;
                              else
                                {
                                  (*counter_6)=0;
                                  tem=(*counter_7)+1;
                                  if (tem <= 9)
                                    (*counter_7)=tem;
                                  else
                                    (*counter_7)=0;
                                }
                            }
                        }
                    }
                }
            }
        }
      return;
    }

static void get_cursor(
  unsigned char *cursor_row,
  unsigned char *cursor_column,
  unsigned char *cursor_start,
  unsigned char *cursor_stop)
    {
      static union REGS in;
      static union REGS out;

      in.h.ah=(unsigned char) 3;
      in.h.bh=(unsigned char) 0;
      int86(0x10,&in,&out);
      *cursor_row=out.h.dh;
      *cursor_column=out.h.dl;
      *cursor_start=out.h.ch;
      *cursor_stop=out.h.cl;
      return;
    }

static void set_cursor_position(
  unsigned char cursor_row,
  unsigned char cursor_column)
    {
      static union REGS in;
      static union REGS out;

      in.h.ah=(unsigned char) 2;
      in.h.dh=cursor_row;
      in.h.dl=cursor_column;
      int86(0x10,&in,&out);
      return;
    }

static void set_cursor_size(
  unsigned char cursor_start,
  unsigned char cursor_stop)
    {
      static union REGS in;
      static union REGS out;

      in.h.ah=(unsigned char) 1;
      in.h.ch=cursor_start;
      in.h.cl=cursor_stop;
      int86(0x10,&in,&out);
      return;
    }

static void titillate()
    {
      set_cursor_position(cursor_row,cursor_column);
      titillator_index++;
      if (titillator_index > 3)
        titillator_index=0;
      putchar((int) titillator[titillator_index]);
      return;
    }

static void solve_maze(
  int       max_x,
  int       max_y,
  int       *num_rooms_in_solution,
  int       *adjacency,
  char      **page,
  stack_rec *stack)
    {
      static int delta_index;
      static int passage_found;
      static int stack_head;
      static int x;
      static int x_next;
      static int y;
      static int y_next;

      *num_rooms_in_solution=1;
      *adjacency=0;
      x=1;
      y=1;
      stack_head=-1;
      page[x][y]='S';
      do
        {
          delta_index=0;
          passage_found=FALSE;
          do
            {
              while ((delta_index < 4) && (! passage_found))
                {
                  x_next=x+delta_x[delta_index][0];
                  y_next=y+delta_y[delta_index][0];
                  if (page[x_next][y_next] == ' ')
                    passage_found=TRUE;
                  else
                    delta_index++;
                }
              if (! passage_found)
                {
                  delta_index=(int) (stack[stack_head].index_1);
                  page[x][y]=' ';
                  x-=delta_x[delta_index][0];
                  y-=delta_y[delta_index][0];
                  page[x][y]=' ';
                  x-=delta_x[delta_index][0];
                  y-=delta_y[delta_index][0];
                  stack_head--;
                  delta_index++;
                }
            }
          while (! passage_found);
          page[x_next][y_next]='S';
          x_next+=delta_x[delta_index][0];
          y_next+=delta_y[delta_index][0];
          if (y_next <= max_y)
            {
              stack_head++;
              stack[stack_head].index_1=(char) delta_index;
              page[x_next][y_next]='S';
              x=x_next;
              y=y_next;
            }
        }
      while (y_next < max_y);
      x=max_x-1;
      y=max_y-1;
      *adjacency=0;
      while (stack_head >= 0)
        {
          for (delta_index=0; delta_index < 4; delta_index++)
            {
              x_next=x+delta_x[delta_index][0];
              y_next=y+delta_y[delta_index][0];
              if (page[x_next][y_next] != 'S')
                {
                  if (page[x_next][y_next] == 'W')
                    {
                      x_next+=delta_x[delta_index][0];
                      y_next+=delta_y[delta_index][0];
                      if (x_next < 0)
                        (*adjacency)++;
                      else
                        if (x_next > max_x)
                          (*adjacency)++;
                        else
                          if (y_next < 0)
                            (*adjacency)++;
                          else
                            if (y_next > max_y)
                              (*adjacency)++;
                            else
                              {
                                if (page[x_next][y_next] == 'S')
                                  (*adjacency)++;
                              }
                    }
                }
            }
          x-=(2*delta_x[stack[stack_head].index_1][0]);
          y-=(2*delta_y[stack[stack_head].index_1][0]);
          stack_head--;
          (*num_rooms_in_solution)++;
        }
      for (delta_index=0; delta_index < 4; delta_index++)
        {
          x_next=x+delta_x[delta_index][0];
          y_next=y+delta_y[delta_index][0];
          if (page[x_next][y_next] != ' ')
            {
              if (page[x_next][y_next] == 'W')
                {
                  x_next+=delta_x[delta_index][0];
                  y_next+=delta_y[delta_index][0];
                  if (x_next < 0)
                    (*adjacency)++;
                  else
                    if (x_next > max_x)
                      (*adjacency)++;
                    else
                      if (y_next < 0)
                        (*adjacency)++;
                      else
                        if (y_next > max_y)
                          (*adjacency)++;
                        else
                          {
                            if (page[x_next][y_next] == 'S')
                              (*adjacency)++;
                          }
                }
            }
        }
      return;
    }

static void generate_maze(
  int       num_columns,
  int       num_rows,
  int       num_rooms_in_maze,
  int       max_x,
  int       max_y,
  char      **page,
  stack_rec *stack,
  char      *seed_ptr)
    {
      static   int           adjacency;
      static   int           age;
      static   int           counter_0;
      static   int           counter_1;
      static   int           counter_2;
      static   int           counter_3;
      static   int           counter_4;
      static   int           counter_5;
      static   int           counter_6;
      static   int           counter_7;
      static   int           delta_index_1a;
      static   int           delta_index_1b;
      static   int           delta_index_1c;
      static   int           delta_index_1d;
      static   int           delta_index_2;
      static   int           digit;
      static   int           digit_num;
      static   int           num_rooms_in_solution;
      static   int           passage_found;
      static   int           r_n [8];
      static   int           r_n_index_1;
      static   int           r_n_index_2;
      static   int           search_complete;
      static   int           stack_head;
      static   int           sum;
      static   int           tem_int;
      static   int           trial_num_mod_10;
      static   int           x;
      register int           x_next;
      static   int           y;
      register int           y_next;

      while ((*seed_ptr == ' ')
      ||     (*seed_ptr == (char) 9))
        seed_ptr++;
      r_n_index_1=0;
      while ((r_n_index_1 < 8) && (*seed_ptr) && (*seed_ptr != '\n'))
        r_n[r_n_index_1++]=(int) (*(seed_ptr++) % 10);
      r_n_index_2=7;
      while (r_n_index_1 > 0)
        {
           r_n_index_1--;
           r_n[r_n_index_2]=r_n[r_n_index_1];
           r_n_index_2--;
        }
      while (r_n_index_2 >= 0)
        {
          r_n[r_n_index_2]=8;
          r_n_index_2--;
        }
      counter_0=r_n[0];
      counter_1=r_n[1];
      counter_2=r_n[2];
      counter_3=r_n[3];
      counter_4=r_n[4];
      counter_5=r_n[5];
      counter_6=r_n[6];
      counter_7=r_n[7];
      hash(&counter_0,&counter_1,&counter_2,&counter_3,&counter_4,&counter_5,
       &counter_6,&counter_7);
      delta_x[0][0]=-1;
      delta_y[0][0]=0;
      delta_x[1][0]=0;
      delta_y[1][0]=1;
      delta_x[2][0]=1;
      delta_y[2][0]=0;
      delta_x[3][0]=0;
      delta_y[3][0]=-1;
      delta_index_2=0;
      for (delta_index_1a=0; delta_index_1a < 4; ++delta_index_1a)
        for (delta_index_1b=0; delta_index_1b < 4; ++delta_index_1b)
          if (delta_index_1a != delta_index_1b)
            for (delta_index_1c=0; delta_index_1c < 4; ++delta_index_1c)
              if ((delta_index_1a != delta_index_1c)
              &&  (delta_index_1b != delta_index_1c))
                for (delta_index_1d=0; delta_index_1d < 4; ++delta_index_1d)
                  if ((delta_index_1a != delta_index_1d)
                  &&  (delta_index_1b != delta_index_1d)
                  &&  (delta_index_1c != delta_index_1d))
                    {
                      delta_x[delta_index_1a][delta_index_2]=delta_x[0][0];
                      delta_y[delta_index_1a][delta_index_2]=delta_y[0][0];
                      delta_x[delta_index_1b][delta_index_2]=delta_x[1][0];
                      delta_y[delta_index_1b][delta_index_2]=delta_y[1][0];
                      delta_x[delta_index_1c][delta_index_2]=delta_x[2][0];
                      delta_y[delta_index_1c][delta_index_2]=delta_y[2][0];
                      delta_x[delta_index_1d][delta_index_2]=delta_x[3][0];
                      delta_y[delta_index_1d][delta_index_2]=delta_y[3][0];
                      delta_index_2++;
                    };
      get_cursor(&cursor_row,&cursor_column,&cursor_start,&cursor_stop);
      set_cursor_size((unsigned char) 32,(unsigned char) 32);
      titillator_index=0;
      age=3;
      trial_num_mod_10=0;
      do
        {
          titillate();
          for (x=0; x <= max_x; ++x)
            for (y=0; y <= max_y; ++y)
              page[x][y]='W';
          r_n[0]=counter_0+1;
          r_n[1]=counter_1+1;
          r_n[2]=counter_2+1;
          r_n[3]=counter_3+1;
          r_n[4]=counter_4+1;
          r_n[5]=counter_5+1;
          r_n[6]=counter_6+1;
          r_n[7]=counter_7+1;
          sum=0;
          for (digit_num=1; digit_num <= 3; ++digit_num)
            {
              digit=r_n[0];
              r_n_index_1=0;
              for (r_n_index_2=1; r_n_index_2 < 8; ++r_n_index_2)
                {
                  tem_int=r_n[r_n_index_2];
                  r_n[r_n_index_1]=tem_int;
                  digit+=tem_int;
                  if (digit >= 29)
                     digit-=29;
                  r_n_index_1=r_n_index_2;
                }
              r_n[7]=digit;
              sum=29*sum+digit;
            }
          x=2*(sum % num_columns)+1;
          sum=0;
          for (digit_num=1; digit_num <= 3; ++digit_num)
            {
              digit=r_n[0];
              r_n_index_1=0;
              for (r_n_index_2=1; r_n_index_2 < 8; ++r_n_index_2)
                {
                  tem_int=r_n[r_n_index_2];
                  r_n[r_n_index_1]=tem_int;
                  digit+=tem_int;
                  if (digit >= 29)
                     digit-=29;
                  r_n_index_1=r_n_index_2;
                }
              r_n[7]=digit;
              sum=29*sum+digit;
            }
          y=2*(sum % num_rows)+1;
          page[x][y]=' ';
          stack_head=-1;
          do
            {
              delta_index_1a=0;
              do
                {
                  delta_index_2=r_n[0];
                  r_n_index_1=0;
                  r_n_index_2=1;
                  while (r_n_index_2 < 8)
                    {
                      tem_int=r_n[r_n_index_2];
                      r_n[r_n_index_1]=tem_int;
                      delta_index_2+=tem_int;
                      if (delta_index_2 >= 29)
                        delta_index_2-=29;
                      r_n_index_1=r_n_index_2;
                      r_n_index_2++;
                    }
                  r_n[7]=delta_index_2;
                }
              while (delta_index_2 >= 24);
              passage_found=FALSE;
              search_complete=FALSE;
              while (! search_complete)
                {
                  while ((delta_index_1a < 4) && (! passage_found))
                    {
                      x_next=x+2*delta_x[delta_index_1a][delta_index_2];
                      if (x_next <= 0)
                        delta_index_1a++;
                      else
                        if (x_next > max_x)
                          delta_index_1a++;
                        else
                          {
                            y_next=y+2*delta_y[delta_index_1a][delta_index_2];
                            if (y_next <= 0)
                              delta_index_1a++;
                            else
                              if (y_next > max_y)
                                delta_index_1a++;
                              else
                                if (page[x_next][y_next] == 'W')
                                  passage_found=TRUE;
                                else
                                  delta_index_1a++;
                          }
                    }
                  if (! passage_found)
                    {
                      if (stack_head >= 0)
                        {
                          delta_index_1a=(int) (stack[stack_head].index_1);
                          delta_index_2=stack[stack_head].index_2;
                          x-=2*delta_x[delta_index_1a][delta_index_2];
                          y-=2*delta_y[delta_index_1a][delta_index_2];
                          stack_head--;
                          delta_index_1a++;
                        }
                    }
                  search_complete=((passage_found)
                   || ((stack_head == -1) && (delta_index_1a >= 4)));
                }
              if (passage_found)
                {
                  stack_head++;
                  stack[stack_head].index_1=(char) delta_index_1a;
                  stack[stack_head].index_2=delta_index_2;
                  page[x_next][y_next]=' ';
                  page[(x+x_next)/2][(y+y_next)/2]=' ';
                  x=x_next;
                  y=y_next;
                }
            }
          while (stack_head != -1);
          page[1][0]='S';
          page[max_x-1][max_y]=' ';
          solve_maze(max_x,max_y,&num_rooms_in_solution,&adjacency,page,stack);
          increment(&counter_0,&counter_1,&counter_2,&counter_3,&counter_4,
           &counter_5,&counter_6,&counter_7);
          trial_num_mod_10++;
          if (trial_num_mod_10 >= 10)
            {
              trial_num_mod_10=0;
              age++;
            }
        }
      while ((3*num_rooms_in_solution < num_rooms_in_maze)
      ||     (2*adjacency > age*num_rooms_in_solution));
      set_cursor_size(cursor_start,cursor_stop);
      return;
    }

static void output_wall(
  int num_columns,
  int x_out_left,
  int x_out_right,
  int y_pixel_floor_back,
  int y_pixel_floor_front,
  int y_pixel_top_back,
  int y_pixel_top_front,
  int x_pixel_floor_back_left_edge,
  int x_pixel_floor_back_right_edge,
  int x_pixel_top_back_left_edge,
  int x_pixel_top_back_right_edge,
  int x_pixel_floor_front_left_edge,
  int x_pixel_floor_front_right_edge,
  int x_pixel_top_front_left_edge,
  int x_pixel_top_front_right_edge)
    {
      static    corner_rec quadrilateral [4];
      static    int        x_pixel_floor_back_left;
      static    int        x_pixel_floor_back_right;
      static    int        x_pixel_floor_front_left;
      static    int        x_pixel_floor_front_right;
      static    int        x_pixel_top_back_left;
      static    int        x_pixel_top_back_right;
      static    int        x_pixel_top_front_left;
      static    int        x_pixel_top_front_right;

      x_pixel_floor_back_left
       =((int) (((long) x_out_left)
       *((long) (x_pixel_floor_back_right_edge
       -x_pixel_floor_back_left_edge))
       /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_columns+1))))
       +x_pixel_floor_back_left_edge;
      x_pixel_floor_back_right
       =((int) (((long) x_out_right)
       *((long) (x_pixel_floor_back_right_edge
       -x_pixel_floor_back_left_edge))
       /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_columns+1))))
       +x_pixel_floor_back_left_edge;
      x_pixel_floor_front_left
       =((int) (((long) x_out_left)
       *((long) (x_pixel_floor_front_right_edge
       -x_pixel_floor_front_left_edge))
       /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_columns+1))))
       +x_pixel_floor_front_left_edge;
      x_pixel_floor_front_right
       =((int) (((long) x_out_right)
       *((long) (x_pixel_floor_front_right_edge
       -x_pixel_floor_front_left_edge))
       /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_columns+1))))
       +x_pixel_floor_front_left_edge;
      x_pixel_top_back_left
       =((int) (((long) x_out_left)
       *((long) (x_pixel_top_back_right_edge
       -x_pixel_top_back_left_edge))
       /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_columns+1))))
       +x_pixel_top_back_left_edge;
      x_pixel_top_back_right
       =((int) (((long) x_out_right)
       *((long) (x_pixel_top_back_right_edge
       -x_pixel_top_back_left_edge))
       /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_columns+1))))
       +x_pixel_top_back_left_edge;
      x_pixel_top_front_left
       =((int) (((long) x_out_left)
       *((long) (x_pixel_top_front_right_edge
       -x_pixel_top_front_left_edge))
       /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_columns+1))))
       +x_pixel_top_front_left_edge;
      x_pixel_top_front_right
       =((int) (((long) x_out_right)
       *((long) (x_pixel_top_front_right_edge
       -x_pixel_top_front_left_edge))
       /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_columns+1))))
       +x_pixel_top_front_left_edge;
      if (2*(x_pixel_floor_back_left-x_pixel_floor_back_left_edge)
       > (x_pixel_floor_back_right_edge-x_pixel_floor_back_left_edge))
        {
          setcolor(LEFT_WALL_COLOR);
          setfillstyle(SOLID_FILL,LEFT_WALL_COLOR);
          quadrilateral[0].x=x_pixel_floor_back_left;
          quadrilateral[0].y=y_pixel_floor_back;
          quadrilateral[1].x=x_pixel_top_back_left;
          quadrilateral[1].y=y_pixel_top_back;
          quadrilateral[2].x=x_pixel_top_front_left;
          quadrilateral[2].y=y_pixel_top_front;
          quadrilateral[3].x=x_pixel_floor_front_left;
          quadrilateral[3].y=y_pixel_floor_front;
          fillpoly(4,&(quadrilateral[0].x));
        }
      if (2*(x_pixel_floor_back_right-x_pixel_floor_back_left_edge)
       < (x_pixel_floor_back_right_edge-x_pixel_floor_back_left_edge))
        {
          setcolor(RIGHT_WALL_COLOR);
          setfillstyle(SOLID_FILL,RIGHT_WALL_COLOR);
          quadrilateral[0].x=x_pixel_floor_back_right;
          quadrilateral[0].y=y_pixel_floor_back;
          quadrilateral[1].x=x_pixel_top_back_right;
          quadrilateral[1].y=y_pixel_top_back;
          quadrilateral[2].x=x_pixel_top_front_right;
          quadrilateral[2].y=y_pixel_top_front;
          quadrilateral[3].x=x_pixel_floor_front_right;
          quadrilateral[3].y=y_pixel_floor_front;
          fillpoly(4,&(quadrilateral[0].x));
        }
      setcolor(FRONT_WALL_COLOR);
      setfillstyle(SOLID_FILL,FRONT_WALL_COLOR);
      quadrilateral[0].x=x_pixel_floor_front_left;
      quadrilateral[0].y=y_pixel_floor_front;
      quadrilateral[1].x=x_pixel_floor_front_right;
      quadrilateral[1].y=y_pixel_floor_front;
      quadrilateral[2].x=x_pixel_top_front_right;
      quadrilateral[2].y=y_pixel_top_front;
      quadrilateral[3].x=x_pixel_top_front_left;
      quadrilateral[3].y=y_pixel_top_front;
      fillpoly(4,&(quadrilateral[0].x));
      setcolor(TOP_WALL_COLOR);
      setfillstyle(SOLID_FILL,TOP_WALL_COLOR);
      quadrilateral[0].x=x_pixel_top_front_left;
      quadrilateral[0].y=y_pixel_top_front;
      quadrilateral[1].x=x_pixel_top_front_right;
      quadrilateral[1].y=y_pixel_top_front;
      quadrilateral[2].x=x_pixel_top_back_right;
      quadrilateral[2].y=y_pixel_top_back;
      quadrilateral[3].x=x_pixel_top_back_left;
      quadrilateral[3].y=y_pixel_top_back;
      fillpoly(4,&(quadrilateral[0].x));
      return;
    }

static void display_maze(
  int  num_columns,
  int  num_rows,
  int  max_x,
  int  max_y,
  char **page)
  {
    static    char       current_char;
    static    char       previous_char;
    static    corner_rec quadrilateral [4];
    static    int        x;
    static    int        x_even;
    static    int        x_out_left;
    static    int        x_out_left_most;
    static    int        x_out_right;
    static    int        x_out_right_most;
    static    int        x_pixel_floor_back_left_edge;
    static    int        x_pixel_floor_back_right_edge;
    static    int        x_pixel_floor_front_left_edge;
    static    int        x_pixel_floor_front_right_edge;
    static    int        x_pixel_top_back_left_edge;
    static    int        x_pixel_top_back_right_edge;
    static    int        x_pixel_top_front_left_edge;
    static    int        x_pixel_top_front_right_edge;
    static    int        y;
    static    int        y_even;
    static    int        y_out_back;
    static    int        y_out_front;
    static    int        y_pixel_floor_back;
    static    int        y_pixel_floor_front;
    static    int        y_pixel_top_back;
    static    int        y_pixel_top_front;

    setlinestyle(SOLID_LINE,0xffff,NORM_WIDTH);
    setcolor(FLOOR_COLOR);
    setfillstyle(SOLID_FILL,FLOOR_COLOR);
    quadrilateral[0].x=x_corner[0][0][0];
    quadrilateral[0].y=y_corner[0][0][0];
    quadrilateral[1].x=x_corner[0][1][0];
    quadrilateral[1].y=y_corner[0][1][0];
    quadrilateral[2].x=x_corner[1][1][0];
    quadrilateral[2].y=y_corner[1][1][0];
    quadrilateral[3].x=x_corner[1][0][0];
    quadrilateral[3].y=y_corner[1][0][0];
    fillpoly(4,&(quadrilateral[0].x));
    y_even=TRUE;
    y_out_back=0;
    y_out_front=1;
    for (y=0; y <= max_y; y++)
      {
        y_pixel_floor_back
	 =((int) ((long) y_out_back)
         *((long) (y_corner[1][1][0]-y_corner[1][0][0]))
         /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1)))
         +y_corner[1][0][0];
        y_pixel_floor_front
         =((int) ((long) y_out_front)
         *((long) (y_corner[1][1][0]-y_corner[1][0][0]))
         /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1)))
         +y_corner[1][0][0];
        y_pixel_top_back
         =((int) ((long) y_out_back)
         *((long) (y_corner[1][1][1]-y_corner[1][0][1]))
         /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1)))
         +y_corner[1][0][1];
        y_pixel_top_front
         =((int) ((long) y_out_front)
         *((long) (y_corner[1][1][1]-y_corner[1][0][1]))
         /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1)))
         +y_corner[1][0][1];
        x_pixel_floor_back_left_edge
         =((int) ((long) y_out_back)
         *((long) (x_corner[0][1][0]-x_corner[0][0][0]))
         /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1)))
         +x_corner[0][0][0];
        x_pixel_floor_back_right_edge
         =((int) ((long) y_out_back)
         *((long) (x_corner[1][1][0]-x_corner[1][0][0]))
         /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1)))
         +x_corner[1][0][0];
        x_pixel_top_back_left_edge
         =((int) ((long) y_out_back)
         *((long) (x_corner[0][1][1]-x_corner[0][0][1]))
         /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1)))
         +x_corner[0][0][1];
        x_pixel_top_back_right_edge
         =((int) ((long) y_out_back)
         *((long) (x_corner[1][1][1]-x_corner[1][0][1]))
         /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1)))
         +x_corner[1][0][1];
        x_pixel_floor_front_left_edge
         =((int) ((long) y_out_front)
         *((long) (x_corner[0][1][0]-x_corner[0][0][0]))
         /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1)))
         +x_corner[0][0][0];
        x_pixel_floor_front_right_edge
         =((int) ((long) y_out_front)
         *((long) (x_corner[1][1][0]-x_corner[1][0][0]))
         /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1)))
         +x_corner[1][0][0];
        x_pixel_top_front_left_edge
         =((int) ((long) y_out_front)
         *((long) (x_corner[0][1][1]-x_corner[0][0][1]))
         /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1)))
         +x_corner[0][0][1];
        x_pixel_top_front_right_edge
         =((int) ((long) y_out_front)
         *((long) (x_corner[1][1][1]-x_corner[1][0][1]))
         /((long) ((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1)))
         +x_corner[1][0][1];
        x_even=TRUE;
        x_out_left=0;
        x_out_right=1;
        previous_char=' ';
        for (x=0; x <= max_x; x++)
          {
            current_char=page[x][y];
            if (current_char == 'W')
              {
                if (previous_char != 'W')
                  x_out_left_most=x_out_left;
              }
            else
              {
                if (previous_char == 'W')
                  {
                    x_out_right_most=x_out_left;
                    output_wall(num_columns,x_out_left_most,x_out_right_most,
                     y_pixel_floor_back,y_pixel_floor_front,
                     y_pixel_top_back,y_pixel_top_front,
                     x_pixel_floor_back_left_edge,
                     x_pixel_floor_back_right_edge,
                     x_pixel_top_back_left_edge,
                     x_pixel_top_back_right_edge,
                     x_pixel_floor_front_left_edge,
                     x_pixel_floor_front_right_edge,
                     x_pixel_top_front_left_edge,
                     x_pixel_top_front_right_edge);
                  }
              }
            previous_char=current_char;
            x_out_left=x_out_right;
            x_out_right++;
            if (x_even)
              x_out_right+=ROOM_WIDTH_TO_WALL_WIDTH_RATIO;
            x_even=! x_even;
          }
        x_out_right_most=x_out_left;
        output_wall(num_columns,x_out_left_most,x_out_right_most,
         y_pixel_floor_back,y_pixel_floor_front,
         y_pixel_top_back,y_pixel_top_front,
         x_pixel_floor_back_left_edge,
         x_pixel_floor_back_right_edge,
         x_pixel_top_back_left_edge,
         x_pixel_top_back_right_edge,
         x_pixel_floor_front_left_edge,
         x_pixel_floor_front_right_edge,
         x_pixel_top_front_left_edge,
         x_pixel_top_front_right_edge);
        y_out_back=y_out_front;
        y_out_front++;
        if (y_even)
          y_out_front+=ROOM_WIDTH_TO_WALL_WIDTH_RATIO;
        y_even=! y_even;
      }
    return;
  }

static void draw_line(
  int num_rows,
  int num_columns,
  int x1,
  int y1,
  int x2,
  int y2)
    {
      static int x1_out;
      static int x1_pixel;
      static int x1_pixel_left_edge;
      static int x1_pixel_right_edge;
      static int x2_out;
      static int x2_pixel;
      static int x2_pixel_left_edge;
      static int x2_pixel_right_edge;
      static int y1_out;
      static int y1_pixel;
      static int y2_out;
      static int y2_pixel;

      x1_out=(ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*x1+1;
      y1_out=(ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*y1+1;
      x2_out=(ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*x2+1;
      y2_out=(ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*y2+1;
      x1_pixel_left_edge
       =((int) ((long) y1_out)
       *((long) (x_corner[0][1][1]-x_corner[0][0][1]))
       /((long) (2*((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1))))
       +x_corner[0][0][1];
      x1_pixel_right_edge
       =((int) ((long) y1_out)
       *((long) (x_corner[1][1][1]-x_corner[1][0][1]))
       /((long) (2*((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1))))
       +x_corner[1][0][1];
      x1_pixel
       =((int) (((long) x1_out)
       *((long) (x1_pixel_right_edge
       -x1_pixel_left_edge))
       /((long) (2*((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_columns+1)))))
       +x1_pixel_left_edge;
      y1_pixel
       =((int) ((long) y1_out)
       *((long) (y_corner[1][1][1]-y_corner[1][0][1]))
       /((long) (2*((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1))))
       +y_corner[1][0][1];
      x2_pixel_left_edge
       =((int) ((long) y2_out)
       *((long) (x_corner[0][1][1]-x_corner[0][0][1]))
       /((long) (2*((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1))))
       +x_corner[0][0][1];
      x2_pixel_right_edge
       =((int) ((long) y2_out)
       *((long) (x_corner[1][1][1]-x_corner[1][0][1]))
       /((long) (2*((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1))))
       +x_corner[1][0][1];
      x2_pixel
       =((int) (((long) x2_out)
       *((long) (x2_pixel_right_edge
       -x2_pixel_left_edge))
       /((long) (2*((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_columns+1)))))
       +x2_pixel_left_edge;
      y2_pixel
       =((int) ((long) y2_out)
       *((long) (y_corner[1][1][1]-y_corner[1][0][1]))
       /((long) (2*((ROOM_WIDTH_TO_WALL_WIDTH_RATIO+2)*num_rows+1))))
       +y_corner[1][0][1];
      moveto(x1_pixel,y1_pixel);
      lineto(x2_pixel,y2_pixel);
      return;
    }

static void display_solution(
  int  num_columns,
  int  num_rows,
  int  max_x,
  int  max_y,
  char **page)
    {
      static int delta_index;
      static int path_found;
      static int x;
      static int x_next;
      static int x_previous;
      static int y;
      static int y_next;
      static int y_previous;

      setlinestyle(SOLID_LINE,0xffff,THICK_WIDTH);
      setcolor(SOLUTION_COLOR);
      x_previous=1;
      y_previous=-1;
      x=1;
      y=0;
      do
        {
          path_found=FALSE;
          for (delta_index=0; (! path_found); delta_index++)
            {
              x_next=x+delta_x[delta_index][0];
              y_next=y+delta_y[delta_index][0];
              if ((x_next != x_previous) || (y_next != y_previous))
                path_found=(page[x_next][y_next] == 'S');
            }
          draw_line(num_rows,num_columns,x,y,x_next,y_next);
          x_previous=x;
          y_previous=y;
          x=x_next;
          y=y_next;
        }
      while ((x != max_x-1) || (y != max_y));
      return;
    }

static void let_user_try_to_solve(
  int  *key_pressed,
  int  num_rows,
  int  num_columns,
  int  max_x,
  int  max_y,
  char **computer_page,
  char **user_page)
    {
      static int delta_index_1;
      static int frequency;
      static int passage_found;
      static int x;
      static int x_next;
      static int y;
      static int y_next;

      setlinestyle(SOLID_LINE,0xffff,NORM_WIDTH);
      for (x=0; x <= max_x; x++)
        for (y=0; y <= max_y; y++)
          if (computer_page[x][y] == 'W')
            user_page[x][y]='W';
          else
            user_page[x][y]=' ';
      x=1;
      y=1;
      user_page[x][y]='S';
      setcolor(ADVANCE_COLOR);
      draw_line(num_rows,num_columns,1,0,x,y);
      do
        {
          do
            {
              passage_found=TRUE;
              *key_pressed=getch();
              if ((*key_pressed != (int) 'Q')
              &&  (*key_pressed != (int) 'q')
              &&  (*key_pressed != (int) 'S')
              &&  (*key_pressed != (int) 's'))
                {
                  if (*key_pressed == 0)
                    {
                      *key_pressed=getch();
                      switch (*key_pressed)
                        {
                          case 72:
                             delta_index_1=3;
                             break;
                          case 77:
                             delta_index_1=2;
                             break;
                          case 80:
                             delta_index_1=1;
                             break;
                          case 75:
                             delta_index_1=0;
                             break;
                          default:
                            {
                              passage_found=FALSE;
                              sound(120);
                              delay(278);
                              nosound();
                              *key_pressed=(int) ' ';
                              break;
                            }
                        }
                    }
                  else
                    {
                      switch (*key_pressed)
                        {
                          case 56:
                            delta_index_1=3;
                            break;
                          case 54:
                            delta_index_1=2;
                            break;
                          case 50:
                            delta_index_1=1;
                            break;
                          case 52:
                            delta_index_1=0;
                            break;
                          case 8:
                            delta_index_1=0;
                            break;
                          default:
                            passage_found=FALSE;
                            break;
                        }
                    }
                  if (passage_found)
                    {
                      x_next=x+delta_x[delta_index_1][0];
                      if (x_next <= 0)
                        passage_found=FALSE;
                      else
                        if (x_next >= max_x)
                          passage_found=FALSE;
                        else
                          {
                            y_next=y+delta_y[delta_index_1][0];
                            if (y_next <= 0)
                              passage_found=FALSE;
                            else
                              if (y_next > max_y)
                                passage_found=FALSE;
                              else
                                if (user_page[x_next][y_next] == 'W')
                                  passage_found=FALSE;
                          }
                    }
                  if (! passage_found)
                    {
                      passage_found=FALSE;
                      sound(120);
                      delay(278);
                      nosound();
                    }
                }
            }
          while ((! passage_found)
          &&     (*key_pressed != (int) 'Q')
          &&     (*key_pressed != (int) 'q')
          &&     (*key_pressed != (int) 'S')
          &&     (*key_pressed != (int) 's'));
          if ((*key_pressed != (int) 'Q')
          &&  (*key_pressed != (int) 'q')
          &&  (*key_pressed != (int) 'S')
          &&  (*key_pressed != (int) 's'))
            {
              x_next+=delta_x[delta_index_1][0];
              y_next+=delta_y[delta_index_1][0];
              if (y_next < max_y)
                {
                  if (user_page[x_next][y_next] == 'S')
                    {
                      setcolor(BACKOUT_COLOR);
                      user_page[x][y]=' ';
                    }
                  else
                    {
                      setcolor(ADVANCE_COLOR);
                      user_page[x_next][y_next]='S';
                    }
                  draw_line(num_rows,num_columns,x,y,x_next,y_next);
                }
              else
                {
                  setcolor(ADVANCE_COLOR);
                  draw_line(num_rows,num_columns,x,y,max_x-1,max_y);
                }
              x=x_next;
              y=y_next;
            }
        }
      while ((y_next < max_y)
      &&     (*key_pressed != (int) 'Q')
      &&     (*key_pressed != (int) 'q')
      &&     (*key_pressed != (int) 'S')
      &&     (*key_pressed != (int) 's'));
      setcolor(0);
      outtextxy(NUM_X_PIXELS/2,NUM_Y_PIXELS-1,
       "Arrows - Move    S - Solve    Q - Quit");
      if    ((*key_pressed != (int) 'Q')
      &&     (*key_pressed != (int) 'q')
      &&     (*key_pressed != (int) 'S')
      &&     (*key_pressed != (int) 's'))
        {
          setcolor(NUM_COLORS-4);
          outtextxy(NUM_X_PIXELS/2,NUM_Y_PIXELS-1,"Congratulations!");
          frequency=10;
          for (delta_index_1=1; delta_index_1 <= 100;
           delta_index_1++)
            {
              sound(frequency);
              delay(56);
              nosound();
              frequency+=10;
            };
          setcolor(0);
          outtextxy(NUM_X_PIXELS/2,NUM_Y_PIXELS-1,"Congratulations!");
          setcolor(NUM_COLORS-4);
          outtextxy(NUM_X_PIXELS/2,NUM_Y_PIXELS-1,
           "S - Solve    Other - Restart program");
          while (kbhit())
            {
              *key_pressed=getch();
              if (*key_pressed == 0)
                {
                  *key_pressed=getch();
                  *key_pressed=(int) ' ';
                }
            }
          *key_pressed=getch();
          if (*key_pressed == 0)
            {
              *key_pressed=getch();
              *key_pressed=(int) ' ';
            }
          setcolor(0);
          outtextxy(NUM_X_PIXELS/2,NUM_Y_PIXELS-1,
           "S - Solve    Other - Restart program");
        }
      return;
    }
