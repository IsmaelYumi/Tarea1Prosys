#ifndef Funciones.h
#define Funciones.h
typedef struct usuario{
    char Nombre[15];
    int rol;
    char password[10];
}Usuario;
typedef struct  producto{
    char Nombre[15];
    char Categoria[15];
    char Marca[15];
    char Codigo[15];
    char Bodega[15];
    float PrecioCompra;
} Producto;
typedef struct {
    char Producto[10];
    char local[50];
    char vendedor[50];
    char fecha[20];
    float precioVenta;
    int cantidadVendida;
} Venta;
void IniciarUsuarios();
void IniciarProductos();
void IniciarVentas();
void RealizarVenta(Usuario usuario_actu);
void AdministrarUsuarios();
void AdministrarProductos();
void Hola();
#endif
