#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int numGana(){
	srand(time(NULL));
	int numPrem = rand() % 100;
	return numPrem;
}
int serGana(){
	srand(time(NULL));
	int serPrem = rand() % 1000;
	return serPrem;
}
	


	
int main() {
	//Declaración de variables
	int opcMenu;
	int montoAcu=100;
	int numSortAcu = 1;
	int numSortLot = 1001;
	//int premFinal;
	//int incrAcu;
	//int montSigSort;
	int bolDosmill = 10;
	int bolDosyMedmill = 10;
	int bolTresmill = 16;
	int bolCincomill = 10;
	int bolDiezmill = 2;
	int bolQuinmill = 1;
	int bolAcu= 1;
	
	
	
	for(int i=1;i<=21;i++){
		int bolExt= bolDosmill+bolDosyMedmill+bolTresmill+bolCincomill+bolDiezmill+bolQuinmill;
		
		
		
		cout<<"El numero de sorteo de acumulado es "<<numSortAcu<<" y el numero de sorteo de loteria es "<<numSortLot<<endl;
		cout<<endl;
		cout<<"El monto del acumulado esta en: "<<montoAcu<<" millones"<<endl;
		cout<<"Bolitas de acumulado: "<<bolAcu<<" y bolitas de premios extra: "<<bolExt<<endl;
		cout<<endl;
		cout<<"El número ganador es "<<numGana()<<" y la serie es "<<serGana()<<endl;
		cout<<endl;
		numSortAcu++;
		numSortLot++;
		cout<<"Ingrese 1 para ejecutar sorteo "<<endl;
		cout<<"Ingrese 2 para salir "<<endl;
		cout<<endl;
		cout<<"Ingrese su opción:  ";
		cin>>opcMenu;
		//Validación del Acumulado
		if (bolAcu==0){
			cout<<"Ya salió el acumulado, gracias por participar ";
			system("CLS()");
			break;
		}
			
		//Aumento del monto de Acumulado por sorteo
		if (i<11){
			montoAcu=montoAcu+20;
		}
		else{
			montoAcu=montoAcu+30;
		}
		//El menú de elección para salir o ejecutar
		if(opcMenu==1){
			system("CLS()");
		}
		else{
			system("CLS()");
			cout<<"Muchas gracias por participar.";
			break;
		}
		
		
	}
	
	//Ya no quedan sorteos
	cout<<"Muchas gracias por participar, ya no quedan premios.";
	
	
	
	return 0;
}


