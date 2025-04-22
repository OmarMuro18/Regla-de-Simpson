# 📐 Reglas de Integración Numérica: Simpson 1/3, Simpson 3/8 y Trapecio

Este programa en C++ implementa métodos de **integración numérica** para aproximar el valor de una integral definida utilizando:

- 🟪 **Regla del Trapecio**
- 🟦 **Regla de Simpson 1/3**
- 🟧 **Regla de Simpson 3/8**

## ✨ Características principales

- El usuario introduce los **límites de integración**, el **número de segmentos** y los **coeficientes** de un polinomio de hasta quinto grado.
- El programa evalúa el polinomio en los puntos requeridos.
- Según la cantidad de segmentos, elige el método de integración más adecuado:
  - Si el número de segmentos es impar, usa **Simpson 3/8** para los últimos 4 puntos y el resto con **Simpson 1/3**.
  - Si hay solo un segmento, aplica la **Regla del Trapecio**.
- Muestra el resultado final de la integración.

## 🧮 Fórmula usada

### Regla de Simpson 1/3:
\[
\int_a^b f(x)dx \approx \frac{h}{3} [f(x_0) + 4f(x_1) + 2f(x_2) + 4f(x_3) + \ldots + f(x_n)]
\]

### Regla de Simpson 3/8:
\[
\int_a^b f(x)dx \approx \frac{3h}{8} [f(x_0) + 3f(x_1) + 3f(x_2) + f(x_3)]
\]

### Regla del Trapecio:
\[
\int_a^b f(x)dx \approx \frac{h}{2} [f(a) + 2f(x_1) + \ldots + 2f(x_{n-1}) + f(b)]
\]
