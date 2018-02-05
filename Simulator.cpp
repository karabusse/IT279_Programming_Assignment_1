//
// Created by Frazzlectra on 2/4/2018.
//

int main() {
    list* l = new list();
    int input;
    char choice;
    cout << "Enter a list of integers in order to add them to the linked list. When you are done entering numbers, enter the letter n"<< endl;
    for (;;) {
        cin >> choice;
        if (choice != 'n') {
            input = atoi(&choice);
            l->add(input);
        }
        else {
            break;
        }
    }
    l->print();

    int sum = 0;
    double counter = 0;
    node* current = l->head;
    while (current != nullptr) {
        sum += current->data;
        counter++;
        current = current->next;
    }
    cout << "The sum of the list is " << sum << endl;
    cout << "The average of the list is " << (sum / counter) << endl;

    cout << "Enter a value you'd like to delete " << endl;
    cin >> input;
    l->remove(l->search(input));
    l->print();
    return 0;
}

