   /*SNAKE & LADDER GAME */
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void main ()
{
 int gd = DETECT,gm,i,j,a,h,c,d=0,e=9,z=0,y=0,g,p=9,m=0,n=0,o,b=0,l;
 char r,w;
 initgraph (&gd,&gm,"c:\\tc\\bgi");
 setbkcolor (BLUE);
 settextstyle (3,HORIZ_DIR,0.5);
 outtextxy (230,210,"WEL-COME");
 for (g=1;g<=5;g++)
 {
 for (i=1;i<=13;i++)
 setbkcolor (i);
 }
 cleardevice ();
 setbkcolor (8);
 j=1;
 for (i=1;i<=14;i++)
 {
 setbkcolor (j);
 if (j>8)
 j=1;
 cleardevice ();
  settextstyle (j,HORIZ_DIR,2);
 outtextxy (300-i*10,200-i*10,"SNAKE & LADDERS");
 delay (500);
 j++;
 }
  sound (600);
 delay (100);
 nosound ();
 delay (1000);
 ajit:
 setbkcolor (1);
 cleardevice ();
 for (i=1;i<=13;i++)
 {

 setbkcolor (i) ;
 settextstyle (3,HORIZ_DIR,1);
 outtextxy (320,230,"1.WANT TO PLAY");
 outtextxy (320,250,"2.GAME INSTRUCTION");
 outtextxy (320,270,"3.QUIT");
 outtextxy (320,290,"press the option");
 delay (500);
 }
 scanf ("%d",&i);
 if (i==1)
 {
  cleardevice ();
  setbkcolor (5);
  settextstyle (10,HORIZ_DIR,1);
  outtextxy (250,200,"BEST OF LUCK  !");
  delay (2000);
  cleardevice ();
  setbkcolor (4);
  //printf ("enter the first player name");
//  gets(w);
  //printf ("enter the second player name");
  //gets(r);
  cleardevice ();
 setbkcolor (BLUE);
 gotoxy (270,220);
 settextstyle (10,HORIZ_DIR,1);
 outtextxy (200,20,"SNAKE & LADDERS");
 delay (1000);
 settextstyle (7,HORIZ_DIR,1);
 outtextxy (270,280,"presented by :-");
 printf ("\n");
 outtextxy (390,340," AJIT KUMAR BEHERA");
 printf ("\n");
 outtextxy (390,360,"CLASS-IX");
 delay (5000);
 j=1;
 for (i=0;i<=640;i++)
 {
  if (j>=14)
  j=1;
  setfillstyle (SOLID_FILL,j);
  bar (i,0,640,480);
  rectangle (i,0,640,480);
 delay (0);
 j++;
 }
 cleardevice ();
 rectangle (20,0,640,420);
 for (i=1;i<=9;i++)
 {
 line (20,42*i,640,42*i);
 delay (500);
 }
 for (i=1;i<=9;i++)
 {
 line (64*i,0,64*i,420);
 delay (500);
 }
 outtextxy (25,15,"100" );
 outtextxy (89,15,"99");
 outtextxy (153,15,"98");
 outtextxy (217,15,"97");
 outtextxy (281,15,"96");
 outtextxy (345,15,"95");
 outtextxy (409,15,"94");
 outtextxy (473,15,"93");
 outtextxy (531,15,"92");
 outtextxy (601,15,"91");
 {
  i=58;
 outtextxy (25,i,"90");
 outtextxy (89,i,"89");
 outtextxy (153,i,"88");
 outtextxy (217,i,"87");
 outtextxy (281,i,"86");
 outtextxy (345,i,"85");
 outtextxy (409,i,"84");
 outtextxy (473,i,"83");
 outtextxy (531,i,"82");
 outtextxy (601,i,"81");
 delay (500);
 }
 i=101;
 {
 outtextxy (25,i,"80" );
 outtextxy (89,i,"79");
 outtextxy (153,i,"78");
 outtextxy (217,i,"77");
 outtextxy (281,i,"76");
 outtextxy (345,i,"75");
 outtextxy (409,i,"74");
 outtextxy (473,i,"73");
 outtextxy (531,i,"72");
 outtextxy (601,i,"71");
 delay (500);
 }
 i=144;
 {
 outtextxy (25,i,"70" );
 outtextxy (89,i,"69");
 outtextxy (153,i,"68");
 outtextxy (217,i,"67");
 outtextxy (281,i,"66");
 outtextxy (345,i,"65");
 outtextxy (409,i,"64");
 outtextxy (473,i,"63");
 outtextxy (531,i,"62");
 outtextxy (601,i,"61");
 delay (500);
 }
 i=187;
 {
 outtextxy (25,i,"60" );
 outtextxy (89,i,"59");
 outtextxy (153,i,"58");
 outtextxy (217,i,"57");
 outtextxy (281,i,"56");
 outtextxy (345,i,"55");
 outtextxy (409,i,"54");
 outtextxy (473,i,"53");
 outtextxy (531,i,"52");
 outtextxy (601,i,"51");
 delay (500);
 }
 i=230;
 {
 outtextxy (25,i,"50" );
 outtextxy (89,i,"49");
 outtextxy (153,i,"48");
 outtextxy (217,i,"47");
 outtextxy (281,i,"46");
 outtextxy (345,i,"45");
 outtextxy (409,i,"44");
 outtextxy (473,i,"43");
 outtextxy (531,i,"42");
 outtextxy (601,i,"41");
 delay (500);
 }
 i=273;
 {
 outtextxy (25,i,"40");
 outtextxy (89,i,"39");
 outtextxy (153,i,"38");
 outtextxy (217,i,"37");
 outtextxy (281,i,"36");
 outtextxy (345,i,"35");
 outtextxy (409,i,"34");
 outtextxy (473,i,"33");
 outtextxy (531,i,"32");
 outtextxy (601,i,"31");
 delay (500);
 }
 i=316;
 {
 outtextxy (25,i,"30" );
 outtextxy (89,i,"29");
 outtextxy (153,i,"28");
 outtextxy (217,i,"27");
 outtextxy (281,i,"26");
 outtextxy (345,i,"25");
 outtextxy (409,i,"24");
 outtextxy (473,i,"23");
 outtextxy (531,i,"22");
 outtextxy (601,i,"21");
 delay (500);
 }
 i=359;
 {
 outtextxy (25,i,"20" );
 outtextxy (89,i,"19");
 outtextxy (153,i,"18");
 outtextxy (217,i,"17");
 outtextxy (281,i,"16");
 outtextxy (345,i,"15");
 outtextxy (409,i,"14");
 outtextxy (473,i,"13");
 outtextxy (531,i,"12");
 outtextxy (601,i,"11");
 delay (500);
 }
 i=400;
 {
 outtextxy (25,i,"10" );
 outtextxy (89,i,"9");
 outtextxy (153,i,"8");
 outtextxy (217,i,"7");
 outtextxy (281,i,"6");
 outtextxy (345,i,"5");
 outtextxy (409,i,"4");
 outtextxy (473,i,"3");
 outtextxy (531,i,"2");
 outtextxy (601,i,"1");
 delay (500);
 }
 rectangle (0,430,120,460);
 delay (500);
 setfillstyle (SOLID_FILL,6);
 bar (5,440,48,455);
 rectangle (5,440,48,455);
 setfillstyle (SOLID_FILL,14);
 bar (53,440,106,455);
 rectangle (53,440,106,455);
 outtextxy (30,435,"a");
 outtextxy (70,435,"b");
 delay (800);
 setfillstyle (SOLID_FILL,BLUE);
 bar (5,440,106,455);
 rectangle (5,440,106,455);
 for (i=1;i<=100;i++)
 {
  for (g=1;g<=2;g++)
   {
    if (g==1)
     {
      if (i!=1)
      {
      setfillstyle (SOLID_FILL,BLUE);
      bar (50+64*(d)-1,42*e+10,64+64*(d)-1,42*e+20);
      rectangle (50+64*(d)-1,42*e+10,64+64*(d)-1,42*e+20);
      }
      gotoxy (1,1);
      scanf ("%d",&a);
      if (a<=6 && a>0)
      {
      b=z+a;
      z=b;
      c=1;
      while (b>10)
       {
	c++;
	b=b-10;
       }
      d=10-b;
      e=10-c;
      setfillstyle (SOLID_FILL,6);
      bar (50+64*(d)-1,42*e+10,64+64*(d)-1,42*e+20);
      rectangle (50+64*(d)-1,42*e+10,64+64*(d)-1,42*e+20);
      switch (z)
      {
      case 60 :
		z=30;
		b=30;
		setfillstyle (SOLID_FILL,4);
		bar (20,42*4,64,42*5);
		rectangle (20,42*4,64,42*5);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (20,42*4,64,42*5);
		rectangle (20,42*4,64,42*5);
		delay (10);
		setfillstyle (SOLID_FILL,4);
		bar (20,42*7,64,42*8);
		rectangle (20,42*7,64,42*8);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (20,42*7,64,42*8);
		rectangle (20,42*7,64,42*8);
		delay (10);
		outtextxy (40,42*7+10,"30");
		setfillstyle (SOLID_FILL,1);
      bar (50+64*(d)-1,42*e+10,64+64*(d)-1,42*e+20);
      rectangle (50+64*(d)-1,42*e+10,64+64*(d)-1,42*e+20);

		setfillstyle (SOLID_FILL,6);
		bar (50,42*7,64,42*7+10);
		rectangle (50,42*7,64,42*7+10);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (50,42*7,64,42*7+10);
		rectangle (50,42*7,64,42*7+10);

		break;
      case 94 :
		z=1;
		b=1;
		setfillstyle (SOLID_FILL,4);
		bar (384,0,448,42);
		rectangle (384,0,448,42);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (384,0,448,42);
		rectangle (384,0,448,42);
		delay (10);
		setfillstyle (SOLID_FILL,4);
		bar (576,378,640,420);
		rectangle (576,378,640,420);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (576,378,640,420);
		rectangle (576,378,640,420);
		delay (10);
		outtextxy (596,388,"1");
		 setfillstyle (SOLID_FILL,1);
      bar (50+64*(d)-1,42*e+10,64+64*(d)-1,42*e+20);
      rectangle (50+64*(d)-1,42*e+10,64+64*(d)-1,42*e+20);

		setfillstyle (SOLID_FILL,6);
		bar (626,378,640,388);
		rectangle (626,378,640,388);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (626,378,640,388);
		rectangle (626,378,640,388);

		break;
      case 82 :
		z=17;
		b=17;
		setfillstyle (SOLID_FILL,4);
		bar (512,42,576,84);
		rectangle (512,42,576,84);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (512,42,576,84);
		rectangle (512,42,576,84);
		delay (10);
		setfillstyle (SOLID_FILL,4);
		bar (192,336,256,378);
		rectangle (192,336,256,378);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (192,336,256,378);
		rectangle (192,336,256,378);
		delay (10);
		outtextxy (212,346,"17");
		 setfillstyle (SOLID_FILL,1);
      bar (50+64*(d)-1,42*e+10,64+64*(d)-1,42*e+20);
      rectangle (50+64*(d)-1,42*e+10,64+64*(d)-1,42*e+20);

		setfillstyle (SOLID_FILL,6);
		bar (242,336,256,346);
		rectangle (242,336,256,346);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (242,336,256,346);
		rectangle (242,336,256,346);
		break;
      case 36 :
		z=7;
		b=7;
		setfillstyle (SOLID_FILL,4);
		bar (256,252,320,294);
		rectangle (256,252,320,294);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (256,252,320,294);
		rectangle (256,252,320,294);
		delay (10);
		setfillstyle (SOLID_FILL,4);
		bar (320,378,384,420);
		rectangle (320,378,384,420);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (320,378,384,420);
		rectangle (320,378,384,420);
		delay (10);
		outtextxy (340,388,"7");
		 setfillstyle (SOLID_FILL,1);
      bar (50+64*(d)-1,42*e+10,64+64*(d)-1,42*e+20);
      rectangle (50+64*(d)-1,42*e+10,64+64*(d)-1,42*e+20);

		setfillstyle (SOLID_FILL,6);
		bar (370,378,384,388);
		rectangle (370,378,384,388);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (370,378,384,388);
		rectangle (370,378,384,388);
		break;
      case 99 :
		z=3;
		b=3;
		setfillstyle (SOLID_FILL,4);
		bar (64,0,128,42);
		rectangle (64,0,128,42);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (64,0,128,42);
		rectangle (64,0,128,42);
		delay (10);
		setfillstyle (SOLID_FILL,4);
		bar (448,378,512,420);
		rectangle (448,378,512,420);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (448,378,512,420);
		rectangle (448,378,512,420);
		delay (10);
		outtextxy (468,388,"3");
		 setfillstyle (SOLID_FILL,1);
      bar (50+64*(d),42*e,64+64*(d),42*e+10);
      rectangle (50+64*(d),42*e,64+64*(d),42*e+10);

		setfillstyle (SOLID_FILL,6);
		bar (498,378,512,388);
		rectangle (498,378,512,388);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (498,378,512,388);
		rectangle (498,378,512,388);
		break;
      case 97 :
		z=32;
		b=32;
		setfillstyle (SOLID_FILL,4);
		bar (192,0,256,42);
		rectangle (192,0,256,42);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (192,0,256,42);
		rectangle (192,0,256,42);
		delay (10);
		setfillstyle (SOLID_FILL,4);
		bar (512,252,576,294);
		rectangle (512,252,576,294);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (512,252,576,294);
		rectangle (512,252,576,294);
		delay (10);
		outtextxy (532,262,"32");
		 setfillstyle (SOLID_FILL,1);
      bar (50+64*(d),42*e,64+64*(d),42*e+10);
      rectangle (50+64*(d),42*e,64+64*(d),42*e+10);

		setfillstyle (SOLID_FILL,6);
		bar (562,252,576,262);
		rectangle (562,252,576,262);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (562,252,576,262);
		rectangle (562,252,576,262);
		break;
      case 27 :
		z=98;
		b=98;
		setfillstyle (SOLID_FILL,2);
		bar (192,294,256,336);
		rectangle (192,294,256,336);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (192,294,256,336);
		rectangle (192,294,256,336);
		delay (10);
		setfillstyle (SOLID_FILL,2);
		bar (128,0,192,42);
		rectangle (128,0,192,42);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (128,0,192,42);
		rectangle (128,0,192,42);
		delay (10);
		outtextxy (148,10,"98");
		 setfillstyle (SOLID_FILL,1);
      bar (50+64*(d),42*e,64+64*(d),42*e+10);
      rectangle (50+64*(d),42*e,64+64*(d),42*e+10);

		setfillstyle (SOLID_FILL,6);
		bar (178,0,192,10);
		rectangle (178,0,192,10);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (178,0,192,10);
		rectangle (178,0,192,10);
		break;
      case 43 :
		z=66;
		b=66;
		setfillstyle (SOLID_FILL,2);
		bar (448,210,512,252);
		rectangle (448,210,512,252);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (448,210,512,252);
		rectangle (448,210,512,252);
		delay (10);
		setfillstyle (SOLID_FILL,2);
		bar (256,126,320,168);
		rectangle (256,126,320,168);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (256,126,320,168);
		rectangle (256,126,320,168);
		delay (10);
		outtextxy (276,136,"66");
		 setfillstyle (SOLID_FILL,1);
      bar (50+64*(d),42*e,64+64*(d),42*e+10);
      rectangle (50+64*(d),42*e,64+64*(d),42*e+10);

		setfillstyle (SOLID_FILL,6);
		bar (306,126,320,136);
		rectangle (306,126,320,136);
		delay (1500);

		setfillstyle (SOLID_FILL,1);
		bar (306,126,320,136);
		rectangle (306,126,320,136);
		break;
      case 7 :
		z=77;
		b=77;
		setfillstyle (SOLID_FILL,2);
		bar (192,378,168,420);
		rectangle (192,378,168,420);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (192,378,168,420);
		rectangle (192,378,168,420);
		delay (10);
		setfillstyle (SOLID_FILL,2);
		bar (192,84,256,126);
		rectangle (192,84,256,126);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (192,84,256,126);
		rectangle (192,84,256,126);
		delay (10);
		outtextxy (212,94,"77");
		 setfillstyle (SOLID_FILL,1);
      bar (50+64*(d),42*e,64+64*(d),42*e+10);
      rectangle (50+64*(d),42*e,64+64*(d),42*e+10);

		setfillstyle (SOLID_FILL,6);
		bar (242,84,256,94);
		rectangle (242,84,256,94);
		delay (2000);

		setfillstyle (SOLID_FILL,1);
		bar (242,84,256,94);
		rectangle (242,84,256,94);

		break;
      case 33 :
		z=85;
		b=85;
		setfillstyle (SOLID_FILL,2);
		bar (448,252,512,294);
		rectangle (448,252,512,294);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (448,252,512,294);
		rectangle (448,252,512,294);
		delay (10);
		setfillstyle (SOLID_FILL,2);
		bar (320,42,384,84);
		rectangle (320,42,384,84);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (320,42,384,84);
		rectangle (320,42,384,84);
		delay (10);
		outtextxy (340,52,"85");
		 setfillstyle (SOLID_FILL,1);
      bar (50+64*(d),42*e,64+64*(d),42*e+10);
      rectangle (50+64*(d),42*e,64+64*(d),42*e+10);

		setfillstyle (SOLID_FILL,6);
		bar (370,42,384,52);
		rectangle (370,42,384,52);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (370,42,384,52);
		rectangle (370,42,384,52);

		break;
      case 49 :
		z=93;
		b=93;
		setfillstyle (SOLID_FILL,2);
		bar (64,210,128,252);
		rectangle (64,210,128,252);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (64,210,128,252);
		rectangle (64,210,128,252);
		delay (10);
		setfillstyle (SOLID_FILL,2);
		bar (448,0,512,42);
		rectangle (448,0,512,42);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (448,0,512,42);
		rectangle (448,0,512,42);
		delay (10);
		outtextxy (468,522,"93");
		 setfillstyle (SOLID_FILL,1);
      bar (50+64*(d),42*e,64+64*(d),42*e+10);
      rectangle (50+64*(d),42*e,64+64*(d),42*e+10);

		setfillstyle (SOLID_FILL,6);
		bar (498,0,512,10);
		rectangle (498,0,512,10);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (498,0,512,10);
		rectangle (498,0,512,10);

		break;
      case 14 :
		z=61;
		b=61;
		setfillstyle (SOLID_FILL,2);
		bar (384,336,448,378);
		rectangle (384,336,448,378);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (384,336,448,378);
		rectangle (384,336,448,378);
		delay (10);
		setfillstyle (SOLID_FILL,2);
		bar (576,126,640,168);
		rectangle (576,126,640,168);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (576,126,640,168);
		rectangle (576,126,640,168);
		delay (10);
		outtextxy (596,132,"61");
		 setfillstyle (SOLID_FILL,1);
      bar (50+64*(d),42*e,64+64*(d),42*e+10);
      rectangle (50+64*(d),42*e,64+64*(d),42*e+10);

		setfillstyle (SOLID_FILL,6);
		bar (626,126,640,136);
		rectangle (626,126,640,136);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (626,126,640,136);
		rectangle (626,126,640,136);
		break;
      case 100 :
		cleardevice ();
		cleardevice ();
		setbkcolor (5);
		settextstyle (8,HORIZ_DIR,1);
		outtextxy (320,230,"PLAYER A WIN ");
		outtextxy (320,300,"CONGRATULATION!");
		exit (0);
		break;
      default :
      printf ("");
      }
     }
    }
     if (g==2)
     {
      if (i!=1)
      {
      setfillstyle (SOLID_FILL,BLUE);
      bar (50+64*n,42*p+10,64+64*n,42*p+20);
      rectangle (50+64*n,42*p+10,64+64*n,42*p+20);
      }
      scanf ("%d",&h);
      if (h<=6 && h>0)
      {
      m=y+h;
      y=m;
      o=1;
      while (m>10)
      {
       o++;
       m=m-10;
      }
      n=10-m;
      p=10-o;
      setfillstyle (SOLID_FILL,14);
      bar (50+64*n,42*p+10,64+64*n,42*p+20);
      rectangle (50+64*n,42*p+10,64+64*n,42*p+20);
     switch (y)
     {
      case 60 :
		y=30;
		m=30;
		setfillstyle (SOLID_FILL,4);
		bar (20,42*4,64,42*5);
		rectangle (20,42*4,64,42*5);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (20,42*4,64,42*5);
		rectangle (20,42*4,64,42*5);
		delay (10);
		setfillstyle (SOLID_FILL,4);
		bar (20,42*7,64,42*8);
		rectangle (20,42*7,64,42*8);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (20,42*7,64,42*8);
		rectangle (20,42*7,64,42*8);
		delay (10);
		outtextxy (40,42*7+10,"30");
		setfillstyle (SOLID_FILL,1);
      bar (50+64*n,42*p+10,64+64*n,42*p+20);
      rectangle (50+64*n,42*p+10,64+64*n,42*p+20);
		setfillstyle (SOLID_FILL,14);
		bar (50,42*7+10,64,42*7+20);
		rectangle (50,42*7+10,64,42*7+20);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (50,42*7+10,64,42*7+20);
		rectangle (50,42*7+10,64,42*7+20);
		break;
      case 94 :
		y=1;
		m=1;
		setfillstyle (SOLID_FILL,4);
		bar (384,0,448,42);
		rectangle (384,0,448,42);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (384,0,448,42);
		rectangle (384,0,448,42);
		delay (10);
		setfillstyle (SOLID_FILL,4);
		bar (576,378,640,420);
		rectangle (576,378,640,420);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (576,378,640,420);
		rectangle (576,378,640,420);
		delay (10);
		outtextxy (596,388,"1");
		setfillstyle (SOLID_FILL,1);
      bar (50+64*n,42*p+10,64+64*n,42*p+20);
      rectangle (50+64*n,42*p+10,64+64*n,42*p+20);
		setfillstyle (SOLID_FILL,14);
		bar (626,388,640,398);
		rectangle (626,388,640,398);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (626,388,640,398);
		rectangle (626,388,640,398);

		break;
      case 82 :
		y=17;
		m=17;
		setfillstyle (SOLID_FILL,4);
		bar (512,42,576,84);
		rectangle (512,42,576,84);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (512,42,576,84);
		rectangle (512,42,576,84);
		delay (10);
		setfillstyle (SOLID_FILL,4);
		bar (192,336,256,378);
		rectangle (192,336,256,378);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (192,336,256,378);
		rectangle (192,336,256,378);
		delay (10);
		outtextxy (212,346,"17");
		setfillstyle (SOLID_FILL,1);
      bar (50+64*n,42*p+10,64+64*n,42*p+20);
      rectangle (50+64*n,42*p+10,64+64*n,42*p+20);
		setfillstyle (SOLID_FILL,14);
		bar (242,346,256,356);
		rectangle (242,346,256,356);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (242,346,256,356);
		rectangle (242,346,256,356);

		break;
      case 36 :
		y=7;
		m=7;
		setfillstyle (SOLID_FILL,4);
		bar (256,252,320,294);
		rectangle (256,252,320,294);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (256,252,320,294);
		rectangle (256,252,320,294);
		delay (10);
		setfillstyle (SOLID_FILL,4);
		bar (320,378,384,420);
		rectangle (320,378,384,420);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (320,378,384,420);
		rectangle (320,378,384,420);
		delay (10);
		outtextxy (340,388,"7");
		setfillstyle (SOLID_FILL,1);
      bar (50+64*n,42*p+10,64+64*n,42*p+20);
      rectangle (50+64*n,42*p+10,64+64*n,42*p+20);
		setfillstyle (SOLID_FILL,14);
		bar (370,388,384,398);
		rectangle (370,388,384,398);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (370,388,384,398);
		rectangle (370,388,384,398);

		break;
      case 99 :
		y=3;
		m=3;
		setfillstyle (SOLID_FILL,4);
		bar (64,0,128,42);
		rectangle (64,0,128,42);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (64,0,128,42);
		rectangle (64,0,128,42);
		delay (10);
		setfillstyle (SOLID_FILL,4);
		bar (448,378,512,420);
		rectangle (448,378,512,420);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (448,378,512,420);
		rectangle (448,378,512,420);
		delay (10);
		outtextxy (468,388,"3");
		setfillstyle (SOLID_FILL,1);
      bar (50+64*n,42*p+10,64+64*n,42*p+20);
      rectangle (50+64*n,42*p+10,64+64*n,42*p+20);
		setfillstyle (SOLID_FILL,14);
		bar (498,388,512,398);
		rectangle (498,388,512,398);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (498,388,512,398);
		rectangle (498,388,512,398);
		break;
      case 97 :
		y=32;
		m=32;
		setfillstyle (SOLID_FILL,4);
		bar (192,0,256,42);
		rectangle (192,0,256,42);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (192,0,256,42);
		rectangle (192,0,256,42);
		delay (10);
		setfillstyle (SOLID_FILL,4);
		bar (512,252,576,294);
		rectangle (512,252,576,294);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (512,252,576,294);
		rectangle (512,252,576,294);
		delay (10);
		outtextxy (532,262,"32");
		setfillstyle (SOLID_FILL,1);
      bar (50+64*n,42*p+10,64+64*n,42*p+20);
      rectangle (50+64*n,42*p+10,64+64*n,42*p+20);
		setfillstyle (SOLID_FILL,14);
		bar (562,262,576,272);
		rectangle (562,262,576,272);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (562,262,576,272);
		rectangle (562,262,576,272);
		break;
      case 27 :
		y=98;
		m=98;
		setfillstyle (SOLID_FILL,2);
		bar (192,294,256,336);
		rectangle (192,294,256,336);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (192,294,256,336);
		rectangle (192,294,256,336);
		delay (10);
		setfillstyle (SOLID_FILL,2);
		bar (128,0,192,42);
		rectangle (128,0,192,42);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (128,0,192,42);
		rectangle (128,0,192,42);
		delay (10);
		outtextxy (148,10,"98");
		setfillstyle (SOLID_FILL,1);
      bar (50+64*n,42*p+10,64+64*n,42*p+20);
      rectangle (50+64*n,42*p+10,64+64*n,42*p+20);
		setfillstyle (SOLID_FILL,14);
		bar (178,10,192,20);
		rectangle (178,10,192,20);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (178,10,192,20);
		rectangle (178,10,192,20);
		break;
      case 43 :
		y=66;
		m=66;
		setfillstyle (SOLID_FILL,2);
		bar (448,210,512,252);
		rectangle (448,210,512,252);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (448,210,512,252);
		rectangle (448,210,512,252);
		delay (10);
		setfillstyle (SOLID_FILL,2);
		bar (256,126,320,168);
		rectangle (256,126,320,168);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (256,126,320,168);
		rectangle (256,126,320,168);
		delay (10);
		outtextxy (276,136,"66");
		setfillstyle (SOLID_FILL,1);
      bar (50+64*n,42*p+10,64+64*n,42*p+20);
      rectangle (50+64*n,42*p+10,64+64*n,42*p+20);
		setfillstyle (SOLID_FILL,14);
		bar (306,136,320,146);
		rectangle (306,136,320,146);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (306,136,320,146);
		rectangle (306,136,320,146);
		break;
      case 7 :
		y=77;
		m=77;
		setfillstyle (SOLID_FILL,2);
		bar (192,378,168,420);
		rectangle (192,378,168,420);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (192,378,168,420);
		rectangle (192,378,168,420);
		delay (10);
		setfillstyle (SOLID_FILL,2);
		bar (192,84,256,126);
		rectangle (192,84,256,126);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (192,84,256,126);
		rectangle (192,84,256,126);
		delay (10);
		outtextxy (212,94,"77");
		setfillstyle (SOLID_FILL,1);
      bar (50+64*n,42*p+10,64+64*n,42*p+20);
      rectangle (50+64*n,42*p+10,64+64*n,42*p+20);
		setfillstyle (SOLID_FILL,14);
		bar (242,94,256,104);
		rectangle (242,94,256,104);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (242,94,256,104);
		rectangle (242,94,256,104);
		break;
      case 33 :
		y=85;
		m=85;
		setfillstyle (SOLID_FILL,2);
		bar (448,252,512,294);
		rectangle (448,252,512,294);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (448,252,512,294);
		rectangle (448,252,512,294);
		delay (10);
		setfillstyle (SOLID_FILL,2);
		bar (320,42,384,84);
		rectangle (320,42,384,84);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (320,42,384,84);
		rectangle (320,42,384,84);
		delay (10);
		outtextxy (340,52,"85");
		setfillstyle (SOLID_FILL,1);
      bar (50+64*n,42*p+10,64+64*n,42*p+20);
      rectangle (50+64*n,42*p+10,64+64*n,42*p+20);
		setfillstyle (SOLID_FILL,14);
		bar (370,452,384,62);
		rectangle (370,52,384,62);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (370,452,384,62);
		rectangle (370,52,384,62);
		break;
      case 49 :
		y=93;
		m=93;
		setfillstyle (SOLID_FILL,2);
		bar (64,210,128,252);
		rectangle (64,210,128,252);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (64,210,128,252);
		rectangle (64,210,128,252);
		delay (10);
		setfillstyle (SOLID_FILL,2);
		bar (448,0,512,42);
		rectangle (448,0,512,42);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (448,0,512,42);
		rectangle (448,0,512,42);
		delay (10);
		outtextxy (468,10,"93");
		setfillstyle (SOLID_FILL,1);
      bar (50+64*n,42*p+10,64+64*n,42*p+20);
      rectangle (50+64*n,42*p+10,64+64*n,42*p+20);
		setfillstyle (SOLID_FILL,14);
		bar (498,10,512,20);
		rectangle (498,10,512,20);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (498,10,512,20);
		rectangle (498,10,512,20);
		break;
      case 14 :
		y=61;
		m=61;
		setfillstyle (SOLID_FILL,2);
		bar (384,336,448,378);
		rectangle (384,336,448,378);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (384,336,448,378);
		rectangle (384,336,448,378);
		delay (10);
		setfillstyle (SOLID_FILL,2);
		bar (576,126,640,168);
		rectangle (576,126,640,168);
		delay (80);
		setfillstyle (SOLID_FILL,BLUE);
		bar (576,126,640,168);
		rectangle (576,126,640,168);
		delay (80);
		outtextxy (596,136,"61");
		setfillstyle (SOLID_FILL,1);
      bar (50+64*n,42*p+10,64+64*n,42*p+20);
      rectangle (50+64*n,42*p+10,64+64*n,42*p+20);
		setfillstyle (SOLID_FILL,14);
		bar (626,136,640,146);
		rectangle (626,136,640,146);
		delay (1500);
		setfillstyle (SOLID_FILL,1);
		bar (626,136,640,146);
		rectangle (626,136,640,146);
		break;
      case 100 :
		cleardevice ();
		cleardevice ();
		setbkcolor (7);
		settextstyle (8,HORIZ_DIR,1);
		outtextxy (320,230,"PLAYER B WIN ");
		outtextxy (320,270,"CONGRATULATION!");
		exit (0);
      default :
		printf ("");
     }
    }
   }
  }
 }
}
if (i==2)
{
 cleardevice ();
 setbkcolor (12);
 printf ("1. 2 PLAYERS MUST PLAY.\n2. PLAYER SHOULD PUT HIS WILLING NUMBER WITH THE KEYBOARD.\n3. THAT NUMBER SHOULD BELONG >=1 AND <=6 .\n4. IF THE PLAYER WILL PUT NUMBER INGNORING \nTHE INSTRUCTION THE HE WILL LOSS HIS CHANCE.\n5. YOU SHOULD PRESS THE ENTER KEY AFTER YOU \n ENTERED THE NUMBER.\n6. THE SNAKES AND LADDERS ARE NOT SEEN TO THE \n PLAYERS.");
 outtextxy (320,240,"READ PROPERLY");
 delay (15000);
 goto ajit;
}
if (i==3)
 {
 cleardevice ();
 setbkcolor (2);
 settextstyle (10,HORIZ_DIR,1);
 outtextxy (320,230,"THANK YOU");
 delay (3000);
 j=1;
 for (i=0;i<=640;i++)
 {
  if (j>=14)
  j=1;
  setcolor (2);
  setfillstyle (SOLID_FILL,j);
  bar (0+i,200,i+100,280);
  rectangle (0+i,200,i+100,280);
  delay (5);
  j++;
 }

 exit (0);
 }
 getch ();
 closegraph ();
 restorecrtmode ();
}

