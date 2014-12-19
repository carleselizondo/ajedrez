
//INCLUSIÓ DE LLIBRERIES
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

//DEFINICIÓ DE CONSTANTS
#define FIL 8
#define COL 8
#define RES ' ' 

//DECLARACIO DE VARIABLES
int i, j, fitxa, fil=0, col=0, h=8;
int pos_fil, pos_col;
char tabl[FIL+1] [COL+1]={' '};


//FUNCIONES
//1. funcion mostrar tablero
void dibujar_tablero(){
printf("\n   ");
for(col=1;col<=h;col++)
{
	printf( "%c%i",RES, col);
}
	printf("\n");
	for(fil=1;fil<=h;fil++)
{
	printf( " %c%i ",RES, fil);
	

	for(col=1; col<=h;col++)
	{
		printf("%c ", tabl[fil] [col]);	
	}
	printf("%i\n", fil);
}
printf("   ");
for(col=1;col<=h;col++)
{
	printf( "%c%i",RES, col);
}

}

//2. funcion errors de files
void errors_fil(){
	if(fil==0)
		printf("La fila no pot ser 0\n\n");
	if(fil>=9)
		printf("La fila no pot ser major de 8\n\n");
	if(fil<0)
		printf("La fila no pot ser un numero negatiu\n\n");	
}
//funcio 3 errors de columnes
void errors_col(){
	if(col==0)
		printf("La columna no pot ser 0\n\n");
	if(col>=9)
		printf("La columna no pot ser major de 8\n\n");
	if(col<0)
		printf("la columna no pot ser un numero negatiu\n\n");
}
//funcio 4. tablero net
void tablero_net(){
	for(fil=1;fil<=8;fil++){
		for(col=1;col<=8;col++){
		tabl[fil][col]=' ';
		}
	}
}

