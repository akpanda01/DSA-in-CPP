class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // Initialize result
        long long num1 = 0, num2 = 0;
        const long long MOD = 1e9 + 7;

        // Traverse the first list and calculate the number
        while (first != nullptr) {
            num1 = (num1 * 10 + first->data) % MOD;
            first = first->next;
        }

        // Traverse the second list and calculate the number
        while (second != nullptr) {
            num2 = (num2 * 10 + second->data) % MOD;
            second = second->next;
        }

        // Multiply the two numbers and take modulo MOD
        return (num1 * num2) % MOD;
    }
};
