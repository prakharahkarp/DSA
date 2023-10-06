class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.length() > num2.length()) return multiply(num2, num1);
        if(num1 == "0" || num2 == "0") return "0";
        string product = "";
        for(int i = 0; i < num1.length() + num2.length(); i++) product += '0';
        int skippedInd = product.length(); 
        // the index of which we place the x-mark to take the place value into account. Since it is outside the length of string, therefore we don't have to skip any element currently

        int i, j, k; 
        // i and j are used to traverse the strings to be multiplied while k is used to traverse the product string
        int carry = 0, temp_ans = 0;
        for(i = num1.length() - 1; i >= 0 ; i--){
            int curr1 = num1[i] - '0';
            k = skippedInd - 1;
//             this way we can easily skip 1 index in each iteration of i
            for(j = num2.size() - 1; j >= 0; j--){
                int curr2 = num2[j] - '0';
                temp_ans = curr1 * curr2 + carry + (product[k] - '0');
                product[k] = (char)('0' + (temp_ans%10));
                carry = temp_ans/10; 
                k--;
            }
            temp_ans = carry + (product[k] - '0');
            product[k] = (char)('0' + temp_ans);
            carry = 0;
            skippedInd--;
        }
        i = 0;
        while(product[i] == '0') i++;
        return product.substr(i);
    }
};