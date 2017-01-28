Copyright © 2017 Rodolphe Cargnello, rodolphe.cargnello@u-psud.fr <br />

# BRSS - Biochemical Reaction Stochastic Simulator

BRSS is a study and research project supervised by Mr. [Patrick Amar](https://www.lri.fr/~pa/) in the framework of the simulation of biochemical reaction. [(Subject)](https://perso.limsi.fr/Individu/allauzen/cours/ter/TER-Simulation.html)<br /><br />
  This project is divided into 3 modules:<br />

  - Lexical and syntactic parsers of the reactions description language<br />

  - Resolution engines (sequential and parallel)<br />

  - Output filters: temporal concentration curves in real time.

Clone it to run the different exemples:

```sh
git https://github.com/rodolphe-c/BRSS.git
cd BRSS
```

### System Requirement

Required:

- C++11 compiler
- [Boost] (http://www.boost.org/)
- [Qt5](https://www.qt.io/)
- [OpenSceneGraph](http://www.openscenegraph.org/)
- [QCustomPlot](http://www.qcustomplot.com/)

### Compilation with CMake

```sh
mkdir build
cd build
cmake ..
make
./brss
```
