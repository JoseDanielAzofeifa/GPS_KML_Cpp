/*
** Copyright © YYYY NAME
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU Library General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

/**
   @file main.cpp
   @author NAME
   @date YYYY-MM-DD
   @version 0.01
*/
/*
** Copyright © YYYY NAME
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU Library General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

/**
   @file main.cpp
   @author NAME
   @date YYYY-MM-DD
   @version 0.01
*/
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Scroll.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>
#include "tinyxml2\tinyxml2.h"
#include <sstream>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
using namespace std;
using namespace tinyxml2;
Fl_Double_Window *win;

int ver=0;
vector<double> coordx;                                                         
vector<double> coordy;
vector<double> coordx2;                                                         
vector<double> coordy2;
vector<double> coordxz;
vector<double> coordxz2;                                                         
vector<double> coordyz;                                                         
vector<double> coordyz2;
vector<double> bound;
vector<double> boundz;
vector<double> todox;
vector<double> todoy;
vector<double> todoxz;
vector<double> todoyz;
vector<double> linea;
vector<double> lineaz;
vector<int> orden;
vector<int>repetidos;
int cont;
bool paint=false,paint2=false;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//C:\\Users\\Albin\\Dropbox\\I Proyecto C\\II Proyecto\\sanjose.kml


class floyd{
int n;
int A[1000][1000];
int vect1[1000];
int vect2[1000];
int B[1000][1000];
public:

void ingresar();
void nodointer();
void floid();
void mostrar1();
void mostrar2();
void preguntar(int i, int j);

};

void floyd::ingresar()
{
     int x,y;
     double distancia;
     n=todox.size();
     int i,j;
     if(orden.empty())
     {
         for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
            {
                x=100+((int)((todox[i]-bound[0])*100000))/10;
                y=100+((int)((bound[1]-todoy[i])*100000))/10;
                A[i][j]=1000;
                for(int k=0;k<coordx.size();k++)
                {
                     if(coordx[k]==x && coordy[k]==y)                     
                       A[i][j]=(int)sqrt(pow((x-coordx2[k]),2)+pow((y-coordy2[k]),2));  
                     
                }    
            }
     }
}

void floyd::nodointer()
{int i,j;
    for(i=1;i<=6;i++)
    for(j=1;j<=6;j++)
    {if(i==j)
    B[i][j]=0;
    else B[i][j]=j;}
}

void floyd::floid()
{int bucle,i,j,suma;
    for(bucle=1;bucle<=n;bucle++){
for(i=1;i<=n;i++){
vect1[i]=A[bucle][i];
vect2[i]=A[i][bucle];
}

for(i=1;i<=n;i++)
for(j=1;j<=n;j++){
if(vect2[i]==999 || vect1[j]==999) suma=999;
else suma=vect2[i]+vect1[j];
if(suma<A[i][j]){
A[i][j]=suma;
B[i][j]=bucle;}

}}}

void floyd:: mostrar1()
{int i,j;
    cout<<"imprime distancias o pesos optimo"<<endl;
      for(i=1;i<=n;i++){
    for(j=1;j<=n;j++)
    {cout<<A[i][j];}
cout<<endl;}
}

void floyd:: mostrar2()
{int i,j;
    cout<<"imprime matriz intermedios"<<endl;
      for(i=1;i<=n;i++){
    for(j=1;j<=n;j++)
    {cout<<B[i][j];}
cout<<endl;}
}

void floyd:: preguntar(int i, int j)
{
if (orden.empty())
   orden.clear();
if(i==0 || j==0 || i==j)
orden.push_back (i);
else{
//cout<<"distancia minima"<<endl;
//cout<<A[i][j]<<endl;
orden.push_back(B[i][j]);
orden.push_back(j);}
getch();
}



