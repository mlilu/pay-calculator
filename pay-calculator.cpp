//Program: Babbages Cabbages
//Author: L. Montoya
//Date: 02/13/2023
//Description: This program calculates and displays an employees gross pay, net pay, taxes when they input their first and last name, hours worked, and hourly rate. 

#include <iomanip>
#include <iostream>
#include <string>


void input_user_data(std::string &first_name, std::string &last_name, double &hours, double &hourly_rate);
void join_names(std::string first_name, std::string last_name, std::string &full_name);
void compute_gross_pay(double hours, double hourly_rate, double &gross_pay);
void compute_taxes(double gross_pay, double &taxes);
void compute_net_pay(double gross_pay, double taxes, double &net_pay);
void show_header();
void output_results(std::string full_name, double hours, double hourly_rate, double gross_pay, double taxes,double net_pay);

#define TAX_RATE 0.28
#define PARKING_DEDUCTION 7.50

int main()
{
    std::string first_name, last_name, full_name;
                
    double hours, hourly_rate, gross_pay, taxes, net_pay;

    std::cout << std::fixed << std::setprecision(2);a

    input_user_data(first_name, last_name, hours, hourly_rate);
    join_names(first_name, last_name, full_name);
    compute_gross_pay(hours, hourly_rate, gross_pay);
    compute_taxes(gross_pay, taxes);
    compute_net_pay(gross_pay, taxes, net_pay);
    show_header();
    output_results(full_name, hours, hourly_rate, gross_pay, taxes, net_pay);
}

//A module that prompts the user to enter their first and last name, hours worked, and hourly wage.
void input_user_data(std::string &first_name, std::string &last_name, double &hours, double &hourly_rate)
{
    std::cout << "Enter employee's first name: ";
    std::cin >> first_name;
    std::cout << "Enter employee's last name: ";
    std::cin >> last_name;
    std::cout << "Enter number of hours worked: ";
    std::cin >> hours;
    std::cout << "Enter hourly pay rate: ";
    std::cin >> hourly_rate;
}

//A module that combines the first and last names input by the user to produce a full name in a last, first format.
void join_names(std::string first_name, std::string last_name, std::string &full_name)
{
    full_name = last_name + "," + first_name;
}

//A module that calculates the users gross pay based on hours worked and hourly wage.
void compute_gross_pay(double hours, double hourly_rate, double &gross_pay)
{
    gross_pay = hours * hourly_rate;
}

//A module that calculates the users taxes from the gross pay and tax rate.
void compute_taxes(double gross_pay, double &taxes)
{
    taxes = gross_pay * TAX_RATE;
}

//A module that calculates the users net pay based on their gross pay, taxes, and deductions. 
void compute_net_pay(double gross_pay, double taxes, double &net_pay)
{
    net_pay = gross_pay - taxes - PARKING_DEDUCTION;
}

//This module formats a table to display the results.
void show_header()
{
    std::cout << std::endl;
    std::cout << "12345678901234567890##21.00##321.00##4321.00##321.00##321.00##4321.00" << std::endl;
    std::cout << "                             Hourly  Gross                    Net" << std::endl;
    std::cout << "Name                  Hours  Rate    Pay      Taxes   Deduct  Pay" << std::endl;
    std::cout << "====================  =====  ======  =======  ======  ======  ======" << std::endl;
}

//A module that displays the users name, hours worked, hourly rate, gross pay, net pay, taxes, and deductions.
void output_results(std::string full_name, double hours, double hourly_rate, double gross_pay, double taxes, double net_pay)
{
    std::cout << std::left << std::setw(20) << full_name << "  "
       <<std::right <<std::setw(5) << hours << "  "
        << std:: setw(6) << hourly_rate << "  "
        << std::setw(7) << gross_pay << "  "
        << std::setw(6) << taxes << "  "
        << std::setw(6) << PARKING_DEDUCTION << "  "
        << std::setw(6) << net_pay << "  ";
}
