#include <iostream>
#include <stdlib.h>
using namespace std;

struct Producto
{
    string nombre;
    int codigo;
    int stock;
    int calificaciones = 0;
    int* lasCalificaciones = nullptr;
};

void cargar_productos(Producto* productos,int calificaciones[],int total_productos)
{
    for (int i = 0; i < total_productos; i++)
    {
        cout << "Ingrese el nombre del producto: "; cin >> productos[i].nombre;
        cout << "Ingrese el codigo del producto: "; cin >> productos[i].codigo;
        cout << "Ingrese el stock del producto: "; cin >> productos[i].stock;
        cout << "Ingrese cuantas calificaciones quiere para el producto: " << productos[i].nombre<<": "; cin>> calificaciones[i];
        productos[i].calificaciones = calificaciones[i];
        productos[i].lasCalificaciones = new int[calificaciones[i]];
        for (int j = 0; j < calificaciones[i]; j++) {
            cout << "Ingrese las " << calificaciones[i] << " calificaciones del producto: "<<productos[i].nombre<<": "; cin >> productos[i].lasCalificaciones[j];
        }
    }
}

void mostrar(Producto* producto,int calificaciones[],int cantidad_total_productos)
{
    for (int i=0;i<cantidad_total_productos;i++)
    {
        cout<<"Nombre producto: "<<producto[i].nombre<<endl;
        cout<<"Codigo producto: "<<producto[i].codigo<<endl;
        cout<<"Stock producto: "<<producto[i].stock<<endl;
        cout<<"Calificaciones del producto: "<<producto->calificaciones<<endl;
        cout<<"Las calificaciones son: "<<endl;
        for (int j=0;j< calificaciones[i];j++)
        {
            cout<<producto[i].lasCalificaciones[j]<<" ";
        }
    }
    cout<<endl;
}

void promedio_satisfaccion_producto(Producto* producto, int calificaciones[],int cantidad_total_productos)
{
    int divisor =0;
    float promedio = 0;

    for (int i=0;i<cantidad_total_productos;i++)
    {
        int total =0;
        for (int j=0;j<calificaciones[i];j++)
        {
            total += producto[i].lasCalificaciones[j];
        }
        divisor = producto[i].calificaciones;
        promedio = total / divisor;
        cout<<"El promedio de satisfaccion del producto: "<<producto[i].nombre<<", es: "<<promedio<<endl;
    }
}

void mayor_promedio_satisfaccion(Producto* producto, int calificaciones[],int cantidad_total_productos)
{
    int mayor = producto[0].calificaciones;
    string producto_nombre = producto[0].nombre;

    for (int i = 1; i < cantidad_total_productos; i++) {
        if (producto[i].calificaciones > mayor) {
            mayor = producto[i].calificaciones;
            producto_nombre = producto[i].nombre;
        }
    }
    cout<<"El producto con mayor promedio de satisfaccion es: "<<producto_nombre<<endl;
}

void producto_mayor_cantidad_calificaciones(Producto* producto, int calificaciones[],int cantidad_total_productos)
{
    int menor = producto[0].calificaciones;
    string producto_nombre = producto[0].nombre;

    for (int i = 1; i < cantidad_total_productos; i++) {
        if (producto[i].calificaciones < menor) {
            menor = producto[i].calificaciones;
            producto_nombre = producto[i].nombre;
        }
    }
    cout<<"El producto con menor cantidad de calificaciones es: "<<producto_nombre<<endl;
}

void menor_stock(Producto* producto, int calificaciones[],int cantidad_total_productos)
{
    string producto_nombre = producto->nombre;
    for (int i=0;i<cantidad_total_productos;i++)
    {
        int menor = producto[i].stock;
        for (int j=0;j<calificaciones[i];j++)
        {
            if (producto[i].stock<menor)
            {
                menor = producto[i].stock;
                producto_nombre = producto[i].nombre;
            }
        }
    }
    cout<<"El producto con menor stock es: "<<producto_nombre<<endl;
}

int main()
{
    int cantidad_total_productos;
    cout<<"Ingrese la cantidad total de productos: "; cin>>cantidad_total_productos;
    int calificaciones_productos[cantidad_total_productos];
    Producto* producto = new Producto[cantidad_total_productos];

    cargar_productos(producto,calificaciones_productos,cantidad_total_productos);
    cout<<endl;
    mostrar(producto,calificaciones_productos,cantidad_total_productos);
    promedio_satisfaccion_producto(producto,calificaciones_productos,cantidad_total_productos);
    mayor_promedio_satisfaccion(producto,calificaciones_productos,cantidad_total_productos);
    producto_mayor_cantidad_calificaciones(producto,calificaciones_productos,cantidad_total_productos);
    menor_stock(producto,calificaciones_productos,cantidad_total_productos);


    for (int i = 0; i < cantidad_total_productos; i++)
    {
        delete[] producto[i].lasCalificaciones;
    }

    delete[] producto;
    return 0;
}