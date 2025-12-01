# Bhojpur C++ - Native Collections

This repository is meant for software developers. It comprises of a collection
of commonly used __algorithms__ written in **C++** __programming language__. A
set of native libraries located in specific folders can be compiled by software
developers to include the same in their own applications.

## Basic Requirements

Prior to start using this repository, a POSIX compliant software development
environment would be required. Ideally, you could have 

1. __macOS__ or __Linux__ operating system
2. __git__ - version control system
3. __make__ - software build tool
4. GNU __C++__ Compiler
5. Microsoft Visual Studio Code IDE

## Folder Hierarchy

The following folders serve specific purpose with regard to software development

1. [inc](/inc/) - include header files
2. [lib](/lib/) - pre-compiled library files
3. [obj](/obj/) - pre-compiled object files
4. [bio](/bio/) - biological algorithms
5. [che](/che/) - chemical algorithms
6. [dsa](/dsa/) - data structure algorithms
7. [gis](/gis/) - geospatial system algorithms
8. [grt](/grt/) - general relativity algorithms
9. [phy](/phy/) - physical algorithms
10. [qft](/qft/) - quantum field algorithms
11. [shp](/shp/) - geometrical shape algorithms
12. [web](/web/) - web development system

## Source Code Compilation

Besides using following command in the main folder, you could compile each
domain-specific folder independently

```bash
$ make all
```

### Understanding Dependencies

The micro-world phenomenon is modeled using the following libraries

- firstly, the [dsa](/dsa/) library must be compiled to use available data containers
- then, compile [shp](/shp/) library which forms the base for several other libraries
- then, compile [qft](/qft/) library that models core concepts of the physical reality
- then, compile [phy](/phy/) library that builds on [qft](/qft/) to model the Physics
- then, compile [che](/che/) library that builds on [phy](/phy/) to model the Chemistry
- then, compile [bio](/bio/) library that builds on [che](/che/) to model the Biology

The macro-world phenomenon is modeled using the following libraries

- the [gis](/gis/) library could be compiled after [shp](/shp/) library is ready
- the [grt](/grt/) library could be compiled after [gis](/gis/) library is ready

## Folder Cleanup

To clean all temporary file folders (e.g., obj, lib)

```bash
$ make clean
```

To clean only pre-compiled object files folder

```bash
$ make clean-objs
```

To clean only pre-compiled library folder

```bash
$ make clean-libs
```

To clean only pre-compiled application files

```bash
$ make clean-apps
```

## Software Developer

- Shashi Bhushan Rai