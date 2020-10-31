# Grey Wolf Optimizer 

## Inspiration
Are considered as apex predator. Live in a pack. The group size is 5–12 on average.
Very strict social dominant hierarchy:

* Alphas: The leaders (dominant wolf ).
* Beta: Subordinate wolves.
* Delta: Have to submit to alphas and betas, but they dominate the omega. Omega: lowest ranking.

## Hunting phases:
* Tracking, chasing.
* Encircling.
* Attack the prey.

## Social hierarchy
Fittest solution respectively: α β δ ω

## Mathematical Model

### Hunting
Guided by the alpha. We have no idea about the location of the optimum(prey).
Therefore, we save the first three best solutions obtained so far and oblige the other search agents
(including the omegas) to update their positions according to the position of the best search agents.

###
* Attack prey (exploitation), |A| < 1
* Search for prey (exploration), |A| > 1

## Search Process
+ Creating a random population of grey wolves.
+ Alpha, beta, and delta wolves estimate the probable position of the prey.
+ Each candidate solution updates its distance from the prey.
+ The parameter a is decreased from 2 to 0 in order to emphasize exploration and exploitation.
+ Candidate solutions tend to diverge from the prey when |A| > 1 and converge towards the prey when |A| < 1.
+ GWO algorithm is terminated by the satisfaction of an end criterion.

# Motivation
There is no meta-heuristic best suited for solving all optimization problems.
NFL makes this field of study highly active. Hence motivates authors of GWO to develop a new
meta-heuristic with inspiration from grey wolves.

# What is Meta-heuristics ?
Why meta-heuristics have become remarkably common:

* Fairly simple: The simplicity assists scientists to
learn meta-heuristics quickly and apply them to their
problems.
* Flexibility: Applicability of meta-heuristics to different
problems without any special changes in the structure of
the algorithm.
* Derivation-free: The optimization process starts with
random solution(s), and there is no need to calculate the
derivative of search spaces to find the opti-mum.
* Avoid local optima: Due to the stochastic nature of
meta-heuristics which allow them to avoid stagnation in
local solutions and search the entire search space.

# Meta-heuristics search process
* Exploration: The process of investigating the promising
area(s) of the search space as broadly as possible,
(an algorithm needs to have stochastic operators to
randomly search).
* Exploitation: the local search capability around the
promising regions obtained in the exploration phase.
Finding a proper balance between these two phases is
considered a challenging task due to the stochastic
nature of meta-heuristic.

# Development toolchains:
The proposed algorithm was developed under Debian Linux 64bit operating system (version 8.1.0), with the following  toolchains:

| Tool name | Version  | Description  |
| :---:   | :-: | :-: |
| g++ | 5.4.0 | C++ compiler (standard 0x11) |
| ld | 2.26.1 | GNU linker |
| make | 4.1 |  GNU make (builder) |
    
# How to compile:
Locate the root source code, then type the folowing:
```
$ make clean
$ make
```
If the compilation process proceeds successfully, you will see "gwo" binary under build directory.

# Benchmark usage:
```
./gwo -name [-population_size] [-iterations] [-debug]
where:
    -name               [required]    Benchmark name: F1, F2, F3, F4, F5, F6, F7
    -population_size    [optinal ]    integer >= 0, default(30)
    -iterations         [optinal ]    integer >= 0, defualt(500)
    -debug              [optinal ]    show debugging info, defualt(false)

```

# Run benchmarks:
In this release, I only added support for seven benchmarks: F1, F2, F3, F4, F5, F6 and F7; which represent the Unimodal functions. For more information about the benchmarks, please see the reference section.

## Example
```
$ build/gwo -name F3 -population_size 100 -iterations 1000
```

# Author
Ahmad Dajani
Email: eng.adajani@gmail.com

# Reference
+ Grey Wolf Optimizer: http://dx.doi.org/10.1016/j.advengsoft.2013.12.007
