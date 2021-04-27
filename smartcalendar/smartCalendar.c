#include <stdio.h>
#include <stdlib.h>

int main()

{
   int options, diaNum, mesNum, i;
   char r;

   char diaRef[10]="Jueves";  //nombre correspondiente al último día, anterior al 1/1/2021
   
   char dias [7][10] = {"Jueves", "Viernes", "Sabado", "Domingo", "Lunes", "Martes", "Miercoles"};
   char meses [12][15] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
   int cantDias [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


   printf ("Bienvenido a Smart Calendar v1.0\n");
   printf ("Le informaremos el nombre del día ingresado... \n");

   do 

   {

      printf ("\nIntroduzca una fecha:\n");

      do

      {

         printf ("Mes: ");
         scanf ("%d", &mesNum);
            
      }

      while (mesNum < 1 || mesNum > 12);
      
      do

      {
         
         printf ("Dia: ");
         scanf ("%d", &diaNum);     

      }

      while (diaNum < 1 || diaNum > cantDias [mesNum - 1]);



      for (i = 0; i < mesNum; i++)    /*Sumar la cantidad de dias hasta el mes que corresponda*/
      
      {
                                       
         cantDias [i];
         

      }
      

      printf ("\nLa fecha %d/%d/2021 fue/será %s \n", diaNum, mesNum, dias [diaNum % 7]);


      printf ("\nDesea que infomemos el día de otra fecha? y/n: ");
      scanf (" %c", &r);


      printf ("\n=======================================================================\n");

   }

   while (r == 'y');

   return 0;

}