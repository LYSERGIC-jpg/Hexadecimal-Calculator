#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

int main()
{
    int choice = 0;
    std::cout << "############ Hexadecimal Calculator ############\n";
    std::cout << "Select Mode\n";
    std::cout << " 1: Standerd hex (e.g, F4 + 2C)\n";
    std::cout << " 2: Address & offset (e.g, 0xF0128B5 - 0xFC)\n\n";
    std::cout << "Enter choice ( 1 or 2 ): > ";
    
    if (!(std::cin >> choice )) return 0;

    char op;
    std::string input1, input2;
    long long result = 0;

    if (choice == 1)
    {

        std::cout << "\n=== Standerd hex ===\n";
        std::cout << "Enter experession (e.g, 0x7A + 0xC4): > ";

        if (!(std::cin >> input1 >> op >> input2)) return 0;

        long long val1 = 0, val2 = 0;
        std::stringstream(input1) >> std::hex >> val1;
        std::stringstream(input2) >> std::hex >> val2;

        long long result = 0;
        switch (op)
        {
        case '+': result = val1 + val2; break;
        case '-': result = val1 - val2; break;
        case '*': result = val1 * val2; break;
        case '/': result = val1 / val2; break;
            if (val2 != 0) result = val1 / val2;
            else { std::cout << "Error: Division by zero\n"; return 1; }
            break;
        default:
            std::cout << "Invalid operator\n";
            system("pause>0");
            return 1;
        }
        std::cout << "Result: 0x" << std::hex << std::uppercase << result << "\n";
    }
    else if (choice == 2)
    {
        std::cout << "\n=== Address & offset ===\n";
        std::cout << "Enter experession (e.g, 0xB730F3C + 0xF8): > ";
        if (!(std::cin >> input1 >> op >> input2)) return 0;

        long long val1 = std::stoll(input1, nullptr, 0);
        long long val2 = std::stoll(input2, nullptr, 0);

        switch (op)
        {
        case '+': result = val1 + val2; break;
        case '-': result = val1 - val2; break;
        case '*': result = val1 * val2; break;
        case '/': result = val1 / val2; break;
            if (val2 != 0) result = val1 / val2;
            else { std::cout << "Error: Division by zero\n"; return 1; }
            break;
        default:
            std::cout << "Invalid operator\n";
            system("pause>0");
            return 1;
        }
        std::cout << "Result Address: 0x"
            << std::hex << std::uppercase
            << std::setw(8) << std::setfill('0') << result
            << "\n";
    }
    else
    {
        std::cout << "Invalid mode selection.\n";
    }

    std::cout << "\n###############################################\n";
    system("pause>0");
    return 0;
}


