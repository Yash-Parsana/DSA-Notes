class Solution {
public:
    bool parseBoolExpr(string expression) {
        return parseBoolExpr(expression, 0).first;
    }
private:
    pair<bool, int> parseBoolExpr(string& expr, int index) {
        if (expr[index] == 'f') return make_pair(false, index + 1);
        if (expr[index] == 't') return make_pair(true, index + 1);
        if (expr[index] == '!') {
            pair<bool, int> result = parseBoolExpr(expr, index + 2);
            return make_pair(!result.first, result.second + 1);
        }
        pair<bool, int> result = parseBoolExpr(expr, index + 2);
        while (expr[result.second] != ')') {
            pair<bool, int> next_result = parseBoolExpr(expr, result.second + 1);
            if (expr[index] == '|') {
                result = make_pair(result.first || next_result.first, next_result.second);
            } else {
                result = make_pair(result.first && next_result.first, next_result.second);
            }
        }
        return make_pair(result.first, result.second + 1);
    }
};