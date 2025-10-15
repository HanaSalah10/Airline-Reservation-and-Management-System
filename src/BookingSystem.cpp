#include "BookingSystem.hpp"
#include "CashPayment.hpp"
#include "CreditCardPayment.hpp"
#include "PayPalPayment.hpp"
#include <iostream>

BookingSystem::BookingSystem(std::shared_ptr<FlightManager> fm, std::shared_ptr<PassengerManager> pm) 
    : flightManager(fm), passengerManager(pm) {
}

void BookingSystem::searchFlights() {
    if (flightManager) {
            flightManager->viewAllFlights();
    } else {
        std::cout << "FlightManager not available!" << std::endl;
    }
}

void BookingSystem::bookFlight() {
    if (flightManager) {
        flightManager->viewAllFlights();
        std::string passengerID;
        std::cout << "Enter Passenger ID: ";
        std::cin >> passengerID;
        std::string flightNumber;
        std::cout << "Enter Flight Number to book: ";
        std::cin >> flightNumber;

        Flight* flight = flightManager->searchFlight(flightNumber);
        if (!flight) {
            std::cout << "Flight not found!" << std::endl;
            return;
        }
        flight->displayAllAvailableSeats();
        std::string seatNumber;
        std::cout << "Enter Seat Number to book: ";
        std::cin >> seatNumber;
        if (flight->bookSeat(seatNumber)) {
            // Assuming passengerManager can provide a Passenger object based on passengerID
            Passenger* user = passengerManager->findPassenger(passengerID);
            if(!user) {
                std::cout << "Passenger not found!" << std::endl;
                return;
            } 
            //Directing to payment
            double price = flight->getPrice();
            Payment* payment = makePayment(price);
            if (!payment) {
                std::cout << "Payment setup failed. Booking not completed." << std::endl;
                return;
            }
            if(payment->processPayment()) {
                std::cout << "Payment processed successfully." << std::endl;
            } else {
                std::cout << "Payment failed. Booking not completed." << std::endl;
                delete payment; // Clean up allocated memory
                return;
            }   
            Reservation reservation(flight, user, payment);
            if(reservation.confirm()) {
                std::cout << "Reservation confirmed!" << std::endl;
                reservations.push_back(reservation);
                reservation.displayReservationDetails();
            } else {
                std::cout << "Reservation could not be confirmed." << std::endl;
                return;
            }
            
        } else {
            std::cout << "Failed to book seat. It may already be booked." << std::endl;
        }

    } else {
        std::cout << "FlightManager not available!" << std::endl;
    }
}
Payment* BookingSystem::makePayment(double amount) {
    std::cout << "Entering payment method(1. Credit Card Payment 2. PayPal Payment 3. Cash Payment)..." << std::endl;
    int choice;
    std::cin >> choice;
    
    // Check if input failed
    if (std::cin.fail()) {
        std::cin.clear(); // Clear the error state
        std::cin.ignore(10000, '\n'); // Ignore the invalid input
        std::cout << "Invalid input. Please enter a number (1, 2, or 3)." << std::endl;
        return nullptr;
    }
    
    Payment* payment = nullptr;
    switch (choice) {
        case 1: {
            std::string cardNumber, cardHolderName, expiryDate, cvv;
            std::cout << "Enter Card Number: ";
            std::cin >> cardNumber;
            std::cout << "Enter Card Holder Name: ";
            std::cin.ignore(); // To ignore the newline character left in the buffer
            std::getline(std::cin, cardHolderName);
            std::cout << "Enter Expiry Date (MM/YY): ";
            std::cin >> expiryDate;
            std::cout << "Enter CVV: ";
            std::cin >> cvv;
            payment = new CreditCardPayment(amount, cardNumber, cardHolderName, expiryDate, cvv);
            break;
        }
        case 2: {
            std::string email, password;
            std::cout << "Enter PayPal Email: ";
            std::cin >> email;
            std::cout << "Enter PayPal Password: ";
            std::cin >> password;
            payment = new PayPalPayment(amount, email, password);
            break;
        }
        case 3: {
            std::string cashierName;
            std::cout << "Enter Cashier Name: ";
            std::cin >> cashierName;
            payment = new CashPayment(amount, cashierName);
            break;
        }
        default: {
            std::cout << "Invalid payment method choice. Please select 1, 2, or 3." << std::endl;
            payment = nullptr;
            break;
        }
    }
    return payment;
}
void BookingSystem::getMyReservations(std::string passengerID) {
    for (const auto& reservation : reservations) {
        if (reservation.getPassenger() && reservation.getPassenger()->getPassengerID() == passengerID) {
            reservation.displayReservationDetails();

        }
    }
}
void BookingSystem::bookPassengerFlight(Passenger* passenger, std::string flightNumber)
{
    Flight* flight = flightManager->searchFlight(flightNumber);
    if (!flight) {
        std::cout << "Flight not found!" << std::endl;
        return;
    } 
    flight->displayAllAvailableSeats();
    std::string seatNumber;
    std::cout << "Enter Seat Number to book: "; 

    std::cin >> seatNumber;
    if (flight->bookSeat(seatNumber)) {
        double price = flight->getPrice();
        Payment* payment = makePayment(price);
        if (!payment) {
            std::cout << "Payment setup failed. Booking not completed." << std::endl;
            return;
        }
        if(payment->processPayment()) {
            std::cout << "Payment processed successfully." << std::endl;
        } else {
            std::cout << "Payment failed. Booking not completed." << std::endl;
            delete payment; // Clean up allocated memory
            return;
        }   
        Reservation reservation(flight, passenger, payment);
        if(reservation.confirm()) {
            std::cout << "Reservation confirmed!" << std::endl;
            reservations.push_back(reservation);
            reservation.displayReservationDetails();
        } else {
            std::cout << "Reservation could not be confirmed." << std::endl;
            return;
        }
        
    } else {
        std::cout << "Failed to book seat. It may already be booked." << std::endl;
    }

    // Implementation for booking logic
}

void BookingSystem::confirmBooking() {
    std::cout << "Confirming booking..." << std::endl;
    // Implementation for confirmation logic
}
void BookingSystem::cancelReservation() {
    std::cout << "Canceling reservation..." << std::endl;
    // Implementation for cancellation logic
}

void BookingSystem::modifyReservation() {
    std::cout << "Modifying reservation..." << std::endl;
    // Implementation for modification logic
}  