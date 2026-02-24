---
date: '2026-02-22T15:36:05-06:00'
draft: false
title: 'Semana 1, Analisis'
---

# Objetivos de la semana
 - [ ] Resolver 10 problemas de dificultad medio-dificil 
   - Hice 8/10 :c
 - [x] Escribir sobre los 3 problemas mas dificiles de la semana
   - Sparse table (tema)
   - Hair dresser
   - Gepetto and pizzas
 - [x] Aprender uno o mas temas
   - Sparse table

## Lista de problemas
No la recopile jaja, para la otra si los recopilo

# Sparse Table, explicación
La Sparse Table (o tabla dispersa) es una *estructura de datos* que sirve para responder consultas de rango, tales como hallar el minimo, M.C.D o el maximo en arreglos estaticos, es decir, aquellos que no cambian. Todo esto en tiempo constante $O(1)$ !, todo esto requiere de una precomputacion de costo $O(nlogn)$

## Estructura
Para hacer uso de estructura de datos previamente requerimos precalcular datos que almacenaremos en una matriz. La longitud de dicha matriz debe ser *n* filas y $log_2 (n) + 1$ columnas

### ¿Porque $log_2 (n)$ columnas?
A la hora de llenar la matriz, compararemos los elementos del arreglo en bloques cuyos tamaños son exactamente potencias de 2 (1,2,4,8,16...)
La principal razón de hacer esto es por la alta eficiencia en memoria, pues pasamode utilizar $n^2$ a $nlogn$, afectando también el tiempo requerido, siendo este cuadratico.

Al guardar unicamente los bloques que son potencias de 2, la cantidad maxima que necesitamos es el exponente de la potencia de 2 mas grande que cabe en nuestro arreglo de $n$ elementos. Matematicante esto seria $log_2(n)$, pero le debemos sumar 1 a la formula ya que nuestra columna $0$ representa la potencia de $2^0$ (Que son los bloques de UN SOLO ELEMENTO)

### Construyendo nuestra Sparse Table
Algo muy bonito de esta estructura de datos es que utiliza *programación dinámica* y si aún no sabemos sobre este tema (como yo), aprender esta ED sin duda es un gran comienzo en la DP.
En lugar de volver aa calcular rangos grandes desde 0, utilizamos la información de rangos mas pequeños que obtendremos con anterioridad. 
La idea principal es la siguiente:
$$\text{Un bloque de tamaño } 2^j \text{ se calcula uniendo dos bloques adyacentes de tamaño } 2^{j-1}$$
Ejemplo con j = 2 ($2^2 = 4$)
$$
\begin{array}{c}
\begin{array}{|c|c|c|c|}
\hline
\phantom{xx} & \phantom{xx} & \phantom{xx} & \phantom{xx} \\
\hline
\end{array} \quad 2^2 = 4 \\
\swarrow \qquad \qquad \searrow \\
\underbrace{
    \begin{array}{|c|c|}
    \hline
    \phantom{xx}&\phantom{xx} \\
    \hline
    \end{array}
    \qquad \qquad
    \begin{array}{|c|c|}
    \hline
    \phantom{xx} & \phantom{xx} \\
    \hline
    \end{array}
}_{\begin{array}{c} 2^{2-1} \\ 2 \end{array}}
\end{array}
$$

Probemos con un ejemplo: Supongamos que queremos calcular el minimo de un bloque de tamaño 4 (j = 2). En lugar de iterar sobre los 4 elementos, solamente partimos el bloque a la mitad (j-1) y comparamos los dos minimos de cada bloque partido resultante
- La mitad izquierda: Un bloque que ya se calculó de tamaño 2
- La mitad derecha: Otro bloque precalculado de tamaño 2 que empieza exactamente donde termina la mitad izquierda!
Ahora, en terminos mas tecnicos, en nuestra matriz (Que llamaremos $sparse[][]$), donde $i$ representa el inicio y $j$ la potencia de 2, esto se ve asi.
$$sparse[i][j] = min(sparse[i][j-1],sparse[i+2^{j-1}][j-1])$$
-   $sparse[i][j-1]$: Representa el resultado de la primera mitad
-   $sparse[i+2^{j-1}][j-1]$: Representa el resultado de la segunda mitadque esta desplazada hacia adelante

