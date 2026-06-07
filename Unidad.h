/**
 * @file Unidad.h
 * @brief Definición de las estructuras de datos para el convertidor basado en grafos.
 * @author Diego Rojas Botello
 * @date 07/06/2026
 */

#ifndef UNIDAD_H
#define UNIDAD_H

#include <string>
#include <vector>

/**
 * @struct Arista
 * @brief Representa una conexión dirigida entre dos unidades (un factor de conversión).
 */
struct Arista {
    std::string destino; /**< Nombre de la unidad destino (ej. "cm") */
    double factor;       /**< Factor multiplicador para la conversión (ej. 100.0) */

    /**
     * @brief Constructor de la estructura Arista.
     * @param dest Unidad de destino.
     * @param fac Factor de conversión.
     */
    Arista(std::string dest, double fac) : destino(dest), factor(fac) {}
};

/**
 * @class GrafoConversor
 * @brief Clase que gestiona las unidades de medida y calcula sus conversiones mediante rutas.
 */
class GrafoConversor {
private:
    // En el siguiente paso añadiremos la lista de adyacencia y lógica interna.
    
public:
    /**
     * @brief Constructor por defecto del grafo.
     */
    GrafoConversor();

    /**
     * @brief Agrega una nueva unidad al sistema (Nodo).
     * @param nombre Nombre único de la unidad (ej. "metros").
     */
    void agregarUnidad(const std::string& nombre);

    /**
     * @brief Agrega una conversión directa entre dos unidades (Arista dirigida).
     * @param origen Unidad de partida.
     * @param destino Unidad de llegada.
     * @param factor Valor por el que se multiplica para convertir de origen a destino.
     */
    void agregarConversion(const std::string& origen, const std::string& destino, double factor);
};

#endif // UNIDAD_H
