# Bhojpur C++ - Native Collections

A collection of common software algorithms written in C++ programming language

## Basic Requirements

1. Linux operating system
2. GNU C++ Compiler

## Folder Hierarchy

1. [inc](/dsa/) - include header files
2. [lib](/lib/) - pre-compiled library files
3. [obj](/obj/) - pre-compiled object files
4. [dsa](/dsa/) - data structure algorithms 

## Source Code Compilation

```bash
$ make all
```

## Folder Cleanup

To clean all temporary folders

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