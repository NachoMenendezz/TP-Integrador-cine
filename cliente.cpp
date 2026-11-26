#include <iostream>
#include <ctime>
#include "cliente.h"
#include "funcionesGlobales.h"

#include "clsClientes.h"
#include "ArchivoCliente.h"

#include "clsFuncion.h"
#include "ArchivoFuncion.h"

#include "clsPelicula.h"
#include "ArchivoPeliculas.h"

#include "clsSala.h"
#include "ArchivoSala.h"

#include "clsTipoSala.h"
#include "ArchivoTipoSala.h"

#include "clsVentaEntrada.h"
#include "ArchivoVentaEntrada.h"

#include "clsFecha.h"

using namespace std;


bool funcionTieneHorarioDisponible(Fecha fechaFuncion, int horaFuncion)
{
    // time() lee el reloj del sistema. localtime() descompone ese valor
    // en la fecha y la hora locales de la computadora.
    time_t t = time(NULL);
    if (t == -1)
    {
        return false;
    }

    tm* ahora = localtime(&t);
    if (ahora == NULL)
    {
        return false;
    }

    // tm_mday ya trae el día del mes. tm_mon empieza en 0 para enero
    // y tm_year cuenta los años desde 1900.
    Fecha hoy(ahora->tm_mday, ahora->tm_mon + 1, ahora->tm_year + 1900);

    if (esPosterior(hoy, fechaFuncion))
    {
        return false;
    }

    if (esPosterior(fechaFuncion, hoy))
    {
        return true;
    }

    // Si ninguna fecha es posterior a la otra, la función es de hoy.
    // Como los horarios son en punto, alcanza con comparar tm_hour.
    // A las 20:15, por ejemplo, tm_hour vale 20 y la función de las 20 ya empezó.
    int horaActual = ahora->tm_hour;
    return horaFuncion > horaActual;
}


//COMPRA DE ENTRADAS COMPLETA

