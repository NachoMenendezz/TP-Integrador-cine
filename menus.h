#ifndef MENUS_H_INCLUDED#define MENUS_H_INCLUDED// Menús Principales y de Nivelvoid menuPrincipal();void menuEmpleado();void menuCliente();// Submenú Empleadovoid menuGestionDatos();void menuListados();void menuConsultas();void menuInformes();// Submenús ABM (Gestión de Datos)void menuPeliculas();void menuGeneros();void menuSalas();void menuTipoSalas();void menuFunciones();// Funciones ABM - Películasvoid agregarPelicula();void bajaPelicula();void modificarPelicula();void listarPeliculas();// Funciones ABM - Génerosvoid agregarTipoGenero();void bajaTipoGenero();void modificarTipoGenero();void listarTipoGeneros();// Funciones ABM - Salasvoid agregarSala();void bajaSala();void modificarSala();void listarSalas();// Funciones ABM - Tipos de Salavoid agregarTipoSala();void bajaTipoSala();void modificarTipoSala();void listarTipoSalas();// Funciones ABM - Funcionesvoid agregarFuncion();void bajaFuncion();void modificarFuncion();void listarFunciones();

// Submenu de listados

void subMenuListarPeliculas();
void subMenuListarGeneros();
void subMenuListarSalas();
void subMenuListarTiposSala();
void subMenuListarFunciones();
void subMenuListarClientes();
void subMenuListarVentas();

//Submenu de consultas

void subMenuConsultaPeliculas();
void subMenuConsultaSalas();
void subMenuConsultaFunciones();
void subMenuConsultaClientes();
void subMenuListarVentas();
// Submenú y Procesos Clientevoid realizarVenta();void consultarComprasCliente();

// Funciones globales
int seleccionarFuncion();
int seleccionarGenero();
int seleccionarPelicula();
int seleccionarSala();
int seleccionarTipoSala();#endif // MENUS_H_INCLUDED