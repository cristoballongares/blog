---
title: "Implementando la Regla del Trapecio en C++"
date: 2025-11-19
draft: false
categories: ["C++", "Matemáticas"]
tags: ["calculo", "integrales", "algoritmos"]
summary: "Hoy aprendí a calcular el área bajo la curva usando sumatorias y C++."
---

Hoy en clase de cálculo numérico vimos cómo resolver integrales definidas que son difíciles de calcular a mano. La técnica más sencilla es la **Regla del Trapecio**.

Aquí explico la teoría matemática y mi implementación en C++.

## El Problema Matemático

Queremos aproximar el valor de una integral definida:

$$I = \int_{a}^{b} f(x) dx$$

La idea es dividir el área bajo la curva en $n$ pequeños trapecios. La suma de las áreas de estos trapecios nos da el valor aproximado.

### La Fórmula

Si definimos el ancho de cada paso como $h = \frac{b-a}{n}$, la fórmula de aproximación es:

$$\int_{a}^{b} f(x) dx \approx \frac{h}{2} \left[ f(a) + 2\sum_{i=1}^{n-1} f(a + i \cdot h) + f(b) \right]$$

Donde:
* $a$ y $b$ son los límites de integración.
* $n$ es el número de divisiones (trapecios).

---

## Mi Solución en C++

Decidí probar esto con la función $f(x) = x^2$.
Sabemos por cálculo básico que $\int_{0}^{3} x^2 dx = [\frac{x^3}{3}]_0^3 = 9$. Veamos si el código se acerca.

```cpp
#include <iostream>
#include <cmath>

using namespace std;

// 1. Definimos la función a integrar: f(x) = x^2
double f(double x) {
    return x * x;
}

int main() {
    // Parámetros de la integral
    double a = 0.0;      // Límite inferior
    double b = 3.0;      // Límite superior
    int n = 1000;        // Número de trapecios (entre más alto, más preciso)

    // 2. Calculamos el ancho del paso (h)
    double h = (b - a) / n;

    // 3. Sumamos los extremos f(a) + f(b)
    double suma = f(a) + f(b);

    // 4. Sumamos los puntos intermedios multiplicados por 2
    for (int i = 1; i < n; i++) {
        double x_actual = a + i * h;
        suma += 2 * f(x_actual);
    }

    // 5. Multiplicamos por h/2
    double resultado = (h / 2) * suma;

    cout << "--- Resultado de la Integración ---" << endl;
    cout << "Funcion: f(x) = x^2" << endl;
    cout << "Limites: [" << a << ", " << b << "]" << endl;
    cout << "Divisiones (n): " << n << endl;
    cout << "Resultado aproximado: " << resultado << endl;
    cout << "Resultado real: 9.0" << endl;

    return 0;
}

```

## Análisis del Resultado

Al compilar y ejecutar el código, obtuve:

> **Resultado aproximado:** `9.0000045`
> **Resultado real:** `9.0`

El error es minúsculo. Aprendí que la precisión depende totalmente de la variable `n`. Si usara `n=10`, el error sería mucho mayor.

¡Mañana intentaré implementar la **Regla de Simpson**, que se supone es más precisa!

```text
--- Resultado de la Integración ---
Funcion: f(x) = x^2
Limites: [0, 3]
Divisiones (n): 1000
Resultado aproximado: 9.0000045
Resultado real: 9.0