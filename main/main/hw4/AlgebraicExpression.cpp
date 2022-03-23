#include "AlgebraicExpression.h"
//Emrehan Hoþver 21903488
int priorityalgeb(char c) {
    //kullanma 
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
std::string infix2postfix(const std::string exp) {
    //boþluklarý hallet !!!
    Stack s; 
    std::string result;
    std::string temp = "";
    for (int i = 0; i < exp.length(); i++) {
        std::string c(1, exp[i]);
        s.getTop(temp);
        if (c == " ") continue;
        if ((c >= "0" && c <= "9"))
            result += c;

      
        else if (c == "(")
           s.push(c);

      
        else if (c == ")") {
            
            while (temp != "(" && !s.isEmpty())
            {
                result +=  temp;
                s.pop();
                s.getTop(temp);
                
            }
            s.pop();
            
        }

       
        else {
           
            while (!s.isEmpty() && priorityalgeb(c[0]) <= priorityalgeb(temp[0])) {
                
                result += temp;
                s.pop();
                s.getTop(temp);
                
            }
            
            s.push(""+c);
            
        }
    }
    s.getTop(temp);
    
    while (!s.isEmpty()) {
        //to check other elements until stack is empty
        result += temp;
        s.pop();
        s.getTop(temp);
       
    }
    
    return result;

}
std::string infix2prefix(const std::string exp) {
    //boþluklarý hallet 
    int l = exp.size();
    std::string result;
    
    result = rever(exp);

    
    for (int i = 0; i < l; i++) {

        if (result[i] == '(') {
            result[i] = ')';
            i++;
        }
        else if (result[i] == ')') {
            result[i] = '(';
            i++;
        }
    }
    std::string realr = infix2postfix(result);
    
    return rever(realr);
}
std::string rever(std::string s) {
    //ters çevirmek için
    int size = s.length();
    int j = size, i = 0;
    std::string ss(s.length(), '\0');

    ss[j--] = '\0';
    while (s[i] != '\0')
    {
        ss[j] = s[i];
        j--;
        i++;
    }
    
    return ss;
}
//bu iyi çalýþýyor 
std::string prefix2infix(const std::string exp) {
    Stack s;
    std::string c;
    std::string s1;
    std::string s2;
  


    for (int i = exp.length()-1; i >= 0; i--) {
        while (exp[i] != ' ') {
            c = std::string(1, exp[i]) + c;
            i--;
            if (i >= exp.length()) {
                break;
            }
        }
        char cc = c[0];
        if (isOperator(cc)) {
          
           
            s.getTop(s1);   
            s.pop();
             
            s.getTop(s2);  
            s.pop();
                    
            s.push("(" + s1 + c + s2 + ")");
        }

        else {

           
            s.push(c+"");
        }
        c = "";
    }
    std::string last;
    s.getTop(last);
    return last;
}
bool isOperator(char x) {

    //bunu kullan diðerini deðil 
     switch (x) {
        case '+':
         case '-':
        case '/':
        case '*':
        return true;
        }
    return false;
 

}
std::string prefix2postfix(const std::string exp) {
    // usage of written code 
    std::string res = prefix2infix(exp);
    return infix2postfix(res);

}

std::string postfix2infix(const std::string exp) {
    //reuse of code 
    std::string temo = postfix2prefix(exp);

    return prefix2infix(temo);
    


}
std::string postfix2prefix(const std::string exp) {

    Stack s;

    std::string c = "";
    std::string s1;
    std::string s2;
    for (int i = 0; i < exp.length(); i++)
    {
        while (exp[i] != ' ') {

            c += std::string(1, exp[i]);
            i++;
            if (i >= exp.length()) break;
        }
        char cc = c[0];
        if (isOperator(cc)) {
            s.getTop(s1);
            s.pop();

            s.getTop(s2);
            s.pop();
            s.push(c + " " + s2 + " " + s1);

        }


        else
        {
            s.push(c);
        }
        c = "";
    }


    std::string last;
    s.getTop(last);
    return last;

}
