---
date: '2025-11-20'
draft: false
title: 'Codeforces- Contest1065 Analisis'
---

![Pinguino](/images/pinguino_pensando.webp)

# Introduccion
Participar en este contest fue todo un reto y no lo digo el problemset, lamentablemente llegue un poco mas de 15 minutos despues de que iniciara (9:05AM aprox) *mal mal*. La razon principal a esto es porque tuve que caminar un largo tramo para llegar a la escuela, cosa que no tenia previsto pero bueno, no habia nada que hacer, solo caminar rapido para tratar de llegar a tiempo.
Otro detalle es que resolvia mientras estaba en clase jajaja, el estar haciendo apuntes, pensar en las preguntas del maestro, en el problema, etc. Afortunadamente *quiero pensar* que el maestro no se dio cuenta:p.
Lamentablemente solo resolvi 2 problemas (A,B), el ultimo casi a 30 minutos de terminar la competencia 😞.
Bueno, el analisis a los problemas es el siguiente:

## A. Shizuku Hoshikawa and Farm Legs
El problema es el siguiente:

At Farmer John's farm, Shizuku counts *n* legs. It is known that only chickens and cows live on the farm; a chicken has 2 legs, while a cow has 4.

Count how many different configurations of Farmer John's farm are possible. Two configurations are considered different if they contain either a different number of chickens, a different number of cows, or both.

Note that Farmer John's farm may contain zero chickens or zero cows.

**Input**
The first line contains a single integer $t\ (1<=t<=100)$ - the number of test case
The only line of each test case contains a single integer $n\ (1<=n<=100).$

**Output**
For each test case, output a single integer, the number of different configurations of Farmer John's farm that are possible.

### Detalles a destacar.
La palabra *It is known that* en Codeforces esta como un hipervinculo que nos redirige a un problema bastante similar! [A. Legs](https://codeforces.com/contest/1996/problem/A). Para ese problema tenemos que encontrar la cantidad minima de animales que viven en la granja :p, sabiendo que las vacas tienen 4 patas y los pollos 2. Cabe destacar que *n* siempre es par. 
La solucion es: 
*n* es multiplo de 4?
- Si: sol = $\frac{n}{4}$. Todas vacas
- No: sol = $\frac{n-2}{4}$. 
- Simplificando: sol = $\frac{n+2}{4}$. Porque?. Primero, indendientemente de que *n* sea o no divisible entre 4, al sumarle 2 a *n* hacemos que al hacer la division, esta incluya las patas de la vacas y la de los pollos, sin depender de que 4 divida exactamente a *n*. De forma simple, hacemos un *empujon* a *n* con el fin de que si la division tuviera residuo, esta se aproxime a un divisor de 4 y en caso de que no haya residuo, no se redondaria al proximo divisor de 4.
  
  
Dicho problema es *casi* el mismo planteamiento, con la diferencia de que en el actual problema nos pide la cantidad de *diferentes* configuraciones posibles.
### ¿Que significa *configuraciones posibles*?
Dos configuraciones son diferentes si ambas tienen una cantidad diferente de pollos, de vacas o ambas. Tambien es importante destacar que pueden exisitir 0 vacas o 0 pollos
Casos simple:
$$
n = 8, \text{Configuraciones: 3 (2 Vacas, 4 Pollos, 1 Vaca y 2 Pollos)}\\
n = 4, \text{Configuraciones: 2 (1 Vaca, 2 Pollos)}\\
n = 14, \text{Configuraciones: 4 (3 Vacas y 1 Pollo, 7 Pollos, 2 Vacas y 3 Pollos, 1 Vaca y 5 Pollos)}
$$

Lo pueden ver?, hay detalles importantes para resolver el problema y es saber ¿Cuantas vacas caben en n? y otro importante, cada vez que quitamos una vaca, se suman dos pollos! jjsjsjs, pero, solo es suficiente con saber cuantas vacas caben en n y tomar en cuenta el caso de 0 vacas!. Entonces, formalmente la respuesta seria
$$sol=\frac{n}{4}$$

### Observacion

**Peroooo...**, esto solo funciona cuando *n* es par! ¿Porque?, veamos que pasa cuando sumamos la cantidad de patas que puede haber en total:
$$
 4v + 2p = x, \text{Donde v es vacas y p es pollos}\\
 \text{Notese que x siempre sera par debido a la suma de productos pares:)}
