# Guía de Contribución

¡Gracias por tu interés en contribuir al Blog Dev! Aceptamos contribuciones de la comunidad en forma de nuevos artículos, correcciones y mejoras.

---

## Tipos de Posts Aceptados

- **Análisis Semanal**: Problemas resueltos con explicaciones detalladas
- **Tutoriales**: Estructuras de datos, algoritmos, técnicas avanzadas
- **Editoriales**: Soluciones completas a contests (Codeforces, AtCoder, etc)

---

## Estándar de Contenido

### Estructura Recomendada

1. **Introducción**: Presenta el problema/tema
2. **Análisis**: Explica la idea, estrategia y fórmulas matemáticas
3. **Implementación**: Código compilable, probado y comentado
4. **Conclusión**: Reflexión, variantes o problemas relacionados

### Requisitos Mínimos

- Mínimo **500 palabras**
- Código **compilable y probado**
- Mínimo **1 imagen o diagrama** (especialmente para tutoriales)
- Fórmulas matemáticas con **KaTeX** cuando sea relevante
- **Referencias** a fuentes o problemas originales (Codeforces, SPOJ, etc)

### Estilo

- Lenguaje claro, evita jerga innecesaria
- Primera persona permitida ("yo", "nosotros")
- Código con sintaxis highlighting: ` ```cpp `, ` ```python `, etc
- Links válidos a plataformas de problemas
- Español preferible (pero inglés es aceptado)

---

## Proceso de Publicación

```bash
# 1. Fork del repositorio en GitHub

# 2. Clonar tu fork localmente
git clone https://github.com/tu-usuario/mi-blog-dev.git
cd mi-blog-dev

# 3. Crear rama para tu contribución
git checkout -b posts/tu-tema

# 4. Crear nuevo post
hugo new posts/categoria/nombre-post.md

# 5. Escribir contenido en tu editor
# (Asegúrate que draft: false)

# 6. Probar localmente
hugo server
# Abre http://localhost:1313

# 7. Commit y push
git add content/posts/
git commit -m "feat: add post about tema"
git push origin posts/tu-tema

# 8. Abrir Pull Request en GitHub
```

---

## Checklist Pre-Publicación

Antes de enviar tu PR, asegúrate de:

- [ ] `hugo --minify` compila sin errores
- [ ] Fórmulas KaTeX se renderizan correctamente ($x^2 + y^2$)
- [ ] Imágenes cargan correctamente (sin paths rotos)
- [ ] Links internos y externos son válidos
- [ ] Frontmatter completo: `title`, `date`, `categories`, `tags`, `description`
- [ ] Mínimo 500 palabras
- [ ] Código está probado y compilable
- [ ] `draft: false`

---

## Preguntas Frecuentes

**¿Puedo escribir en inglés?**
Sí, pero preferimos español. Si escribes en inglés, incluye translations claras.

**¿Cuánto tarda el review?**
Generalmente 1-2 semanas, depende de la complejidad.

**¿Cómo me doy crédito?**
En el frontmatter `author: "Tu Nombre"` o menciona tu usuario de GitHub.

**¿Qué si tengo dudas?**
Abre una issue o contacta directamente a @cristoballongares.

---

**Gracias por contribuir al blog. ¡Esperamos tus aportes!** 🚀
