# Simulated Internet Cafe Manager

A C++ program that simulates bandwidth allocation and client session management in an Internet Cafe.

## Table of Contents

* Description
* Features
* How to Use

  * Compilation
  * Running Automatic Simulation
  * Running Interactive Mode
* Example

  * Automatic Simulation
  * Interactive Mode
* Contributing
* License
* Contact
* 
## Description

This project implements a simulation of an Internet Cafe using C++. It models fair bandwidth distribution among connected clients and tracks session times. The program includes input validation and offers both automatic and interactive simulation modes for user flexibility.

## Features

* Client management with session tracking
* Fair bandwidth allocation algorithm
* Interactive mode with menu-driven interface
* Automatic simulation mode
* Input validation for incorrect or unrealistic values
* Clear status updates for each simulated minute

## How to Use

### Compilation

Use the following command in your terminal (C++11 standard required):

```bash
g++ -o InternetCafeSimulator bandwidth_alloc.cpp -std=c++11


### Running Automatic Simulation

```bash
./bandwidth_alloc

* Select option `1` for automatic simulation
* Add clients with bandwidth and session time
* The system will run until all sessions are completed

### Running Interactive Mode

```bash
./bandwidth_alloc

* Select option `2`
* You can:

  * Add clients
  * Simulate each minute
  * Monitor bandwidth distribution
  * Update total bandwidth
  * Exit the program

## Example

### Automatic Simulation

Select simulation mode:
1. Automatic Simulation
2. Interactive Mode
Enter your choice: 1

Enter number of clients: 3
Client 1 - Bandwidth: 20 Mbps, Time: 5 minutes
Client 2 - Bandwidth: 50 Mbps, Time: 4 minutes
...
Simulation complete.
```

### Interactive Mode

```
Select simulation mode:
1. Automatic Simulation
2. Interactive Mode
Enter your choice: 2

=== Menu ===
1. Add Client
2. Simulate 1 Minute
3. Display Status
4. Change Bandwidth
5. Exit
```

---

## Contributing

Feel free to fork this repository and submit pull requests for improvements, bug fixes, or additional features.

---

## License

This project is licensed under the MIT License.


