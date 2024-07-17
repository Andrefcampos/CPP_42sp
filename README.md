# CPP Modules

![42 São Paulo](https://img.shields.io/badge/42-SP-000000)

## Table of Contents

- [About](#about)
- [Modules](#modules)
- [Requirements](#requirements)
- [How to Compile](#how-to-compile)
- [How to Use](#how-to-use)
- [File Structure](#file-structure)
- [Contributing](#contributing)
- [License](#license)

## About

The **CPP Module** project is part of the curriculum at [42 São Paulo](https://www.42sp.org.br/). This project aims to deepen the understanding of C++ programming by exploring advanced concepts and features of the language, such as object-oriented programming, templates, exception handling, and more.

## Modules

This project is divided into several modules, each focusing on different aspects of C++:

- **[Module00](module00)**: Basics of C++ (namespaces, classes, member functions, stdio streams, initialization lists, static, const, and more);
- **[Module01](module01)**: Memory Allocation (new, delete, pointers to members, references, file streams);
- **[Module02](module02)**: Ad-hoc Polymorphism, Operators Overloading;
- **[Module03](module03)**: Inheritance;
- **[Module04](module04)**: Subtype Polymorphism, Abstract Classes, Interfaces;
- **[Module05](module05)**: Repetition and Exceptions;
- **Module06**: C++ Casts;
- **Module07**: Templates;
- **Module08**: Templated Containers, Iterators, Algorithms.

## Requirements

- A C++ compiler supporting C++98 standard.
- Make utility for building the project.

## How to Compile

Each module comes with a Makefile to ease the compilation process. Navigate to the module directory and run the following command in the terminal:

```sh
make
```

This will compile the project and generate the executable file.

To clean up the object files generated during compilation:

```sh
make clean
```

To clean all generated files, including the executable:

```sh
make fclean
```

To recompile the project from scratch:

```sh
make re
```

## How to Use

After compiling the project, run the generated executable from the terminal:

```sh
./module_executable
```

Each module may have specific instructions on how to use and test the features implemented. Refer to the module's README or documentation for detailed usage.

## File Structure

The project directory structure is organized as follows:

```css
cpp_42sp/
├── module00/
│   ├── includes/
│   │   └── example.hpp
│   ├── srcs/
│   │   ├── main.cpp
│   │   └── example.cpp
│   ├── Makefile
│   ├── README.md
├── module01/
│   ├── includes/
│   │   └── another_example.hpp
│   ├── srcs/
│   │   ├── main.cpp
│   │   └── another_example.cpp
│   ├── Makefile
│   ├── README.md
├── ...
├── LICENSE
└── README.md
```

- module00/, module01/, ...: Directories for each module containing their respective source code, headers, and Makefiles;
- includes/: Contains the header files;
- srcs/: Contains the source code files;
- Makefile: Build script for the module;
- README.md: Documentation for the module;
- LICENSE: License file for the project.

## Contributing

Contributions are welcome! If you want to contribute to this project, please follow the steps below:

1. Fork the project;
2. Create a branch for your feature (git checkout -b feature/new-feature);
3. Commit your changes (git commit -am 'Add new feature');
4. Push to the branch (git push origin feature/new-feature);
5. Create a new Pull Request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE.txt) file for more details.
