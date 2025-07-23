#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Client structure to represent individual cafe users
struct Client {
    int id;
    double requestedBandwidth;
    double allocatedBandwidth;
    int remainingTime;
    
    Client(int id_, double bandwidth_, int time_)
        : id(id_), 
          requestedBandwidth(bandwidth_), 
          allocatedBandwidth(0), 
          remainingTime(time_) {}
};

// Cafe class to manage clients and bandwidth allocation
class Cafe {
private:
    vector<Client> clients;
    double totalBandwidth;
    int maxClients;
    int nextClientId;

public:
    Cafe(double bandwidth = 100.0, int maxClientCount = 10) 
        : totalBandwidth(bandwidth), maxClients(maxClientCount), nextClientId(1) {}

    void addClient(double requestedBandwidth, int timeMinutes) {
        if (clients.size() >= maxClients) {
            cout << "Cannot add more clients. Maximum limit reached.\n";
            return;
        }
        clients.emplace_back(nextClientId++, requestedBandwidth, timeMinutes);
        allocateBandwidth();
    }

    void allocateBandwidth() {
        if (clients.empty()) return;
        
        double demandSum = 0;
        for (const auto& client : clients) {
            demandSum += client.requestedBandwidth;
        }

        if (demandSum <= totalBandwidth) {
            // Give everyone what they want
            for (auto& client : clients) {
                client.allocatedBandwidth = client.requestedBandwidth;
            }
        } else {
            // Scale down proportionally
            for (auto& client : clients) {
                client.allocatedBandwidth = 
                    (client.requestedBandwidth / demandSum) * totalBandwidth;
            }
        }
    }

    void simulateMinute() {
        cout << "----- Simulating 1 minute -----" << endl;

        // Decrement remaining time for all clients
        for (auto& client : clients) {
            client.remainingTime--;
        }

        // Remove clients whose sessions have expired
        clients.erase(remove_if(clients.begin(), clients.end(),
                               [](Client& c) { return c.remainingTime <= 0; }),
                     clients.end());

        // Reallocate bandwidth among remaining clients
        allocateBandwidth();
        displayStatus();
    }

    void displayStatus() const {
        cout << "Current Clients (" << clients.size() << "):\n";
        for (const auto& client : clients) {
            cout << "Client " << client.id
                 << " - Allocated: " << client.allocatedBandwidth << " Mbps"
                 << ", Remaining Time: " << client.remainingTime << " minutes\n";
        }
        cout << "-------------------------------\n";
    }

    bool isEmpty() const {
        return clients.empty();
    }

    double getTotalBandwidth() const {
        return totalBandwidth;
    }

    void setTotalBandwidth(double bandwidth) {
        totalBandwidth = bandwidth;
        allocateBandwidth(); // Reallocate with new total
    }
};

// Simulator class to control the overall simulation process
class Simulator {
private:
    Cafe cafe;
    int initialClients;

public:
    Simulator(double totalBandwidth = 100.0) : cafe(totalBandwidth) {}

    void setupClients() {
        cout << "=== Internet Cafe Manager Simulation ===" << endl;
        cout << "Total Available Bandwidth: " << cafe.getTotalBandwidth() << " Mbps" << endl;
        cout << "Enter number of clients to connect (max allowed: 10): ";
        cin >> initialClients;

        if (initialClients > 10) {
            cout << "Too many clients! Limiting to 10.\n";
            initialClients = 10;
        }

        if (initialClients < 0) {
            cout << "Invalid number of clients! Setting to 0.\n";
            initialClients = 0;
        }

        for (int i = 0; i < initialClients; ++i) {
            double bandwidth;
            int time;
            cout << "Client " << (i + 1) << " - Enter requested bandwidth (Mbps): ";
            cin >> bandwidth;
            
            // Validate bandwidth input
            if (bandwidth < 0) {
                cout << "Invalid bandwidth! Setting to 1 Mbps.\n";
                bandwidth = 1.0;
            }
            
            cout << "Client " << (i + 1) << " - Enter session time (minutes): ";
            cin >> time;
            
            // Validate time input
            if (time < 1) {
                cout << "Invalid time! Setting to 1 minute.\n";
                time = 1;
            }

            cafe.addClient(bandwidth, time);
        }
        
        cout << "\n=== Initial Setup Complete ===" << endl;
        cafe.displayStatus();
    }

    void run() {
        setupClients();
        
        if (cafe.isEmpty()) {
            cout << "No clients to simulate.\n";
            return;
        }

        while (!cafe.isEmpty()) {
            cafe.simulateMinute();
            
            // Optional: Add a small pause for better readability
            // Uncomment the next line if you want to pause between minutes
            // system("pause"); // Windows only, or use cin.get() for cross-platform
        }
        
        cout << "Simulation complete. All clients disconnected.\n";
    }

    void runInteractive() {
        cout << "=== Interactive Internet Cafe Manager ===" << endl;
        cout << "Total Available Bandwidth: " << cafe.getTotalBandwidth() << " Mbps" << endl;
        
        int choice;
        do {
            cout << "\n=== Menu ===" << endl;
            cout << "1. Add Client" << endl;
            cout << "2. Simulate 1 Minute" << endl;
            cout << "3. Display Status" << endl;
            cout << "4. Change Total Bandwidth" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    double bandwidth;
                    int time;
                    cout << "Enter requested bandwidth (Mbps): ";
                    cin >> bandwidth;
                    cout << "Enter session time (minutes): ";
                    cin >> time;
                    
                    if (bandwidth < 0) bandwidth = 1.0;
                    if (time < 1) time = 1;
                    
                    cafe.addClient(bandwidth, time);
                    cafe.displayStatus();
                    break;
                }
                case 2:
                    if (!cafe.isEmpty()) {
                        cafe.simulateMinute();
                    } else {
                        cout << "No clients connected.\n";
                    }
                    break;
                case 3:
                    cafe.displayStatus();
                    break;
                case 4: {
                    double newBandwidth;
                    cout << "Enter new total bandwidth (Mbps): ";
                    cin >> newBandwidth;
                    if (newBandwidth > 0) {
                        cafe.setTotalBandwidth(newBandwidth);
                        cout << "Total bandwidth updated to " << newBandwidth << " Mbps\n";
                        cafe.displayStatus();
                    } else {
                        cout << "Invalid bandwidth value.\n";
                    }
                    break;
                }
                case 5:
                    cout << "Exiting simulation.\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 5);
    }
};

int main() {
    Simulator simulator;
    
    int mode;
    cout << "Select simulation mode:" << endl;
    cout << "1. Automatic Simulation" << endl;
    cout << "2. Interactive Mode" << endl;
    cout << "Enter your choice: ";
    cin >> mode;

    if (mode == 1) {
        simulator.run();
    } else if (mode == 2) {
        simulator.runInteractive();
    } else {
        cout << "Invalid choice. Running automatic simulation by default.\n";
        simulator.run();
    }

    return 0;
}