#include <vector>
#include <algorithm>
#include "monedas.h"

int mochila(const std::vector<int>& p, const std::vector<int>& b, int m, std::vector<int>& s) {
    int n = p.size();
    // T[i][w] almacena el beneficio máximo con los primeros i elementos y capacidad w
    std::vector<std::vector<int>> T(n + 1, std::vector<int>(m + 1, 0));
    
    // Construcción de la tabla
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= m; ++w) {
            if (p[i - 1] <= w) {
                T[i][w] = std::max(T[i - 1][w], T[i - 1][w - p[i - 1]] + b[i - 1]);
            } else {
                T[i][w] = T[i - 1][w];
            }
        }
    }
    
    // Recuperar la solución (vector s indicando 1 si se eligió, 0 si no)
    s.assign(n, 0);
    int temp_w = m;
    for (int i = n; i > 0; --i) {
        if (T[i][temp_w] != T[i - 1][temp_w]) {
            s[i - 1] = 1;
            temp_w -= p[i - 1];
        } else {
            s[i - 1] = 0;
        }
    }
    
    // Retorna el beneficio máximo
    return T[n][m];
}
