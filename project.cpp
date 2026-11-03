#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>

using namespace std;

// A Passenger object stores the details of one booking.
class Passenger {
private:
    string name;
    int age;
    string destination;

public:
    Passenger() : name(""), age(0), destination("") {}

    Passenger(const string& passengerName, int passengerAge,
              const string& passengerDestination)
        : name(passengerName), age(passengerAge), destination(passengerDestination) {}

    void display() const {
        cout << left << setw(22) << name
             << setw(8) << age
             << destination;
    }
};

// A Seat has a number and can either be empty or reserved by a Passenger.
class Seat {
private:
    int seatNumber;
    bool reserved;
    Passenger passenger;

public:
    Seat(int number) : seatNumber(number), reserved(false) {}

    bool isReserved() const {
        return reserved;
    }

    int getSeatNumber() const {
        return seatNumber;
    }

    void reserve(const Passenger& newPassenger) {
        passenger = newPassenger;
        reserved = true;
    }

    void cancel() {
        passenger = Passenger();
        reserved = false;
    }

    void displayDetails() const {
        cout << left << setw(8) << seatNumber;
        passenger.display();
        cout << '\n';
    }
};

// AirlineSystem manages all seats and provides the application operations.
class AirlineSystem {
private:
    vector<Seat> seats;

    bool validSeatNumber(int seatNumber) const {
        return seatNumber >= 1 && seatNumber <= static_cast<int>(seats.size());
    }

public:
    AirlineSystem(int totalSeats) {
        for (int i = 1; i <= totalSeats; ++i) {
            seats.push_back(Seat(i));
        }
    }

    void displaySeatMap() const {
        cout << "\n--- Seat Map ---\n";
        cout << "[O] = Available    [X] = Reserved\n\n";

        for (size_t i = 0; i < seats.size(); ++i) {
            cout << "Seat " << setw(2) << seats[i].getSeatNumber() << " "
                 << (seats[i].isReserved() ? "[X]" : "[O]") << "    ";
            if ((i + 1) % 4 == 0) {
                cout << '\n';
            }
        }
        cout << "\n";
    }

    void reserveSeat() {
        int seatNumber;
        cout << "Enter seat number to reserve: ";
        cin >> seatNumber;

        if (!validSeatNumber(seatNumber)) {
            cout << "Invalid seat number. Please choose a listed seat.\n";
            return;
        }
        if (seats[seatNumber - 1].isReserved()) {
            cout << "This seat is already reserved.\n";
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string name, destination;
        int age;

        cout << "Enter passenger name: ";
        getline(cin, name);
        cout << "Enter passenger age: ";
        cin >> age;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter destination: ";
        getline(cin, destination);

        seats[seatNumber - 1].reserve(Passenger(name, age, destination));
        cout << "Reservation successful. Seat " << seatNumber
             << " is booked for " << name << ".\n";
    }

    void cancelReservation() {
        int seatNumber;
        cout << "Enter seat number to cancel: ";
        cin >> seatNumber;

        if (!validSeatNumber(seatNumber)) {
            cout << "Invalid seat number.\n";
        } else if (!seats[seatNumber - 1].isReserved()) {
            cout << "That seat does not have an active reservation.\n";
        } else {
            seats[seatNumber - 1].cancel();
            cout << "Reservation for seat " << seatNumber << " has been cancelled.\n";
        }
    }

    void displayReservations() const {
        bool foundReservation = false;
        cout << "\n--- Confirmed Reservations ---\n";
        cout << left << setw(8) << "Seat" << setw(22) << "Passenger"
             << setw(8) << "Age" << "Destination\n";
        cout << string(55, '-') << '\n';

        for (const Seat& seat : seats) {
            if (seat.isReserved()) {
                seat.displayDetails();
                foundReservation = true;
            }
        }
        if (!foundReservation) {
            cout << "No reservations yet.\n";
        }
    }
};

int main() {
    AirlineSystem airline(12);  // Change 12 to create a different-sized aircraft.
    int choice;

    cout << "=============================================\n";
    cout << "  AIRLINE RESERVATION AND SEAT MANAGEMENT\n";
    cout << "=============================================\n";

    do {
        cout << "\n1. Display seat map\n";
        cout << "2. Reserve a seat\n";
        cout << "3. Cancel a reservation\n";
        cout << "4. View all reservations\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number from 1 to 5.\n";
            continue;
        }

        switch (choice) {
            case 1: airline.displaySeatMap(); break;
            case 2: airline.reserveSeat(); break;
            case 3: airline.cancelReservation(); break;
            case 4: airline.displayReservations(); break;
            case 5: cout << "Thank you for using the airline system.\n"; break;
            default: cout << "Invalid choice. Please select 1 to 5.\n";
        }
    } while (choice != 5);

    return 0;
}
