class TextEditor {
    stack<char> left;
    stack<char> right;
public:
    TextEditor() {
    }
    
    void addText(string text) {
        for(char c : text)
            left.push(c);
    }
    
    int deleteText(int k) {
        int num = 0;
        while(k && !left.empty()){
            left.pop();
            k--;
            num++;
        }

        return num;
    }
    
    string cursorLeft(int k) {
        while(k && !left.empty()){
            right.push(left.top());
            left.pop();
            k--;
        }
        int size = min(10, (int)left.size());
        string str;
        for(int i = 0; i < size; i++){
            str.push_back(left.top());
            left.pop();
        }
        
        reverse(str.begin(), str.end());
        for(char c : str) left.push(c);

        return str;
    }
    
    string cursorRight(int k) {
        while(k && !right.empty()){
            left.push(right.top());
            right.pop();
            k--;
        }
        int size = min(10, (int)left.size());
        string str;
        for(int i = 0; i < size; i++){
            str.push_back(left.top());
            left.pop();
        }
        reverse(str.begin(), str.end());
        for(char c : str) left.push(c);

        return str;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */