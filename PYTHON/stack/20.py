class Solution:
    def isValid(self, s: str) -> bool:
        stack = [] # created an empty stack 
        for ch in s : # looping through elements of s 

            if ch == "(" or ch == "{" or ch == "[": # if ( or { or [ appears we will append it on the stack 
                stack.append(ch)
            else :
                if not stack : #  chec if the stack is non empty before popping element
                    return False 
                top = stack.pop() 

                if (ch == ')' and top != '(') or (ch == ']' and top != '[') or (ch == '}' and top !=  # matching parenthesis 
                    return False 
        if len(stack) != 0 :
            return False

        return True 

                
