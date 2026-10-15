#ifndef DYV_H
#define DYV_H

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<utility>

template <typename T>
int partition(std::vector<T>& v, int ini, int fin){
	T pivote = v[fin];
	int i = ini;
	for(int j = ini; j<fin;j++){
		if (v[j] <= pivote){
			std::swap(v[i],v[j]);
			i = i + 1;
		}
	}
	std::swap(v[i],v[fin]);
		return i;
	}

template<typename T>
int busquedaBinaria(const T& x, const std::vector<T>& v,int ini,int fin){
    if(ini > fin){
	    std::cout<<"No se encuentra en el array."<<std::endl;
        return -1;
    }
    int medio = ini +(fin - ini)/2;
    if(v[medio] == x){
        return medio;
    }else if(v[medio] > x){
	return busquedaBinaria(x,v,ini,medio - 1);
    }else{
	    return busquedaBinaria(x,v,medio + 1,fin);
    } 
}

template <typename T>
void quicksort(std::vector<T>& v, int ini, int fin){
	if(ini < fin){
		int pivote = partition(v, ini, fin);
		quicksort(v, ini, pivote - 1);
		quicksort(v, pivote + 1, fin);
	}
}

#endif


