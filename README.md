# Blog Dev 🚀

Análisis y tutoriales sobre problemas de **Codeforces**, **AtCoder** e **ICPC**. Un espacio para compartir soluciones, explicaciones de algoritmos y estructuras de datos con contenido técnico de alta calidad.

---

## Requisitos Previos

- **Hugo** v0.100+ (extended)
- **Git** 2.0+
- Navegador web

---

## Setup Local

### 1. Clonar el repositorio

```bash
git clone --recurse-submodules https://github.com/cristoballongares/mi-blog-dev
cd mi-blog-dev
```

### 2. Ejecutar servidor de desarrollo

```bash
hugo server
```

Accede a **http://localhost:1313** en tu navegador.

---

## Estructura del Proyecto

```
content/posts/
├── analisis-semana/           # Análisis semanales de problemas
├── codeforces/                # Tutoriales y soluciones Codeforces
└── Interesante/               # Problemas destacados y temas avanzados
```

---

## 📝 Agregar un Nuevo Post

```bash
hugo new posts/categoria/nombre-del-post.md
```

Esto genera un archivo Markdown con frontmatter automático en `content/posts/categoria/nombre-del-post.md`.

Luego abre el archivo en tu editor y completa:
- `title`: Título del post
- `date`: Fecha (auto-generada)
- `draft`: Cambiar a `false` para publicar
- `categories`: Categorías relevantes
- `tags`: Tags para clasificación

---

## 📐 Fórmulas Matemáticas

Usamos **KaTeX** para renderizado de fórmulas. Dos formas de escribirlas:

### Inline (dentro de párrafos)
```markdown
La complejidad es $O(n \log n)$ para este algoritmo.
```
Resultado: La complejidad es $O(n \log n)$ para este algoritmo.

### Display (centradas, destacadas)
```markdown
$$\text{Sparse Table: } ST[i][j] = \min(ST[i][j-1], ST[i+2^{j-1}][j-1])$$
```

Resultado:
$$\text{Sparse Table: } ST[i][j] = \min(ST[i][j-1], ST[i+2^{j-1}][j-1])$$

---

## 🚀 Deploy

El blog se deploya **automáticamente en Vercel** cada vez que haces push a la rama `main`.

No requiere configuración manual.

---

## 📄 Licencia

Este proyecto está bajo licencia **CC BY-NC-SA 4.0**.

- ✅ Puedes compartir y adaptar
- ❌ No para uso comercial
- ✅ Debes acreditar autoría
- ✅ Comparte bajo la misma licencia

---

## 🤝 Contribuciones

¿Encontraste un error o tienes sugerencias? Abre un issue o pull request.

---

**Creado con ❤️ usando [Hugo](https://gohugo.io) + [PaperMod](https://github.com/adityatelange/hugo-PaperMod)**
