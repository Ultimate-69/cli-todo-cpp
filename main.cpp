#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

void GiveOptions();
void HandleOptionInput();

int main()
{
    GiveOptions();
    HandleOptionInput();
}

void GiveOptions()
{
    std::cout << std::endl;
    std::cout << "Welcome to your To-Do List!" << std::endl;
    std::cout << "Here are some options:" << std::endl;
    std::cout << "1. View your To-Do List" << std::endl;
    std::cout << "2. Add a Task" << std::endl;
    std::cout << "3. Erase all tasks" << std::endl;
    std::cout << "4. Quit" << std::endl;
    std::cout << std::endl;
}

void HandleOptionInput()
{
    int choice;
    std::cin >> choice;
    std::cout << std::endl;
    switch (choice)
    {
    case 1:
    {
        std::cout << "Your Tasks: " << std::endl;
        std::string line;
        std::string contentToSay;
        std::ifstream file("tasks.txt");
        if (file.is_open())
        {
            while (std::getline(file, line))
            {
                contentToSay += "- " + line + '\n';
            }
            file.close();
            std::cout << contentToSay << std::endl;
        }
        else
        {
            std::cout << "Unable to find tasks. Please try to add a task and check again!" << std::endl;
        }
        std::cout << std::endl;
        GiveOptions();
        HandleOptionInput();
        break;
    }
    case 2:
    {
        std::ofstream file;
        std::cout << "Insert a task: ";
        std::string contentToAdd;
        std::getline(std::cin >> std::ws, contentToAdd);
        file.open("tasks.txt", std::ios::app);
        file << contentToAdd << '\n';
        file.close();
        GiveOptions();
        HandleOptionInput();
        break;
    }
    case 3:
    {
        std::cout << "Removed all tasks!" << std::endl;
        remove("tasks.txt");
        std::cout << std::endl;
        GiveOptions();
        HandleOptionInput();
        break;
    }
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