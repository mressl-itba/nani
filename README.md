# Level 2: 何？

En esta práctica vas a hacer **identificación automática de lenguajes**.

## Contexto: intercambio en el otro lado del mundo

![Logo](img/logo.png)

Año 2027. Lograste un intercambio en una universidad de Asia. Todo parecía soñado… hasta que llegaste.

Los carteles, los mails institucionales, el campus virtual… **todo está en idiomas que no reconoces**. Algunos parecen japonés, otros coreano, otros quizás chino… o algo completamente distinto.

Tu universidad de origen decidió ayudarte enviándote un repositorio incompleto.

**Tu misión:** reconstruir un sistema de *language identification* capaz de detectar automáticamente el idioma de cualquier texto que encuentres.

Porque si no puedes leer el menú del comedor… las cosas se van a complicar rápidamente.

## El problema a resolver

Queremos identificar el idioma de un texto dado.

La idea general es:

* Analizar el texto
* Compararlo con perfiles de distintos idiomas
* Elegir el idioma más parecido

Para esto utilizaremos una técnica clásica: **perfiles de trigramas**.

## Concepto clave: perfiles de trigramas

Un **trigrama** es una subcadena de tres caracteres consecutivos.

Por ejemplo, para la cadena:

"ANANA Y BANANA"

los trigramas (con sus frecuencias) son:

* "ANA" → 4
* "NAN" → 2
* "NA " → 1
* "A Y" → 1
* " Y " → 1
* "Y B" → 1
* " BA" → 1
* "BAN" → 1
* "NDA" → 1
* "DAN" → 1

Cada texto puede representarse como un **perfil de trigramas**:

* **Clave:** trigrama (string de longitud 3)
* **Valor:** frecuencia

Distintos idiomas presentan **distribuciones de trigramas muy diferentes**, lo que permite identificarlos.

## Restricción importante

En este trabajo:

* Trabaja directamente con bytes (`char`).
* No es necesario decodificar UTF-8 (si no sabes qué implica esto, consúltalo a la IA).

Esto simplifica la implementación, aunque tiene implicancias interesantes que deberás analizar luego.

## La misión

Debes implementar la función principal:

```cpp
std::string IdentifyLanguage(const char *text, LanguageProfiles &language_profiles);
```

La función debe devolver el código del lenguaje detectado.

## Etapas sugeridas

Una posible estrategia:

1. Construcción del perfil

    * Recorre el texto línea por línea
    * Ignora líneas con menos de 3 caracteres
    * Extrae todos los trigramas
    * Cuenta sus frecuencias

2. Normalización

    Para que puedas comparar textos cortos y largos, normaliza el perfil.

    Estrategia:

    * Calcula la suma de los cuadrados de las frecuencias
    * Divide cada frecuencia por la raíz cuadrada de esa suma

    Esto convierte el perfil en un vector normalizado.

3. Comparación de perfiles

    Para comparar dos perfiles, puedes usar la **similitud coseno**:

    * Multiplica las frecuencias de los trigramas en común
    * Suma los productos

    Sólo importan los trigramas compartidos.

4. Decisión final

    * Compara el texto contra todos los idiomas disponibles
    * Elige el de mayor similitud

## Exploración y evaluación

Una vez que tu sistema funcione, reflexiona:

* ¿Cuál es la complejidad computacional de tu algoritmo?
* ¿Qué tan bien distingue idiomas similares?
* ¿Qué ocurre con textos muy cortos?
* ¿Qué pasa con idiomas que comparten alfabeto?
* ¿Cómo afecta trabajar a nivel de bytes en lugar de caracteres?

Responde estas preguntas en `ENTREGA.md`.

## Recomendaciones

* Evita copias innecesarias (usa referencias & de C++)
* Usa estructuras de datos eficientes
* Piensa antes de programar: este problema es más de diseño que de código

## Bonus points 🚀

* Investiga en profundidad la similitud coseno
* Añade nuevos “idiomas” (por ejemplo: guaraní, C++, Python...)
* Analiza el impacto de usar bigramas vs. trigramas
* Mejora la performance para textos grandes
* Experimenta con otras métricas de similitud

Documenta todo en `ENTREGA.md`.

## Epílogo

Después de varios días… tu sistema empieza a funcionar.

El cartel del comedor ya no es un misterio.

El campus deja de ser un glitch cultural.

Y por primera vez desde que llegaste, entiendes lo que dice:

    今日のメニュー

Probablemente deberías seguir mejorando el algoritmo… pero al menos ya sabes qué vas a almorzar.
