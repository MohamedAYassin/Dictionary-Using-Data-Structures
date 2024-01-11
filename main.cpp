#include <iostream>
#include <string>

using namespace std;

struct Node {
    string word;
    string meaning;
    Node* next;
};

class Dictionary {
private:
    Node* head;

public:
    Dictionary() : head(nullptr) {}

    ~Dictionary() {
        clear();
    }

    void addWord(const string& word, const string& meaning) {
        Node* newNode = new Node{word, meaning, nullptr};
        if (!head || word < head->word) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && word > current->next->word) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        cout << "Word added successfully!\n";
    }

    void searchWord(const string& word) {
        Node* current = head;
        while (current && current->word != word) {
            current = current->next;
        }
        if (current) {
            cout << "Word: " << current->word << "\nMeaning: " << current->meaning << "\n";
        } else {
            cout << "Word not found in the dictionary.\n";
        }
    }

    void deleteWord(const string& word) {
        Node* current = head;
        Node* prev = nullptr;

        while (current && current->word != word) {
            prev = current;
            current = current->next;
        }

        if (current) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            cout << "Word deleted successfully!\n";
        } else {
            cout << "Word not found in the dictionary.\n";
        }
    }

    void displayDictionary() {
        Node* current = head;
        while (current) {
            cout << "Word: " << current->word << "\nMeaning: " << current->meaning << "\n\n";
            current = current->next;
        }
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Dictionary dictionary;

    int choice;
    string word, meaning;

    do {
        cout << "\nDictionary Menu:\n";
        cout << "1. Add new word\n";
        cout << "2. Search for a word\n";
        cout << "3. Delete a word\n";
        cout << "4. Display dictionary\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the word: ";
                cin >> word;
                cout << "Enter the meaning: ";
                cin >> meaning;
                dictionary.addWord(word, meaning);
                break;
            case 2:
                cout << "Enter the word to search: ";
                cin >> word;
                dictionary.searchWord(word);
                break;
            case 3:
                cout << "Enter the word to delete: ";
                cin >> word;
                dictionary.deleteWord(word);
                break;
            case 4:
                cout << "\nDictionary:\n";
                dictionary.displayDictionary();
                break;
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
