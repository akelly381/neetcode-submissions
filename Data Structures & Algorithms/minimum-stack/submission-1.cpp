class MinStack {
private:
    std::vector<int> data;
    std::vector<int> min_history; // Tracks the minimum state over time

public:
    MinStack() {
        // No broken variables or manual size tracking needed here
    }
    
    void push(int val) {
        data.push_back(val);
        
        // If it's the first item, or smaller than the current minimum, log it
        if (min_history.empty() || val <= min_history.back()) {
            min_history.push_back(val);
        }
    }
    
    void pop() {
        if (!data.empty()) {
            // If the element we are removing is the current minimum, pop it from history too
            if (data.back() == min_history.back()) {
                min_history.pop_back();
            }
            data.pop_back();
        }
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return min_history.back(); // Instant O(1) access to the true minimum
    }
};
