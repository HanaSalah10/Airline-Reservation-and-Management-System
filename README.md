# Airline Reservation and Management System

A comprehensive C++ application for managing airline reservations, flights, passengers, and crew.

## Features

- **User Management**: Support for Administrators, Passengers, and Booking Agents
- **Flight Management**: Create, modify, and search flights with crew assignments
- **Booking System**: Complete reservation workflow with seat selection and payment processing
- **Passenger Management**: Comprehensive passenger database with authentication
- **Payment Processing**: Multiple payment methods (Credit Card, PayPal, Cash)
- **Crew Management**: Pilot and flight attendant assignment based on aircraft requirements


## Quick Start


#### Using Makefile (Recommended)

```bash
# Basic commands
make              # Build the project
make run          # Build and run
make clean        # Clean build files
make help         # Show all available targets

# Advanced commands
make debug        # Build with debug symbols
make release      # Build optimized version  
make info         # Show system information
make check        # Check syntax only

#### Manual Compilation

# Compile manually (cross-platform)
g++ -std=c++17 -I./include -o main main.cpp src/*.cpp

# Run the program
./main                  # Linux/macOS
main.exe               # Windows
```

## Project Structure

```
Airline-Reservation-and-Management-System/
├── include/          # Header files
├── src/              # Source files
├── database/         # Data files (users, flights, passengers, etc.)
├── main.cpp          # Main application entry point
├── Makefile          # Make build configuration
├── build.sh          # Build and run script
└── README.md         # This file
```

## Usage

1. **Start the application**: Use any of the build methods above
2. **Select your role**: 
   - 1: Admin (manage flights, crew, aircraft)
   - 2: Passenger (search flights, make bookings)
   - 3: Booking Agent (assist with bookings)
3. **Login**: Use credentials from `database/users.txt`
4. **Navigate menus**: Follow the on-screen prompts

### Sample Login Credentials

Check `database/users.txt` for available user accounts. The file contains usernames and passwords for testing different roles.

## Payment Methods

When booking flights, you can choose from:
1. **Credit Card Payment** - Enter card details
2. **PayPal Payment** - Enter email and password  
3. **Cash Payment** - Enter cashier name

**Important**: When prompted for payment method, enter the number (1, 2, or 3), not the text.

## Data Files

The system uses CSV files in the `database/` directory:
- `users.txt` - User authentication data
- `passengers.txt` - Passenger information
- `flights.txt` - Flight schedules and details
- `pilots.txt` - Pilot database
- `flightAttendants.txt` - Flight attendant database
- `aircrafts.txt` - Aircraft fleet information

## Development

### Compilation Requirements
- C++17 compatible compiler (g++, clang++)
- Standard Template Library (STL)

### Build Warnings
Some warnings may appear during compilation related to virtual destructors and initialization order. These are non-critical and don't affect functionality.
