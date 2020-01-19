#include "drawFunction.h"

char funC[512];
std::string fun;
Queue infixQ;
Queue postQ;
int graphicWindow;
double interval=10;

const unsigned int width=getmaxwidth();
const unsigned int height=getmaxheight();
const unsigned int xCentru=width/2;
const unsigned int yCentru=height/2-50;
double xOffset=0;
double yOffset=0;
int graphColor=15;

void getFun()
{
    //std::string aux(funC);
    //fun=aux;
    fun.assign(funC);
}

void getInfixQueue()
{
    putInfixQueue(fun,infixQ);
}

void getPostQueue()
{
    makePostQueue(infixQ,postQ);
}

void getFunArray()
{
    putPostQueue(postQ);
}

void getInterval()
{
    std::cin>>interval;
}

void getGraphColor(int culaleasa)
{
    graphColor=culaleasa;
}

void drawAxis()
{
    line(0,height/2-50+yOffset,width,height/2-50+yOffset); //x axis
    line(width/2+xOffset,0,width/2+xOffset,height-100); //y axis
    setlinestyle(SOLID_LINE, NULL, THICK_WIDTH);
    line(width,height/2-50+yOffset, width-10,height/2-50+yOffset-10); //prima parte din sageata x
    line(width,height/2-50+yOffset, width-10,height/2-50+yOffset+10);
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(width-35, height/2-90, "X");
    outtextxy(width/2+20, 5, "Y");
    outtextxy(xCentru+15, yCentru+10, "O");
    line(width/2+xOffset,0, width/2+xOffset-10,10);
    line(width/2+xOffset,0, width/2+xOffset+10,10);
    setlinestyle(SOLID_LINE, NULL, NORM_WIDTH);
}

void drawGraph(double interval)
{
    //double pas=interval/1000;
    //std::cout<<pas<<'\n';
    bool userVarIntroduse=0;
    drawAxis();
    setcolor(graphColor);
    double xInitial=-interval;
    double yInitial=valueQueue(postQ);

    /*if(userVariables)
        {
            for(unsigned int i=0;i<lungimeVal;++i)
            {
                std::cout<<var[i].name<<"= ";
                std::cin>>userVar;
                var[i].value=userVar;
                std::cout<<'\n';
            }
        }*/
    moveto(xInitial,yInitial);
    for(x=-interval;x<=interval+0.005;x+=0.005)
    {
        double xReal=x;
        double yReal=valueQueue(postQ);

        double xGraph=xCentru+xReal*xCentru/interval+xOffset;
        double yGraph=yCentru-yReal*xCentru/interval+yOffset;
        if(yGraph>height-100)
        {
            moveto(xGraph,yGraph);
            continue;
        }

        if(x==-interval)
        {
            moveto(xGraph,yGraph);
            continue;
        }
        //std::cout<<xReal<<' '<<yReal<<' '<<xGraph<<' '<<yGraph<<'\n';
        lineto(xGraph,yGraph);
        /*if(userVariables)
            if(!userVarIntroduse)
        {
            for(unsigned int i=0;i<lungimeVal;++i)
            {
                std::cout<<var[i].name<<"= ";
                std::cin>>userVar;
                var[i].value=userVar;
                std::cout<<'\n';
            }
            userVarIntroduse=1;
        }*/
        //fillellipse(xGraph,yGraph,1,1);
    }
    setfillstyle(SOLID_FILL, BLACK);
    bar(0,height-100,width,height);
    setcolor(WHITE);
    line(0,height-100,width,height-100);

    //closegraph(graphicWindow);
}
