/**
 * @file GrafoConversor.cpp
 * @brief Implementación de la clase GrafoConversor y su motor de búsqueda BFS.
 * @author Tu Nombre y Equipo
 * @date 2026
 */

#include "Unidad.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <set>

// Lista de adyacencia global del sistema
std::map<std::string, std::vector<Arista>> listaAdyacencia;

GrafoConversor::GrafoConversor() {}

void GrafoConversor::agregarUnidad(const std::string& nombre) {
    if (listaAdyacencia.find(nombre) == listaAdyacencia.end()) {
        listaAdyacencia[nombre] = std::vector<Arista>();
    }
}

void GrafoConversor::agregarConversion(const std::string& origen, const std::string& destino, double factor) {
    agregarUnidad(origen);
    agregarUnidad(destino);
    listaAdyacencia[origen].push_back(Arista(destino, factor));
    if (factor != 0.0) {
        listaAdyacencia[destino].push_back(Arista(origen, 1.0 / factor));
    }
}

/**
 * @brief Encuentra la ruta óptima de conversión mediante Breadth-First Search (BFS).
 * @details El algoritmo explora los nodos por niveles garantizando el camino más corto.
 */
double GrafoConversor::convertir(const std::string& origen, const std::string& destino, double valor) {
    // Si alguna de las unidades no existe, no se puede realizar la conversión
    if (listaAdyacencia.find(origen) == listaAdyacencia.end() || 
        listaAdyacencia.find(destino) == listaAdyacencia.end()) {
        return -1.0; 
    }

    // Si el origen y destino son iguales, el valor no cambia
    if (origen == destino) return valor;

    // Cola para el BFS: guarda pares de (Unidad Actual, Factor Acumulado hasta el momento)
    std::queue<std::pair<std::string, double>> colaBusqueda;
    
    // Conjunto para evitar procesar el mismo nodo dos veces (evita ciclos infinitos)
    std::set<std::string> visitados;

    // Inicializamos la búsqueda con el nodo origen y un factor acumulado de 1.0
    colaBusqueda.push({origen, 1.0});
    visitados.insert(origen);

    while (!colaBusqueda.empty()) {
        std::string unidadActual = colaBusqueda.front().first;
        double factorAcumulado = colaBusqueda.front().second;
        colaBusqueda.pop();

        // ¡Encontramos el camino al destino!
        if (unidadActual == destino) {
            return valor * factorAcumulado;
        }

        // Explorar los vecinos (conversiones directas disponibles)
        for (const auto& arista : listaAdyacencia[unidadActual]) {
            if (visitados.find(arista.destino) == visitados.end()) {
                visitados.insert(arista.destino);
                // Al pasar al siguiente nodo, multiplicamos el factor acumulado por el de la arista
                colaBusqueda.push({arista.destino, factorAcumulado * arista.factor});
            }
        }
    }

    // Si la cola se vacía y no encontramos el destino, significa que no hay conexión
    return -1.0; 
}
