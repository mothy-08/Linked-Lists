#include <iostream>

struct Node 
{
    int data{};
    Node* next{};
};

class LinkedList 
{
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insert_node(int value)
    {
        Node* new_node_1 = new Node;
        new_node_1->data = value;
        new_node_1->next = nullptr;

        if (head == nullptr) 
        {
            head = new_node_1;
        }
        else 
        {
            Node* new_node_2 = head;

            while (new_node_2->next != NULL)
            {
                new_node_2 = new_node_2->next;
            }

            new_node_2->next = new_node_1;
        }
    }

    void insert_at_start(int value)
    {
        Node* new_node = new Node;
        new_node->data = value;
        new_node->next = head;
        head = new_node;
    }

    void insert_at_position(int value, int position)
    {
        if (position <= 0) 
        {
            insert_at_start(value);
            return;
        }

        Node* new_node = new Node;
        new_node->data = value;

        if (position == 1) 
        {
            new_node->next = head;
            head = new_node;
            return;
        }

        Node* current = head;
        int count = 1;

        while (current != nullptr && count < position - 1) 
        {
            current = current->next;
            count++;
        }

        if (current == nullptr) 
        {
            tail->next = new_node;
            tail = new_node;
        }
        else 
        {
            new_node->next = current->next;
            current->next = new_node;
        }
    }

    void compare()
    {
        int head_node{}, tail_node = head->data;
        Node* current = head;

        if (current == nullptr)
        {
            std::cout << "NO ELEMENTS TO COMPARE!" << std::endl;
            system("pause");
            return;
        }
        else
        {
            while (current != nullptr)
            {
                current = current->next;
                head_node = current->data;

                if (current->next == nullptr)
                    break;
            }

            if (head_node > tail_node)
                std::cout << head_node << " is greater than " << tail_node << std::endl << std::endl;
            else if (head_node < tail_node)
                std::cout << tail_node << " is greater than " << head_node << std::endl << std::endl;
            else
                std::cout << tail_node << " is equal to " << head_node << std::endl << std::endl;
        }
    }

    void delete_first() 
    {
        if (head == nullptr)        
            return;        

        Node* first_node = head;
        head = head->next;

        if (head == nullptr)
            tail = nullptr;

        std::cout << first_node->data << " is successfully deleted." << std::endl;
        delete first_node;
    }

    void delete_last()
    {
        Node* current = head;
        Node* previous = nullptr;

        if (head == nullptr)
            return;

        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        while (current->next != nullptr)
        {
            previous = current;
            current = current->next;
        }

        tail = previous;
        tail->next = nullptr;

        std::cout << current->data << " is successfully deleted." << std::endl;
        delete current;
    }

    void delete_position(int position)
    {
        std::cout << "ENTER THE POSITION OF THE ELEMENT YOU WANT TO DELETE: ";
        std::cin >> position;

        if (head == nullptr)
            return;

        if (position <= 0)
        {
            delete_first();
            return;
        }

        Node* current = head;
        Node* previous = nullptr;
        int count = 1;

        while (current != nullptr && count < position)
        {
            previous = current;
            current = current->next;
            count++;
        }

        if (current == nullptr)
            return;

        if (current == head)
        {
            head = current->next;
            std::cout << current->data << " is successfully deleted." << std::endl;
            delete current;
        }
        else if (current == tail)
        {
            tail = previous;
            tail->next = nullptr;
            std::cout << current->data << " is successfully deleted." << std::endl;
            delete current;
        }
        else 
        {
            previous->next = current->next;
            std::cout << current->data << " is successfully deleted." << std::endl;
            delete current;
        }
    }  

    void delete_element(int value)
    {
        std::cout << "ENTER THE ELEMENT YOU WANT TO DELETE: ";
        std::cin >> value;

        Node* current = head;
        Node* previous = nullptr;

        if (current == nullptr)
        {
            std::cout << "NO ELEMENTS TO DELETE!" << std::endl;
            return;
        }
        else
        {
            std::cout << "ELEMENT/S \"" << value << "\" IS/ARE SUCCESFULLY DELETED" << std::endl << std::endl;
            system("pause");
        }

        while (current != nullptr)
        {
            if (current->data == value)
            {
                if (previous == nullptr)
                {
                    head = current->next;
                    delete current;
                    current = head;

                }     
                else
                {
                    previous->next = current->next;
                    delete current;
                    current = previous->next;
                }
            }
            else
            {
                previous = current;
                current = current->next;
            }
        };
    }

    void display()
    {
        std::cout << "DISPLAYING LINKED LIST: ";

        Node* current = head;

        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }   

