#ifndef MONEDAS_H
#define MONEDAS_H
#include <vector>
#include <algorithm>
#include <limits>

void monedas(const std::vector<int>& m, int d, std::vector<int>& s) {
    int n = m.size();
    int inf_val = std::numeric_limits<int>::max();
    
    // Matriz T de tamaño n x (d + 1) inicializada con -1 (representando None)
    std::vector<std::vector<int>> T(n, std::vector<int>(d + 1, -1));
    
    // Caso base
    T[0][0] = 0;
    
    // Cálculo de la primera fila
    for (int j = 1; j <= d; ++j) {
        if (j >= m[0] && T[0][j - m[0]] != -1) {
            T[0][j] = 1 + T[0][j - m[0]];
        }
    }
    
    // Cálculo del resto de filas
    for (int i = 1; i < n; ++i) {
        T[i][0] = 0;
        for (int j = 1; j <= d; ++j) {
            if (j < m[i] || T[i][j - m[i]] == -1) {
                T[i][j] = T[i - 1][j];
            } else if (T[i - 1][j] != -1) {
                T[i][j] = std::min(T[i - 1][j], 1 + T[i][j - m[i]]);
            } else {
                T[i][j] = 1 + T[i][j - m[i]];
            }
        }
    }
    
    // Recuperar la solución
    s.assign(n, 0);
    int i = n - 1;
    int j = d;
    while (i != 0 && j != 0) {
        if (i == 0 || T[i][j] != T[i - 1][j]) {
            s[i] = s[i] + 1;
            j = j - m[i];
        } else {
            i = i - 1;
        }
    }
    while (j > 0 && i == 0 && T[0][j] != -1) {
        s[0] = s[0] + 1;
        j = j - m[0];
    }
}

#endif
