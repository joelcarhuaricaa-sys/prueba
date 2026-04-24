#include <iostream>
#include <cassert>
#include <algorithm>
#include "../include/Solution.h"

void test_caso_basico() {
    Solution sol;
    std::vector<std::vector<char>> board = {{'a','b'},{'c','d'}};
    std::vector<std::string> words = {"ab", "ac", "abcd", "dcba"};
    
    std::vector<std::string> res = sol.findWords(board, words);
    
    // Verificamos que encuentre las palabras (el orden puede variar)
    assert(res.size() == 2);
    assert(std::find(res.begin(), res.end(), "ab") != res.end());
    assert(std::find(res.begin(), res.end(), "ac") != res.end());
    std::cout << "[PASSED] Test Caso Basico" << std::endl;
}

void test_sin_coincidencias() {
    Solution sol;
    std::vector<std::vector<char>> board = {{'x','y'},{'z','w'}};
    std::vector<std::string> words = {"hola", "mundo"};
    
    std::vector<std::string> res = sol.findWords(board, words);
    
    assert(res.empty());
    std::cout << "[PASSED] Test Sin Coincidencias" << std::endl;
}

void test_palabra_larga() {
    Solution sol;
    std::vector<std::vector<char>> board = {{'a','b','c'}};
    std::vector<std::string> words = {"abcd"}; // Mas larga que el tablero
    
    std::vector<std::string> res = sol.findWords(board, words);
    
    assert(res.empty());
    std::cout << "[PASSED] Test Palabra Fuera de Limites" << std::endl;
}

int main() {
    std::cout << "--- Ejecutando Pruebas Unitarias ---" << std::endl;
    test_caso_basico();
    test_sin_coincidencias();
    test_palabra_larga();
    std::cout << "--- Todas las pruebas pasaron con exito ---" << std::endl;
    return 0;
}