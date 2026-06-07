/**
 * @file GrafoConversor.cpp
 * @brief Implementación de la clase GrafoConversor para la gestión de unidades.
 * @author Tu Nombre y Equipo
 * @date 2026
 */

#include "Unidad.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

// Usaremos un mapa interno para simular la lista de adyacencia del grafo:
// Cada unidad (string) se asocia con un vector de Aristas (sus conexiones).
std::map<std::string, std::vector<Arista>> listaAdyacencia;

/**
 * @brief Constructor por defecto de GrafoConversor.
 */
GrafoConversor::GrafoConversor() {
    // Inicialización vacía por ahora
}

/**
 * @brief Agrega una nueva unidad (Nodo) al mapa si no existe.
 * @param nombre Nombre de la unidad (ej. "m", "cm", "inch").
 */
void GrafoConversor::agregarUnidad(const std::string& nombre) {
    // Si la unidad no existe en el mapa, la insertamos con un vector vacío
    if (listaAdyacencia.find(nombre) == listaAdyacencia.end()) {
        listaAdyacencia[nombre] = std::vector<Arista>();
    }
}

/**
 * @brief Agrega una conversión directa (Arista) de una unidad a otra.
 * @param origen Unidad desde la que se convierte.
 * @param destino Unidad a la que se llega.
 * @param factor Valor multiplicador de la conversión.
 */
void GrafoConversor::agregarConversion(const std::string& origen, const std::string& destino, double factor) {
    // Nos aseguramos de que ambos nodos existan en el grafo
    agregarUnidad(origen);
    agregarUnidad(destino);
    
    // Creamos la conexión dirigida desde el origen hacia el destino
    Arista nuevaConexion(destino, factor);
    listaAdyacencia[origen].push_back(nuevaConexion);
    
    // Como bonus, agregamos la conversión inversa automáticamente (1 / factor)
    // para hacer el grafo más inteligente y conectado.
    if (factor != 0.0) {
        Arista conexionInversa(origen, 1.0 / factor);
        listaAdyacencia[destino].push_back(conexionInversa);
    }
}
