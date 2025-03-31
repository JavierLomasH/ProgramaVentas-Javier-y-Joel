#include <stdio.h>
#include <ctype.h>

int main() {
    int id, stock, cantidad, opcion, stockmas;
    float descuento,precio, total_ganancias = 0;
    char nombre[30];

    // Registro del producto
    printf("Ingrese el ID del producto: ");
    scanf("%d", &id);
    
    printf("Ingrese el nombre del producto: ");
    fgets(nombre, sizeof nombre, stdin);
    fgets(nombre, sizeof nombre, stdin);

    while(1){
        printf("Ingrese la cantidad inicial en stock: ");        
        if (scanf("%d", &stock) == 1 && stock > 0){
            break;
        }        
        printf("Entrada inválida.\nIntente nuevamente.\n");        
        while (getchar() != '\n'); //esto es magia >:)
    }
    
    while(1){
        printf("Ingrese el precio unitario del producto: ");        
        if (scanf("%f", &precio) == 1 && precio > 0){
            break;
        }        
        printf("Entrada inválida.\nIntente nuevamente: \n");        
        while (getchar() != '\n'); 
    }
    

    do{
        printf("_______________________________________\n");
        printf("\nMenú de Opciones:\n");
        printf("1. Ingresar descuento\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar información del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("_______________________________________\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                while(1){
                    printf("Ingrese descuento: ");        
                    if (scanf("%f", &descuento) == 1 && descuento >= 0){
                        break;
                    }        
                    printf("Descuento inválido.\nIntente nuevamente: \n");        
                    while (getchar() != '\n'); 
                }
                printf("se aplicara %.0f %% de descuento en las proximas compras\n",descuento);
                break;
            case 2 :
                printf("Ingrese la cantidad a vender: ");
                scanf("%d", &cantidad);
                while (cantidad>stock){
                    printf("\nError\nLa cantidad a vender es mayor al stock");
                    printf("\nIngrese la cantidad a vender: ");
                    scanf("%d", &cantidad);
                }
                
                stock=stock-cantidad;
                
                total_ganancias=total_ganancias+(cantidad*(precio-(precio*(descuento/100))));
                printf("El stock es ahora %d\n",stock);
                break;
                
            case 3:
                printf("Ingrese la cantidad a agregar al stock: ");
                scanf("%d", &stockmas);
                while (stockmas<=0)
                {
                    printf("\nError\nLa cantidad a agregar debe ser mayor a 0");
                    printf("\nIngrese la cantidad a agregar: ");
                    scanf("%d", &stockmas);
                }
                stock=stock+stockmas;
                printf("El stock es ahora %d\n",stock);
                break;
                
            case 4:
                printf("\nInformación del producto:\n");
                printf("ID: %d\n", id);
                printf("Nombre: %s\n", nombre);
                printf("Stock disponible: %d\n", stock);
                printf("Precio unitario: %.2f\n", precio);
                break;
                
            case 5:
                printf("Total de ganancias: $%.2f\n", total_ganancias);
                break;
                
            case 6:
                printf("Saliendo del programa...\n");
                break;
                
            default:
                printf("Error");
                printf("\nOpción inválida. Intente nuevamente.\n");
                
        }
        while (getchar() != '\n'); 
    } while (opcion != 6);

    return 0;

}
