---
date: '2026-03-09T18:15:34-06:00'
title: 'Second and Third Week :p'
---

# Introduction

These two weeks have been mmmhh, rough?, maybe xD, idk, but what I do know is that they were a lot of fun!
LI ended up with 6 problems pending their editorial, but no worries, I actually enjoy writing them. So lets get to it!


# Goals of the weeks
 - [ ] Do 30 problems
   - I do 25/30 :c
 - [x] Escribir sobre los 3 problemas mas dificiles de la semana (both weeks)
  - [x] Product and GCD
  -  [ ] Knight moves grid
  - [x] Serval and Kaitenzushi Buffet
  - [x] Imbalanced Array (Soo easy, just two monotonic stack :p, not worth a full editorial)
   - [ ] Reverse Card (More number theory, i really enjoy that, im falling in love with it)
   - [ ] Subarray Distinct Values (DP!, thats scary O.o)

# Product and GCD
This problem is so beautiful!, we have $N$ integers $a_1,a_2,...,a_n$ not less than 1. This values are uknow but $a_1*a_2*...*a_n = P$.
We need find the maximum possible greatest common divisor of $a_1,a_2,...,a_n$
### Constraints
- $1\leq N \leq 10^{12}$
- $1\leq P \leq 10^{12}$
## Analisis
we discard the solutions that have $O(n)$ in his, because is guarrented TLE 

First, reescribe the expression.
$gcd(a_1,a_2,...,a_n) = g$, then, 

$a_i = g *b_i $, so 

$ gb_1 * gb_2 * ... * gb_n = P$, 

$g^n (b_1*b_2*...*b_n) = P$

Now, if we are a little more explicit, for a number divides a otro o dicho de mejor modo, para que $a \mid b$, es necesario que, los exponentes de los factores primos de $b$ sean menores o iguales a los de $b$, esto por cada primo de forma independiente, formalmente, si:

$$ a = \prod_{}^{} p_i^{f_i} \quad y \quad b = \prod p_i^{e_i} $$ Entonces

$$ a \mid b \iff f_i \leq e_i \ \text{para todo primo }p_i$$

Sabiendo esto, buscaremos todos los $f_i$ de $g$ que sean menores o iguales a $e_i$ de $p$. Sin embargo, no olvidemos que $g$ es $g^n$, por lo tanto para cada exponente de $p$ se debe cumplir para cada exponente de $g$ lo siguiente:

$ f_i \leq \lfloor \frac{e_i}{n}  \rfloor $.



### Resumen
Encontramos y guardamos los factores primos de $P$, por cada uno de estos encontramos el $p_i^{f_i}$ mas grande posible, los multiplicamos y esa será la respuesta.

# Knight Moves Grid
Construyendo solucion... 
# Serval and Kaitenzushi Buffet
Resolver este problema fue un reto al inicio porque pese a que ya habia resuelto varios problemas del mismo tema *[Regret Greedy](https://codeforces.com/blog/entry/140933?#comment-1258111)* (No hay mucha información sobre este topico, sin embargo, es muy interesante) al inicio se me complicó construir la solución.
El problema se resume en: Tenemos $k$ piezas de sushi, la $i-esima$ pieza tiene un nivel de $d_i$ (Que tan rico está o algo asi). Tenemos solo $n$ minutos para comernos los sushi, sin embargo, enl $i-esimo$ minuto solo podemos comer la $i-esima$ pieza. Al inicio empezamos con una variable inicializada en 0, llamada $r$

En el iesimo minuto podemos hacer tres cosas
- Tomar el iesimo plato de sushi (con un nivel $d_i$) de la mesa y $r$ incrementará en $k$
- Comer un plato de sushi que hemos tomado anteriormente y $r$ decrementará en $1$. Solo podemos hacer esto si $r>0$
- Hacer nada y $r$ permanece igual.
**NOTA:** **AL FINAL $r$ debe ser $0$**

**Nuestro objetivo es maximizar la suma de los niveles de todos los platos que tomamos**

### Constraints
- We will have $t$ test cases $1\leq t \leq 10^4$
- $1 \leq k < n \leq 2 \cdot 10^5$
- $1 \leq d_i \leq 10^9$ 

Ojo, con un $O(n)$ o $O(nlogn)$ quedaria, lo dificil es saber como

## Resumen del problema
Cada plato de sushi tiene un nivel de dulzura (llamado $d_i$), hay $k$ sushis por plato y en total hay $n$ platos con y en el i-esimo minuto solo podemos hacer tres cosas

- **Tomar sushi**: $r$ aumenta en $k$
- **Comer sushi**: $r$ decrementa en $1$
- **Ignorarlo**: No pasa nada 

**Observaciones**:
- Al final, $r$ debe ser 0
- Debemos *maximizar la dulzura total obtenida* de los sushis que tomamos

## Solucion
Cada pieza de sushi nos cuesta $k+1$ minutos (Tiempo en digerir y agarrar).
Ademas, si analizamos nos conviene empezar desde n e ir hacia atras, pero... ¿Por que?, bueno, recordemos la pregunta clave del problema, **¿Tengo suficiente tiempo después de este minuto para comer el plato?**. Eso seria tiempo que esta a la derecha de nuestro arreglo, por ende tiene sentido recorrerlo de derecha a izquierda por que si nuestro contrador r va acumulando el tiempo disponible conforme nos movemos hacia la izquierda.

Cuando llegamos al minuto $i$, $r$ ya cuenta exactamente cuantos minutos tenemos despues de $i$.

Haremos uso de una cola de prioridad min-heap en donde iremos guardando la dulzura de los sushis, en donde el tope siempre sera el menor. De esta manera, si se presenta el caso en que un i-esimo sushi tiene mas dulzura que el tope, y ademas, tenemos tiempo para comerlo, quitamos el tope y agregamos el actual.

Otro detalle importante a destacar es que solo podemos hacermos cada que tengamos $k+1$ mins dispnibles

## Codigo
Es relativamente sencillo... 
```cpp
    int n,k; cin>>n>>k;
    vector<ll> a(n+1);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll i, r = 0;
 
    for(i=1;i<=n;i++) cin>>a[i];
 
    for(i=n;i>=1;i--){
 
        r++;
        // tiempo en comer y agarrar
        if(r >= k + 1){
 
            pq.push(a[i]);
            r-= (k+1);
 
        } else if(!pq.empty() && pq.top()<a[i]){
 
            pq.pop(); pq.push(a[i]);
 
        }
 
    }
 
    ll sum = 0;
 
    while(!pq.empty()){
        sum += pq.top(); pq.pop();
    }

```