//funcion 5. moviment torre
void mov_torre(){
	while(fil<=8 && col<=8){	
		fil++;
		if(tabl[fil][col]==' ')
			tabl[fil][col]='*';
		else
			break;
		}
	fil=pos_fil; col=pos_col;	
	while(fil<=8 && col<=8){	
		col++;
		if(tabl[fil][col]==' ')
		tabl[fil][col]='*';
		else
			break;
	}
	fil=pos_fil; col=pos_col;
	while(fil>=1 && col>=1){	
		col--;
		if(tabl[fil][col]==' ')
		tabl[fil][col]='*';
		else
			break;
		
	}
	fil=pos_fil; col=pos_col;
	while(fil>=1 && col>=1){	
		fil--;
		if(tabl[fil][col]==' ')
		tabl[fil][col]='*';
		else
			break;
	}
	fil=pos_fil; col=pos_col;
}
//funcio 6. moviment alfil
void mov_alfil(){
	while(fil<=8 && col<=8){	
		fil++; col++;
		if(tabl[fil][col]==' ')
		tabl[fil][col]='*';
		else
			break;
	}
	fil=pos_fil; col=pos_col;	
	
	while(fil>=1 && col<=8){	
		fil--; col++;
		if(tabl[fil][col]==' ')
		tabl[fil][col]='*';
		else
			break;
	}
	fil=pos_fil; col=pos_col;
	
	while(fil<=8 && col>=1){	
		fil++; col--;
		if(tabl[fil][col]==' ')
		tabl[fil][col]='*';
		else
			break;
	}
	fil=pos_fil; col=pos_col;
	
	while(fil>=1 && col>=1){	
		fil--; col--;
		if(tabl[fil][col]==' ')
		tabl[fil][col]='*';
		else
			break;
	}
	fil=pos_fil; col=pos_col;	
}
//funcio 7. moviment del rei
void mov_rei(){
	if(fil<8 && tabl[fil+1][col]==' '){
		tabl[fil+1][col]='*';
	}
	fil=pos_fil; col=pos_col;	
	if(col<8 && tabl[fil][col+1]==' '){	
		tabl[fil][col+1]='*';
	}
	fil=pos_fil; col=pos_col;
	if(col>1 && tabl[fil][col-1]==' '){
		tabl[fil][col-1]='*';
	}
	fil=pos_fil; col=pos_col;
	if(fil>1 && tabl[fil-1][col]==' '){
		tabl[fil-1][col]='*';
	}
	fil=pos_fil; col=pos_col;
	if(fil<8 && col<8 && tabl[fil+1][col+1]==' '){
		tabl[fil+1][col+1]='*';
	}
	fil=pos_fil; col=pos_col;	
	if(fil>1 && col<8 && tabl[fil-1][col+1]==' '){
		tabl[fil-1][col+1]='*';
	}
	fil=pos_fil; col=pos_col;
	if(fil<8 && col>1 && tabl[fil+1][col-1]==' '){
		tabl[fil+1][col-1]='*';
	}
	fil=pos_fil; col=pos_col;
	if(fil>1 && col>1 && tabl[fil-1][col-1]==' '){
		tabl[fil-1][col-1]='*';
	}
	fil=pos_fil; col=pos_col;	
}
//funcio 8. moviment del cavall
void mov_cavall(){
	if(fil>=2 && col<=6 && tabl[fil-1][col+2]==' '){	
		tabl[fil-1][col+2]='*';
	}
	fil=pos_fil; col=pos_col;	
	if(fil>=3 && col<=7 && tabl[fil-2][col+1]==' '){	
		tabl[fil-2][col+1]='*';
	}
	fil=pos_fil; col=pos_col;
	if(fil>=2 && col>=3 && tabl[fil-1][col-2]==' '){	
		tabl[fil-1][col-2]='*';
	}
	fil=pos_fil; col=pos_col;	
	if(fil>=3 && col>=2 && tabl[fil-2][col-1]==' '){	
		tabl[fil-2][col-1]='*';
	}
	fil=pos_fil; col=pos_col;
	if(fil<=6 && col>=2 && tabl[fil+2][col-1]==' '){	
		tabl[fil+2][col-1]='*';
	}
	fil=pos_fil; col=pos_col;
	if(fil<=7 && col>=3 && tabl[fil+1][col-2]==' '){	
		tabl[fil+1][col-2]='*';
	}
	fil=pos_fil; col=pos_col;
	if(fil<=7 && col<=6 && tabl[fil+1][col+2]==' '){	
		tabl[fil+1][col+2]='*';
	}
	fil=pos_fil; col=pos_col;	
	if(fil<=6 && col<=7 && tabl[fil+2][col+1]==' '){	
		tabl[fil+2][col+1]='*';
	}	
}
//funcio 9. lloc ocupat per un obstacle
void lloc_ocupat(){
	if (tabl[fil] [col]=='#'||tabl[fil][col]=='C'||tabl[fil][col]=='T'||tabl[fil][col]=='D'||tabl[fil][col]=='R'||tabl[fil][col]=='A'){
		printf("Ups! Ho sent molt, pero eixe lloc esta ocupat.\n");
		printf("Tria un altre.\n");
	}
}
//funcio 11. lloc ocupat per una peça
void pieza_ocupada(){
	if (tabl[fil] [col]=='#'||tabl[fil][col]=='C'||tabl[fil][col]=='T'||tabl[fil][col]=='D'||tabl[fil][col]=='R'||tabl[fil][col]=='A'){
		printf("Ups! Ho sent molt, pero eixe lloc esta ocupat.\n");
		printf("Tria un altre.\n");
	}
}
//funcio 12. borrar moviments 



void borrar_mov(){
	for(fil=1;fil<=8;fil++){
		for(col=1;col<=8;col++){
		if(tabl[fil][col]=='*'){
			tabl[fil][col]=' ';
			}
		}
	}
}

