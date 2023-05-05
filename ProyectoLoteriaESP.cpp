#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//Desarrolladores: Jimena Rivera Sancho y Pedro Meléndez Miranda 
//Fecha:04/05/2023
//Versión: 1.0
//Objetivo del programa: Simular el sorteo de la promoción del premio acumulado de la loteria nacional de Costa Rica de manera eficaz.


using namespace std;
  
//Generación de número aleatoriamente

int genenarNum(int max){
	Sleep(500); //tiempo de generación de números
	srand(time(NULL));
	int num = rand() % max; //Se saca un número random con el valor del parámetro que se pasó y se guarda en la variable para retornarlo
	return num;
}

	//Cantidad de bolas con sus respectivos premios 
	
string generarPremio(int &bolDosmill,int &bolDosyMedmill,int &bolTresmill,int &bolCincomill,int &bolDiezmill,int &bolQuinmill,int &bolAcu,bool &acuSalio,int &montoAcu){ //se pasan todas las variables necesarias con un puntero para poder alterar su valor desde la función.
	srand(time(NULL));
	int opcion;
	string respPrem;
	bool premioSalio = false;
	
	
	while(premioSalio==false){
		opcion = genenarNum(7); //se llama la función de generar número aleatoriamente y se guarda en la variable el dato de retorno
		
		if (opcion==0 && bolDosmill!=0){
			respPrem="El premio es de 2.000.000";
			bolDosmill--; //se reduce el el valor de la variable a 1 menos
			premioSalio=true;//se pasa el valor atrue para que cierre el ciclo
		}
		if(opcion==1 && bolDosyMedmill!=0){
			respPrem="El premio es de 2.500.000";
			bolDosyMedmill--;
			premioSalio=true;
		}
		if(opcion==2 && bolTresmill!=0){
			respPrem="El premio es de 3.000.000";
			bolTresmill--;
			premioSalio=true;
		}
		if(opcion==3 && bolCincomill!=0){
			respPrem="El premio es de 5.000.000";
			bolCincomill--;
			premioSalio=true;
		}
		if(opcion==4 && bolDiezmill!=0){
			respPrem="El premio es de 10.000.000";
			bolDiezmill--;
			premioSalio=true;
		}
		if(opcion==5 && bolQuinmill!=0){
			respPrem="El premio es de 15.000.000";
			bolQuinmill--;
			premioSalio=true;
		}
		if(opcion==6 && acuSalio==false){
			respPrem="¡¡¡El premio es el Acumulado!!!";
			bolAcu--;
			premioSalio=true;
			acuSalio=true;
		}
	}
	
	
	return respPrem; //returna el valor de la variable segun el IF donde se hayan cumplido las condiciones dando así un premio
}

	//Agregar una segunda bolita al Acumulado
	
void agregarBolAcu(int i,int &bolAcu){//función para agregar una Bolita al acumulado si llega al sorteo 11
	if(i==11){
		bolAcu++;
	}
}

void verificarAcu(int &bolDosmill,int &bolDosyMedmill,int &bolTresmill,int &bolCincomill,int &bolDiezmill,int &bolQuinmill,int &bolAcu,bool &acuSalio,int &i,int &numSortAcu,int &montoAcu,int &bolExt,int &codSort){//esta función recibe todos los valores que deben ser reiniciados cuando sale el acumulado o despues del sorteo 21 y cada sorteo esta verificando si algo de esto ocurre
	if(acuSalio==true || i==22){
		bolDosmill = 10;
		bolDosyMedmill = 10;
		bolTresmill = 16;
		bolCincomill = 10;
		bolDiezmill = 2;
		bolQuinmill = 1;
		bolAcu= 1;
		acuSalio=false;
		i=1;
		codSort++;
		montoAcu=100;
		numSortAcu = 1;
		bolExt= bolDosmill+bolDosyMedmill+bolTresmill+bolCincomill+bolDiezmill+bolQuinmill;
	}
	
}

