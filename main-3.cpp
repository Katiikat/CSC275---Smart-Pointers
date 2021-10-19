#include <iostream>
#include <string>
#include <memory>
#include <vector>

int main()
{
    //welcome the custome
    std::cout << "\n\nWelcome to this nameless breakfast restaurant.\n\n";

    //set up variables to use in program
    int amt2Order;
    int amt2OrderUpdated = 0;

    std::cout << "How breakfast items would you like to order? ";
    std::cin >> amt2Order;
    //create a unique pointer pointing to a string array
    std::unique_ptr<std::string[]> pOrder (new std::string[amt2Order]);

    //make sure the pointer is not null
    if(pOrder != nullptr)
    {
        int i = 0;
        //since I am going back and forth from cin and getline, I need to flush the cin \0 so I can use getline
        //properly
        std::cin.ignore();
        while(i < amt2Order)
        {
            std::cout << "Enter item to order: ";
            //add the entered food item to the order
            std::getline(std::cin,pOrder[i]);
            i++;
        }
    }
    std::cout << "\nYou ordered the following: \n";
    //pretend to be a waiter and read back the order
    for(int i = 0; i < amt2Order; i++ )
    {
        std::cout << pOrder[i] << std::endl;
    }

    std::cout << "Would you like to add to your order? ";
    std::string ans;
    std::cin >> ans;

    if(ans == "Y" || ans == "y")
    {
        std::cout << "\nHow many items would you like to add?";
        //this is the number to add to the original array size to determine the new array size
        std::cin >> amt2OrderUpdated;
    }
    //calculate new array size
    int newArraySize = amt2Order + amt2OrderUpdated;
    //create a shared pointer of the new array
    std::shared_ptr<std::string[]> pOrderUpdated (new std::string[newArraySize]);
    //create a weak pointer pointing the the updated array
    std::weak_ptr<std::string[]> wOrder = pOrderUpdated;

    //copy first array into the new array
    for(int i = 0; i < amt2Order; i++)
    {
        pOrderUpdated[i] = pOrder[i];
    }
    //buffer cin
    std::cin.ignore();
    //add the new items to the order
    for(int i = amt2Order; i < newArraySize; i++ )
    {
        std::cout << "Enter item to order: ";
        std::getline(std::cin,pOrderUpdated[i]);
    }

    //view total order
    std::cout << "\nYour total order is as follows: \n";
    for(int i = 0; i < newArraySize; i++)
    {
        std::cout << pOrderUpdated[i] << std::endl;
    }
    //say goodbye to customer :)
    std::cout << "\nThank you for eating at this nameless breakfast restaurant. \nHave a great day.";


    //All the pointers were in the same scope, thus the end deleted all the pointers that were created.
    std::cout << "\n\nAll pointers have reached out of scope and are deleted.";
    return 0;
}
