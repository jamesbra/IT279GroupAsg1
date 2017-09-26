#include "CalculatorInput.h"

#include <regex>
#include <iostream>

struct calcNode CalculatorInput::receiveInput(){
    struct calcNode temp;
    std::regex overallStructure("[[:blank:]]*[-+%\\/*][[:blank:]]*[\\d]+[[:blank:]]*");
    std::regex userCommandStructure("[[:blank:]]*[URCQurcq][[:blank:]]*");
    std::regex commandSet("[URCQurcq]");
    std::regex operatorSet("[-+%\\/*]");
    std::regex operands("[\\d]+");
    std::regex userCommandHelp("[?][URCQurcq|+%\\/*\\-]");
    std::smatch m;
    std::string input;
    std::cout << ">";
    getline(std::cin, input);
    if (std::regex_match(input,overallStructure)){
        std::regex_search(input,m,operatorSet);
        temp.operation = m[0].str().at(0);
        std::regex_search(input,m,operands);
        temp.operandTwo = std::stoi(m[0].str());
        temp.help = false;
    }
    else if (std::regex_match(input,m,userCommandHelp)){
        if (std::regex_match(input,m,commandSet)){
            std::regex_search(input,m,commandSet);
            temp.help = true;
            temp.operation = m[0].str().at(0);
            temp.operandOne = 0;
            temp.operandTwo = 0;
        }
        else{
            std::regex_search(input,m,operatorSet);
            temp.help = true;
            temp.operation = m[0].str().at(0);
            temp.operandOne = 0;
            temp.operandTwo = 0;
        }
    }
    else if (std::regex_match(input,m,commandSet)){
        temp.help = false;
        temp.operandOne = 0;
        temp.operandTwo = 0;
        temp.operation = std::toupper(m[0].str().at(0));

    }
    else{
        temp.help = false;
        temp.operandOne = 0;
        temp.operandTwo = 0;
        temp.operation = 'Z';
    }

    return temp;

}


