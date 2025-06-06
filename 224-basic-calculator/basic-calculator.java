class Solution {
    public int calculate(String s) {
        int num = 0;
        int sign = 1;
        int result = 0;
        Stack<Integer> operation = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                result += num * sign;
                sign = (c == '+') ? 1 : -1;
                num = 0;
            } else if (c == '(') {
                operation.push(result);
                operation.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                result *= operation.pop();
                result += operation.pop();
                num = 0;
            }
        }
        return result + num * sign;
}
};