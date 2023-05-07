#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
using namespace std;

const char *nombre_archivo = "archivo.dat";
struct Traductor
{

    char palabra[100];
    char traduccion[100];
    char descripcion[1000];
};
void Crear();
void Leer();
void Actualizar();
void Borrar();
void Traduccirr();
int main(int argc, char const *argv[])
{
   int op;
   do
   {
    system("cls");
    cout<<"INGRESE UNA OPCION"<<endl;
    cout<<" "<<endl;
    cout<<"1.INGRESAR PALABRAS"<<endl;
    cout<<"2.MOSTRAR CANTIDAD DE PALABRAS"<<endl;
    cout<<"3.MODIFICAR PALABRA"<<endl;
    cout<<"4.BORRAR PALABRA"<<endl;
    cout<<"5.TRADUCTOR DE CODIGO"<<endl;
    
    cout<<"ingresa una opcion: ";
    cin>>op;
    switch (op)
    {
    case 1:
        Crear();
         system("pause");
        break;
        case 2:
        Leer();
        system("pause");
        break;
        case 3:
        Actualizar();
        system("pause");
        break;
        case 4:
        Borrar();
        system("pause");
        break;
        case 5:
         Traduccirr();
        system("pause");
        break;

    default:
        break;
    }
    
   } while (op<=4 || op>=4);


    return 0;
}
void Crear(){
    system("cls");
     FILE* archivo = fopen(nombre_archivo, "a+b");
    char res;
    int tam=0;
    Traductor traductor;

    do
    {
        fflush(stdin);
        cin.ignore();
        cout<<"****************************"<<endl;
         cout<<"INGRESE PALABRA: ";
        cin.getline(traductor.palabra,100);
         cout<<"INGRESE TRADUCCION: ";
        cin.getline(traductor.traduccion,100);
         cout<<"INGRESE DESCRIPCION: ";
         cin.getline(traductor.descripcion,1000);
        fwrite(&traductor,sizeof(Traductor),1,archivo);
        cout<<"Ingresar otra palabra ( s ) o  ( n ): ";
        cin>>res;

    } while (res=='S' ||res=='s' );
    
    fclose(archivo);
}

 void Leer(){
    system("cls");
    FILE* archivo = fopen(nombre_archivo,"rb");
    if (!archivo)
    {
        archivo=fopen(nombre_archivo, "w+b");
       }
          Traductor traductor;
        int id=0;
        fread(&traductor,sizeof(Traductor),1, archivo);
        cout<<"_________________________________________"<<endl;
        cout<<" "<<endl;
        do
        {
             cout<<"NO. Palabra: "<<id<<endl;
            cout<<"Palabra: "<<traductor.palabra<<endl;
            cout<<"Traduccion: "<<traductor.traduccion<<endl;
            cout<<"Descripcion: "<<traductor.descripcion<<endl;
            cout<<"----------------------------------------------"<<endl;
            fread(&traductor,sizeof(Traductor),1, archivo);
            id+=1;
        } while (feof(archivo)==0);
        fclose(archivo);
    
       }

       void Actualizar(){
         system("cls");
	
	FILE* archivo = fopen(nombre_archivo,"r+b"); 
	 Traductor traductor;
	int id=0;
	cout<<"Ingrese el No. de palabra que desea Modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(Traductor),SEEK_SET);
		 cin.ignore();
         cout<<"INGRESE PALABRA: ";
        cin.getline(traductor.palabra,100);
         cout<<"INGRESE TRADUCCION: ";
        cin.getline(traductor.traduccion,100);
         cout<<"INGRESE DESCRIPCION: ";
         cin.getline(traductor.descripcion,1000);
        fwrite(&traductor,sizeof(Traductor),1,archivo);
	
	
	fclose(archivo);
}
void Borrar(){
     system("cls");
	const char *nombre_archivo_temp = "archivo_temp.dat";
	FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
	FILE* archivo = fopen(nombre_archivo,"rb");
	 Traductor traductor;
	int id=0,id_n=0;
	cout<<"Ingrese el No. de palabra para eliminar:";
	cin>>id;
	while(fread(&traductor,sizeof(Traductor),1,archivo)){
		if (id_n !=id ){
			fwrite(&traductor,sizeof(Traductor),1,archivo_temp);
		}
		id_n++;
	}
	fclose(archivo);
	fclose(archivo_temp);
	
	archivo_temp = fopen(nombre_archivo_temp,"rb");
	archivo = fopen(nombre_archivo,"wb");
	while(fread(&traductor,sizeof(Traductor),1,archivo_temp)){
		fwrite(&traductor,sizeof(Traductor),1,archivo);
		
	}
		fclose(archivo);
	fclose(archivo_temp);
	
}
   void Traduccirr(){
          system("cls");
    FILE* archivo = fopen(nombre_archivo,"rb");
    if (!archivo)
    {
        archivo=fopen(nombre_archivo, "w+b");
       }
          Traductor traductor;
          char res;
          char cadena[255];   
            char *p;
    char palabra[strlen(cadena)];
    int i,j;
        fread(&traductor,sizeof(Traductor),1, archivo);
        
      cout<<"Ingrese le codigo con cada palabra con espacios y para finalizar preciones '-> . <-'"<<endl;
      cout<<" "<<endl;
      
    cout<<"Ingrese codigo:"<<endl;
    cout<<" "<<endl;
    cin.get(cadena,255,'.');
    p = cadena;
    cout<<"_________________________________________"<<endl;
     while (*p !='\0')
     {
         
        while (*p== ' ' || *p== '\n'){p++;}
         
        strcpy(palabra, "" ); 
        i=0;
      
         while ((*p!=' ') && (*p!='\n') &&  (*p!='\0'))
        {
            
            palabra[i]=*p;
            i++;
            p++; 
           
 
        }
        j++;
        palabra[i] = '\0';
        while (feof(archivo)==0)
       {
         
          if(strcmp(palabra,traductor.palabra)==0){

                    strcpy(palabra, traductor.traduccion);
                      
                       }
                       
          i++;

           fread(&traductor,sizeof(Traductor),1, archivo);  
       }  
       rewind(archivo);
         while (feof(archivo)==0)
       {
         
          if(strcmp(palabra,traductor.palabra)==0){

                    strcpy(palabra, traductor.traduccion);
                      
                       }
                       
          i++;

           fread(&traductor,sizeof(Traductor),1, archivo);  
       }  
  
         cout<<palabra;
        if (*p == ' ')
            {
                  cout<<" ";
            }
             if (*p =='\n')
            {
                  cout<<endl;
            }
         }
        
  
     cout<<" "<<endl;
     cin.ignore();
             
         
                  
        fclose(archivo);
    
       }

            
