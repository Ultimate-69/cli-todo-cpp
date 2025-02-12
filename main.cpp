#include <iostream>

void GiveOptions();
void HandleOptionInput();

int main()
{
    GiveOptions();
    HandleOptionInput();
}

void GiveOptions()
{
    std::cout << "Welcome to your To-Do List!" << std::endl;
    std::cout << "Here are some options:" << std::endl;
    std::cout << "1. View your To-Do List" << std::endl;
    std::cout << "2. Add a Task" << std::endl;
    std::cout << "3. Erase all tasks" << std::endl;
    std::cout << "4. Quit" << std::endl;
}

void HandleOptionInput()
{
    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        GiveOptions();
        HandleOptionInput();
        break;
    case 2:
        GiveOptions();
        HandleOptionInput();
        break;
    case 3:
        GiveOptions();
        HandleOptionInput();
        break;
    case 4:
        std::cout << "Quitting..." << std::endl;
        exit(0);
        break;
    default:
        std::cout << "Invalid choice!" << std::endl;
        GiveOptions();
        HandleOptionInput();
        break;
    }
}