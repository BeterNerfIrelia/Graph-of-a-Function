#include <iostream>1
#include <graphics.h>
#include <winbgim.h>
#include <cstring>
#include "drawFunction/drawFunction/drawFunction.h"

using namespace std;

void meniu_principal(int language);
void meniu_limba();
int getLang(int x, int y);
void citesteInModGrafic2(char text[200], int x, int y, int culoareFundal, int culoareText);
void initializare();
void drawZoom();


int lat=115, orizspace=35, vertspace=20, culori, meniu, limba, language=1;
char text[200];
int xsetari=500, ysetari=650;
int xwindow=1000, ywindow=800;
char * sir_lung="MMMMMMMMMMMMMMMM";
bool buton_exit, buton_exit2, sound_on=1;
int x123, y, i, linie, culoare, lat_culori;
char titlu[10][200], titlu2[10][200];

int main()
{
    initializare();
    meniu=initwindow(xwindow, ywindow,"MENIU");
    meniu_principal(language);
    PlaySound("music.wav", NULL, SND_ASYNC);

    while (buton_exit==0)
    {
        clearmouseclick(WM_LBUTTONDOWN);
        while(!ismouseclick(WM_LBUTTONDOWN)){}
        getmouseclick(WM_LBUTTONDOWN, x123, y);

        if(x123>=0 && (x123<=2*lat) && (y>= ysetari+vertspace) && (y<=ysetari+2*lat))
        {
            buton_exit=1;
            closegraph();
        }
        else
            if(x123>=(xsetari+3*orizspace+2*lat) && x123<=(xsetari+3*orizspace+3*lat) && (y>=ysetari+vertspace) &&(y<=ysetari+vertspace+lat))
              {
                  cleardevice();
                  meniu_principal(language);
                  sound_on=1-sound_on;
                  if(sound_on)
                  {
                    readimagefile("sound on final.jpg", xsetari+3*orizspace+2*lat+1,ysetari+vertspace+1, xsetari+3*orizspace+3*lat-1, ysetari+vertspace+lat-1);
                    PlaySound("music.wav", NULL, SND_ASYNC);
                  }
                  else
                  {
                      readimagefile("sound off final.jpg", xsetari+3*orizspace+2*lat+1,ysetari+vertspace+1, xsetari+3*orizspace+3*lat-1, ysetari+vertspace+lat-1);
                      PlaySound(NULL, NULL, SND_ASYNC);
                  }
              }
            else
                if((x123>=xsetari+2*orizspace+lat) && (x123<=xsetari+2*orizspace+2*lat) && (y>=ysetari+vertspace) &&(y<=ysetari+vertspace+lat))
                  {
                      culori=initwindow(300, 500, "CULORI", 1050, 200);
                      setcurrentwindow(culori);
                      line(100, 0, 100, 500);
                      line(200, 0, 200, 500);
                      line(0, 100, 300, 100);
                      line(0, 200, 300, 200);
                      line(0, 300, 300, 300);
                      line(0, 400, 300, 400);
                      lat_culori=100; linie=0;
                      for(i=1; i<=15; i++)
                      {
                          setfillstyle(SOLID_FILL,i);
                          bar(lat_culori*((i-1)%3), lat_culori*linie, lat_culori*((i-1)%3)+lat_culori, lat_culori*linie+lat_culori);
                          if(i%3==0)
                            linie++;
                      }
                      int x1=0, y1=0;
                      while(!ismouseclick(WM_LBUTTONDOWN)){}
                      getmouseclick(WM_LBUTTONDOWN, x1, y1);
                      if(x1 && y1)
                          {
                              x1/=100; y1/=100;
                              cout<<x1<<' '<<y1<<'\n';
                              culoare=y1*3+x1+1;
                          }
                        cout<<culoare;
                        getGraphColor(culoare);
                        closegraph(CURRENT_WINDOW);
                      }
                else
                    if(x123>=xsetari+orizspace && x123<=xsetari+orizspace+lat && y>=ysetari+vertspace && y<=ysetari+vertspace+lat)
                    {
                        int lang=8;
                        meniu_limba();
                        while(lang!=7)
                        {
                            int x1, y1;
                            while(!ismouseclick(WM_LBUTTONDOWN)) {}
                            getmouseclick(WM_LBUTTONDOWN, x1, y1);
                            lang=getLang(x1, y1);
                            if(lang==7)
                                {
                                    closegraph(CURRENT_WINDOW);
                                }
                            if(lang>=1 && lang<=6)
                                {
                                    language=lang;
                                    cout<<language;
                                }
                        }
                        setcurrentwindow(meniu);
                        cleardevice();
                        meniu_principal(language);
                    }
                    else
                        if(x123>=100 && x123<=800 && y>=200 && y<=250)
                    {
                        int grafic;
                        int xx, yy;
                        settextstyle(SIMPLEX_FONT, HORIZ_DIR, 4);
                        citesteInModGrafic2(text, 55, 205, BLACK, WHITE);
                        grafic=initwindow(width, height, "Grafic");
                        cleardevice();
                        funC[0]=NULL;
                        strcpy(funC, text);
                        cout<<funC<<'\n' ;
                        getFun();
                        getInfixQueue();
                        getPostQueue();
                        getFunArray();
                        for(unsigned int m=0;m<lenPostQueue;++m)
                            cout<<postQueue[m]<<' ';
                        cout<<"             "<<funC<<' '<<fun;
                        cout<<'\n';
                        setcurrentwindow(grafic);
                        buton_exit2=0;
                        while(buton_exit2==0)
                        {
                            cleardevice();
                            drawGraph(interval);
                            rectangle(50, height-90, 250, height-20);
                            settextstyle(SIMPLEX_FONT, HORIZ_DIR, 6);
                            outtextxy(70, height-80, "EXIT");
                            drawZoom();
                            clearmouseclick(WM_LBUTTONDOWN);
                            while(!ismouseclick(WM_LBUTTONDOWN));
                            getmouseclick(WM_LBUTTONDOWN, xx, yy);
                            if(xx>=50 && xx<=250 && yy>=height-90 && yy<=height-20)
                                buton_exit2=1;
                            else
                                if(xx>=width-150 && yy>=height-90 && xx<=width-80 && yy<=height-20 && interval>5)
                                    interval-=5;
                                else
                                    if(xx>=width-220 && yy>=height-90 && xx<=width-150 && yy<=height-20 && interval<50)
                                        interval+=5;
                        }
                        cleardevice();
                        closegraph();
                        exit(0);
                    }
        setcurrentwindow(meniu);
    }
    return 0;
}