$$
Por lo tanto, no podemos tener a *n* como impar ya que esto implicaria que haya *una patita de mas*, UNA SOLA ¿De quien?, no se, un pollito sin patita o una vaca sin 3 patitas, quizas, pero el problema no menciona eso jajaja. Ademas, al inicio de problema se menciona eso y que solo viven vacas y pollos. listo!

### Errores
Envie 2 soluciones, la primera incorrecta, ¿Cual fue mi error?, tenia el *caso base* $Si x=3 : sol = 0$, cosa que es incorrecta jajaja, pero, porque hice eso?. *Mal analisis del problema y por las prisas de resolverlo rapido*, no pense en otros casos y no analice lo suficientemente bien el problema en casos no pares, ademas de que al inicio no habia entendido tan bien el detalle de configuraciones y como dato extra, llegue a la respuesta de $\frac{n}{4}+1$ a pura observacion de los ejemplos jajaja.


## B. Yuu Koito and Minimum Absolute Sum
[Link](https://codeforces.com/contest/2171/problem/B)
El problema es el siguiente:
> You are given a partially filled array of nonnegative integers $a_1, a_2, \dots, a_n$, where blank elements are denoted with $-1$. You would like to fill in the blank elements with nonnegative integers, such that the absolute value of the sum of the elements in its difference array is minimized.
>
> More formally, let $b$ be the array of length $n - 1$ such that $b_i = a_{i+1} - a_i$ for all $1 \le i \le n - 1$. Find the minimum possible value of $|b_1 + b_2 + \dots + b_{n-1}|$, across all possible ways to fill in the blank elements of $a$.
>
> Additionally, output the array that achieves this minimum. If there are multiple such arrays, output the one that is **lexicographically smallest**$^*$.
>
> $^*$For two arbitrary arrays $c$ and $d$ of length $n$, we say that $c$ is *lexicographically smaller* than $d$ if there exists an index $i$ ($1 \le i \le n$) such that $c_j = d_j$ for all $j < i$, and $c_i < d_i$. In other words, $c$ and $d$ differ in at least one index, and at the first index at which they differ, $c_i$ is smaller than $d_i$.
>
> ### Input
>
> The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.
>
> The first line of each test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$).
>
> The second line of each test case contains $n$ integers, $a_1, a_2, \dots, a_n$ ($-1 \le a_i \le 10^6$).
>
> It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.
>
> ### Output
>
> For each test case, on the first line, output the minimum possible value of $|b_1 + b_2 + \dots + b_{n-1}|$. Then, on the second line, output $n$ integers, the values of $a_1, a_2, \dots, a_n$ in the lexicographically smallest array achieving this minimum.

### Detalles a destacar
Podemos *reducir* el output requerido de la siguiente forma:
$$
\sum_{i=0}^{n-2} a_{i+1} - a_i
$$
Como tal no seria necesario crear un arreglo *b* con aquellos valores, con esto ahorrariamos espacio
¿Porque esto sirve?, bueno, primero solo nos piden dos cosas
1.- El menor valor posible del resultado de $\sum_{i=0}^{n-2} a_{i+1} - a_i$
2.- Imprimir los valores del arreglo *a*, de tal manera que los valores de este hagan que sea lexicografimente el menor de todos. En resumen, si se obtiene una misma respuesta con diferentes valores, imprimir el lexicograficamente mejor.
3.- Los valores de *b* tienen que ser *enteros no negativos*, por lo tanto, todo $a_i >= 0$

