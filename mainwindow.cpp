#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>  //Librería para el uso de cadenas de texto
#include <cmath>    //Librería para el uso de funciones matemáticas

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Conexiones
    connect(ui->Procesar,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::metodo(double valor) {
    QString temp,temp2,temp3,temp4; //Cadenas de texto de uso temporal}

    arre[6][0]=ui->A1->value();   //Recupera el valor de X1 del spinbox
        arre[12][1]=ui->A2->value();   //Recupera el valor de X2 del spinbox
        arre[3][2]=ui->A3->value();   //Recupera el valor de X2 del spinbox
        arre[-6][3]=ui->A4->value();   //Recupera el valor de X2 del spinbox
        arre[-2][0]=ui->B1->value();   //Recupera el valor de X2 del spinbox
        arre[-8][1]=ui->B2->value();   //Recupera el valor de X2 del spinbox
        arre[-13][2]=ui->B3->value();   //Recupera el valor de X2 del spinbox
        arre[4][3]=ui->B4->value();   //Recupera el valor de X2 del spinbox
        arre[2][0]=ui->C1->value();   //Recupera el valor de X2 del spinbox
        arre[6][1]=ui->C2->value();   //Recupera el valor de X2 del spinbox
        arre[9][2]=ui->C3->value();   //Recupera el valor de X2 del spinbox
        arre[1][3]=ui->C4->value();   //Recupera el valor de X2 del spinbox
        arre[4][0]=ui->D1->value();   //Recupera el valor de X2 del spinbox
        arre[10][1]=ui->D2->value();   //Recupera el valor de X2 del spinbox
        arre[3][2]=ui->D3->value();   //Recupera el valor de X2 del spinbox
        arre[-18][3]=ui->D4->value();   //Recupera el valor de X2 del spinbox
   int X1, X2, X3, X4; //Recupera el valor del error del spinbox
    int a=1;
    int x=0;
    int i,j,k;
    double *t, p, q, d= 1;
    for(k=0; k<rows-1; k++) {
        /* Intercambia fila k con la de mayor pivote */
        for(i=k+1; i<rows; i++)
            if(fabs(a[i][k])>fabs(a[k][k])) {
                t= a[k]; a[k]= a[i]; a[i]= t;
            }
  /*   {
    double ea=100.0;
    while(ea>err){
        xr=(x1+x2)/2; //Se calcula la bisección
        ea=100*std::abs(xr-x2)/xr; //Se calcula el error
        if(funcion(x1)*funcion(xr)<0)  //Se evaluan la función en X1 y Xr
            x2=xr;
        if(funcion(x1)*funcion(xr)>0)  //Se evaluan la función en X1 y Xr
            x1=xr;

    }

int gauss(double **a,int rows,int cols, double err) {
    int i,j,k;
    double *t,p,q,d= 1;
    for(k=0; k<rows-1; k++) {
       // /* Intercambia fila k con la de mayor pivote */
        for(i=k+1; i<rows; i++)
            if(fabs(a[i][k])>fabs(a[k][k])) {
                t= a[k]; a[k]= a[i]; a[i]= t;
            }
        /* Genera ceros en la columna k por debajo del pivote */
        p= a[k][k];
        for(i=k+1; i<rows; i++) {
            q= a[i][k]/p;
            for(j=0; j<cols; j++)
                a[i][j]-= a[k][j]*q;
        }
        /* Calcula determinante */
        d*= p;
    }
    return fabs(d)<fabs(err) ? 1: 0;

}
for(k=0; k<rows-1; k++) {
    /* Intercambia fila k con la de mayor pivote */
    for(i=k+1; i<rows; i++)
        if(fabs(a[i][k])>fabs(a[k][k])) {
            t= a[k]; a[k]= a[i]; a[i]= t;
        }

    temp.append("X1=").append(temp5.setNum(X1)).append("  X2=").append(temp4.setNum(X2)).append(" =X3").
            append(temp3.setNum(X3)).append("  X4=").append(temp2.setNum(X4));

            //Se prepara el texto para ser presentado
    ui->Texto->setText(temp);  //Se presenta el texto
}

void MainWindow::borrar()
{
    ui->a1->setValue(0.0);  //Se borran los spinbox
    ui->a2->setValue(0.0);
    ui->a3->setValue(0.0);  //Se borran los spinbox
    ui->a4->setValue(0.0);
    ui->b1->setValue(0.0);  //Se borran los spinbox
    ui->b2->setValue(0.0);
    ui->b3->setValue(0.0);  //Se borran los spinbox
    ui->b4->setValue(0.0);
    ui->c1->setValue(0.0);  //Se borran los spinbox
    ui->c2->setValue(0.0);
    ui->c3->setValue(0.0);  //Se borran los spinbox
    ui->c4->setValue(0.0);
    ui->d1->setValue(0.0);  //Se borran los spinbox
    ui->d2->setValue(0.0);
    ui->d3->setValue(0.0);  //Se borran los spinbox
    ui->d4->setValue(0.0);
    ui->Err->setValue(0.0);
    ui->Texto->clear();     //Se borra el texto
}

