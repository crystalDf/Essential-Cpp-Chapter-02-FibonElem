#include <iostream>

bool fibon_elem(int, int&);
bool print_sequence(int);

int main()
{
    while (true)
    {
        int pos;

        std::cout << "Please enter a position: ";
        std::cin >> pos;

        int elem;

        if (fibon_elem(pos, elem))
        {
            std::cout << "element # " << pos
                    << " is " << elem << std::endl;
            print_sequence(pos);
        }
        else
        {
            std::cout << "Sorry. Could not calculate element # "
                    << pos << std::endl;
        }

        char ch;
        std::cout << "Would you like to try again? (Y/N) ";
        std::cin >> ch;

        if (ch != 'y' && ch != 'Y')
        {
            break;
        }
    }
}

bool fibon_elem(int pos, int& elem)
{
    if (pos < 0 || pos > 1024)
    {
        elem = 0;
        return false;
    }

    elem = 1;
    
    int n_1 = 1;
    int n_2 = 1;
    
    for (int ix = 3; ix <= pos; ++ix)
    {
        elem = n_1 + n_2;
        n_1 = n_2;
        n_2 = elem;
    }

    return true;
}

bool print_sequence(int pos)
{
    if (pos <= 0 || pos > 1024)
    {
        std::cerr << "invalid position: " << pos
                << " -- cannot handle request!" << std::endl;

        return false;
    }
    else
    {
        std::cout << "The Fibonacci Sequence for "
                << pos << " positions: " << "\n\t";

        switch (pos)
        {
            default:
            case 2:
                std::cout << "1 ";
            case 1:
                std::cout << "1 ";
                break;
        }

        int elem;
    
        int n_1 = 1;
        int n_2 = 1;
        
        for (int ix = 3; ix <= pos; ++ix)
        {
            elem = n_1 + n_2;
            n_1 = n_2;
            n_2 = elem;

            std::cout << elem << (!(ix % 10) ? "\n\t" : " ");
        }

        std::cout << std::endl;

        return true;
    }
}