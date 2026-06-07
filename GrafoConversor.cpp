/**
 * @file GrafoConversor.cpp
 * @brief Implementación de la clase GrafoConversor y su motor de búsqueda BFS.
 * @author Diego Rojas Botello
 * @date 07/06/2026
 */

#include "Unidad.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <set>

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

double GrafoConversor::convertir(const std::string& origen, const std::string& destino, double valor) {
    if (listaAdyacencia.find(origen) == listaAdyacencia.end() || 
        listaAdyacencia.find(destino) == listaAdyacencia.end()) {
        return -1.0; 
    }

    if (origen == destino) return valor;

    std::queue<std::pair<std::string, double>> colaBusqueda;
    std::set<std::string> visitados;

    colaBusqueda.push({origen, 1.0});
    visitados.insert(origen);

    while (!colaBusqueda.empty()) {
        std::string unidadActual = colaBusqueda.front().first;
        double factorAcumulado = colaBusqueda.front().second;
        colaBusqueda.pop();

        if (unidadActual == destino) {
            return valor * factorAcumulado;
        }

        for (const auto& arista : listaAdyacencia[unidadActual]) {
            if (visitados.find(arista.destino) == visitados.end()) {
                visitados.insert(arista.destino);
                colaBusqueda.push({arista.destino, factorAcumulado * arista.factor});
            }
        }
    }

    return -1.0; 
}
