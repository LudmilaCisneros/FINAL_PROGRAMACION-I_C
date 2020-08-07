#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getString(char* array,char* mensaje,char* mensajeError,int min,int max,int intentos);
int utn_getInt(int* numero, char* mensaje,char* mensajeError,int rangoMin, int rangoMax);
int utn_isValidInt (char* string);
char utn_getChar(char* mensaje,char* mensajeError,char letra1, char letra2);
int utn_isValidName (char* string);
float utn_getFloat(float* numero, char* mensaje,char* mensajeError,float rangoMin, float rangoMax);
int utn_getFactorial(double* pFactorial, int numero);
float utn_sacarPromedio(double total, int contador);


#endif // UTN_H_INCLUDED
