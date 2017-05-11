#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<fstream.h>
#include<graphics.h>
#include<stdlib.h>

class start
{
	public:
	char na[100];
	int nod,nots;
	void tourney_det();
};

class individual_sports
{

public:
	void swimming();
	void tennis();
	void tt();
	void badminton();
	void horse_riding();
	void bowling();
	void karate();
	void golf();
};

class team_sports
{

public:
	void football();
	void swimming_relay();
	void cricket();
	void hockey();
	void basketball();
	void tennis_doubles();
	void tt_doubles();
	void badminton_doubles();
	void volleyball();
};

class methods:public start,public individual_sports,public team_sports
{

public:
	void cyclic_method();
};

ofstream f;

void methods::cyclic_method()
{
	clrscr();

	f.open("FIXTURE.txt");
	char a[100][100],b[100][100],temp[100],v[100][100],cd[100][100],tem[100];
	int mpd,nov,sm,l,d=0,i,j,nm,not,nom,hrs,hrs1,te,mins,mins1,nor,c=0,tl,mw[100];
	cout<<"\nEnter number of teams:";
	cin>>not;
	f<<"\nNumber of teams"<<not;
	nor=not;
	cout<<"\nNumber of rounds:"<<nor;
	f<<"\nNumber of rounds:"<<nor;

	if(not%2!=0)
	{
		for(i=0;i<=not;i++)
		{
			if(i%2!=0)
			{
				c++;
			}
		}
		cout<<"\nNumber of matches:"<<(not*c);
		f<<"\nNumber of matches:"<<(not*c);
	}
	else
	{
		for(i=1;i<=not;i++)
		{
			if(i%2==0)
			{
				d++;
			}
		}

		cout<<"\nNumber of matches:"<<(not*d);
		f<<"\nNumber of matches:"<<(not*d);
	}
	cout<<"\nEnter team names:"<<"\n";
	f<<"\nTeam names:";
	for(i=0;i<not;i++)
	{
		gets(a[i]);
		f<<"\n"<<a[i];
	}
	cout<<"\nEnter number of venues:";
	cin>>nov;
	f<<"\nNumber of venues:"<<nov;
	cout<<"\nEnter venue names:";
	f<<"\nVenue names:";

	for(i=0;i<nov;i++)
	{
		gets(v[i]);
		f<<"\n"<<v[i];
	}

		cout<<"\nEnter time limit for each match in hours:";
		cin>>tl;
		f<<"\nTime limit for each match:"<<tl;
		int p=0,y=0;

		for(i=0;i<not;i++)
		{
			if(i%2==0)
			{
				strcpy(b[p],a[i]);
				p++;
			}
			else
			{
				strcpy(cd[y],a[i]);
				y++;
			}
		}
		int il;

		for(il=1;il<=nor;il++)
		{
			cout<<"\nRound "<<il<<":";
			f<<"\nRound "<<il<<":";
			if(not%2!=0)
			{
				strcpy(cd[(not-1)/2],"BYE");
				for(i=0;i<(not+1)/2;i++)
				{
					cout<<"\n"<<b[i]<<" v/s "<<cd[i]<<"\n";
					f<<"\n"<<b[i]<<" v/s "<<cd[i]<<"\n";
				}
				strcpy(temp,b[(not-1)/2]);
				strcpy(b[(not-1)/2],cd[(not-3)/2]);
				for(j=(not-5)/2;j>=0;j--)
				{
					strcpy(cd[j+1],cd[j]);
				}
				strcpy(cd[0],b[0]);
				for(j=1;j<=(not-1)/2;j++)
				{
					strcpy(b[j-1],b[j]);
				}
				strcpy(b[(not-3)/2],temp);
			}
			else
			{
				for(i=0;i<(not/2);i++)
				{
					cout<<"\n"<<b[i]<<" v/s "<<cd[i]<<"\n";
					f<<"\n"<<b[i]<<" v/s "<<cd[i]<<"\n";
				}

				strcpy(temp,b[(not-2)/2]);
				strcpy(b[(not-2)/2],cd[(not-2)/2]);

				for(j=(not-4)/2;j>=0;j--)
				{
					strcpy(cd[j+1],cd[j]);
				}

				strcpy(cd[0],b[0]);

				for(j=1;j<=(not-2)/2;j++)
				{
					strcpy(b[j-1],b[j]);
				}

				strcpy(b[(not-4)/2],temp);
			}

		}

		cout<<"\nEnter the number of matches won by each team:";
		for(i=0;i<not;i++)
		{
			puts(a[i]);
			cout<<":";
			cin>>mw[i];
		}
		for(i=0;i<not;i++)
		{
			for(j=0;j<=i;j++)
			{
				if(mw[i]>mw[j])
				{
					te=mw[j];
					mw[j]=mw[i];
					mw[i]=te;
					strcpy(tem,a[j]);
					strcpy(a[j],a[i]);
					strcpy(a[i],tem);
				}
			}
		}

		cout<<"\nHighest Scorer:"<<a[0]<<" with "<<mw[0]<<" points";
		f<<"\nWinner:"<<a[0]<<" with "<<mw[0]<<" points. CONGRATULATIONS!!!";
		f.close();
		getch();
	}