void meniu_limba()
{
    limba=initwindow(450, 360, "LIMBA", 1000, 200);
    setcurrentwindow(limba);
    rectangle(25, 25, 125, 125);
    readimagefile("ro.jpg", 26, 26, 124, 124);
    rectangle(175, 25, 275, 125);
    readimagefile("ENG.jpg", 176, 26, 274, 124);
    rectangle(325, 25, 425, 125);
    readimagefile("fra.jpg", 326, 26, 424, 124);
    rectangle(25, 150, 125, 250);
    readimagefile("deu.jpg", 26, 151, 124, 249);
    rectangle(175, 150, 275, 250);
    readimagefile("ita.jpg", 176, 151, 274, 249);
    rectangle(325, 150, 425, 250);
    readimagefile("esp.jpg", 326, 151, 424, 249);
    rectangle(275, 300, 425, 350);
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 5);
    outtextxy(280, 305, "EXIT");
}

void meniu_principal(int language)
{
    int xbox=100, ybox=100;
    setcolor(WHITE);
    rectangle (0, ysetari+vertspace, 2*lat, ysetari+2*lat);
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 7);
    outtextxy(10, ysetari+vertspace+30, "EXIT");
    settextstyle(BOLD_FONT, HORIZ_DIR, 6);
    outtext(titlu[language]);
    rectangle(xsetari, ysetari, 1000, 800);
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(xsetari+4, ysetari-12, "Setari:");
    rectangle(xsetari+orizspace, ysetari+vertspace, xsetari+orizspace+lat, ysetari+vertspace+lat);
    rectangle(xsetari+2*orizspace+lat, ysetari+vertspace, xsetari+2*orizspace+2*lat, ysetari+vertspace+lat);
    rectangle(xsetari+3*orizspace+2*lat, ysetari+vertspace, xsetari+3*orizspace+3*lat, ysetari+vertspace+lat);

    readimagefile("world.jpg", xsetari+orizspace+1, ysetari+vertspace+1, xsetari+orizspace+lat-1, ysetari+vertspace+lat-1);

    readimagefile("color wheel 1.jpg", xsetari+2*orizspace+lat+1, ysetari+vertspace+1, xsetari+2*orizspace+2*lat-1, ysetari+vertspace+lat-1);


    if(sound_on)
        {
        readimagefile("sound on final.jpg", xsetari+3*orizspace+2*lat+1,ysetari+vertspace+1, xsetari+3*orizspace+3*lat-1, ysetari+vertspace+lat-1);
        PlaySound("music.wav", NULL, SND_ASYNC);
        }
            else
            {
                readimagefile("sound off final.jpg", xsetari+3*orizspace+2*lat+1,ysetari+vertspace+1, xsetari+3*orizspace+3*lat-1, ysetari+vertspace+lat-1);
                PlaySound(NULL, NULL, SND_ASYNC);
            }

    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 5);
    outtextxy(100, 150, titlu2[language]);
    rectangle(50, 200,55+textwidth(sir_lung),195+textheight("M"));

}