Visualmente, si calculamos el bloque que inicia en $i=0$:

$$
\begin{array}{c}
\text{Calculando } sparse[0][2] \text{ (Bloque de tamaño 4, } j=2 \text{)} \\
\\
\begin{array}{|c|c|c|c|}
\hline
5 & 1 & 3 & 9 \\
\hline
\end{array} \\
sparse[0][2] = \min(1, 3) = 1 \\
\swarrow \qquad \qquad \qquad \searrow \\
\begin{array}{cc}
\underbrace{
    \begin{array}{|c|c|}
    \hline
    5 & 1 \\
    \hline
    \end{array}
}_{\begin{array}{c} sparse[0][1] \\ \text{Mitad Izquierda} \\ \text{min} = 1 \end{array}}
& \qquad
\underbrace{
    \begin{array}{|c|c|}
    \hline
    3 & 9 \\
    \hline
    \end{array}
}_{\begin{array}{c} sparse[0 + 2^1][1] \rightarrow sparse[2][1] \\ \text{Mitad Derecha} \\ \text{min} = 3 \end{array}}
\end{array}
\end{array}
$$

## Construccion de la matriz paso a paso
Hagamos una prueba con el siguiente arreglo, A = $[5,1,3,9,7,2]$. El tamaño es 6, por lo que calcularemos hasta $j = 2$ bloques, ya que un bloque de tamaño 8 ($j = 3$) excede la longitud del arreglo.

#### Nivel 0 ($j = 0$) — Bloques de tamaño $2^0 = 1$

Cada celda representa el mínimo de un bloque de tamaño 1.

$$
\text{ST}[i][0] = A[i]
$$

$$
\begin{array}{c|c}
i & j=0 \\
\hline
0 & 5 \\
1 & 1 \\
2 & 3 \\
3 & 9 \\
4 & 7 \\
5 & 2 \\
\end{array}
$$

Este nivel simplemente copia el arreglo original.

---

### Nivel 1 ($j = 1$) — Bloques de tamaño $2^1 = 2$

Ahora cada celda almacena el mínimo de dos elementos consecutivos.

La transición es:

$$
\text{ST}[i][1] = \min(\text{ST}[i][0], \text{ST}[i+1][0])
$$

$$
\begin{array}{c|c}
i & j=1 \\
\hline
0 & \min(5,1)=\mathbf{1} \\
1 & \min(1,3)=\mathbf{1} \\
2 & \min(3,9)=\mathbf{3} \\
3 & \min(9,7)=\mathbf{7} \\
4 & \min(7,2)=\mathbf{2} \\
\end{array}
$$

No calculamos $i=5$ porque un bloque de tamaño 2 empezando en 5 se sale del arreglo.

---

### Nivel 2 ($j = 2$) — Bloques de tamaño $2^2 = 4$

Ahora usamos bloques de tamaño 4.

La fórmula general es:

$$
\text{ST}[i][j] = \min(\text{ST}[i][j-1], \text{ST}[i + 2^{j-1}][j-1])
$$

Para $j=2$:

$$
\text{ST}[i][2] = \min(\text{ST}[i][1], \text{ST}[i+2][1])
$$

$$
\begin{array}{c|c}
i & j=2 \\
\hline
0 & \min(1,3)=\mathbf{1} \\
1 & \min(1,7)=\mathbf{1} \\
2 & \min(3,2)=\mathbf{2} \\
\end{array}
$$

Nos detenemos en $i=2$ porque un bloque de tamaño 4 iniciando en 3 excedería los límites del arreglo.

---

### Tabla completa

$$
\begin{array}{c|c|c|c}
i & 2^0 & 2^1 & 2^2 \\
\hline
0 & 5 & 1 & 1 \\
1 & 1 & 1 & 1 \\
2 & 3 & 3 & 2 \\
3 & 9 & 7 & - \\
4 & 7 & 2 & - \\
5 & 2 & - & - \\
\end{array}
$$

Donde:

- Cada columna $j$ representa bloques de tamaño $2^j$
- Cada celda guarda el mínimo del intervalo correspondiente
- Los guiones indican posiciones inválidas

---

### Complejidad

- Preprocesamiento: $O(n \log n)$
- Consulta RMQ: $O(1)$
- Espacio: $O(n \log n)$

Funciona directamente con operaciones **idempotentes** como:

- mínimo
- máximo
- gcd

Una operación binaria $f(x, y)$ es **idempotente** si cumple la siguiente propiedad:

$$
f(x, x) = x
$$

Es decir, aplicar la operación sobre dos valores iguales no cambia el resultado.

---

### Ejemplos

#### Mínimo

$$
\min(x, x) = x
$$

Ejemplo:

$$
\min(5,5) = 5
$$

---

#### Máximo

$$
\max(x, x) = x
$$

Ejemplo:

$$
\max(7,7) = 7
$$

---

#### Máximo Común Divisor (gcd)

$$
\gcd(x, x) = x
$$

Ejemplo:

$$
\gcd(12,12) = 12
$$

---

### Ejemplo de operación NO idempotente

#### Suma

$$
x + x = 2x
$$

Claramente:

$$
f(x,x) \neq x
$$

Por lo tanto, la suma **no es idempotente**.

---

### Perooo... ¿Por qué esto es importante en Sparse Table?

En una Sparse Table para consultas RMQ usamos la idea:

\[
\text{respuesta} =
\min(\text{bloque}_1, \text{bloque}_2)
\]

Estos bloques pueden **solaparse**, o en palabras simples, *colisionar*.



Si la operación es idempotente, no importa si un elemento se considera dos veces, porque:

\[
\min(x,x) = x
\]

El resultado no se altera.

Pero si usáramos suma:

\[
x + x = 2x
\]

Estaríamos contando dos veces el mismo elemento y el resultado sería incorrecto.

---

## Consultas RMQ (Range Minimum Query)

Ya construimos nuestra tabla y entendimos que podemos solapar bloques sin alterar el resultado gracias a la idempotencia. Ahora, ¿Cómo respondemos a una consulta en un rango $[L, R]$?

La longitud de nuestro rango a consultar es $\text{len} = R - L + 1$. 
Para cubrir todo este rango en tiempo $O(1)$, buscamos la **mayor potencia de 2** que quepa completamente dentro de $\text{len}$. Llamemos a este exponente $j$. Matemáticamente, esto es $j = \lfloor \log_2(\text{len}) \rfloor$.

Con este valor $j$, tomamos dos bloques de tamaño $2^j$ y los solapamos:
1. **Bloque Izquierdo:** Lo anclamos al inicio del rango. Empieza exactamente en $L$, por lo que su valor precalculado es $\text{ST}[L][j]$.
2. **Bloque Derecho:** Lo ponemos al final del rango. Para que termine exactamente en $R$, debe empezar en el índice $R - 2^j + 1$. Su valor es $\text{ST}[R - 2^j + 1][j]$.

Al unir estos dos bloques, garantizamos que se cubra el 100% del rango $[L, R]$. La fórmula final es:

$$\text{Respuesta} = \min(\text{ST}[L][j], \text{ST}[R - 2^j + 1][j])$$

Visualmente, si consultamos el rango $[1, 5]$ (longitud 5, por lo que $j = 2$ y el tamaño del bloque a usar es $2^2 = 4$):

$$
\underbrace{
    \overbrace{A[1] \quad A[2] \quad A[3] \quad A[4]}^{\text{Bloque Izq: } \text{ST}[   1][2]} \quad A[5]
}_{\text{Rango total } [1, 5]}
$$
$$
\underbrace{
    A[1] \quad \overbrace{A[2] \quad A[3] \quad A[4] \quad A[5]}^{\text{Bloque Der: } \text{ST}[2][2]}
}_{\text{Rango total } [1, 5]}
$$

Como podemos notar, los elementos centrales ($A[2], A[3], A[4]$) son evaluados dos veces por nuestros bloques. Pero como ya demostramos, al ser el mínimo una operación idempotente, tarann, este solapamiento no afecta para nada y el resultado es perfectamente correcto en tiempo $O(1)$!

---

## Implementación en C++

Esta es la implementación clásica. Utilizamos una matriz global y operadores de bits (`1 << j` equivale a $2^j$) para hacer el código mucho rápido y compacto.