int main() {
	
	//Declaración de variables
	
	int opcMenu;
	int montoAcu=100;
	int numSortAcu = 1;
	int numSortLot = 1001;
	int bolDosmill = 10;
	int bolDosyMedmill = 10;
	int bolTresmill = 16;
	int bolCincomill = 10;
	int bolDiezmill = 2;
	int bolQuinmill = 1;
	int bolAcu= 1;
	int codSort=1;
	bool acuSalio=false;
	
	
	//Este ciclo repite la cantidad de veces que se debe jugar los sorteos sin que salga el acumulado, si llega a 22 se reinicia todo a su valor original
	
	for(int i=1;i<=22;i++){
		int bolExt= bolDosmill+bolDosyMedmill+bolTresmill+bolCincomill+bolDiezmill+bolQuinmill;
		
		agregarBolAcu(i, bolAcu);
		verificarAcu(bolDosmill,bolDosyMedmill,bolTresmill,bolCincomill,bolDiezmill,bolQuinmill,bolAcu,acuSalio,i,numSortAcu,montoAcu,bolExt,codSort);
		
		cout<<"El número de sorteo de acumulado es #"<<numSortAcu<<" y el numero de sorteo de loteria es #"<<numSortLot<<endl;
		cout<<"El código de sorteo es #"<<codSort<<"-"<<numSortAcu<<"-"<<numSortLot<<endl;
		cout<<endl;
		cout<<"*************************************************************************"<<endl;
		cout<<"*		El monto del acumulado esta en: "<<montoAcu<<" millones		*"<<endl;
		cout<<"*	Bolitas de acumulado: "<<bolAcu<<" y bolitas de premios extra: "<<bolExt<<"		*"<<endl;
		cout<<"*************************************************************************"<<endl;
		cout<<endl;
		cout<<"			Premios disponibles:			"<<endl;
		cout<<"		Premio: 2.000.000	Cantidad de bolas: "<<bolDosmill<<endl;
		cout<<"		Premio: 2.500.000	Cantidad de bolas: "<<bolDosyMedmill<<endl;
		cout<<"		Premio: 3.000.000	Cantidad de bolas: "<<bolTresmill<<endl;
		cout<<"		Premio: 5.000.000	Cantidad de bolas: "<<bolCincomill<<endl;
		cout<<"		Premio: 10.000.000 	Cantidad de bolas: "<<bolDiezmill<<endl;
		cout<<"		Premio: 15.000.000 	Cantidad de bolas: "<<bolQuinmill<<endl;
		cout<<"		Premio: Acumulado 	Cantidad de bolas: "<<bolAcu<<endl;
		cout<<endl;
		
		//Aumento del monto de Acumulado por sorteo
		
		if (i<11){
			cout<<"El número ganador es "<<genenarNum(100)<<" y la serie es "<<genenarNum(1000)<<endl;
			cout<<generarPremio(bolDosmill,bolDosyMedmill,bolTresmill,bolCincomill,bolDiezmill,bolQuinmill,bolAcu,acuSalio,montoAcu)<<endl;
			if(acuSalio==false){
				montoAcu=montoAcu+20;
				cout<<endl;
				cout<<"El monto del acumulado se aumenta en 20 millones"<<endl;
				cout<<"El monto del acumulado para el proximo sorteo es de: "<<montoAcu<<" millones."<<endl;
			}
			else{
				cout<<"Su premio es de: "<<montoAcu<<" millones."<<endl;
				cout<<endl;
				cout<<"¡¡¡Felicidades!!!"<<endl;
			}
			
		}
		else if(i<21){
			cout<<"Ganador #1: El número ganador es "<<genenarNum(100)<<" y la serie es "<<genenarNum(1000)<<endl;
			cout<<generarPremio(bolDosmill,bolDosyMedmill,bolTresmill,bolCincomill,bolDiezmill,bolQuinmill,bolAcu,acuSalio,montoAcu)<<endl;
			cout<<endl;
			cout<<"Premio #2: El número ganador es "<<genenarNum(100)<<" y la serie es "<<genenarNum(1000)<<endl;
			cout<<generarPremio(bolDosmill,bolDosyMedmill,bolTresmill,bolCincomill,bolDiezmill,bolQuinmill,bolAcu,acuSalio,montoAcu)<<endl;
			if(acuSalio==true){
				cout<<endl;
				cout<<endl;
				cout<<"El monto del acumulado ganado es: "<<montoAcu<<" millones."<<endl;
				cout<<"¡¡¡Felicidades!!!"<<endl;
			}
			else{
				montoAcu=montoAcu+30;
				cout<<endl;
				cout<<"El monto del acumulado se aumenta en 30 millones"<<endl;
				cout<<"El monto del acumulado para el proximo sorteo es de: "<<montoAcu<<" millones."<<endl;
			}
			
			
			
			//Sesenta ganadores aleatorios en el sorteo 21
		}
		else{
			montoAcu=montoAcu+30;
			cout<<"Premio de "<<montoAcu/60<<" millones por ganador."<<endl;
			cout<<endl;
			for(int i=1;i<=60;i++){
				cout<<"Ganador #"<<i<<": El número ganador es "<<genenarNum(100)<<" y la serie es "<<genenarNum(1000)<<endl;
				cout<<endl;
			}
			
		}
		
		numSortAcu++;
		numSortLot++;
		cout<<endl;
		cout<<"Ingrese 1 para ejecutar sorteo "<<endl;
		cout<<"Ingrese 2 para salir "<<endl;
		cout<<endl;
		cout<<"Ingrese su opción:  ";
		cin>>opcMenu;
		
		//El menú de elección para salir o ejecutar
		
		if(opcMenu==1){
			system("CLS()");
		}
		else if(opcMenu==2){
			system("CLS()");
			cout<<"Muchas gracias por participar.";
			break;
		}
		else{
			system("CLS()");
			cout<<"No ingreso una opción valida.";
			break;
		}
		
	
		
	}
	
	return 0;
}


