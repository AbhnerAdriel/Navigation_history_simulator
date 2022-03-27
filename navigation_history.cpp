#include <iostream>
#include <string>

struct Node {
    std::string value;
    Node* next;
};

Node *top = NULL;

void push_webpage(std::string webpage);
int search_webpage(std::string webpage);
void display_historic();
void clear_history();

int main() {

    std::string web_page_searched;
    int indice_webpage;

    bool stop_simulation = false;
    while (!stop_simulation) {

        std::cout << "\n## Navigation history simulator ##\n\n";

        std::cout << "What do you want to do?\n\n";
        std::cout << "[1] - Access a webpage\n";
        std::cout << "[2] - View browsing history\n";
        std::cout << "[3] - Search for webpage in history\n";
        std::cout << "[4] - Clear browsing history\n";
        std::cout << "[5] - Exit simulation\n";
        std::cout << ">> ";
        int chooice;
        std::cin >> chooice;

        switch (chooice)
        {
            case 1:
                std::cin.ignore();
                std::cout << "URL: ";
                std::getline(std::cin, web_page_searched);
                push_webpage(web_page_searched);
                break;
            
            case 2:
                display_historic();
                break;

            case 3:
                if (top == NULL)
                    std::cout << "\n>> History is empty <<\n";
                else {
                        std::cin.ignore();
                        std::cout << "URL: ";
                        std::getline(std::cin, web_page_searched);
                        indice_webpage = search_webpage(web_page_searched);
                        if (indice_webpage != -1)
                            std::cout << "\n>> The page was found at position " << indice_webpage << " in the history. <<\n";
                        else
                            std::cout << "\n>> Website not found <<\n";
                    }
                break;
            case 4:
                if (top == NULL)
                    std::cout << "\n>> History is empty! <<\n";
                else
                    clear_history();
                break;
            case 5:
                stop_simulation = true;
                break;
            default:
                std::cout << "\n>> Invalid input! Try again <<\n";
                break;
        }

    }

    system("pause");
    return 0;
}

void push_webpage(std::string webpage) {

    Node* ptr = new Node();
    ptr->value = webpage;
    ptr->next = top;
    top = ptr;
}

void display_historic() {

    if (top == NULL)
        std::cout << "\n>> History is empty! <<\n";
    
    else {
        int cout = 1;
        Node *current = top;
        std::cout << "\n+-------------------------------------+\n";
        while (current != NULL) {
            std::cout << cout << " - " << current->value << "\n";
            current = current->next;
            cout++;
        }
        std::cout << "+-------------------------------------+\n";
        
    }
}

int search_webpage(std::string webpage) {

    int cout = 0;
    Node *current = top;

    while (current != NULL) {
        cout++;
        if (current->value == webpage)
            return cout;
        current = current->next;
    }

    return -1;
    
}

void clear_history() {

    while (top != NULL)
    {
        Node *ptr = top;
        top = top->next;
        free(ptr);
    }

    std::cout << "\n>> History has been deleted <<\n";
    
}