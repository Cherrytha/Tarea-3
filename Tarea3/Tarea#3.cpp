#include <pthread.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fstream>

 using namespace std;
void lectura();
int flag[3];
int turn;
const int MAX = 3;
int ans = 0;
 int option;

void lock_init()
{
    
    flag[0] = flag[1] = 0;
    turn = 0;
}
 

void lock(int self)
{
 
    flag[self] = 1;

    turn = 1-self;
 
    while (flag[1-self] == 1 && turn == 1 -self) ;
  
}

void unlock(int self)
{
    
    flag[self] = 0;
}
 

// función para crear los dos hilos para los dos subprocesos creados
// en principal()
void* func_crear(void *s)
{
	int posi1;
	int posi2;
	int memoria;
    int i = 0;
    int *self = (int *)s;
    //int *self = s;
    cout << "                    " << endl;
cout << "**********************************************************************************************************************" << endl;
cout << "                                            MENU PRINCIPAL DE PROCESOS                                  " << endl;
cout << "**********************************************************************************************************************" << endl;
cout << ("\n");
cout << ("\n");
 
    //printf("Hilo creado: %d\n", self);
    
    for (int veces = 0; veces <= MAX; veces++ );
    {
	    void lock(int self);
	    if (lock)
	    {
		    printf("Bloqueo exitoso %d\n", getpid);
		    sleep(3);	
		}

cout << ("\n");
cout << ("\n");
cout << "1.Posicion Inicial:";
cin  >>posi1;
cout << "2.Proceso Final:";
cin  >>posi2;
cout << "3.Tamano de la memoria a reservar (5-11):";
cin  >>memoria;

cout << ("\n");
cout << ("\n");

cout << ("\n");
cout << ("\n");






}
        
    	void unlock(int self);
    	if (unlock)
    	{
			printf("DesBloqueo exitoso %d\n", getpid);
			sleep(3);
		}
       	return 0;
	}
   

 

 
// Funcion principal
int main()
{	
lectura();  
cout << ("\n");
cout << ("\n");
 pthread_t Texto;
    // Inicializó el bloqueo y luego bifurcó el hilo
	lock_init();
 
    // Crea  hilo
    pthread_create(&Texto, NULL, func_crear, (void*)0);
    
 
    // Espere a que termine el hilo
    pthread_join(Texto, NULL);
   
 
    
    
 
    return 0;
}

//lectura de archivo
void lectura(){
	ifstream archivo;
	string texto;
	archivo.open("C:\\tarea3\\TEXTO.txt", ios::in);
	if (archivo.fail()){
		cout<<"Error al abrir el archivo";
		exit(1);
	}
	
	
	
	while(!archivo.eof()){
		getline(archivo, texto);
		cout<<texto<<endl;
	}
	
	archivo.close();
}
// mythread.h (Un archivo de encabezado contenedor para las 
// declaraciones)
#ifndef __MYTHREADS_h__
#define __MYTHREADS_h__
#include <pthread.h>
#include <assert.h>
#include <sched.h>
 
void Pthread_mutex_lock(pthread_mutex_t *m)
{
    int rc = pthread_mutex_lock(m);
    assert(rc == 0);
}
                                                                                 
void Pthread_mutex_unlock(pthread_mutex_t *m)
{
    int rc = pthread_mutex_unlock(m);
    assert(rc == 0);
}
                                                                                 
void Pthread_create(pthread_t *thread, const pthread_attr_t *attr,    
           void *(*start_routine)(void*), void *arg)
{
    int rc = pthread_create(thread, attr, start_routine, arg);
    assert(rc == 0);
}
 
void Pthread_join(pthread_t thread, void **value_ptr)
{
    int rc = pthread_join(thread, value_ptr);
    assert(rc == 0);
}
 
#endif // __MYTHREADS_h__