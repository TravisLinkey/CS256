#include <iostream>
#include "CustomerData.h"
#include "PreferredCustomer.h"

int main() {

    CustomerData customerData1;
    customerData1.set_firstName("Danny");
    customerData1.set_lastName("Morrison");
    customerData1.set_city("Pomona");
    customerData1.set_state("California");
    customerData1.set_address("4555 Sinclair Lane");
    customerData1.set_zip("91767");
    customerData1.set_phone("(760)760-8998");
    customerData1.print_info();

    PreferredCustomer customer2;
    customer2.set_firstName("Tommy");
    customer2.set_lastName("Hilfiger");
    customer2.set_city("Los Angeles");
    customer2.set_state("California");
    customer2.set_address("California Lane Ave");
    customer2.set_zip("92277");
    customer2.set_phone("(760)321-5468");
    customer2.set_purchaseAmount(-100);
    customer2.set_purchaseAmount(3000);
    customer2.set_purchaseAmount(2000);
    customer2.print_info();
    std::cout<< "Customer 2 discount level: " << customer2.get_discountLevel();

    return 0;
}