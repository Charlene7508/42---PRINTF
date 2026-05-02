*This activity has been created as part of the 42 curriculum by chlepain.*


# 42---FT_PRINTF

**Recoder la fonction printf de la libc en gérant les fonctions variadiques en C.**

---

## 📌 Description
Ce projet est réalisé dans le cadre du **Tronc Commun de l'École 42**. Il introduit un concept fondamental du langage C : les **fonctions variadiques**, c'est-à-dire des fonctions capables d'accepter un nombre variable d'arguments, via l'utilisation de `<stdarg.h>`.

- **Objectif :** Écrire une fonction `ft_printf()` capable de gérer les principales conversions de la vraie `printf`, en retournant le nombre de caractères écrits.
- **Langage & outils :** C (Norme 42), GCC, Valgrind.


### Prototype de la fonction

```c
int ft_printf(const char *format, ...);
```

| Paramètre | Description |
|-----------|-------------|
| `format` | La chaîne de format contenant le texte et les spécificateurs (`%d`, `%s`...) |
| `...` | Les arguments variables correspondant aux spécificateurs |


### Conversions gérées

| Spécificateur | Type attendu | Exemple |
|---------------|--------------|---------|
| `%c` | char | `ft_printf("%c", 'A')` → `A` |
| `%s` | char * | `ft_printf("%s", "hello")` → `hello` |
| `%p` | void * | `ft_printf("%p", ptr)` → `0x7fff...` |
| `%d` / `%i` | int | `ft_printf("%d", 42)` → `42` |
| `%u` | unsigned int | `ft_printf("%u", 42)` → `42` |
| `%x` | hexadecimal| `ft_printf("%x", 255)` → `ff` |
| `%X` | hexadecimal maj | `ft_printf("%X", 255)` → `FF` |
| `%%` | (aucun) | `ft_printf("%%")` → `%` |


---


## 🛠️ Compétences techniques validées
- **Fonctions variadiques :** Utilisation de `va_list`, `va_start`, `va_arg`, `va_end` pour lire un nombre variable d'arguments.
- **Parsing de chaîne :** Parcours caractère par caractère d'une format string pour détecter et dispatcher les spécificateurs.
- **Récursion :** Conversion de nombres en bases décimale et hexadécimale via des fonctions récursives.
- **Cas limites :** Gestion de INT_MIN, pointeurs NULL, strings vides et format string se terminant par `%`.


## 🎯 Approche projet & soft skills
Au-delà de la technique, la réalisation de ce projet m'a permis de consolider des piliers essentiels à tout environnement professionnel :
1. **Rigueur & normes :** Respect d'un cahier des charges strict (La Norme 42) et de contraintes de qualité logicielle élevées.
2. **Autonomie & résolution de problèmes :** Capacité à décomposer un problème complexe (recoder printf) en sous-fonctions claires et indépendantes.
3. **Conception durable :** Architecture modulaire avec une responsabilité unique par fichier, pensée pour être maintenue et étendue.
4. **Gestion de l'incertitude :** Recherche et auto-formation sur des concepts non enseignés (variadiques, promotion de types, stack).


## 📐 Architecture retenue

Le projet a été structuré autour de **8 fichiers** aux responsabilités clairement séparées :

1. **`ft_printf.c`** — point d'entrée, initialise `va_list` et parcourt la format string. Contient aussi `ft_specificateur` qui dispatche vers la bonne fonction selon le spécificateur détecté.
2. **`ft_print_char.c`** — gère `%c`, écrit un caractère avec `write()`.
3. **`ft_print_str.c`** — gère `%s`, affiche la string ou `(null)` si le pointeur est NULL.
4. **`ft_print_int.c`** — gère `%d` et `%i`, travaille en `long` pour absorber INT_MIN sans overflow.
5. **`ft_print_uint.c`** — gère `%u`, affiche un entier non signé de façon récursive.
6. **`ft_print_hex.c`** — gère `%x` et `%X`, convertit en base 16 via une chaîne de base indexée.
7. **`ft_print_ptr.c`** — gère `%p`, affiche l'adresse avec le préfixe `0x`, gère le cas NULL → `(nil)`.
8. **`ft_putchar.c`** — écrit un caractère brut et retourne 1.


## 📖 Ressources

### Documentation de référence
- [Man pages C](https://www.man7.org/linux/man-pages/) — référence des fonctions libc
- [cppreference.com](https://en.cppreference.com/w/c) — documentation C complète
- [Valgrind](https://valgrind.org/docs/manual/quick-start.html) — détection des fuites mémoire
- [La Norme 42](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf) — règles de codage

### Utilisation de l'IA
L'IA (Claude) a été utilisée dans ce projet comme outil pédagogique pour :
- **Comprendre les concepts** : explications des fonctions variadiques, de la promotion des types, de la stack
- **Révision** : génération d'un cours complet sur ft_printf avec schémas et exemples annotés
- **Tests** : aide à la création du fichier de test couvrant tous les cas limites
- **Débogage** : analyse des erreurs de compilation et de logique (boucle infinie dans `ft_print_str`, overflow INT_MIN)


## 💻 Installation & utilisation

1. Clonez le dépôt :
```
git clone [https://github.com/Charlene7508/42---PRINTF.git]
```

2. Compilez le projet :
```
cc -Wall -Wextra -Werror *.c -o test
```

3. Exécutez :
```
./test
```

4. Vérifiez les fuites mémoire :
```
valgrind --leak-check=full ./test
```
