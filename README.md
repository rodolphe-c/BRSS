Copyright © 2017 Rodolphe Cargnello, rodolphe.cargnello@u-psud.fr <br />

# BRSS - Biochemical Reaction Stochastic Simulator
![Image of BRSS](https://raw.githubusercontent.com/rodolphe-c/BRSS/master/img/brss.png)

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
- [Qwt](http://qwt.sourceforge.net/)
- [OpenSceneGraph](http://www.openscenegraph.org/)

On macOS Sierra with Homebrew:

```sh
brew install boost --c++11
brew install qt5
brew install qwt
brew install open-scene-graph --c++11 --with-qt5
```

On Ubuntu 16.10:

```sh
sudo apt install libboost-all-dev
sudo apt install qttools5-dev
sudo apt install libqwt-qt5-dev
sudo apt install libopenscenegraph-3.4-dev
```

### Compilation with CMake

```sh
mkdir build
cd build
cmake ..
make
./brss ../test.mcl
./compiler ../test.mcl
./global ../test.mcl
```
