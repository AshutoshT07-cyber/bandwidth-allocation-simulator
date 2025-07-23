Simulated Internet Cafe Manager

Table of Contents





Description



Features



How to Use





Compilation



Running Automatic Simulation



Running Interactive Mode



Example





Automatic Simulation



Interactive Mode



Contributing



License



Contact

Description

This C++ program simulates an internet cafe's bandwidth allocation and client session management. It allows users to create clients with specific bandwidth requests (in Mbps) and session times (in minutes). The simulation runs in one-minute increments, updating client sessions, removing disconnected clients, and reallocating bandwidth fairly among remaining clients. The program supports two modes:





Automatic Mode: Sets up clients initially and runs the simulation until all clients disconnect, displaying the status after each minute.



Interactive Mode: Provides a menu-driven interface to add clients, simulate minutes, display the current status, or adjust the total available bandwidth.

The program includes input validation to handle invalid inputs (e.g., negative bandwidth or session times) by setting default values, ensuring robust operation.

Features





Client Management: Add clients with specified bandwidth requests and session durations.



Fair Bandwidth Allocation: Allocates bandwidth to clients, granting full requests if possible or scaling proportionally when demand exceeds supply.



Time Simulation: Advances time in one-minute increments, updating client sessions and reallocating bandwidth.



Interactive Mode: Offers a menu to add clients, simulate time, display status, or change total bandwidth.



Automatic Mode: Runs the simulation from setup to completion without user intervention.



Input Validation: Ensures invalid inputs (e.g., negative values) are handled gracefully with default values.

How to Use

Compilation

To compile the program, use a C++ compiler such as g++. Ensure your compiler supports C++11 or later:

g++ -o InternetCafeSimulator bandwidth_alloc.cpp -std=c++11


Running Automatic Simulation

To run in automatic mode:

./bandwidth_alloc





Select option 1 for automatic simulation.



Enter the number of clients (up to 10) and their bandwidth (Mbps) and session time (minutes).



The program will simulate the cafe operations, displaying the status after each minute until all clients disconnect.



Invalid inputs (e.g., negative bandwidth) are automatically corrected to default values (e.g., 1 Mbps).

Running Interactive Mode

To run in interactive mode:

./bandwidth_alloc





Select option 2 for interactive mode.



Use the menu to:





Add Client: Specify bandwidth and session time for a new client.



Simulate 1 Minute: Advance the simulation by one minute.



Display Status: Show current client details.



Change Total Bandwidth: Adjust the total available bandwidth.



Exit: End the simulation.



Invalid inputs are handled with default values for robustness.

Example

Automatic Simulation

Below is an example of running the program in automatic mode with three clients:

Select simulation mode:
1. Automatic Simulation
2. Interactive Mode
Enter your choice: 1

=== Internet Cafe Manager Simulation ===
Total Available Bandwidth: 100 Mbps
Enter number of clients to connect (max allowed: 10): 3
Client 1 - Enter requested bandwidth (Mbps): 30
Client 1 - Enter session time (minutes): 3
Client 2 - Enter requested bandwidth (Mbps): 30
Client 2 - Enter session time (minutes): 2
Client 3 - Enter requested bandwidth (Mbps): 40
Client 3 - Enter session time (minutes): 5

=== Initial Setup Complete ===
Current Clients (3):
Client 1 - Allocated: 30 Mbps, Remaining Time: 3 minutes
Client 2 - Allocated: 30 Mbps, Remaining Time: 2 minutes
Client 3 - Allocated: 40 Mbps, Remaining Time: 5 minutes
-------------------------------

----- Simulating 1 minute -----
Current Clients (3):
Client 1 - Allocated: 30 Mbps, Remaining Time: 2 minutes
Client 2 - Allocated: 30 Mbps, Remaining Time: 1 minutes
Client 3 - Allocated: 40 Mbps, Remaining Time: 4 minutes
-------------------------------

----- Simulating 1 minute -----
Current Clients (2):
Client 1 - Allocated: 30 Mbps, Remaining Time: 1 minutes
Client 3 - Allocated: 40 Mbps, Remaining Time: 3 minutes
-------------------------------

----- Simulating 1 minute -----
Current Clients (1):
Client 3 - Allocated: 40 Mbps, Remaining Time: 2 minutes
-------------------------------

----- Simulating 1 minute -----
Current Clients (1):
Client 3 - Allocated: 40 Mbps, Remaining Time: 1 minutes
-------------------------------

----- Simulating 1 minute -----
Current Clients (0):
-------------------------------

Simulation complete. All clients disconnected.

Interactive Mode

Below is an example of running the program in interactive mode:

Select simulation mode:
1. Automatic Simulation
2. Interactive Mode
Enter your choice: 2

=== Interactive Internet Cafe Manager ===
Total Available Bandwidth: 100 Mbps

=== Menu ===
1. Add Client
2. Simulate 1 Minute
3. Display Status
4. Change Total Bandwidth
5. Exit
Enter your choice: 1
Enter requested bandwidth (Mbps): 20
Enter session time (minutes): 4

Current Clients (1):
Client 1 - Allocated: 20 Mbps, Remaining Time: 4 minutes
-------------------------------

=== Menu ===
1. Add Client
2. Simulate 1 Minute
3. Display Status
4. Change Total Bandwidth
5. Exit
Enter your choice: 2

----- Simulating 1 minute -----
Current Clients (1):
Client 1 - Allocated: 20 Mbps, Remaining Time: 3 minutes
-------------------------------

=== Menu ===
...

Contributing

Contributions are welcome! To contribute:





Fork the repository.



Make your changes (e.g., bug fixes, new features, or documentation improvements).



Submit a pull request with a clear description of your changes.

License

This project is licensed under the MIT License. See the LICENSE.md file for details.

Contact

For questions, feedback, or suggestions, please contact [Your Name or Email]. (Replace with your actual contact information when adding to GitHub.)
