# 📄 README.md — **CipheFile**
---

## 🇪🇸 Español

# CipheFile

**CipheFile** es una aplicación de escritorio que permite cifrar y descifrar archivos de texto
mediante criptografía moderna, ofreciendo una interfaz gráfica intuitiva y una vista previa
del contenido antes de guardar los resultados.

El proyecto está enfocado en buenas prácticas de arquitectura de software, seguridad y claridad,
y ha sido desarrollado como proyecto personal de portafolio.
---

## ✨ Características
* Cifrado y descifrado de archivos de texto (`.txt`)
* Selección de distintos algoritmos de cifrado
* Cifrado basado en contraseña
* Vista previa del contenido cifrado o descifrado
* Interfaz gráfica clara e intuitiva
* Aplicación multiplataforma (Windows / Linux)
---

## 🧰 Tecnologías utilizadas
* **Lenguaje:** C++ (C++17 / C++20)
* **Interfaz gráfica:** Qt 6
* **Criptografía:** libsodium
* **Sistema de compilación:** CMake
* **Control de versiones:** Git & GitHub
---

## 🧱 Arquitectura
El proyecto sigue una arquitectura por capas con separación clara de responsabilidades:
* **UI:** Interfaz gráfica basada en Qt
* **Capa de aplicación:** Orquesta las acciones del usuario
* **Core:** Gestión de archivos y lógica de dominio
* **Crypto:** Operaciones criptográficas mediante libsodium
Este enfoque mejora la mantenibilidad, testabilidad y escalabilidad del proyecto.
---

## ⚙️ Compilación

### Requisitos
* CMake >= 3.16
* Compilador C++ con soporte C++17
* Qt 6
* libsodium

### Pasos

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## ▶️ Uso básico
1. Ejecutar la aplicación
2. Seleccionar un archivo de texto (`.txt`)
3. Elegir el algoritmo de cifrado
4. Ingresar una contraseña
5. Visualizar la vista previa del resultado
6. Guardar el archivo cifrado o descifrado
---

## 🔐 Consideraciones de seguridad
* Las contraseñas **no se almacenan**
* Las claves se derivan mediante funciones seguras
* Los archivos cifrados son intencionalmente ilegibles sin la contraseña correcta
* Este proyecto es de carácter educativo y de portafolio, y **no ha sido auditado externamente**
---

## 🚧 Estado del proyecto
CipheFile se encuentra en desarrollo activo.
Funciones planificadas:
* Soporte para más algoritmos de cifrado
* Mejora del sistema de vista previa
* Pruebas automatizadas
* Mejor manejo de errores
---

## 📄 Licencia
Este proyecto se distribuye bajo la licencia MIT.
---

## 🇬🇧 English

# CipheFile

**CipheFile** is a desktop application that allows users to encrypt and decrypt
text files using modern cryptography, providing an intuitive graphical interface
and a preview of the content before saving the results.

The project is focused on good software architecture practices, security, and clarity,
and was developed as a personal portfolio project.
---

## ✨ Features
* Encryption and decryption of text files (`.txt`)
* Multiple encryption algorithm options
* Password-based encryption
* Preview of encrypted or decrypted content
* Clean and intuitive graphical interface
* Cross-platform application (Windows / Linux)
---

## 🧰 Tech Stack
* **Language:** C++ (C++17 / C++20)
* **GUI:** Qt 6
* **Cryptography:** libsodium
* **Build system:** CMake
* **Version control:** Git & GitHub
---

## 🧱 Architecture
The project follows a layered architecture with clear separation of concerns:
* **UI:** Qt-based graphical interface
* **Application layer:** Orchestrates user actions
* **Core:** File handling and domain logic
* **Crypto:** Cryptographic operations using libsodium
This design improves maintainability, testability, and scalability.
---

## ⚙️ Build Instructions

### Prerequisites
* CMake >= 3.16
* C++ compiler with C++17 support
* Qt 6
* libsodium

### Build
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## ▶️ Basic Usage
1. Launch the application
2. Select a text file (`.txt`)
3. Choose an encryption algorithm
4. Enter a password
5. Preview the result
6. Save the encrypted or decrypted file
---

## 🔐 Security Notes
* Passwords are **never stored**
* Keys are derived using secure key derivation functions
* Encrypted files are intentionally unreadable without the correct password
* This project is intended for educational and portfolio purposes and has **not been externally audited**
---

## 🚧 Project Status
CipheFile is currently under active development.
Planned features:
* Additional encryption algorithms
* Improved preview system
* Automated tests
* Enhanced error handling
---

## 📄 License
This project is licensed under the MIT License.
---