### Solucion! (:
Primero, como buena practica empezamos analizando lo mas sencillo, casos faciles, por ejemplo con $n = 5$, analicemos, ¿Como se veria la sumatoria?
$$
R = \sum_{i=0}^{3} a_{i+1} - a_i \\ 
R = (a_1 - a_0) + (a_2 - a_1) + (a_3 - a_2) + (a_4 - a_3) \\
\text{Simplificando... }\\
R = (\cancel{a_1} - a_0) + (\cancel{a_2} - \cancel{a_1}) + (\cancel{a_3} - \cancel{a_2}) + (a_4 - \cancel{a_3}) \\
R = a_4 - a_0
$$
Increible!, todo se reduce a dos valores sencillos, el inicio y el fin!.
A este tipo de sumatorias se le conoce como *Sumas telescópicas*, formalmente, su definicion es la siguiente:
> *Una suma telescopica es una serie de términos que se cancelan parcialmente entre sí, dejando solo el primer y el último término para obtener el resultado final*

Si continuamos analizando con diferentes valores para *n* siempre obtendremos lo mismo, que es lo siguiente:
$R = a_n - a_0$
Por lo tanto, todo se reduce a minimizar dicha resta!
Sin embargo, dado a que ambos valores pueden ser o no -1, abordaremos diferentes casos, que son los siguientes:
$a_n = -1 \quad \text{y} \quad a_0 = -1\ : \\$
> $ a_n = -0 \ y \ a_0 = 0$

\*Notese que aca si o si se cumple el segundo detalle mencionado anteriormente:) (Arreglo *a* lexicograficamente menor)

$a_n \neq -1 \quad \text{y} \quad a_0 = -1 :$
> $a_0 = a_n$

$a_n = -1 \quad \text{y} \quad a_0 \neq -1 :$
> $a_n = a_0$


Para el resto de elementos, (Los que no son $a_n$ y $a_0$) su valor debe ser $0$, de esta forma, estariamos cumpliendo con el detalle de que debe ser lexicograficamente menor!

Al hacer los cambios correspondientes, deberemos imprimir:
$a_n - a_0$ (Una vez modificados, claro)
Seguido de todos los valores del arreglo *a* (:

### Codigo

### Conclusion
La solucion se centra en si conocemos o no el primer y ultimo valor, el resto de valores no importa dado a que *b* resulta en una *Suma telescopica*

## C1. Renako Amaori and XOR Game (easy version) ( Mi favorito :p)
[Link](https://codeforces.com/contest/2171/problem/C1)

### Codigo
```cpp
#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    
    int score_a = 0, score_b = 0;
    int tie = 0;

    for(int &x:a){
        cin>>x;
        score_a^=x;
    }
    
    for(int &x:b){
        cin>>x;
        score_b^=x;
    }

    if(score_a == score_b){
        cout<<"Tie"; return ;
    }

    int j,i;

    // cout<<"Score antes de jugar: "<<' '<<score_a<<' '<<score_b<<'\n';

    bool turn = 1;
    for(i=0;i<n;i++){
        
        // Solo haremos un intercambio si y solo si:
        // - vamos perdiendo :p 
        // - Nos conviene hacerlo, claro xD

        if(turn){ // ajisai
            if(score_a==0 &&( b[i]==1 && a[i]==0)){
                score_a = 1;
                score_b = 0;
            } else if (score_a==0 &&( b[i]==0 && a[i]==1)){
                score_a = 1;
                score_b = 0;
            }

            turn = !turn;
        } else {
            if(score_b==0 &&( a[i]==1 && b[i]==0)){
                score_b = 1;
                score_a = 0;
            }  else if (score_b==0 &&( a[i]==0 && b[i]==1)){
                score_a = 0;
                score_b = 1;
            }
            turn = !turn;
        }

    }    
    // cout<<score_a<<' '<<score_b<<' ';
    cout<<(score_a==1?"ajisai":"mai");

    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        solve();
        if(t>0)cout<<'\n';
    }

    return 0;
}
```