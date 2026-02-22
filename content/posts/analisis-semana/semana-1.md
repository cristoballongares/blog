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