class MyCanvas : public Fl_Widget {
  void draw() {          
         if (paint==true){
         int a=0,q=0;
         fl_color(FL_WHITE);
         fl_rectf(x(),y(),w(),h());
         // DRAW
    double mayory2=coordy2[0];
    double menorx=coordx[0];
    for(int i=0; i<coordx.size();i++) {
            if (mayory2<coordy2[i])
               mayory2=coordy2[i];
            if (menorx>coordx[i])
               menorx=coordx[i];                    
         }
    bound.push_back (menorx);  
    bound.push_back (mayory2);
    
    for(int r=0;r<todox.size();r++){
       for(int s=0;s<todoy.size();s++){
          if(r!=s && todox[r]==todox[s] && todoy[r]==todoy[s])
          {
             todox.erase(todox.begin()+s);
             todoy.erase(todoy.begin()+s);
          }
       }
    }
    
         fl_color(FL_BLACK);
         redraw();
         int t = coordx.size();
         for(int i=0; i<t;i++) {       
                       
                       int x1 = 100+((int)((coordx[i]-bound[0])*100000))/10;
                       int y1 = 100+((int)((bound[1]-coordy[i])*100000))/10;
                       int x2 = 100+((int)((coordx2[i]-bound[0])*100000))/10;
                       int y2 = 100+((int)((bound[1]-coordy2[i])*100000))/10;
                    fl_line(x1,y1,x2,y2); 
                    if(i==t-1){                                 
                        char etiqueta[30];          
                        fl_font(FL_HELVETICA,8); 
                        for(int z=0;z<todox.size();z++){
                            int x = 100+((int)((todox[z]-bound[0])*100000))/10;
                            int y = 100+((int)((bound[1]-todoy[z])*100000))/10;
                            itoa(z,etiqueta,10); printf(etiqueta);  
                            fl_draw(etiqueta, x+2,y);  
                        }
                    }                              
         }
         if(paint2==true){
             fl_color(FL_RED);
                  int r= 100+((int)((linea[0]-bound[0])*100000))/10;
                  int s=100+((int)((bound[1]-linea[1])*100000))/10;
                  int t= 100+((int)((linea[2]-bound[0])*100000))/10;
                  int u=100+((int)((bound[1]-linea[3])*100000))/10;
             fl_line(r,s,t,u);  }
       }          
     }
  static void Canvas_CB(void *userdata) {
        MyCanvas *o = (MyCanvas*)userdata;
        o->redraw();
        Fl::repeat_timeout(0.1, Canvas_CB, userdata);}
        
public: 
     MyCanvas(int X,int Y,int W,int H,const char*L=0) : Fl_Widget(X,Y,W,H,L) {
     Fl::add_timeout(0.1, Canvas_CB, (void*)this);}
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//saca las coordenadas
void sacarcoor(string s)
{
    char * pch;
    istringstream iss(s);
    string sub;
    bool i=false;
    double x1=0;
    double x2=0;
    double y1=0;
    double y2=0;
    int tam=0;
    int locate=0;
    do
    {
        string sub;
        iss >> sub;
        cout<<sub<< endl;
        tam = sub.size();
        if (tam>0)
        {
            if (x1==0 && y1==0)
            {
               x1 = strtof (sub.c_str(),NULL);
               pch=strchr(sub.c_str(),',');
               locate = pch-sub.c_str()+1;
               string subcadenay = sub.substr(locate);
               y1 = strtof (subcadenay.c_str(),NULL);
            }
            else
            {
                if (i)
                {
                   x1=x2;
                   y1=y2;
                }
                i=true;
               x2 = strtof (sub.c_str(),NULL);
               pch=strchr(sub.c_str(),',');
               locate = pch-sub.c_str()+1;
               string subcadenay = sub.substr(locate);
               y2 = strtof (subcadenay.c_str(),NULL);
                   coordx.push_back (x1);  
                   coordy.push_back (y1);    
                   coordx2.push_back (x2);  
                   coordy2.push_back (y2); 
                   todox.push_back (x1);  
                   todoy.push_back (y1);    
                   todox.push_back (x2);  
                   todoy.push_back (y2);
            }
        }
    }while (iss);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//leer kml
void leer(const char * archivo)
 {      
        int contador=0;
        const char* itemText="";
  try{
        XMLDocument doc;
        doc.LoadFile(archivo);
        
 		XMLElement* itemElement = doc.FirstChildElement( "kml" )->FirstChildElement( "Document" )->FirstChildElement( "Folder" )->FirstChildElement( "Placemark");
        while(itemElement){
            if(contador>=766 && contador<=772 || contador>=774 && contador<788 || contador>791 && contador<796 || contador>796 && contador<800 || contador>800 && contador<815 || contador>815 && contador<829 || contador>829 && contador<832 || contador>833 && contador<=834){
                   XMLElement* itemElement2 = itemElement->FirstChildElement( "MultiGeometry" )->FirstChildElement( "LineString" );
                  while(itemElement2){
                        XMLElement* itemElementcoor2 = itemElement2->FirstChildElement( "coordinates" );
                        itemText = itemElementcoor2->GetText();
                        sacarcoor(itemText);
                        itemElement2 = itemElement2->NextSiblingElement("LineString");
                        }
            }
             else{
                  XMLElement* itemElementcoor = itemElement->FirstChildElement( "LineString" )->FirstChildElement( "coordinates" );
                  itemText = itemElementcoor->GetText();
                  sacarcoor(itemText);
            }
	        contador++;
            itemElement = itemElement->NextSiblingElement("Placemark");
       }
                 
    coordxz=coordx;
    coordxz2=coordx2;
    coordyz=coordy;
    coordyz2=coordy2;
    boundz=bound;
    todoxz=todox;
    todoyz=todoy;
    paint=true;                                               //manda a dibujar
    Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "File loaded");
	box->box(FL_UP_BOX);
	box->labelsize(24);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
  }
  catch(...) {
    Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "File error");
	box->box(FL_UP_BOX);
	box->labelsize(24);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//open.cpp 
void read_cb( Fl_Widget* o , void* ) {
    try{
   Fl_Button* b=(Fl_Button*)o;
   Fl_Input* iw = (Fl_Input*) b -> parent() -> child(1);
   leer(iw->value() );}
   catch(...){
    Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "File error");
	box->box(FL_UP_BOX);
	box->labelsize(24);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();}
}



void open_window(Fl_Widget* buttonptr) {
   try{
   Fl_Window* win= new Fl_Window(420,200, "OPEN FILE");
   win->begin();      
      Fl_Button*  copy = new Fl_Button( 10, 150, 70, 30, "OPEN"); //child 0   : 1st widget
      Fl_Input*       inp = new Fl_Input(50, 50, 350, 30, "FILE");              //child 1 : 2rd widget
      Fl_Input*       msj = new Fl_Input(300, 20, 0, 0, "Example: C:\\\\Documents\\\\text.kml");
   win->end();
   copy->callback(  read_cb );
   win->show();}
   catch(...){
   Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Open error");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();}
 }
 
 
 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//get coordenadas para camino mas corto.cpp 
void gps_cb( Fl_Widget* o , void* ) {
    try{
        //floyd E;
        int x,x2,y,y2;
   Fl_Button* b=(Fl_Button*)o;
   Fl_Input* iw = (Fl_Input*) b -> parent() -> child(1);
   Fl_Input* iw2 = (Fl_Input*) b -> parent() -> child(2);
   //*****(iw->value(),iw2->value() );                        aqui hay que cojer las coordenadas de las etiquetas digitadas y llamar a lo del camino mas corto con esas coordenadas
    /*E.ingresar();
    E.nodointer();
    E.floid();
    E.preguntar(atoi(iw->value()),atoi(iw2->value()));*/
     linea.clear();
     linea.push_back (todox[atoi(iw->value())]);  
     linea.push_back (todoy[atoi(iw->value())]);    
     linea.push_back (todox[atoi(iw2->value())]);  
     linea.push_back (todoy[atoi(iw2->value())]);
     lineaz=linea;
     paint2=true;
    Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "GPS Load");
	box->box(FL_UP_BOX);
	box->labelsize(24);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
   }  
   catch(...){
    Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "GPS error");
	box->box(FL_UP_BOX);
	box->labelsize(24);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();}
}



