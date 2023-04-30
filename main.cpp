#include <iostream>
 #include <cmath>
 #include <string>
 #include <sstream>
using namespace std;

#define NONE    0
#define WELCOME_BANNER             "----------Welcome to the COMMAND-LINE CALCULATOR v1.0!	"
#define INVALID_OPERATION_ERROR    "ERROR: Operation not defined."
#define DIV_BY_ZERO_ERROR    "ERROR: Divide by zero."
#define FIRST_VAR_PROMPT    "Enter the initial value for your variable: "
#define SECOND_VAR_PROMPT    "Enter the second operand: "
#define COMMAND_PROMPT    "Enter command: "
#define RESULT_STR    "Result => "
#define QUIT    "quit"
#define MENU    "menu"
#define ABS    "abs"
#define INC    "inc"
#define DEC    "dec"
#define POW2    "pow2"
#define SHIFT    "shift"
#define ADD    "+"
#define SUB    "-"
#define MULT    "*"
#define DIV    "/"
#define DQUIT    "exit program"
#define DMENU    "display this menu"
#define DABS    "absolute value"

#define DINC    "increment value"
#define DDEC    "decrement value"
#define DPOW2    "raise to the power of 2"
#define DSHIFT    "shifts the bits to the left by one"
#define DADD    "+"
#define DSUB    "-"
#define DMULT    "*"
#define DDIV    "integer division"
#define abs(a)    abs(a)
#define inc(a)    ++(a)
#define dec(a)    --(a)
#define pow2(a)    (a) * (a)
#define shift(a)    (a) << 2
#define add(a, b)    (a) + (b)
#define sub(a, b)    (a) - (b)
#define mult(a, b)    (a) * (b)
#define div(a, b)    (a) / (b)

#define IS_UNARY_OP(op)    (op) < 100 && (op) >= 0
#define IS_BINARY_OP(op)    (op) >= 100 && (op) >= 0
enum OpCode {
    OP_ABS = 0, OP_INC, OP_DEC, OP_POW2, OP_SHIFT,

    OP_ADD = 100, OP_SUB, OP_MULT, OP_DIV,
    OP_QUIT = -10,
    OP_MENU = -11,
    OP_INVALID = -1,
};

int set_initial_value() {
    int var;
    std::cout << FIRST_VAR_PROMPT;
    std::cin >> var;
    return var;
}


#define PRINT_MENU_ENTRY(cmd) std::cout << cmd << "\t\t" << D##cmd << std::endl;

void show_menu() {
    std::cout << "	\n";
    PRINT_MENU_ENTRY(QUIT);
    PRINT_MENU_ENTRY(MENU);
    PRINT_MENU_ENTRY(ABS);
    PRINT_MENU_ENTRY(INC);
    PRINT_MENU_ENTRY(DEC);
    PRINT_MENU_ENTRY(POW2);
    PRINT_MENU_ENTRY(SHIFT);
    PRINT_MENU_ENTRY(ADD);
    PRINT_MENU_ENTRY(SUB);
    PRINT_MENU_ENTRY(MULT);
    PRINT_MENU_ENTRY(DIV);
    std::cout << "	\n";
}

int execute_operation(OpCode op, int arg1, int arg2) {
//std::cout << op << std::endl;
    stringstream ss;
    switch (op) {
        case OP_ABS:
            ss << abs(arg1);
            break;
        case OP_INC:
            ss << inc(arg1);
            break;
        case OP_DEC:
            ss << dec(arg1);
            break;
        case OP_POW2:
            ss << pow2(arg1);
            break;
        case OP_SHIFT:
            ss << shift(arg1);
            break;
        case OP_ADD:
            ss << add(arg1, arg2);
            break;
        case OP_SUB:
            ss << sub(arg1, arg2);
            break;
        case OP_MULT:
            ss << mult(arg1, arg2);
            break;


        case OP_DIV:
            if (arg2 == 0) {
                std::cout << DIV_BY_ZERO_ERROR;
                exit(-1);
            }
            ss << div(arg1, arg2);
            break;
        default:
            break;
    }

    ss >> arg1;
    return arg1;
}

OpCode get_opcode(std::string op) {

    if (op == POW2) {
        return OP_POW2;
    } else if (op == SHIFT) {
        return OP_SHIFT;
    } else if (op == ABS) {
        return OP_ABS;
    } else if (op == INC) {
        return OP_INC;
    } else if (op == DEC) {
        return OP_DEC;
    } else if (op == ADD) {
        return OP_ADD;
    } else if (op == SUB) {
        return OP_SUB;
    } else if (op == MULT) {
        return OP_MULT;
    } else if (op == DIV) {
        return OP_DIV;
    } else if (op == QUIT) {
        return OP_QUIT;
    } else if (op == MENU) {
        return OP_MENU;
    } else {
        return OP_INVALID;
    }
}

OpCode get_command() {


    OpCode op;
    std::string command;
    do {
        std::cout << COMMAND_PROMPT;
        std::cin >> command;
        op = get_opcode(command);
        if (op == OP_INVALID) {
            std::cout << INVALID_OPERATION_ERROR << std::endl;
        }
    } while (op == OP_INVALID);
    return op;
}

int main() {
    int var;
    int var2;
    OpCode op;

    std::cout << WELCOME_BANNER << std::endl;
    show_menu();
    var = set_initial_value();
    while (true) {
        op = get_command();
        if (op == OP_QUIT) {
            break;
        }
        if (op == OP_MENU) {
            show_menu();
            continue;
        }
        if (IS_UNARY_OP(op)) {
            var = execute_operation(op, var, NONE);
        } else if (IS_BINARY_OP(op)) {
            std::cout << SECOND_VAR_PROMPT;
            std::cin >> var2;
            var = execute_operation(op, var, var2);
        }
        std::cout << RESULT_STR << var << std::endl;
    }


    return 0;
}

