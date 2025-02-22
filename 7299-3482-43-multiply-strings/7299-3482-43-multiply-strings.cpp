class Solution {
public:
    string multiply(string num1, string num2) {
           if (num1 == "0" || num2 == "0") return "0"; // If any number is 0, product is 0.

    int len1 = num1.size(), len2 = num2.size();
    vector<int> result(len1 + len2, 0); // To store intermediate results

    // Multiply each digit from the back of num1 and num2
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0'); // Convert char to int and multiply
            int sum = mul + result[i + j + 1]; // Add to the previous result at the correct position

            result[i + j + 1] = sum % 10; // Store the unit digit
            result[i + j] += sum / 10; // Carry to the previous place
        }
    }

    // Convert result vector to string, skipping leading zeros
    string product = "";
    for (int num : result) {
        if (!(product.empty() && num == 0)) // Skip leading zeros
            product += (num + '0'); // Convert int to char
    }

    return product;
    }
};