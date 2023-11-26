#include<stdio.h>

int main(){
    FILE *archivo; // Declara un puntero a FILE
    char linea[100]; // Buffer para almacenar la línea leída

    // Abre el archivo en modo lectura ("r")
    archivo = fopen("Usuarios.txt", "r");

    // Verifica si el archivo se abrió correctamente
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1; // Sale del programa con un código de error
    }

    // Lee cada línea del archivo y la imprime en la consola
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }

    // Cierra el archivo después de usarlo
    fclose(archivo);

    return 0; // Indica que el programa se ejecutó correctamente
    
}