void start::tourney_det()
{
	int x;
	ofstream t;
	t.open("DETAILS.txt");

	cout<<"\nEnter name of tournament:";
	gets(na);
	t<<"\nTournament name:";

	for(x=0;x<(strlen(na));x++)
	{
		t<<na[x];
	}

	cout<<"\nEnter the length of the tournament in days:";
	cin>>nod;
	t<<"\nLength of tournament:"<<nod;
	cout<<"\nEnter total number of teams participating:";
	cin>>nots;
	t<<"\nNumber of participating teams:"<<nots;
	t.close();
}

methods m;
void individual_sports::swimming()
{
	cout<<"\nYou have chosen Swimming...";
	m.cyclic_method();
}

void individual_sports::tennis()
{
	cout<<"\nYou have chosen Tennis...";
	m.cyclic_method();
}

void individual_sports::tt()
{
	cout<<"\nYou have chosen Table Tennis...";
	m.cyclic_method();
}

void individual_sports::badminton()
{
	cout<<"\nYou have chosen Badminton...";
	m.cyclic_method();
}

void individual_sports::horse_riding()
{
	cout<<"\nYou have chosen Horse Riding...";
	m.cyclic_method();
}

void individual_sports::bowling()
{
	cout<<"\nYou have chosen Bowling...";
	m.cyclic_method();
}

void individual_sports::karate()
{
	cout<<"\nYou have chosen Karate...";
	m.cyclic_method();
}

void individual_sports::golf()
{
	cout<<"\nYou have chosen golf...";
	m.cyclic_method();
}

void team_sports::football()
{
	cout<<"\nYou have chosen football...";
	m.cyclic_method();
}

void team_sports::swimming_relay()
{
	cout<<"\nYou have chosen swimming relay...";
	m.cyclic_method();
}

void team_sports::cricket()
{
	cout<<"\nYou have chosen cricket...";
	m.cyclic_method();

}
void team_sports::hockey()
{
	cout<<"\nYou have chosen hockey...";
	m.cyclic_method();
}

void team_sports::basketball()
{
	cout<<"\nYou have chosen basketball...";
	m.cyclic_method();
}

void team_sports::tennis_doubles()
{
	cout<<"\nYou have chosen tennis doubles...";
	m.cyclic_method();
}

void team_sports::tt_doubles()
{
	cout<<"\nYou have chosen table tennis doubles...";
	m.cyclic_method();
}

void team_sports::badminton_doubles()
{
	cout<<"\nYou have chosen badminton doubles...";
	m.cyclic_method();
}

void team_sports::volleyball()
{
	cout<<"\nYou have chosen volley ball...";
	m.cyclic_method();
}

