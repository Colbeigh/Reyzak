# Template for CPSC2720 Two Week Project

Last Updated: 2024.09.16 by Nicole Wilson [n.wilson@uleth.ca]

Notes:

* The Makefile and .gitlab-ci.yml files are provided.
* The .gitlab-ci.yml file uses the targets in the Makefile.
* These are the tools/commands/apps used:
  * Compiler: g++ 
  * Style Check: cpplint
  * Static Check: cppcheck
  * Memory Check: valgrind
* Use `make version` to see the versions of the tools.

Certain assumptions have been made:
* One repo contains the files for one project.
* All header files for the project are found in <code>include/</code> and named <code>*.hpp</code>, every class must have a header file.
* All project source files for the project are named <code>*.cpp</code>.
  * Any needed source files that correspond to header files are found in <code>src/</code>.
  * There is a <code>main.cpp</code> found in <code>src/project/</code>.
