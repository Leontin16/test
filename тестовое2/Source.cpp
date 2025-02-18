#include <iostream>
#include <cstring>
#include <cstdint>
#include <stdexcept>
using namespace std;

enum class Op : uint8_t {
    ADD = 1, SUB, MUL, DIV
};

struct M {
    Op oper;
    float oper1;
    float oper2;
};

M parsM(const uint8_t* data) {
    M msg;
    msg.oper = static_cast<Op>(data[0]);
    memcpy(&msg.oper1, &data[1], sizeof(float));
    memcpy(&msg.oper2, &data[5], sizeof(float));
    return msg;
}

float executeOperation(const M& msg) {
    switch (msg.oper) {
    case Op::ADD:
        return msg.oper1 + msg.oper2;
    case Op::SUB:
        return msg.oper1 - msg.oper2;
    case Op::MUL:
        return msg.oper1 * msg.oper2;
    case Op::DIV:
        if (msg.oper2 == 0) {
            throw "error";
        }
        return msg.oper1 / msg.oper2;
    default:
        throw "error";
    }
}

int main() {
    uint8_t buffer[9];

    M msg;
    msg.oper = Op::ADD;
    msg.oper1 = 5.0f;
    msg.oper2 = 3.0f;

    buffer[0] = static_cast<uint8_t>(msg.oper);
    memcpy(&buffer[1], &msg.oper1, sizeof(float));
    memcpy(&buffer[5], &msg.oper2, sizeof(float));

    M receivedMsg = parsM(buffer);

    try {
        float result = executeOperation(receivedMsg);
        cout << "Result: " << result << endl;
    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