void main()
{

   int gdriver = DETECT,gmode, errorcode;
   int style, midx, midy;
   initgraph(&gdriver, &gmode, "c:\\TC\\bgi");
   errorcode = graphresult();

   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;

   settextjustify(CENTER_TEXT, CENTER_TEXT);

      cleardevice();
      setbkcolor(0);
      setcolor(4);
      settextstyle(7,HORIZ_DIR,10);
      outtextxy(midx, midy/3,"Welcome" );
      setcolor(14);
      outtextxy(midx-2, midy/3-2,"---Welcome---" );

      settextstyle(7,HORIZ_DIR,7);
      setcolor(4);
      outtextxy(midx,midy,"---Fixture Maker---");
      setcolor(14);
      outtextxy(midx-2,midy-2,"---Fixture Maker---");

      setcolor(4);
      rectangle(0,0,getmaxx(),getmaxy());
      rectangle(2,2,getmaxx()-2,getmaxy()-2);

      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
      outtextxy(midx+60,midy+90,"By:-");
      outtextxy(midx+200,midy+110,"Anmol Singh");
      outtextxy(midx+180,midy+145,"Anish Krishnan");
      outtextxy(midx+200,midy+180,"Paavan Jain");
      getch();

       cleardevice();

       rectangle(0,0,getmaxx(),getmaxy());
       rectangle(2,2,getmaxx()-2,getmaxy()-2);

       settextstyle(7,HORIZ_DIR,10);
       setcolor(4);
       outtextxy(midx-1,midy/6-1,"Sports");

       setcolor(14);
       outtextxy(midx,midy/6,"Sports");

       setcolor(14);
       outtextxy(midx-2,midy/6-2,"Sports");

       setcolor(3);
       settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
       outtextxy(110,250,"Tennis");
       outtextxy(450,180,"Swimming");
       outtextxy(540,370,"Badminton");

       settextstyle(SANS_SERIF_FONT,HORIZ_DIR,6);
       outtextxy(91,151,"Cricket");
       outtextxy(401,271,"Football");
       outtextxy(126,350,"Basketball");
       outtextxy(321,421,"Hockey");

       settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
       outtextxy(midx+11,371,"Bowling");
       outtextxy(591,241,"Karate");
       outtextxy(551,421,"Golf");

       settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
       outtextxy(60,430,"Volley Ball");
       outtextxy(560,150,"Horse Riding");
       outtextxy(270,210,"Table Tennis");


       setcolor(4);
       settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
       outtextxy(109,249,"Tennis");
       outtextxy(449,179,"Swimming");
       outtextxy(539,369,"Badminton");

       settextstyle(SANS_SERIF_FONT,HORIZ_DIR,6);
       outtextxy(90,150,"Cricket");
       outtextxy(400,270,"Football");
       outtextxy(125,350,"Basketball");
       outtextxy(320,420,"Hockey");

       settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
       outtextxy(midx+10,370,"Bowling");
       outtextxy(589,239,"Karate");
       outtextxy(549,419,"Golf");

       settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
       outtextxy(61,431,"Volley Ball");
       outtextxy(561,151,"Horse Riding");
       outtextxy(271,211,"Table Tennis");

       getch();

       cleardevice();
	int ch;
	methods met;
	met.tourney_det();

	cleardevice();

	settextstyle(7,HORIZ_DIR,7);
	setcolor(14);
	outtextxy(midx,midy/6,"Menu");

	setcolor(4);
	outtextxy(midx-2,midy/6-2,"Menu");

	cout<<"\n1.Swimming";
	cout<<"\n2.Tennis";
	cout<<"\n3.Table Tenis";
	cout<<"\n4.Badminton";
	cout<<"\n5.Horse Riding";
	cout<<"\n6.Bowling";
	cout<<"\n7.Karate";
	cout<<"\n8.Golf";
	cout<<"\n9.Football";
	cout<<"\n10.Swimming Relay";
	cout<<"\n11.Cricket";
	cout<<"\n12.Hockey";
	cout<<"\n13.Basketball";
	cout<<"\n14.Tennis Doubles";
	cout<<"\n15.Table Tennis Doubles";
	cout<<"\n16.Badminton Doubles";
	cout<<"\n17.Volley Ball";
	cout<<"\nEnter your choice:";
	cin>>ch;

	switch(ch)
	{
		case 1:met.swimming();
		break;
		case 2:met.tennis();
		break;
		case 3:met.tt();
		break;
		case 4:met.badminton();
		break;
		case 5:met.horse_riding();
		break;
		case 6:met.bowling();
		break;
		case 7:met.karate();
		break;
		case 8:met.golf();
		break;
		case 9:met.football();
		break;
		case 10:met.swimming_relay();
		break;
		case 11:met.cricket();
		break;
		case 12:met.hockey();
		break;
		case 13:met.basketball();
		break;
		case 14:met.tennis_doubles();
		break;
		case 15:met.tt_doubles();
		break;
		case 16:met.badminton_doubles();
		break;
		case 17:met.volleyball();
		break;

	}

	closegraph();
	getch();
}