void gps_window(Fl_Widget* buttonptr) {
   try{
   Fl_Window* win= new Fl_Window(500,250, "GPS");
   win->begin();      
      Fl_Button*  go = new Fl_Button( 10, 190, 70, 30, "GO"); //child 0   : 1st widget
      Fl_Input*       inp = new Fl_Input(120, 50, 350, 30, "Initial coordinate");              
      Fl_Input*       inp2 = new Fl_Input(120, 120, 350, 30, "End coordinate");            

   win->end();
   go->callback(  gps_cb );
   win->show();}
   catch(...){
   Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "GPS error");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();}
 } 
 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//main.cxx
void right(Fl_Widget* buttonptr){
     try{
     bound[0]=bound[0]-0.001;         
     bound[1]=bound[1];
    paint=true;                                                                      //manda a dibujar
    }
     catch(...){Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Right error");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
	}}

void left(Fl_Widget* buttonptr){
     try{
     bound[0]=bound[0]+0.001;    
     bound[1]=bound[1];
    paint=true;                                                                      //manda a dibujar
    }
     catch(...){Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Left error");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
	}}
	
void up(Fl_Widget* buttonptr){
     try{
     bound[0]=bound[0];
     bound[1]=bound[1]-0.001;     
    paint=true;                                                                      //manda a dibujar
    }
     catch(...){Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Up error");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
	}}
	
