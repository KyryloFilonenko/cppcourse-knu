#include "TextBox.hpp"
#include <iostream>

int main() {
    // create a TextBox and call draw
    TextBox mybox("my text box", 10, 5);
    // mybox.draw();
    // error C2385: ambiguous access of 'draw'

    // Fix the code to call both draws by using types
    Rectangle &rec = mybox;
    rec.draw();
    Text &tex = mybox;
    tex.draw();

    // try with virtual inheritance
    mybox.draw();

}
