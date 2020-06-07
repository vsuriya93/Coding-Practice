 def isValid(self, s: str) -> bool:
        stack = []
        dict_map = {'{' : '}', '(':')','[':']'}
        for element in s:
            if element in ('{','(','['):
                stack.append(element)
            elif element in ('}',')',']'):
                if stack:
                    top_element = stack.pop()
                    if dict_map[top_element]!=element:
                        return False
                else:
                    return False
        
        if len(stack)==0:
            return True
        else:
            return False