int main(){
	
//DECLARACION DE VARIABLES
int opcion, fitxa;
int obst_col, obst_fil;
char sino;

	//funcio 4.
	tablero_net();
	do{
	//funcion 1.
	dibujar_tablero();	
		printf("\n \n");
		//MENU DE COSES QUE ES PODEN FER
		printf("\n\n");
		printf("TABLERO DE ESCACS\n");
		printf("-------------------------------------\n");
     	printf("1. Mostrar els moviments d'una fitxa\n");
     	printf("2. Posar impediments\n");
     	printf("3. Esborrar tauler\n");
     	printf("4. Eixir\n");
     	printf("-------------------------------------\n");
     	printf("\n\n - ");
 		printf("Tria el numero d'una opcio: "); scanf("%i", &opcion); 
        fflush(stdin); 	
		
	    //EXECUTEM L'OPCIO ESCOLLIDA
        switch (opcion){
         		//Demanar fitxa
				 case 1: 
				
				 //do{	
				 	printf("\n");
					printf("FITXES DE ESCACS\n");
					printf("-------------------------------------\n");
			     	printf("1. TORRE\n");
			     	printf("2. ALFIL\n");
			     	printf("3. DAMA\n");
			     	printf("4. REI\n");
			     	printf("5. CAVALL\n");
			     	printf("6. EIXIR\n");
			     	printf("-------------------------------------\n");
			     	printf("\n");
				    printf("Tria el numero d''una fitxa: "); scanf("%i", &fitxa);
					fflush(stdin);
					printf("\n");
					
					

					switch(fitxa){
						// TORRE
						case 1:
							
							borrar_mov(); //funcio 12.
							printf(" # TORRE #\n");
							printf("-----------------------------\n");
							do{
							
								do{
									printf("\nEn quina fila vols colocar-la?\n ");
									scanf("%i", &fil);
									fflush(stdin);
									//funcio 2
									errors_fil();
								} while (fil<=0 || fil>=9);
								printf("Molt be!\n");		
								do{
									printf("\nEn quina columna vols colocar-la?\n ");
									scanf("%i", &col);
									fflush(stdin);
									//funcio 3
									errors_col();
								} while (col<=0 || col>=9);	
									//funcio 9
									lloc_ocupat();	
							}while(tabl[fil][col]!=' ');
							tabl[fil][col]='T';
							//guardem la possicio
							pos_fil=fil; pos_col=col;
							mov_torre(); //funcion 5.
							system("cls"); // neteja la pantalla
						break;
						
						// ALFIL
						case 2:
							borrar_mov(); //funcio 12.
							printf(" # ALFIL #\n");
							printf("-----------------------------\n");
						do{
													
								do{
									printf("\nEn quina fila vols colocar-la?\n ");
									scanf("%i", &fil);
									fflush(stdin);
									//funcio 2
									errors_fil();
								} while (fil<=0 || fil>=9);		
								printf("Molt be!\n");			
								do{
									printf("\nEn quina columna vols colocar-la?\n ");
									scanf("%i", &col);
									fflush(stdin);
									//funcio 3
									errors_col();
								} while (col<=0 || col>=9);	
							//funcio 9
									lloc_ocupat();	
						}while(tabl[fil][col]!=' ');	
							tabl[fil] [col]='A';
							//guardem la possicio
							pos_fil=fil; pos_col=col;
							//funcio 6
							mov_alfil();
							system("cls"); // neteja la pantalla
						break;
						
						// DAMA
						case 3:
							borrar_mov(); //funcio 12.
							printf(" # DAMA #\n");
							printf("-----------------------------\n");
							do{
							
								do{
									printf("\nEn quina fila vols colocar-la?\n ");
									scanf("%i", &fil);
									fflush(stdin);
									//funcio 2
									errors_fil();
								} while (fil<=0 || fil>=9);		
								printf("Molt be!\n");			
								do{
									printf("\nEn quina columna vols colocar-la?\n ");
									scanf("%i", &col);
									fflush(stdin);
									//funcio 3
									errors_col();
								} while (col<=0 || col>=9);	
								//funcio 9
								lloc_ocupat();	
							}while(tabl[fil][col]!=' ');							
							tabl[fil] [col]='D';
							//guardem la possicio
							pos_fil=fil; pos_col=col;
							//funcio 5 i 6
							mov_torre();
							mov_alfil();
							system("cls"); // neteja la pantalla
						break;
						
						// REI
						case 4:
							borrar_mov(); //funcio 12.
							printf(" # REI #\n");
							printf("-----------------------------\n");
						do{
						
								do{
									printf("\nEn quina fila vols colocar-la?\n ");
									scanf("%i", &fil);
									fflush(stdin);
									//funcio 2
									errors_fil();
								} while (fil<=0 || fil>=9);		
								
								printf("Molt be!\n");		
								do{
									printf("\nEn quina columna vols colocar-la?\n ");
									scanf("%i", &col);
									fflush(stdin);
									//funcio 3
									errors_col();
								} while (col<=0 || col>=9);	
							//funcio 9
								lloc_ocupat();	
						}while(tabl[fil][col]!=' ');
							tabl[fil] [col]='R';
							//guardem la possicio
							pos_fil=fil; pos_col=col;
							//funcio 7 
							mov_rei();
							system("cls"); // neteja la pantalla
						break;
						
						// CAVALL
						case 5:
							borrar_mov(); //funcio 12.
							printf(" # CAVALL #\n");
							printf("-----------------------------\n");
						do{
						
								do{
									printf("\nEn quina fila vols colocar-la?\n ");
									scanf("%i", &fil);
									fflush(stdin);
									//funcio 2
									errors_fil();
								} while (fil<=0 || fil>=9);		
								printf("Molt be!\n");		
								do{
									printf("\nEn quina columna vols colocar-la?\n ");
									scanf("%i", &col);
									fflush(stdin);
									//funcio 3
									errors_col();
								} while (col<=0 || col>=9);		
							//funcio 9
								lloc_ocupat();	
						}while(tabl[fil][col]!=' ');
							tabl[fil] [col]='C';
							//guardem la possicio
							pos_fil=fil; pos_col=col;
							//funcio 8
							mov_cavall();
							system("cls"); // neteja la pantalla
						break;
						
						//EIXIR
						case 6:
							printf("Adeu!");
							getch();
							borrar_mov(); //funcio 12.
							system("cls"); // neteja la pantalla
						break;
						
						default:
							printf("Opcio incorrecta");
							getch();

					}// final del switch de fitxa
					break;
				 //POSAR ELS IMPEDIMENTS
				 case 2:
				 	do{
				 		do{
				 			do{
								printf("\nEn quina fila vols colocar l'obstacle'?\n - ");
								scanf("%i", &fil);
								fflush(stdin);
								//funcio 2
								errors_fil();
						 	}while (fil<=0 || fil>=9);			
						 		printf("Molt be!\n");				
							do{
								printf("\nEn quina columna?\n - ");
								scanf("%i", &col);
								fflush(stdin);
								//funcio 3
								errors_col();
						 	} while (col<=0 || col>=9);	
							//funcio 11
							pieza_ocupada();	
						}while (tabl[fil][col]=='T' || tabl[fil][col]=='D' || tabl[fil][col]=='A' || tabl[fil][col]=='R' || tabl[fil][col]=='C');	
							printf("Perfecte!\n\n");						
							tabl[fil] [col]='#';
							printf("Vols ficar un altre obstacle?\n");
							printf("Indica s/n - ");
							scanf("%c", &sino);
							fflush(stdin);
							if(sino=='s'){
								printf("Cap problema\n");
							}
							else{
								printf("Adeu!");
							}
					}while(sino=='s');
					system("cls"); // neteja la pantalla	
				 	break;
				 
				 //ESBORRAR TAULES
				 case 3:
				 	printf("Estas segur que ho vols borrar tot? Indica s/n \n");
				 	scanf("%c", &sino);
				 	fflush(stdin);
				 	if (sino=='s'){
				 		tablero_net();
					}
				 	else {
					 }
				 	system("cls"); // neteja la pantalla
				break;
			
				 //EIXIR
				 case 4:
				 	printf("Adeu!");
				 	break;
						
				 default:
				 printf("Opcio incorrecta");
				 getch();
		} //final del switch de opció
	}while(opcion!=4); //FINAL DEL BUCLE QUE REPETEIX EL MENU
getch();
return 0;	
} // FINAL DEL PROGRAMA
