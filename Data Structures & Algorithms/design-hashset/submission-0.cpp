// The building block: A Node class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// The wrapper: A LinkedList class to manage nodes
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // 1. Add element to the front (O(1))
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 2. Add element to the end (O(n))
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // 3. Print the list
    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    void remove(int val) { 
        // Case 1: Empty list
        if (head == nullptr) return;

        // Case 2: Node to remove is the head
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Case 3: Node to remove is in the middle or end
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }

        // If value was found
        if (curr != nullptr) {
            prev->next = curr->next;
            delete curr;
        }
    }

    bool contains(int val) {
        Node* current = head; // Start at the beginning
        while (current != nullptr) {
            if (current->data == val) {
                return true; // Value found
            }
            current = current->next; // Move to next node
        }
        return false; // Not found
    }

    // 4. Destructor to free memory and prevent leaks
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

class MyHashSet {
public:
    static const int buckets = 10000;
    vector<LinkedList> hashSet;

    MyHashSet() : hashSet(buckets) {}
    
    void add(int key) {
        if (!contains(key))
            hashSet[hash(key) % buckets].insertAtEnd(key);
    }
    
    void remove(int key) {
        hashSet[hash(key) % buckets].remove(key);
    }
    
    bool contains(int key) {
        return hashSet[hash(key) % buckets].contains(key);
    }

    uint32_t hash(uint32_t x) {
        x = ((x >> 16) ^ x) * 0x45d9f3bu;
        x = ((x >> 16) ^ x) * 0x45d9f3bu;
        x = (x >> 16) ^ x;
        return x;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */