---
date: '2025-12-25T21:44:06-06:00'
draft: true
title: 'LargestRectangleInHistogram'
---
# Por fin
Despues de muchisimo tiempo, al fin logré resolver este problema tan divertido jajaja
Si desde un inicio hubiera investigado sobre que es una pila monótona y haber practicado con ella este problema hubiese sido muchisimo mas sencillo.
Sin embargo, agradezco el no haberlo hecho, pues aprendi muchisimo sobre otras Estructuras de Datos:).

Por lo pronto solo dejo el codigo de la solucion para LeetCode, el de SPOJ no difiere mucho, solo usamos long long en vez de int para el resultado y evaluamos varios casos en vez de uno solo.

```cpp
class Solution {
public:

vector<int> nse(vector<int> a){
    int i;
    unordered_map<int,int> um;
    stack<pair<int,int>> s;
    int n = a.size();
    // what hahaha
    // hice lo mismo que pse:p, solo cambie la forma de recorrer *a* jajaja
    for(i=a.size()-1;i>=0;i--){
        int x = a[i];
        while(!s.empty() && s.top().first>=x){
            s.pop(); 
        }
        if(!s.empty() && s.top().first<x) um[i] = s.top().second+1;
        s.push({x,i});
    }

    vector<int> sol(a.size(),n+1);
    for(i=0;i<a.size();i++){
        if(um.count(i)) sol[i] = um[i];
    }
    return sol;}

vector<int> pse(vector<int> a){
    int i;
    int n = a.size();
    unordered_map<int,int> um;
    stack<pair<int,int>> s;
    //         valor,pos
    // Recorremos de inico a fin
    for(i=0;i<a.size();i++){
        int x = a[i];
        // Si tenemos algo en s y este es mayor igual a lo actual...
        while(!s.empty() && s.top().first>=x){
            s.pop(); // lo sacamos!, hasta encontrar uno < x
        }
        // Si s no esta vacia y el tope es <= x, listo!, PSE encontrado:)
        if(!s.empty() && s.top().first<x) um[i] = s.top().second+1; // OJOO, estamos usando 1-based indexing xD
        s.push({x,i});
     }
    vector<int> sol(a.size(),0);
    for(i=0;i<a.size();i++){
        if(um.count(i)) sol[i] = um[i];
    }
    return sol;

}
// Como manejamos repetidos?, recuerda que estas usando almcacenando por mapa, aquello involucra claves hash
// En este caso, lo unico son las posiciones (0,1,2,3,..,n-1)
// si um almacena <pos,pos_PSE>, entoncessss...
// 

// Si no hay un PSE o un NSE podemos usar -1 para indicarlo, gracias a las restricciones del problemaaaa:))
int largestRectangleArea(vector<int>& heights) {
    int sol = INT_MIN, n = heights.size(),i;
    vector<int> a = heights;
    vector<int> NSE = nse(heights);
    vector<int> PSE = pse(heights);
    // cout<<"NSE: ";
    // for(int &x:NSE) cout<<x<<' ';
    // cout<<'\n';
    // cout<<"PSE: ";
    // for(int &x:PSE) cout<<x<<' ';
    // cout<<'\n';
    int j;
    for(j=0;j<n;j++){
        i=j+1;
        int h = heights[j];
        sol = max(sol,h*(NSE[j]-PSE[j]-1));
    }

    return sol;

}};
```