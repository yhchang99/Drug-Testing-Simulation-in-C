# Drug Testing Simulation in C
This program simulates the drug testing's problem in C. The drug testing problem is a scenario in which pairs of patients are treated sequentially with one member of the pair receiving drug 1 and the other drug 2.The results for each pair are determined, and the testing stops when the cumulative number of cures using one of the drugs exceeds the cumulative number of cures when using the other by some fixed predetermined number.

More formally, let
```math
X_j =
\begin{cases}
1, & \text{if the patient in the jth pair to receive drug number 1 is cured}\\
0, & \text{otherwise}
\end{cases}
```

For a predetermined positive integer **M**, the test stops after pair N where N is the first value of n such that either:
```math
\begin{cases}
X_1 + ... + X_n - (Y_1 + ... + Y_n) = M \\ 
X_1 + ... + X_n - (Y_1 + ... + Y_n) = -M
\end{cases}
```

This project is avaliable on: https://github.com/yhchang99/Drug-Testing-Simulation-in-C

## Usage
In practice, this test can be used to compare the efficacy of two drugs in a clinical trial. The predetermined number **M** can be chosen based on the desired level of confidence and the sample size of the trial. The test can also be modified to allow for multiple pairs of patients to be treated simultaneously or to include a placebo group.

## Installation
To compile and run the program, you must have a C compiler installed on your system, such as `GCC` or `Clang`.
Clone the repository to your local machine:

```bash
git clone https://github.com/yhchang99/Drug-Testing-Simulation-in-C.git
```
Navigate to the project directory:
```bash
cd Drug-Testing-Simulation-in-C
```

## Compile the program:

```bash
make
```
## Run the program:

```bash
./DrugTesting
```
## Plot the results of the program
To plot the diagram, you must have `gnuplot` installed on your local machine:
```bash
make plot
```

## Example
Here's an example usage of the program:

```bash
***********************************************
Drug Testing Parameters:
    Drug 1 cure rate:        0.90
    Drug 2 cure rate:        0.50
    test stop at M :           1
                                                                                                             
Average number of rounds needed: 2.00.
Results:
    Drug1 finish the test with prob:   90.2900%
    Drug2 finish the test with prob:   9.7100%
***********************************************
```
![Image text](https://github.com/yhchang99/Drug-Testing-Simulation-in-C/blob/anderson/image/results.jpg)


