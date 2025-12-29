---
date: '2025-12-28T23:17:52-06:00'
title: 'The Last Digit - SPOJ - Teoria de Numeros'
---
En resumen, el [problema](https://www.spoj.com/problems/LASTDIG/en/) es el siguiente:
> *Encontrar el ultimo digito de $a^b$ tal que $0<=a<=20$ y $0<=b<=2,147,483,000$*
Como detalle extra *a* y *b* no pueden ser 0 a la vez ($0^0$ **ESTO NO**).

Al principio resultaba fácil, supuse que con fuerza bruta lo resolvia, hasta que leí esa ultima restriccion de *b* (Solo imaginemos calcular $20^{2147483000}$). Si lo hacemos asi, la complejidad seria $O(b)$, Como se ve, NO es nada optimo.

## Explicacion de la solucion
Primero, ¿Como calculamos el ultimo digito de un numero $n$?, sencillo, con $n\ mod\ 10$ el resultado de dicha operación es aquel último digito.
Peroo, hay un detalle, como lo mencioné anteriormente, calcular $a^b$ conlleva una complejidad algoritmica muy ineficiente para las restricciones del problema... Entonces?.

Aqui es donde entra la *exponenciacion binaria* (Tambien conocida como *potenciación por cuadrados*) el cual es un algoritmo eficiente para calcular $a^b$ en tiempo logaritmico! $O(log(b))$.

Funciona diviendo el exponente a la mitad repetidamente y usando la expansion binaria del exponente, de forma MUUUY resumida e informal, este algoritmo calcula las potencias *base 2* y multiplica entre ellas aquellas en donde el bit de $b$ sea un $1$ :p (Dejo un [video](https://www.youtube.com/watch?v=8r4-5k-o1QE) en donde lo explica genial).

Esto que quiere decir?, si b es $1000000000$ a este algoritmo le tomaria 30 operaciones llegar al resultado, debido a que dicho numero solo tiene 30 bits :p.

El algoritmo es el siguiente:
$$
a^b = \begin{cases} 
1 & \text{si } b = 0 \\
(a^{b/2})^2 & \text{si } b \text{ es par} \\
a^{b-1} \cdot a & \text{si } b \text{ es impar}
\end{cases}
$$

El codigo en C++ es el siguiente:
```cpp
long long binpow(long long a, long long b, long long m){
    if(b==0) return 1;
    if(b%2) return binpow(a,b-1,m) * a%m;
    long long r = binpow(a,b/2,m);
    return r*r% m;
}
```
> Hay otro codigo un poco mas sencillo y mas interesante!, hace uso de bits:), sin embargo, aun estoy trabajando en el :p, requiere entender bitmasking.

Por ultimo, solo seria llamar a la funcion con los respectivos datos Y USAR $m = 10$, para que nos de el ultimo digito en tiempo logaritmico.

## Codigo 
```cpp
#include<bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b, long long m){
    if(b==0) return 1;
    if(b%2) return binpow(a,b-1,m) * a%m;
    long long r = binpow(a,b/2,m);
    return r*r% m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<binpow(a,b,10)<<'\n';
    }
        return 0;
}
```