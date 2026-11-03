# HCL-Project
Airline Reservation and management system

# ✈️ Airline Reservation and Seat Management System

A console-based **Airline Reservation and Seat Management System** developed using C++. This project allows users to manage airline seat reservations, view seat availability, book seats, cancel reservations, and display passenger details.

## 📌 Project Overview

The Airline Reservation and Seat Management System is designed to demonstrate the practical implementation of Object-Oriented Programming (OOP) concepts in C++.

It provides a simple menu-driven interface where users can perform basic airline reservation operations efficiently.

## 🚀 Features

- **Display Seat Map:** View the available and reserved seats.
- **Reserve a Seat:** Book a seat by entering passenger details.
- **Cancel Reservation:** Cancel an existing booking.
- **View All Reservations:** Display the details of all booked passengers.
- **Exit:** Safely exit the application.

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Compiler:** GCC (g++)
- **IDE:** Visual Studio Code
- **Libraries:**
  - `iostream`
  - `iomanip`
  - `limits`
  - `string`
  - `vector`

## 🧠 OOP Concepts Implemented

This project demonstrates the following Object-Oriented Programming concepts:

1. **Classes and Objects:** Used to represent passengers and the airline reservation system.
2. **Encapsulation:** Passenger information is stored using private data members.
3. **Constructors:** Used to initialize passenger objects.
4. **Member Functions:** Used to perform operations such as displaying passenger details.
5. **Data Abstraction:** Internal passenger data is accessed through public member functions.

## 💻 Sample Output

```text
========================================
    AIRLINE RESERVATION AND SEAT MANAGEMENT
========================================

1. Display seat map
2. Reserve a seat
3. Cancel a reservation
4. View all reservations
5. Exit

Enter your choice: 1

Displaying Seat Map...

Enter your choice: 2

Enter passenger name: Rahul
Enter passenger age: 20
Enter destination: Mumbai

Reservation successful!
```

*Note: Sample output is illustrative.*

## ⚙️ How to Run the Project

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/airline-reservation-system.git
```

### 2. Navigate to the Project Folder

```bash
cd airline-reservation-system
```

### 3. Compile the C++ Program

```bash
g++ project.cpp -o project
```

### 4. Run the Application

**Windows:**
```bash
.\project.exe
```

**Linux / macOS:**
```bash
./project
```

## 📂 Project Structure

```text
Airline-Reservation-System/
│
├── project.cpp
└── README.md
```

## 💾 Data Storage

- Uses runtime-only storage.
- Reservation information is maintained during program execution.
- Data is not permanently stored in a database or external file.
- All reservation data is lost when the application terminates.

## 🎯 Project Objective

The main objective of this project is to understand how C++ programming and Object-Oriented Programming concepts can be applied to solve real-world problems through a basic airline reservation system.

## 👥 Team Members

Developed by:

1. **Saish Pardeshi**
2. **Krushna Jadhav**
3. **Gauri Sanvatsarkar **

## 🔮 Future Improvements

- Develop a graphical user interface (GUI).
- Add permanent data storage using files or a database.
- Implement flight selection and ticket generation.
- Add passenger login and authentication.
- Generate digital boarding passes.

## 📜 License

This project is developed for educational purposes as part of a college academic project.

---

⭐ If you find this project interesting, feel free to explore the source code!
