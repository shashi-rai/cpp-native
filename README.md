# Bhojpur C++ - Native Collections

This repository is meant for software developers. It comprises of a collection
of commonly used __algorithms__ written in **C++** __programming language__. A
set of native libraries located in specific folders can be compiled by software
developers to include the same in their own applications.

## Basic Requirements

Prior using this repository, a POSIX compliant software development environment
would be required. Ideally, you could have 

1. __macOS__ or __Linux__ operating system
2. __git__ - version control system for maintaining the source code
3. __make__ - software build tool to compile C++ programs
4. GNU __C++__ Compiler - free &amp; opern soure software
5. Microsoft Visual Studio Code IDE for editing the source code

## Folder Hierarchy

The following folders serve specific purpose with regard to software development

1. [inc](/inc/) - include header files
2. [lib](/lib/) - pre-compiled library files
3. [obj](/obj/) - pre-compiled object files
4. [act](/act/) - accounting algorithms
5. [bio](/bio/) - biological algorithms
6. [bit](/bit/) - information theory algorithms
7. [che](/che/) - chemical algorithms
8. [dsa](/dsa/) - data structure algorithms
9. [eco](/eco/) - economics algorithms
10. [fin](/fin/) - financial algorithms
11. [gis](/gis/) - geospatial system algorithms
12. [grt](/grt/) - general relativity algorithms
13. [phy](/phy/) - physical algorithms
14. [qft](/qft/) - quantum field algorithms
15. [shp](/shp/) - geometrical shape algorithms
16. [web](/web/) - web development system

## Source Code Compilation

Besides using te following command in the main folder, you could compile each
domain-specific folder independently

```bash
$ make all
```

Once all the libraries are built in respective sub-directories, you could compile
the application alone by simply using the following command

```bash
$ make app
```

### Understanding Dependencies

The micro-world phenomenon is modeled using the following libraries

- firstly, the [dsa](/dsa/) library must be compiled to use available data containers
- then, compile [shp](/shp/) library which forms the base for several other libraries
- then, compile [qft](/qft/) library that models core concepts of the physical reality
- then, compile [phy](/phy/) library that builds on [qft](/qft/) to model the Physics
- then, compile [che](/che/) library that builds on [phy](/phy/) to model the Chemistry
- then, compile [bio](/bio/) library that builds on [che](/che/) to model the Biology
- then, compile [bit](/bit/) library that builds on [qft](/qft/) to model the Information

The macro-world phenomenon is modeled using the following libraries

- the [gis](/gis/) library could be compiled after [shp](/shp/) library is ready
- the [grt](/grt/) library could be compiled after [gis](/gis/) library is ready

The financial system is modeled using the following libraries

- the [act](/act/) library could be compiled after [shp](/shp/) library is ready
- the [eco](/eco/) library could be compiled after [act](/act/) library is ready
- the [fin](/fin/) library could be compiled after [act](/act/) library is ready

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

## Source Code Repository

The source code of [cpp-native](https://github.com/shashi-rai/cpp-native) is fully
maintained at [GitHub](https://github.com). You could push modified source code to
the repository using the following command

```bash
$ make repo
```

However, use the changed commands first. For example

### Add Source File/Folder

To add new or affectd files or folders

```bash
$ git add a.cpp
```

### Remove Source File/Folder

To remove existing files or folders

```bash
$ git rm a.cpp
```

## Executing Sample Application

To run [bhojpur.app](bhojpur.app) (i.e., sample program) built using libraries
compiled after calling __make__ command, you can issue the following in your
command shell

```bash
$ ./bhojpur.app -v
```

It would simply print a copyright message. Perhaps, you could customise this
[main.cpp](main.cpp) file further and recompile to test your ideas.

## Software Developer

- Shashi Bhushan Rai, [Bhojpur Consulting Private Limited](https://www.bhojpur-consulting.com), India
