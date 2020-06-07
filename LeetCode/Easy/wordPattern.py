def wordPattern(self, pattern: str, str: str) -> bool:
        str = str.split(' ')
        
        if len(str) != len(pattern):
            return False
        
        mapper = {}
        for element, word in zip(pattern, str):
            if mapper.get(element) is None:
                if word not in mapper.values():
                    mapper[element] = word
                    continue
                else:
                    return False
            elif mapper[element]==word:
                continue
            else:
                return False
            
        return True