#include "Funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
Usuario ListaUsuario[10];
Producto ListaProductos[10];
int numVentas=0;
int j=0;
void IniciarUsuarios(){
    FILE*archivo;
        char caracteres[50];
        char datos[3][15];
        char *token; 
        archivo=fopen("Usuarios.txt","r");
        if (archivo == NULL)
    {
       printf("Archivo no encontrado");
       exit(1);
    }
   
 	        while(fgets(caracteres,sizeof(caracteres),archivo)!=NULL){
            int i =0;
            token = strtok(caracteres, ",");
            while(token!=NULL && i<3){
            strcpy(datos[i],token);
            token=strtok(NULL,",");
            i++;
            }
            if(i==3){
                strcpy(ListaUsuario[j].Nombre,datos[0]);
                ListaUsuario[j].rol=atoi(&datos[1]);
                strcpy(ListaUsuario[j].password,datos[2]);
                j++;

             }
            }
                
                 fclose(archivo);
                 
        }
void InicializarProductos(){
    j=0;
    FILE*archivo;
        char caracteres[50];
        char datos[6][15];
        char *token; 
        archivo=fopen("Productos.txt","r");
        if (archivo == NULL)
    {
       printf("Archivo no encontrado");
       exit(1);
    }
   
 	        while(fgets(caracteres,sizeof(caracteres),archivo)!=NULL){
            int i =0;
            token = strtok(caracteres, ",");
            while(token!=NULL && i<3){
            strcpy(datos[i],token);
            token=strtok(NULL,",");
            i++;
            }
            if(i==3){
                strcpy(ListaProductos[j].Nombre,datos[0]);
                strcpy(ListaProductos[j].Categoria,datos[1]);
                strcpy(ListaProductos[j].Marca,datos[2]);
                strcpy(ListaProductos[j].Nombre,datos[3]);
                strcpy(ListaProductos[j].Nombre,datos[4]);
                ListaProductos[j].Nombre=atof(datos[5]);
                j++;

             }
            }
                
                 fclose(archivo);
                 
        }
void Hola(){
    for (int i =0; i<j ;i++){
        printf("Nombre: %s,rol: %i,Contraseña: %s",usua[i].Nombre,ListaUsuario[i].rol,ListaUsuario[i].password);
    }
}
void RealizarVenta(Usuario usuario_actual){

    if (numProductos == 0) {
        printf("No hay productos disponibles para la venta.\n");
        return;
    }

    // Mostrar los productos disponibles
    printf("Productos disponibles:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("%d. %s\n", i + 1, ListaProductos[i].nombre);
    }

    int productoSeleccionado;
    printf("Seleccione un producto para la venta (1-%d): ", numProductos);
    scanf("%d", &productoSeleccionado);

    if (productoSeleccionado < 1 || productoSeleccionado > numProductos) {
        printf("Selección de producto no válida.\n");
        return;
    }

    int cantidadVendida;
    printf("Ingrese la cantidad vendida: ");
    scanf("%d", &cantidadVendida);

    if (cantidadVendida <= 0 || cantidadVendida > ListaProductos[productoSeleccionado - 1].bodega) {
        printf("Cantidad no válida o insuficiente en bodega.\n");
        return;
    }

    // Registrar la venta
    Venta venta;
    strcpy(venta.local, "Local1");  // Simulación de local
    strcpy(venta.vendedor, usuario_actual.Nombre);  // Simulación de vendedor
    strcpy(venta.Producto,ListaProductos[productoSeleccionado - 1].Nombre)
    venta.precioVenta = ListaProductos[productoSeleccionado - 1].precioCompra * 1.2; // Ejemplo de precio de venta
    venta.cantidadVendida = cantidadVendida;
    ventas[numVentas] = venta;
    // Actualizar la cantidad en bodega
    productos[productoSeleccionado - 1].bodega -= cantidadVendida;
    FILE *archivo; // Declara un puntero a FILE

    // Abre el archivo en modo escritura ("w")
    archivo = fopen("Ventas.txt", "w");

    // Verifica si el archivo se abrió correctamente
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1; // Sale del programa con un código de error
    }

    // Escribe en el archivo
    fprintf(archivo,"%s,%s\n",usuario_actual.Nombre,venta.Producto);
    // Cierra el archivo después de escribir
    fclose(archivo);


    printf("Venta registrada con éxito.\n");

}
bool ValidarUsuario(Usuario usuario_act){
    for (int i=0; i<j; i++;){
        if(ListaUsuario[i].Nombre==usuario_act.Nombre && ListaUsuario[i].password==usuario_act.password){
            usuario_act.rol= ListaUsuario[i].rol;
            return true;
        }
      
    }
    return false;

}


       
