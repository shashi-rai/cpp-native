# Bhojpur C++ - Native Collections

This source code repository is designed to be used by Software Developers. It
comprises of a collection of commonly used software __algorithms__ written in
**C++** __programming language__. A set of native (e.g., macOS, Linux, UNIX)
environment C++ libraries located in specific folders could be compiled by the
software developers to include the same in their own industry applications.

## Basic Requirements

Prior to using this source code repository, a POSIX compliant software
development environment would be required. Ideally, you could have 

1. __macOS__ or __Linux__ operating system
2. __git__ - version control system for maintaining the source code
3. __make__ - software build tool to compile all C++ programs
4. GNU __C++__ Compiler - free &amp; open source software
5. Microsoft Visual Studio Code IDE for editing the source code

## Folder Hierarchy

The following folders serve specific purpose with regard to software development

1. [inc](/inc/) - include header files
2. [lib](/lib/) - pre-compiled library files
3. [obj](/obj/) - pre-compiled object files
4. [act](/act/) - financial accounting algorithms
5. [bio](/bio/) - biological algorithms
6. [bit](/bit/) - information theory algorithms
7. [che](/che/) - chemical algorithms
8. [doc](/doc/) - document assembly algorithms
9. [dsa](/dsa/) - data structure algorithms
10. [ecn](/ecn/) - electronic circuit algorithms
11. [eco](/eco/) - economic model algorithms
12. [fin](/fin/) - financial algorithms
13. [gis](/gis/) - geospatial system algorithms
14. [grt](/grt/) - general relativity algorithms
15. [img](/img/) - digital imaging algorithms
16. [law](/law/) - legal matter algorithms
17. [phy](/phy/) - physical algorithms
18. [qft](/qft/) - quantum field algorithms
19. [shp](/shp/) - geometrical shape algorithms
20. [web](/web/) - web development system

## Source Code Compilation

Besides using the following command in the main folder, you could compile each
domain-specific folder independently. The following command would build all the
sub-folders as well. It will add native libraries into [lib](/lib/) folder.

```bash
$ make all
```

Once all the vative libraries are built in respective sub-directories, you could
compile a custom software application alone by simply using the following command

```bash
$ make app
```

For example, the [bhojpur.app](bhojpur.app) is a custom application built from
[main.cpp](main.cpp) in the root folder.

### Understanding Dependencies

The microscropic realm phenomenon is modeled using the following native C++ libraries

- firstly, the [dsa](/dsa/) library must be compiled to use available data containers
- then, compile [shp](/shp/) library which forms the base for several other libraries
- then, compile [img](/img/) library which forms the base for image processing libraries
- then, compile [qft](/qft/) library that models core concepts of the physical reality
- then, compile [phy](/phy/) library that builds on [qft](/qft/) to model the Physics
- then, compile [che](/che/) library that builds on [phy](/phy/) to model the Chemistry
- then, compile [bio](/bio/) library that builds on [che](/che/) to model the Biology
- then, compile [ecn](/ecn/) library that builds on [qft](/qft/) to model the Circuits
- then, compile [bit](/bit/) library that builds on [qft](/qft/) to model the Information

The macro-world phenomenon is modeled using the following native C++ libraries

- the [gis](/gis/) library could be compiled after [shp](/shp/) library is ready
- the [grt](/grt/) library could be compiled after [gis](/gis/) library is ready

The legal system is modeled using the following native C++ libraries

- the [doc](/doc/) library could be compiled after [act](/act/) library is ready
- the [law](/law/) library could be compiled after [doc](/doc/) library is ready

The financial system is modeled using the following native C++ libraries

- the [act](/act/) library could be compiled after [shp](/shp/) library is ready
- the [eco](/eco/) library could be compiled after [act](/act/) library is ready
- the [fin](/fin/) library could be compiled after [act](/act/) library is ready

## Folder Cleanup

To clean up all the temporary files and folders (e.g., obj, lib)

```bash
$ make clean
```

However, to clean up pre-compiled C++ object files containing folder alone,
you can issue the following command

```bash
$ make clean-objs
```

Also, to clean up pre-compiled C++ library files containing folder alone,
you can issue the following command 

```bash
$ make clean-libs
```

And, to clean up only pre-compiled custom application files, you can issue
the following command

```bash
$ make clean-apps
```

## Source Code Repository

The entire source code of [cpp-native](https://github.com/shashi-rai/cpp-native) is
maintained at [GitHub](https://github.com). You could push modified source code to
this repository by using the following command

```bash
$ make repo
```

However, update changed files by issueing the following commands first. For example

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

To run [bhojpur.app](bhojpur.app) (i.e., a custom application program) built
using native C++ libraries compiled after calling __make__ command, you could
issue the following command in your shell environment

```bash
$ ./bhojpur.app -v
```

It would simply print a copyright message. Perhaps, you could customize this
[main.cpp](main.cpp) source code file and recompile it to test your new ideas
further.

## Software Developers

- Mr. [Shashi Bhushan Rai](https://github.com/shashi-rai/), [Bhojpur Consulting](https://github.com/bhojpur/), Arrah, Bihar
- Mrs. [Bimla Pandey]((https://github.com/bimla-pandey/)), [Bhojpur Consulting](https://github.com/bhojpur/), Arrah, Bihar
- Ms. [Divya Rai](https://github.com/dvya-rai/), [Bhojpur Consulting](https://github.com/bhojpur/), Arrah, Bihar
- Ms. Anushka Rai, [Bhojpur Consulting](https://github.com/bhojpur/), Arrah, Bihar

## Copyright Owner

This software is created and distributed originally by

- [Bhojpur Consulting Private Limited](https://www.bhojpur-consulting.com), India