void realizarVenta()
{
    system("cls");
    cout << "========================================" << endl;
    cout << "          SELECCION DE PELICULA         " << endl;
    cout << "========================================" << endl;

    // 1. Usa la función global para seleccionar la película
    int idPelicula = seleccionarPelicula();
    if (idPelicula == -1)
    {
        return;
    }

    // 2. Busca los datos de la película seleccionada
    ArchivoPeliculas arcPel;
    int posPel = arcPel.buscarRegistro(idPelicula);
    Pelicula pelSel = arcPel.leerRegistro(posPel);

    cout << "\n=========================================================================" << endl;
    cout << " FUNCIONES DISPONIBLES PARA: " << pelSel.getNombrePelicula() << endl;
    cout << "=========================================================================" << endl;

    // 3. Busca y muestra todas las funciones activas de esa película
    ArchivoFuncion arcFunciones;
    ArchivoSala arcSalas;
    ArchivoTipoSala arcTipoSala;
    ArchivoVentaEntrada arcVentas;

    int totalFunciones = arcFunciones.contarRegistros();
    int encontradas = 0;

    for (int i = 0; i < totalFunciones; i++)
    {
        Funcion func = arcFunciones.leerRegistro(i);

        // El horario se comprueba antes de buscar la sala y calcular las butacas.
        if (func.getEstado() && func.getIdPelicula() == idPelicula
            && funcionTieneHorarioDisponible(func.getFechaFuncion(), func.getHoraFuncion()))
        {
            // Buscamos por número de sala y leemos por posición en el archivo.
            int posSala = arcSalas.buscarRegistro(func.getNumSala());
            if (posSala >= 0)
            {
                Sala sala = arcSalas.leerRegistro(posSala);
                if (sala.getEstado())
                {
                    int posTipo = arcTipoSala.buscarRegistro(sala.getTipoSala());
                    if (posTipo >= 0)
                    {
                        TipoSala ts = arcTipoSala.leerRegistro(posTipo);
                        if (ts.getEstado()&&ts.getPrecio()>0)
                        {
                            // Calcula las Butacas Libres
                            // La auxiliar suma las entradas vendidas para este ID de función.
                            int entradasVendidas = contarEntradasVendidasPorFuncion(func.getIdFuncion());
                            int butacasLibres = sala.getCapacidadTotal() - entradasVendidas;
                            if (butacasLibres > 0)
                            {
                                Fecha f = func.getFechaFuncion();

                                cout << "ID Func: " << func.getIdFuncion() << " | "
                                     << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << " | "
                                     << func.getHoraFuncion() << " hs | "
                                     << "Sala " << func.getNumSala() << " | "
                                     << ts.getDescSala() << " | "
                                     << butacasLibres << " lib. | $"
                                     << ts.getPrecio() << endl;

                                encontradas++;

                            }

                        }
                    }

                }
            }
        }
    }

    if (encontradas == 0) {
        cout << "NO HAY FUNCIONES DISPONIBLES PARA ESTA PELICULA." << endl;
        return;
    }

    cout << "-------------------------------------------------------------------------" << endl;

    //Selecciona la Función específica a la hora de comprar
    int idSeleccionado;
    cout << "\nINGRESE EL ID DE LA FUNCION A COMPRAR (0 para cancelar): ";
    cin >> idSeleccionado;

    if (idSeleccionado == 0) return;

    int posFuncSel = arcFunciones.buscarRegistro(idSeleccionado);
    if (posFuncSel < 0)
    {
        cout << "EL ID DE FUNCION INGRESADO NO EXISTE." << endl;
        return;
    }

    Funcion funcSel = arcFunciones.leerRegistro(posFuncSel);
    if (!funcSel.getEstado() || funcSel.getIdPelicula() != idPelicula)
    {
        cout << "LA FUNCION SELECCIONADA NO CORRESPONDE O NO SE ENCUENTRA ACTIVA." << endl;
        return;
    }

    // El cliente puede ingresar un ID que no apareció en el listado.
    // Revisamos el horario otra vez antes de continuar con la compra.
    if (!funcionTieneHorarioDisponible(funcSel.getFechaFuncion(), funcSel.getHoraFuncion()))
    {
        cout << "LA FUNCION SELECCIONADA NO ESTA DISPONIBLE POR SU HORARIO." << endl;
        return;
    }

    //Calcula disponibilidad y precio de la función elegida
    int posSalaSel = arcSalas.buscarRegistro(funcSel.getNumSala());
    if (posSalaSel<0)
    {
        cout<<"LA SALA SELECCIONADA NO ESTA DISPONIBLE";
        return;
    }
    Sala salaSel = arcSalas.leerRegistro(posSalaSel);
    if (!salaSel.getEstado())
    {
        cout<<"LA SALA SELECCIONADA ESTA DADA DE BAJA";
        return;
    }
    int posTipoSel = arcTipoSala.buscarRegistro(salaSel.getTipoSala());
    if (posTipoSel<0)
    {
        cout<<"NO SE ENCONTRO EL TIPO DE SALA DE ESTA FUNCION";
        return;
    }

    TipoSala tsSel = arcTipoSala.leerRegistro(posTipoSel);
    if (!tsSel.getEstado())
    {
        cout<<"EL TIPO DE SALA ESTA DADO DE BAJA";
        return;
    }
    if (tsSel.getPrecio()<=0)
    {
        cout<<"EL TIPO DE SALA NO TIENE UN PRECIO VALIDO";
        return;
    }
    int precioUnitario =tsSel.getPrecio();


    int entVendidasSel = contarEntradasVendidasPorFuncion(funcSel.getIdFuncion());
    int libresSel = salaSel.getCapacidadTotal() - entVendidasSel;

    if (libresSel <= 0)
    {
        cout << "\n¡LO SENTIMOS! LA FUNCION SELECCIONADA NO TIENE BUTACAS DISPONIBLES." << endl;
        return;
    }

    int cantEntradas;
    cout << "BUTACAS DISPONIBLES: " << libresSel << " | PRECIO POR ENTRADA: $" << precioUnitario << endl;
    cout << "INGRESE LA CANTIDAD DE ENTRADAS DESEADAS: ";
    cin >> cantEntradas;

    if (cantEntradas <= 0 || cantEntradas > libresSel)
    {
        cout << "CANTIDAD INVALIDA. NO HAY SUFICIENTES BUTACAS LIBRES." << endl;
        return;
    }

    int importeTotal = cantEntradas * precioUnitario;
    cout << "\n--> SUBTOTAL A PAGAR: $" << importeTotal << endl;

    // 6. DNI Cliente
    int dni;
    cout << "\nINGRESE SU DNI: ";
    cin >> dni;
    if (dni<=0){
        cout<<"EL NUMERO INGRESADO NO ES VALIDO"; return;
    }
    ArchivoCliente arcClientes;
    int posCliente = arcClientes.buscarRegistro(dni);
    Cliente nuevoCliente;
    if (posCliente < 0)
    {
        cout << "\n[CLIENTE NO ENCONTRADO EN SISTEMA. REGISTRANDO NUEVO CLIENTE...]" << endl;
        nuevoCliente.setDni(dni);
        nuevoCliente.Cargar();
    }
    else
    {
        Cliente cli = arcClientes.leerRegistro(posCliente);
        cout << "-> BIENVENIDO/A: " << cli.getNombreApellido() << endl;
    }

    // 7. Confirmación y grabado
    int confirmacion;
    cout << "\n¿DESEA CONFIRMAR LA COMPRA DE " << cantEntradas << " ENTRADA(S) POR $" << importeTotal << "? (1: SI / 2: NO): ";
    cin >> confirmacion;

    if (confirmacion != 1)
    {
        cout << "COMPRA CANCELADA POR EL USUARIO." << endl;
        return;
    }
    // Reusamos el resultado de la búsqueda del DNI. Recién después de
    // confirmar grabamos al cliente nuevo y luego guardamos la venta.
     if (posCliente < 0 ){
         if (arcClientes.grabarRegistro(nuevoCliente))
        {
            cout << "-> Cliente registrado con exito." << endl;
        }
        else
        {
            cout << "ERROR AL REGISTRAR EL CLIENTE." << endl;
            return;
        }
     }
    VentaEntrada nuevaVenta;
    int nuevoIdVenta = arcVentas.generarId();
    nuevaVenta.setIdVenta(nuevoIdVenta);
    nuevaVenta.setIdFuncion(funcSel.getIdFuncion());
    nuevaVenta.setDniComprador(dni);
    nuevaVenta.setCantEntradasVendidas(cantEntradas);
    nuevaVenta.setImporteTotal(importeTotal);

    // La fecha de compra se toma del sistema. La función puede ser otro día.
    Fecha hoy;
    hoy.setHoy();
    nuevaVenta.setDiaCompra(hoy);

    if (arcVentas.grabarRegistro(nuevaVenta))
    {
        cout << "\n=========================================================================" << endl;
        cout << "           ¡COMPRA COMPLETADA CON EXITO! (TICKET #" << nuevoIdVenta << ")          " << endl;
        cout << "=========================================================================" << endl;
        cout << " MONTO TOTAL PAGADO: $" << importeTotal << endl;
        cout << "=========================================================================" << endl;
    }
    else
    {
        cout << "ERROR AL GUARDAR LA VENTA EN EL ARCHIVO." << endl;
    }
}
