# Drug Testing Simulation in C
This program simulates the drug testing's problem in C. The drug testing problem is a scenario in which pairs of patients are treated sequentially with one member of the pair receiving drug 1 and the other drug 2.The results for each pair are determined, and the testing stops when the cumulative number of cures using one of the drugs exceeds the cumulative number of cures when using the other by some fixed predetermined number.

More formally, let
$$ X_j =
\begin{cases}
1, & \text{if the patient in the jth pair to receive drug number 1 is cured}\\
0, & \text{otherwise}
\end{cases}
$$

For a predetermined positive integer **M**, the test stops after pair N where N is the first value of n such that either:
$$
X_1 + ... + X_n - (Y_1 + ... + Y_n) = M,
$$

This project is avaliable on: https://github.com/yhchang99/Drug-Testing-Simulation-in-C

## Usage
In practice, this test can be used to compare the efficacy of two drugs in a clinical trial. The predetermined number **M** can be chosen based on the desired level of confidence and the sample size of the trial. The test can also be modified to allow for multiple pairs of patients to be treated simultaneously or to include a placebo group.

## Installation
To compile and run the program, you must have a C compiler installed on your system, such as GCC or Clang.
Clone the repository to your local machine:

```bash
git clone https://github.com/yhchang99/Drug-Testing-Simulation-in-C.git
```
Navigate to the project directory:
```bash
cd gambler-ruin-c
```

## Compile the program:

```bash
make
```
## Run the program:

```bash
./DrugTesting
```

## Example
Here's an example usage of the program:

```
Drug Testing Parameters:
    Drug 1 cure rate:        0.60
    Drug 2 cure rate:        0.40
    test stop at M :           10
                                                                                                             
Average number of rounds needed: 50.00.
Results:
    Drug1:   59.9678%
    Drug2:   40.0639%
```

## License
There is no license for this project.
