# Ejercicios con cadenas de carácteres en C++

## Actividad 1

Escriba un algoritmo (programa) que utilice tipos de datos carácter para comparar si una determinada palabra (cadena de caracteres) es un palíndromo. Una palabra es palíndroma cuando la lectura directa e indirecta de la misma tiene el mismo valor.

<Ejemplo:>
alila es palíndromo, se lee en ambas direcciones.
         cara (arac) no es palíndromo.

La palabra se lee carácter por carácter y se almacena en una variable cadena de caracteres. Una vez leída la palabra, se procede a identificar si es o no palíndromo.

Nota: La aplicación debe permita al usuario introducir una cadena de caracteres (carácter por carácter), mientras la cadena no llegue al máximo de su tamaño o se presione la tecla Enter.

### Solución

```c++
const int MAX = 10;
    char palabra[MAX + 1]; // +1 Para el carácter nulo

    cout << "Introduce una palabra letra por letra (hasta " << MAX << " caracteres): ";

    for (int i = 0; i < MAX; i++) {
        char result = getchar();
        if (result == '\n'){ // detecta si se preciona la tecla ENTER para romper el ciclo;
            break;
        }
        palabra[i] = result; //añadimos el caracter introducido a la cadena de caracteres
    }

    palabra[strlen(palabra)] = '\0'; // Agregar el caracter nulo al final de la cadena

    cout << "Palabra ingresada: " << palabra << endl;

    return 0;
```

Ahora que tenemos la palabra introducida, vamos a comprobar si es palindromo o no lo es.

Para ello vamos a crear una funcion que retorne un valor booleano (verdadero o falso) como se muestra a continuacion:

```c++
bool esPalindromo(char palabra[]) {
    size_t longitud = strlen(palabra);
    
    // Invertir la cadena (algoritmo de burbuja)
    for (size_t i = 0, j = longitud - 1; i < j; ++i, --j) {
        char temp = palabra[i];
        palabra[i] = palabra[j];
        palabra[j] = temp;
    }

    // Comparar la cadena original con la cadena invertida
    return (strcmp(palabra, palabra) == 0);
}
```

Por último comparamos en el main mediante condicionales si la palabra es palindromo utilizando la funcion creada anteriormente

```c++
// Verificar si es un palíndromo
    if (esPalindromo(palabra)) {
        cout << "La palabra es un palindromo." << endl;
    } else {
        cout << "La palabra no es un palindromo." << endl;
    }
```

## Actividad 2

Escriba un programa que lea una frase compuesta por dos palabras en minuscula  e imprima en pantalla la misma frace con la primera letra de cada palabra en mayúscula.