        std::cout << std::endl << std::endl;
    }

    void search(int value)
    {
        std::cout << "ENTER THE ELEMENT YOU WANT TO SEARCH: ";
        std::cin >> value;
        std::cout << std::endl;

        display();

        Node* current = head;
        Node* previous = nullptr;
        int i = 1, position = 0;

        if (current == nullptr)
        {
            std::cout << "NO ELEMENTS INSIDE THE LIST!" << std::endl;
            return;
        }
        else
            std::cout << "POSITION OF ELEMENT " << value << ": ";

        while (current != nullptr)
        {
            if (current->data == value)
            {
                previous = current;
                position = i;
                std::cout << position << " ";
                current = current->next;
            }
            else
            {
                previous = current;
                current = current->next;
            }

            i++;
        }

        std::cout << std::endl;
    }
};

void handle_error(int& choice, int n = 4)
{
    if (n == 4)
    {
        while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "CHOICE: ";
            std::cin >> choice;
        }
    }
    else
    {
        while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "CHOICE: ";
            std::cin >> choice;
        }
    }
}

void enter_value(int& value)
{ 
    std::cout << "ENTER VALUE: ";
    std::cin >> value;
}

int main() 
{
    LinkedList linked_list;

    int choice = 0, position = 0, value = 0;

    std::cout << "LINKED LISTS" << std::endl << std::endl;
    std::cout << "ENTER 5 VALUES:" << std::endl;

    enter_value(value);
    linked_list.insert_node(value);
    enter_value(value);
    linked_list.insert_node(value);
    enter_value(value);
    linked_list.insert_node(value);
    enter_value(value);
    linked_list.insert_node(value);
    enter_value(value);
    linked_list.insert_node(value);

    while (true)
    {
        system("cls");

        std::cout << "PLEASE CHOOSE BELOW: " << std::endl;
        std::cout << "[1] ADD ELEMENTS" << std::endl;
        std::cout << "[2] DELETE ELEMENTS" << std::endl;
        std::cout << "[3] DISPLAY ELEMENTS" << std::endl;
        std::cout << "[4] SEARCH ELEMENTS" << std::endl;
        std::cout << "[5] TERMINATE PROGRAM" << std::endl << std::endl;
        std::cout << "CHOICE: ";
        std::cin >> choice;

        handle_error(choice, 5);

        if (choice == 1)
        {
            std::cout << "ADDING ELEMENTS" << std::endl << std::endl;
            std::cout << "[1] ADD AT THE START" << std::endl;
            std::cout << "[2] ADD AT THE END" << std::endl;
            std::cout << "[3] ADD AT POSITION X" << std::endl;
            std::cout << "[4] COMPARE HEAD AND TAIL" << std::endl << std::endl;
            std::cout << "CHOICE: ";
            std::cin >> choice;

            handle_error(choice);

            if (choice == 1)
            {
                enter_value(value);
                linked_list.insert_at_start(value);
                linked_list.display();
                system("pause");
            }
            else if (choice == 2)
            {
                enter_value(value);
                linked_list.insert_node(value);
                linked_list.display();
                system("pause");
            }
            else if (choice == 3)
            {
                linked_list.display();
                std::cout << "ENTER POSITION: ";
                std::cin >> position;
                enter_value(value);
                linked_list.insert_at_position(value, position);
                linked_list.display();
                system("pause");
            }
            else if (choice == 4)
            {
                std::cout << "COMPARING HEAD AND TAIL ELEMENT" << std::endl << std::endl;
                linked_list.display();
                linked_list.compare();
                system("pause");    
            }       
        }
        else if (choice == 2)
        {
            std::cout << "DELETING ELEMENTS" << std::endl << std::endl;
            std::cout << "[1] DELETE FIRST ELEMENT" << std::endl;
            std::cout << "[2] DELETE LAST ELEMENT" << std::endl;
            std::cout << "[3] DELETE POSITION OF X ELEMENT" << std::endl;
            std::cout << "[4] DELETE ELEMENT X" << std::endl;
            std::cout << "CHOICE: ";
            std::cin >> choice;

            handle_error(choice);

            if (choice == 1)
            {
                linked_list.delete_first();
                system("pause");
            }
            else if (choice == 2)
            {
                linked_list.delete_last();
                system("pause");
            }
            else if (choice == 3)
            {
                linked_list.delete_position(position);
                system("pause");
            }
            else if (choice == 4)            
            {
                linked_list.delete_element(value);
                system("pause");
            }
        }
        else if (choice == 3)
        {
            linked_list.display();
            system("pause");
        }
        else if (choice == 4)
        {
            linked_list.search(value);
            system("pause");
        }
        else if (choice == 5)
            return 0;
    }
}