```cpp
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

vector<vector<int>>pre_min(vector<int> &input, int n){
    vector<vector<int>> sparse(n,vector<int>(1+log2(n)));

    // Llenamos nuestra columna inicial:)
    int i,j;
    for(i=0;i<n;i++) sparse[i][0] = i;

    // Recordemos que 2^n = (1<<n) 
    // Bitwise Left Shift

    for(j=1;(1<<j)<=n;j++){
        for(i=0; i + (1<<j) - 1 <n;i++){
            if(input[sparse[i][j-1]] < input[sparse[i + (1<<(j-1))][j-1]]){
                sparse[i][j] = sparse[i][j-1];
            } else {
                sparse[i][j] = sparse[i + (1<<(j-1))][j-1];
            }
        }
    }

    return sparse;

}
// Extra!, Sparse Table para guardar maximos:)
vector<vector<int>>pre_max(vector<int> &input, int n){
    vector<vector<int>> sparse(n,vector<int>(1+log2(n)));

    // Llenamos nuestra columna inicial:)
    int i,j;
    for(i=0;i<n;i++) sparse[i][0] = i;

    // Recordemos que 2^n = (1<<n) 
    // Bitwise Left Shift

    for(j=1;(1<<j)<=n;j++){
        for(i=0; i + (1<<j) - 1 <n;i++){
            if(input[sparse[i][j-1]] > input[sparse[i + (1<<(j-1))][j-1]]){
                sparse[i][j] = sparse[i][j-1];
            } else {
                sparse[i][j] = sparse[i + (1<<(j-1))][j-1];
            }
        }
    }

    return sparse;

}



int query(int l, int r, const vector<vector<int>>& sparse, const vector<int>& input) {
    int len = r - l+ 1;
    // k = potencia de 2 mas grande que cabe    
    int k = (int)log2(len);
    
    // obtenemos indices en ambos bloques
    int leftI = sparse[l][k];
    int rightI = sparse[r - (1 << k) + 1][k]; // r - 2^k + 1
    
    // comparamos los valores
    return min(input[leftI],input[rightI]);
    
}
```

# Gepetto and Pizzas
Solving this problem was very satisfying!, I really like solving problems that involve recursion!.
A quick summary of this problem is: We have $n$ ingredients and we need to find the total number of all possible valid pizza *combinations* such that none of the $m$ pairs of ingredients $a,b$ are present in the actual combination of ingredients
## Mistakes I made while solving
When i was started to solve this problem i made a mistake while reading the description because i believed that combinations could only be at most 2 ingredients and that is completely false!

For example if we have $3$ ingredients and $2$ restricted pairs of ingredients $[1,2]$ and $[2,3]$, the possible combinations are:
$\{\}, \{1\}, \{2\}, \{3\}, \{1,3\}$ **Note that a pizza without ingredients counts a combination!**

Another mistake i made was not analizing the time complexity and the best strategy to attack this problem, the restriccions are: $1<=n<=20, 1 <= M <= 400$ and for the ingredientes $1<=a,b<=N$.
Can u notice it? yes, N is veryyy small and not noticing that is a huge mistake!, beacuase if we analize the constraints, we realize we can use algorithms with $n^2, \ n^3,$ **$2^n$**.

## Solution
After a looong time thinking about the solution, the best strategy is to use backtracking!.
The solution is easy. We need a global vector to store the current combionation of ingredients if the current combination is valid, we increment another global variable (named total) by 1. If a combination is not possible we backtrack and try with another ingredient.
We need to repite this procces until the actual ingredient is greather than $n$

---

## Visualization of the algorithm
![Pizarron](/images/semana-1/pizarron.jpg)


## Code
```cpp
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;

int n, m;
bool bad[21][21];
int total = 0;

vector<int> pizza_actual;

void buscar(int id) {
    if(id>n){
        total++;
        return;
    }
    buscar(id+1);

    bool ok = true;
    for(int ing:pizza_actual) {
        if(bad[id][ing]) {
            ok=false;
            break;
        }
    }

    if(ok){
        pizza_actual.push_back(id); // metemos
        buscar(id+1); // seguimos buscando con el siguiente
        pizza_actual.pop_back(); // lo sacamos para probar otras
    }
}

void solve(){
    cin>>n>>m;
    int t = m;
    while(t--){
        int x,y;cin>>x>>y;
        bad[x][y] = true;
        bad[y][x] = true;
    }

    buscar(1);
    cout<<total;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t=1; 
    // cin>>t;
    while(t--){solve();cout<<'\n';}

    return 0;
}
```