---
title: "Codeforces Contest 1065: Análisis"
date: 2025-11-20
draft: false
author: "Cristobal Longares"
description: "Análisis de los problemas A y B del contest Codeforces 1065. Soluciones con explicaciones detalladas."
categories: ["Codeforces"]
tags: ["codeforces", "contest", "resolucion-problemas"]
ShowToc: true
TocOpen: true
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

### Codigo
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
void solve(){
    
    int x; cin>>x;
    if(x%2!=0) cout<<0;
    else cout<<(x/4)+1;
    cout<<'\n';
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t; cin>>t;
    while(t--){
        solve();
    }
 
    return 0;
}
```


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
> Input
>
> The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.
>
> The first line of each test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$).
>
> The second line of each test case contains $n$ integers, $a_1, a_2, \dots, a_n$ ($-1 \le a_i \le 10^6$).
>
> It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.
>
> Output
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
En esta ocasion, paso por poner el enunciado del problma :b, se puede leer en el anterior link.
### Observaciones
1.- $a_i \text{ y } b_i$ solo pueden 1 o 0.
2.- Si ambos alcanzan el mismo *score*, es empate
3.- Solo se puede swapear si y solo si $a_i, b_j\quad i=j$
4.- Ambos jugadores siempre juegan de la mejor forma, la mas optima.

### Analisis

#### ¿Se puede desampatar?
Comenzemos con el empate, ¿Cuando sucede?, cuando ambos alcanzan el mismo score, pero... en caso de que al inicio haya un empate, ¿Hay forma de que alguno de los dos pueda ganar?, empecemos por un caso sencillo.
*n = 4* *a: 0 0 1 0* y *b: 1 0 1 1* 

Score a: $0\oplus0\oplus1\oplus0 = 1$
Score b: $1\oplus0\oplus1\oplus1 = 1$

Para ganar, tanto el jugador *a* como el jugador *b* tendrian que hacer un *swap* en una posicion en la que el score final cambie, es decir, en una posicion donde $a_i \neq b_i$, se supone, que de esta manerar el score cambiaria, probemos haciendo un swap en $i = 0$

Score a: $1\oplus0\oplus1\oplus0 = 0$
Score b: $0\oplus0\oplus1\oplus1 = 0$

Notese que **no es conveniente realizar un swap cuando se va ganando, esto NO seria una forma optima de jugar** ya que *perjudica* el score, pero, ¿Y si ambos tienen un score de 0?, utilizaremos el arreglo anterior, probemos con un swap en $i = 3$

Score a: $1\oplus0\oplus1\oplus1 = 1$
Score b: $0\oplus0\oplus1\oplus0 = 1$

Ambos van perdiendo, el jugador del turno $i = 3$ hace un swap y terminan con el mismo score.

Entonces... a partir de esas pruebas, lo mismo pasara con otros casos de empate, por lo tanto, **NO ES OPTIMO** hacer cambios cuando ambos scores son iguales ya que siempre termina en un empate, sin importar los cambios que se hagan

#### Sin empate, ambos scores difieren
Este caso sucede cuando los scores de *a y b* son diferentes, mi enfoque es el siguiente
1.- Recorrer cada uno de los *n* elementos de *a* y *b* simultaneamente
2.- Si $a_i \neq b_i$ hacemos un *swap* **SIEMPRE Y CUANDO SEA CONVENIENTE**, anteriormente explicamos cuando lo es.
3.- Si hacemos un *swap*, le damos el punto ganador al jugador de aquel turno
4.- Al final, simplemente con un condicional verificamos quien tiene el punto ganador, fin.

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
### Una solcuin mejor
La anterior solucion *no es la mas optima* :c,  para empezar, si analizamos mejor, el score final se puede represtar de la siguiente forma
$$ score = (a_0 \oplus a_1 \oplus a_1 ... \oplus a_n ) \oplus (b_0 \oplus b_1 \oplus b_1 ... \oplus b_n ) $$
Si $score = 0$, es un empate, de lo contrario, existe una forma de desempatar.
La manera de desempatar es genial!, me gusta muchisimo, no pertenece a la solucion oficial.
Si analizamos otro poco, para saber quien gana, basta con comprobar, *¿Quien hace el ultimo swap?* y listo, es todo jaja.
Para optimizar esto empezamos a recorrer ambos arreglos desde la ultima posicion, si el siguiente caso:
$$ a_i \oplus b_i = 1 (\text{Aquello es igual a } a_i \neq b_i)$$
Entonces, guardamos el indice en donde sucede esto y salimos del ciclo que lo reccore!, por ultimo, simplemente hacemos verificamos
> ¿El indice en donde los elementos son diferentes es par o impar?

Y listo, si es par, gana Mai, de lo contrario, Ajisai.

**¿Porque solo basta con comprobar quien hace el ultimo swap?**
Por que ese ultimo swap significa que ya no se puede hacer ningun otro cambio despues de ese indice, por lo tanto, aquel indice en donde se hace el intercambio es el ultimo, es decir, quien hace el movimiento ganador.

### Dato extra:p
A este tipo de juegos, se le conoce como *Juego Determinista de Información Perfecta*, en ellos no existe el azar y todos los jugadores conocen en todo momento el estado completo del juego y las acciones previas de los demás. Ejemplos de juegos de este tipo son el *Ajedrez, Go, Damas, Gato, etc*.

Por lo tanto, este problema se puede resolver super facil si conocemos sobre *Teoria de Juegos*, la solucion se centra unicamente en dos casos, el empate y no empate. Para el segundo caso basta con buscar un *estado crítico* que nos de la victoria, ¿Y cual es ese estado critico?, *el quien haga el ultimo swap*.

Ademas, otra cosa, en el enunciado del problema nos dice algo como *Determine the outcome... with optimal play*, es decir, asusimos que ambos jugadores son unos genios omniscientes que leen mentes y ven el futuro, por lo tanto... ¿Que implica esto?, implica que el juego ya esta decidido desde el inicio, el resultado es simplemente una propiedad matematica...

Afortunadamente, este problema es sencillo, es solo logica, ad-hoc puro jajaja, si vamos a problemas que involucran *Impartial Games*, como juegos tipo *Nim* seria muchisimo mas complicado.


### Analisis matematico
> Antes, esta demostracion NO ES MIA, la saque de internet, creditos a su respectivo autor!.

**1. Definiciones Formales**
Sea $n$ el número total de turnos. Definimos dos conjuntos iniciales $A$ y $B$ de longitud $n$:
$$A = \{a_1, a_2, \dots, a_n\} \quad , \quad B = \{b_1, b_2, \dots, b_n\}$$
Donde $a_i, b_i \in \{0, 1\}$.

El juego consiste en $n$ turnos. En el turno $i$ ($1 \le i \le n$), el jugador activo puede elegir una de dos operaciones:
1.  **Mantener:** $(a_i, b_i) \to (a_i, b_i)$
2.  **Intercambiar:** $(a_i, b_i) \to (b_i, a_i)$

Definimos el **Puntaje Final** ($S$) de cada jugador como la suma XOR de sus elementos al finalizar el turno $n$:
$$S_A = \bigoplus_{i=1}^{n} a'_i \quad , \quad S_B = \bigoplus_{i=1}^{n} b'_i$$

La condición de victoria está dada por:
* Si $S_A > S_B \implies$ Gana Ajisai.
* Si $S_B > S_A \implies$ Gana Mai.
* Si $S_A = S_B \implies$ Empate.

---

**2. Teorema de la Invariante Global**

**Proposición:** La suma XOR total de todos los elementos en juego, denotada como $X_{total}$, es invariante respecto a cualquier operación realizada durante el juego.

**Demostración:**
El valor total es:
$$X_{total} = \left( \bigoplus_{i=1}^{n} a_i \right) \oplus \left( \bigoplus_{i=1}^{n} b_i \right)$$

En cualquier turno $i$, un intercambio simplemente permuta los valores entre el conjunto $A$ y el conjunto $B$. Debido a que la operación XOR es conmutativa y asociativa, el conjunto de valores sobre el que se opera globalmente permanece idéntico.
$$a_i \oplus b_i = b_i \oplus a_i$$
Por lo tanto, $S_A \oplus S_B = X_{total}$ es constante. $\blacksquare$

**Corolario: Condición de Empate**
Si $X_{total} = 0$, entonces:
$$S_A \oplus S_B = 0 \implies S_A = S_B$$
Esto demuestra que si la suma XOR total inicial es cero, el juego **siempre terminará en empate**, independientemente de la estrategia.

---

**3. Teorema del Turno Crítico (Estrategia Óptima)**

Supongamos que $X_{total} \neq 0$. Esto implica que $S_A \neq S_B$, por lo que el empate es imposible. Dado que los puntajes son binarios ($0$ o $1$), uno será el ganador y el otro el perdedor.

Definimos el **Índice Crítico** $k$ como el mayor índice tal que los valores en $A$ y $B$ son distintos:
$$k = \max \{ i \mid a_i \neq b_i \}$$

**Afirmación:** El jugador que posee el turno $k$ tiene una estrategia ganadora garantizada.

**Demostración por Inducción Hacia Atrás:**

1.  **Turnos irrelevantes ($i > k$):**
    Para todo turno $j$ donde $j > k$, sabemos por definición que $a_j = b_j$.
    La operación de intercambio $(x, x) \to (x, x)$ no altera el estado del juego. Por tanto, los turnos posteriores a $k$ no afectan el resultado.

2.  **El Turno Decisivo ($i = k$):**
    Consideremos el estado del juego justo antes del turno $k$. Sea $P$ el jugador activo en este turno.
    El puntaje final de Ajisai, $S_A$, dependerá exclusivamente de la decisión tomada en $k$, dado que los turnos futuros son irrelevantes y los pasados son fijos.
    
    Como $a_k \neq b_k$, tenemos que $\{a_k, b_k\} = \{0, 1\}$.
    El jugador $P$ tiene dos opciones que resultarán en dos posibles valores finales para $S_A$: un valor $v$ o su complemento $v \oplus 1$.
    
    * Si $P$ decide **no intercambiar**, el resultado final será $R_1$.
    * Si $P$ decide **intercambiar**, el resultado final será $R_2$.
    
    Dado que se intercambian un 0 y un 1, $R_1 \neq R_2$. Uno de estos resultados corresponde a una victoria para $P$ y el otro a una derrota.
    
    Asumiendo juego óptimo, $P$ elegirá la opción que maximice su propio puntaje. Como $P$ tiene la "última palabra" efectiva del juego, su decisión sobrescribe cualquier ventaja obtenida por el oponente en los turnos $1 \dots k-1$.

**Conclusión:**
* Si $k$ es impar (turno de Ajisai) $\to$ Ajisai controla el resultado final $\to$ **Gana Ajisai**.
* Si $k$ es par (turno de Mai) $\to$ Mai controla el resultado final $\to$ **Gana Mai**.

---