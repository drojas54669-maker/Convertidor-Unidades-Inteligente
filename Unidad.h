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
#include <map>

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
    std::map<std::string, std::vector<Arista>> listaAdyacencia; /**< Lista de adyacencia del grafo */
    
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

    /**
     * @brief Convierte un valor de una unidad origen a una destino usando BFS.
     * @param origen Unidad de entrada.
     * @param destino Unidad de salida deseada.
     * @param valor Cantidad numérica a transformar.
     * @return El valor convertido. Si no hay ruta, retorna -1.0.
     */
    double convertir(const std::string& origen, const std::string& destino, double valor);
};

#endif // UNIDAD_H