void down(Fl_Widget* buttonptr){
     try{
     bound[0]=bound[0];
     bound[1]=bound[1]+0.001;
    paint=true;                                                                      //manda a dibujar
    }
     catch(...){Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Down error");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
	}}

void zoomIn(Fl_Widget* buttonptr){
     try{
     for (int i=0; i<coordx.size();i++)
    {
        coordx[i]=coordx[i]*2;
        coordx2[i]=coordx2[i]*2;
        coordy[i]=coordy[i]*2;
        coordy2[i]=coordy2[i]*2;
    } 
    bound[0]=bound[0]*2;
    bound[1]=bound[1]*2;
    if(paint2==true){
    linea[0]=linea[0]*2;
    linea[1]=linea[1]*2;
    linea[2]=linea[2]*2;
    linea[3]=linea[3]*2;}
    for (int i=0; i<todox.size();i++)
    {
        todox[i]=todox[i]*2;
        todoy[i]=todoy[i]*2;
    } 
    paint=true;                                                                      //manda a dibujar
    }
     catch(...){Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Zoom in error");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
	}}
void zoomOut(Fl_Widget* buttonptr){
     try{
     for (int i=0; i<coordx.size();i++)
    {
        coordx[i]=coordx[i]/2;
        coordx2[i]=coordx2[i]/2;
        coordy[i]=coordy[i]/2;
        coordy2[i]=coordy2[i]/2;                         
    }
    bound[0]=bound[0]/2;
    bound[1]=bound[1]/2; 
    if(paint2==true){
    linea[0]=linea[0]/2;
    linea[1]=linea[1]/2;
    linea[2]=linea[2]/2;
    linea[3]=linea[3]/2;}
    for (int i=0; i<todox.size();i++)
    {
        todox[i]=todox[i]/2;
        todoy[i]=todoy[i]/2;
    } 
    paint=true;                                                                             //manda a dibujar
    }
     catch(...){Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Zoom out error");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
	}}

void reset(Fl_Widget* buttonptr){
     try{
     bound=boundz;
     coordx=coordxz;
     coordx2=coordxz2;
     coordy=coordyz;
     coordy2=coordyz2; 
     todox=todoxz;
     todoy=todoyz;
     if(paint2==true){
     linea=lineaz;}                                                                    //manda a dibujar
    }
     catch(...){Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Restore error");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
	}}

int main(int argc, char **argv) 
{
try{
// Create a window - width, height, label (=title)
Fl_Double_Window win(1000,700);
win.label("MAPAS");
// Set color of window to white
win.color(FL_WHITE);
// Begin adding children to this window
win.begin();
         //Create a button - x , y , width, height, label
       Fl_Button but(5,5,100,30,"OPEN");
       Fl_Button *buttonZoomIn = new Fl_Button(120,5,100,30,"ZOOM IN");
       Fl_Button *buttonReset = new Fl_Button(230,5,100,30,"RESET");
       Fl_Button *buttonZoomOut = new Fl_Button(340,5,100,30,"ZOOM OUT");
       Fl_Button *buttonUp = new Fl_Button(450,5,100,30,"UP");
       Fl_Button *buttonDown = new Fl_Button(560,5,100,30,"DOWN");
       Fl_Button *buttonLeft = new Fl_Button(670,5,100,30,"LEFT");
       Fl_Button *buttonRight = new Fl_Button(780,5,100,30,"RIGHT");
       Fl_Button *buttonGps = new Fl_Button(890,5,100,30,"GPS");
       //register callback function with this button
       buttonZoomIn->callback(zoomIn);
       buttonReset->callback(reset);
       buttonZoomOut->callback(zoomOut);
       buttonLeft->callback(left);
       buttonRight->callback(right);
       buttonUp->callback(up);
       buttonDown->callback(down);
       buttonGps->callback(gps_window);
       but.callback(open_window);  
       MyCanvas canvas(0,50,2000,2000);
       
// Stop adding children to this window
      
      win.end();
      win.resizable(win);
      // Display the window
      win.show();
      
      // Run and return
      return Fl::run();}
catch(...){
    Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Critical error");
	box->box(FL_UP_BOX);
	box->labelsize(24);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
    return Fl::run();}
}