int getLang(int x, int y)
{
    int i=8;
    if(x>=25 && x<=125)
    {
        if(y>=25 && y<=125)
            i=1;
        if(y>=150 && y<=250)
            i=4;
    }
    if(x>=175 && x<=275)
    {
        if(y>=25 && y<=125)
            i=2;
        if(y>=150 && y<=250)
            i=5;
    }
    if(x>=325 && x<=425)
    {
        if(y>=25 && y<=125)
            i=3;
        if(y>=150 && y<=250)
            i=6;
    }
    if(x>=275 && x<=425 && y>=300 && y<=350)
        i=7;
    return i;
}

void citesteInModGrafic2(char text[200], int x, int y, int culoareFundal, int culoareText)
{
    char tasta, sir[2];
    char * sir_lung="MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM";
    bool vizibil=false;
    int nrtaste=0;
    sir[1]='\0';
    strcpy(text,"");
    setcolor(culoareText);
    settextstyle(SIMPLEX_FONT, HORIZ_DIR,3);
    //rectangle(x,y,x+textwidth(sir_lung),y+textheight("M")+5);
    outtextxy(x,y,text);
    do
    {
        if (kbhit())
        {
            tasta=getch();
            if (tasta==8 && strlen(text)>0)
            {
                setcolor(culoareFundal);
                outtextxy(x,y,text);
                outtextxy(x+textwidth(text),y,"_");
                text[strlen(text)-1]='\0';
                setcolor(culoareText);
                outtextxy(x,y,text);
            }
            if (tasta>=32 && tasta<=127 && strlen(text)<strlen(sir_lung)-2)
            {
                setcolor(culoareFundal);
                outtextxy(x,y,text);
                sir[0]=tasta;
                setcolor(culoareText);
                strcat(text,sir);
                outtextxy(x,y,text);
                nrtaste++;
            }
        }
        else {
            if (vizibil) setcolor(culoareText);
            else setcolor(culoareFundal);
            outtextxy(x+textwidth(text),y,"_");
            vizibil=not vizibil;
            delay(100);
        }
    }
    while (tasta!=13 && tasta!=27);
    setcolor(culoareFundal);
    outtextxy(x,y,text);
    outtextxy(x+textwidth(text),y,"_");
    rectangle(x-5,y-5,x+textwidth(sir_lung),y+textheight("M")+5);
    if (tasta==27) strcpy(text,"");
}

void initializare()
{
    strcpy(titlu[1], "GRAFICUL UNEI FUNCTII");
    strcpy(titlu[2], "THE GRAPH OF A FUNCTION");
    strcpy(titlu[3], "GRAPHIQUE D'UNE FONCTION");
    strcpy(titlu[4], "GRAFIK EINER FUNKTION");
    strcpy(titlu[5], "GRAFICO DI UNA FUNZIONE");
    strcpy(titlu[6], "GRÁFICO DE UNA FUNCIÓN");
    strcpy(titlu2[1], "Introduceti (corect) functia:");
    strcpy(titlu2[2], "Enter the function:");
    strcpy(titlu2[3], "Entrez la fonction:");
    strcpy(titlu2[4], "Geben Sie die Funktion ein:");
    strcpy(titlu2[5], "Inserisci la funzione:");
    strcpy(titlu2[6], "Escribe la función:");
}

void drawZoom()
{
    rectangle(width-150, height-90, width-80, height-20);
    readimagefile("plus.jpg", width-149, height-89, width-81, height-21);
    rectangle(width-220, height-90, width-150, height-20);
    readimagefile("minus.jpg",width-219, height-89, width-151, height-21);
}
