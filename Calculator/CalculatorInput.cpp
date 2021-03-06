#include "CalculatorInput.h"

#include <regex>
#include <iostream>

struct calcNode CalculatorInput::receiveInput(){
    struct calcNode temp;
    std::regex overallOperationStructure("[[:blank:]]*[-+%\\/*][[:blank:]]*[-]?[[:blank:]]*[\\d]+[[:blank:]]*");
    std::regex commandSetStructure("[[:blank:]]*[URCQurcq][[:blank:]]*");



    std::regex operatorSet("[-+%\\/*]");
    std::regex posOperatorSet("[+%\\/*]");
    std::regex operatorWithNegOperand("[+%\\/*][-][\\d]+");
    std::regex negOperand("[-]?[\\d]+");
    std::regex posOperand("[\\d]+");
    std::regex minusNeg("-{2}[\\d]");



    std::regex overallHelpStructure("[?][URCQurc|+%\\/*\\-]");
    std::regex commandSetHelp("[?][URCQurc]");
    std::regex commandSet("[URCQurcq]");
    std::smatch m;
    std::string input;
    std::cout << ">";
    getline(std::cin, input);

    if (std::regex_match(input,overallOperationStructure)){

        // "--7"
        if (std::regex_match(input,minusNeg)){
            std::regex_search(input,m,operatorSet);
            temp.operation = m[0].str().at(0);
            std::regex_search(input,m,negOperand);
            temp.operandTwo = std::stoi(m[0].str());
            temp.help = false;
        }
        // "+-7"
        else if (std::regex_match(input,m,operatorWithNegOperand)){
            std::regex_search(input,m,posOperatorSet);
            temp.operation = m[0].str().at(0);
            std::regex_search(input,m,negOperand);
            temp.operandTwo = std::stoi(m[0].str());
            temp.help = false;
        }
        // "-7"
        // "+7"
        else{
            std::regex_search(input,m,operatorSet);
            temp.operation = m[0].str().at(0);
            std::regex_search(input,m,posOperand);
            temp.operandTwo = std::stoi(m[0].str());
            temp.help = false;
        }
        
    }
    else if (std::regex_match(input,m,overallHelpStructure)){
        if (std::regex_match(input,m,commandSetHelp)){
            std::regex_search(input,m,commandSet);
            temp.help = true;
            temp.operation = std::toupper(m[0].str().at(0));
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
    else if (std::regex_match(input,m,commandSetStructure)){
        std::regex_search(input,m,commandSet);
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


