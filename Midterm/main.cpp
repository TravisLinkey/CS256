#include <iostream>
#include "Parent.h"
#include "Child.h"

int main() {
    Parent Homer("Homer", 38, 'M');
    Parent March("March", 36, 'F');

    Homer.set_work("Safety Inspector");
    March.set_work("Housewife");

    Child Bart(Homer,March);
    Child Lisa(Homer,March);
    Child Maggie(Homer,March);

    Bart.set_work("Student");
    Lisa.set_work("Student");
    Maggie.set_work("Play");

    March.set_name(Maggie, "Maggie");
    Homer.set_name(Bart, "Bart");
    Homer.set_name(Lisa, "Lisa");

    March.get_child();

    return 0;
}