#include <iostream>
#include <chrono>
#include <vector>
#include "../include/Solution.h"

void run_benchmark() {
    Solution sol;
    
    // Escenario de prueba pesado
    std::vector<std::vector<char>> board(10, std::vector<char>(10, 'a'));
    std::vector<std::string> words;
    for(int i = 0; i < 500; ++i) {
        words.push_back(std::string(5, 'a')); // 500 palabras de prueba
    }

    auto start = std::chrono::high_resolution_clock::now();
    
    sol.findWords(board, words);
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "--- Benchmark Resultados ---" << std::endl;
    std::cout << "Tiempo de ejecucion: " << duration.count() << " ms" << std::endl;
    std::cout << "Tamano del tablero: 10x10" << std::endl;
    std::cout << "Cantidad de palabras procesadas: " << words.size() << std::endl;
}

int main() {
    run_benchmark();
    return 0;
}